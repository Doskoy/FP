////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Matriz promedio

/*
En este ejercicio no hay que construir ninguna función o
clase. Todo se programará en el main . Defina dos matrices de reales original
y suavizada de tamaño 50 x 30 . Lea desde teclado los valores de la matriz
original , obligando a que sea simétrica. Para ello, lea el número de filas n y a
continuación introduzca los n × n datos de la matriz.
Construya la matriz suavizada acorde a las siguientes indicaciones:
a) La tabla resultante será simétrica.
b) Los valores de la diagonal principal de la tabla resultante serán iguales a los de
la tabla original.
c) Los valores del triángulo superior de la tabla resultante se calculan de la si-
guiente manera: si (i,j) es una posición en el triángulo superior de la tabla re-
sultante, su valor es el valor medio de los valores que ocupan las posiciones de
las columnas j,j + 1,...,n - 1 en la fila i de la tabla original.
*/

#include <iostream>
using namespace std;

int main(){
   const int MAX_FIL = 50, MAX_COL = 30;
   double matriz[MAX_FIL][MAX_COL];
   double promedio[MAX_FIL][MAX_COL];
   int util_filas_matriz, util_filas_promedio;
   double suma;


   // No etiquetamos las entradas porque suponemos que leemos de un fichero
   // Supondremos que util_filas > 0

   cin >> util_filas_matriz;

   for (int i=0; i<util_filas_matriz; i++)
      for (int j=0; j<util_filas_matriz; j++)
         cin >> matriz[i][j];

   ///////////////////////////////////////////////////////////////////////////
   // Promedio
   /*
      Algoritmo Matriz Promedio vs 1
      
      Recorrer todas las filas -i- de la matriz original
         Asignar el mismo elemento de la diagonal principal
         
         Recorrer las columnas -j- a partir de i+1
            Calcular la media de los elementos que hay
            en las columnas posteriores a j
            Asignar el resultado a la componente ij y a la ji
   */
   
   /*
   9  7   4  5         9    (7+4+5)/3    (4+5)/2    5/1
   2  18  2  12        =    18           (2+12)/2   12/1
   7  9   1  5         =    =            1          5/1
   0  1   2  3         =    =            =          3
   */
   

   for (int i = 0; i < util_filas_matriz; i++){
      promedio[i][i] = matriz[i][i];
      
      for (int j = i+1; j < util_filas_matriz; j++){
         suma = 0;
         
         for (int k = j; k < util_filas_matriz; k++)
            suma = suma + matriz[i][k];

         promedio[i][j] = suma / (util_filas_matriz - j);
         promedio[j][i] = promedio[i][j];
      }
   }

   

   /*
      Algoritmo Matriz Promedio vs 2 (más rápida)

      Recorrer todas las filas -i- de la matriz original
         Asignar el mismo elemento de la diagonal principal

         Recorrer las columnas -j- desde la última hasta i
            Ir acumulando en una variable suma
            el sumatorio de los m[i][j]
            Asignar media correspondiente a la componente ij y a la ji
   */
   
   /*
   Con una matriz tan pequeña como la siguiente no se aprovecha la
   eficiencia de este algoritmo. De hecho, obsérvese que sólo se aprovecha
   con una componente, la 01 -> (7+9)/3
   */
   /*
   9  7   4  5         9    (7+9)/3      (4+5)/2    5/1
   2  18  2  12        =    18           (2+12)/2   12/1
   7  9   1  5         =    =            1          5/1
   0  1   2  3         =    =            =          3
   */

   for (int i = 0; i < util_filas_matriz; i++){
      promedio[i][i] = matriz[i][i];
      suma = 0;
      
      for (int j = util_filas_matriz - 1 ; j > i; j--){
         suma           = suma + matriz[i][j];
         promedio[i][j] = suma / (util_filas_matriz - j);
         promedio[j][i] = promedio[i][j];
      }
   }

   
   util_filas_promedio = util_filas_matriz;
   
 
   cout << "\n\n";
   cout << "Matriz promedio:\n";
   
   for (int i = 0; i < util_filas_promedio; i++){
      cout << "\n";
      
      for (int j = 0; j < util_filas_promedio; j++)
         cout << promedio[i][j] << '\t';
   }  
   
   // Entrada:
   // 4   9 7 4 5    2 18 2 12    7 9 1 5   0 1 2 3

   // Salida:
   /*
   9       5.33333 4.5     5
   5.33333 18      7       12
   4.5     7       1       5
   5       12      5       3
   */
}
