//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Buscaminas

/*
Éste es un juego muy conocido cuyo objetivo es encontrar todas las minas
existentes en un tablero rectangular, sin abrir ninguna.
Si el jugador abre una mina, pierde la partida.
Se pide definir la clase TableroBuscaMinas conteniendo lo siguiente:

a) Para representar el tablero se trabajará con una matriz de datos de tamaño 50 ×
30 en la que todas las filas tienen el mismo número de columnas y los datos son
de tipo bool . Contendrá un valor true en caso de haber una mina en la casilla
especificada y false en caso contrario. Esta matriz será un dato miembro de la
clase y al principio, todos los valores estarán a false .

b) Un método para incluir una mina en una determinada casilla.

c) Un método que reciba las coordenadas (i,j) de una casilla y devuelva un valor
entero que indique el número de minas que rodean a la misma (será un número
entre 0 y 8). En caso de que la casilla contenga una mina, se devolverá el valor
-1.

Hay que tener especial cuidado con las casillas que hay en los bordes de la matriz
ya que la casilla en la posición [0][0] , por ejemplo, sólo tiene tres vecinos
rodeándola.
Por ejemplo, si 0 representa false y 1 representa true :

Tablero original:
1 0 0
1 1 0
0 1 0
0 1 1
0 0 1

Minas alrededor de cada casilla:
-1 3 1
-1 -1 2
4 -1 4
2 -1 -1
1 3 -1

Construya un programa que lea un entero representando el máximo número de minas
a generar. A continuación, el programa asignará aleatoriamente tantas minas como
indique dicho entero (utilice la clase generadora de números enteros pseudoaleatorios
descrita en la página RP-III.14)
Una vez generadas las minas, recorra el tablero completo e imprima, por cada casilla,
cuántas tiene a su alrededor.
*/

#include <iostream>
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
using namespace std;


class GeneradorAleatorioEnteros{
private:
   mt19937 generador_mersenne;   // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec(){
      return chrono::high_resolution_clock::now().
             time_since_epoch().count();
   }
public:
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   GeneradorAleatorioEnteros(int min, int max){
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006

      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme =
         uniform_int_distribution<int> (min, max);
   }

   int Siguiente(){
      return distribucion_uniforme(generador_mersenne);
   }
};

class TableroBuscaMinas{
private:
   static const int FILAS = 50;
   static const int COLUMNAS = 30;
   bool tablero[FILAS][COLUMNAS];
   
   bool EnRango(int fil, int col){
      return 0 <= fil && fil < FILAS && 0 <= col && col < COLUMNAS;
   }
public:
   TableroBuscaMinas(){
      for (int i = 0; i < FILAS; i++)
         for (int j = 0; j < COLUMNAS; j++)
            tablero[i][j] = false;
   }
   
   void AsignaMina (int fil, int col){
      if (EnRango(fil, col))
         tablero[fil][col] = true;
   }
   
   int MaxFilas(){
      return FILAS;
   }
   
   int MaxColumnas(){
      return COLUMNAS;
   }

   int NumeroMinasAlrededor(int fil, int col){
      int numero_minas = 0;
      
      if (EnRango(fil, col)){
         if (tablero[fil][col])
            numero_minas = -1;
         else{
            for (int i = -1; i <= 1; i++) {
               for (int j = -1; j <= 1; j++){
                  
                  if (! (i == 0 && j == 0)) {
                     int fil_alrededor = fil + i;
                     int col_alrededor = col + j;
                  
                     if (
                        EnRango(fil_alrededor, col_alrededor)
                        &&
                        tablero[fil_alrededor][col_alrededor])
                      
                        numero_minas++;
                  }
               }
            }
         }
      }

      
      return numero_minas;
   }
   
   string ToString(){
      string cadena;
      
      cadena.reserve(2 * FILAS * COLUMNAS + COLUMNAS);
      
      for (int i = 0; i < FILAS; i++){
         for (int j = 0; j < COLUMNAS; j++){
            cadena.append(to_string(tablero[i][j]));
            cadena.push_back('\t');
         }
         cadena.push_back('\n');
      }
      
      return cadena;
   }
};

int LeeEntero_en_Rango (int inferior, int superior){
   int entero;
   bool en_rango;
   
   do{
      cin >> entero;
      en_rango = inferior <= entero && entero <= superior;
   }while (! en_rango);
   
   return entero;
}


int main(){
   TableroBuscaMinas tablero;
   int max_numero_minas;
   int numero_minas_a_generar;
   int filas_tablero, columnas_tablero;
   
   filas_tablero     = tablero.MaxFilas();
   columnas_tablero  = tablero.MaxColumnas();
   max_numero_minas  = filas_tablero * columnas_tablero;
   numero_minas_a_generar = LeeEntero_en_Rango(1 , max_numero_minas);
   
   GeneradorAleatorioEnteros aleat_filas(0, filas_tablero - 1);
   GeneradorAleatorioEnteros aleat_columnas(0, columnas_tablero - 1);
   
   for (int i=1; i <= numero_minas_a_generar; i++){
      int fila_aleatoria = aleat_filas.Siguiente();
      int columna_aleatoria = aleat_columnas.Siguiente();
      tablero.AsignaMina(fila_aleatoria , columna_aleatoria);
   }
   
   cout << "\n\n";
   cout << "Tablero original:\n";
   cout << tablero.ToString();
   
   cout << "\n\n";
   cout << "Minas alrededor:\n";
   
   for (int i=0; i<filas_tablero; i++){
      cout << "\n";
      
      for (int j=0; j<columnas_tablero; j++)
         cout << tablero.NumeroMinasAlrededor(i,j) << '\t';
   }  
}
