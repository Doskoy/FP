#include <iostream>
using namespace std;

static const char TERMINADOR = '#'; 
static const int TAMANIO = 3e+6; 
static const int NUMERO_CARACTERES_ASCII = 256; 


class SecuenciaEnteros{
private:
   static const int TAMANIO = 50;
   long vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaEnteros()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(long nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, long nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   long Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++){
         cadena.append(to_string(vector_privado[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(vector_privado[i])  <- Evitarlo. Muy ineficiente para tamaños grandes;
      }
      
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, long buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (long buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < total_utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      long minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (long buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, long valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < total_utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, total_utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      long a_desplazar;

      for (izda=1; izda < total_utilizados; izda++){
         a_desplazar = vector_privado[izda];

         for (i=izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[i] = a_desplazar;
      }
   }
   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < total_utilizados; izda++)
        for (i = total_utilizados-1 ; i > izda ; i--)
          if (vector_privado[i] < vector_privado[i-1])
             IntercambiaComponentes_en_Posiciones(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < total_utilizados && cambio; izda++){
        cambio=false;

        for (i=total_utilizados-1 ; i>izda ; i--)
          if (vector_privado[i] < vector_privado[i-1]){
             IntercambiaComponentes_en_Posiciones(i, i-1);
             cambio=true;
          }
      }
   }
   
   void AniadeVarios(SecuenciaEnteros nuevos){
      int totales_a_aniadir = nuevos.TotalUtilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }


   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosicionContiene (SecuenciaEnteros a_buscar){
      int  inicio;
      int  ultima_componente;
      bool encontrado;
      int  posicion_contiene;
      bool va_coincidiendo;
      int  utilizados_a_buscar;

      /*
      Tenemos una secuencia "grande" de tamaño G y otra pequeña de tamaño P

      Recorrer la secuencia "grande" fijando una posición inicial inicio
      La última posición inicial a probar será G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "pequeña"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      utilizados_a_buscar = a_buscar.TotalUtilizados();

      if (utilizados_a_buscar > 0){
         ultima_componente = total_utilizados - utilizados_a_buscar;
         encontrado = false;

         for (inicio = 0; inicio <= ultima_componente && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < utilizados_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = vector_privado[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               posicion_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return posicion_contiene;
      else
         return -1;
   /*
   Batería de pruebas:
      Los dos vectores vacíos.
      Alguno de ellos vacío.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego sí se encuentre.  atttij / ti
   */
   }
};


struct FrecuenciaCaracter{
   char caracter;
   int  frecuencia;
};
   
class SecuenciaCaracteres{
private:
   char vector_privado[TAMANIO];
   int  total_utilizados;
public:
   SecuenciaCaracteres()
      :total_utilizados(0)
   {
   }

   int  TotalUtilizados(){
      return  total_utilizados;
   }

   void  Aniade(char  nuevo){
      if (total_utilizados  <  TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }
   
   int Capacidad(){
      return TAMANIO;
   }

   void AniadeCadena(string nuevo){
      int tope = nuevo.size();

      for (int i = 0; i < tope; i++)
         Aniade(nuevo[i]);
   }

   char Elemento(int  indice){
      return  vector_privado[indice];
   }

   void Modifica(int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }


   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }

   SecuenciaEnteros PosicionesOcurrencias(char buscado, int izda, int dcha){
       SecuenciaEnteros ocurrencias;
       SecuenciaCaracteres procesados;
       char caracter_actual;
       bool encontrado;

       for(int i = izda; i < dcha; i++){
         caracter_actual = vector_privado[i];
         encontrado = false;

         if (caracter_actual == buscado)
            encontrado = true;
         
         if(!encontrado){
            procesados.Aniade(caracter_actual);
         }
         else
            ocurrencias.Aniade(i);
       }
       return ocurrencias; 

   }

   FrecuenciaCaracter Moda(){
      char procesados[NUMERO_CARACTERES_ASCII];
      FrecuenciaCaracter moda;
      char caracter_actual;
      int conteo_frecuencia;
      int utilizados_procesados;
      bool encontrado;


      utilizados_procesados = 0;
      moda.frecuencia = 0;

      for (int i = 0 ; i < total_utilizados ; i++){
         caracter_actual = vector_privado[i];
         encontrado = false;

         for (int j = 0; j < utilizados_procesados && !encontrado; j++){
            if (caracter_actual == procesados[j])
               encontrado = true;
         }

         if (! encontrado){
            procesados[utilizados_procesados] = caracter_actual;
            utilizados_procesados++;
            conteo_frecuencia = 1;

            for (int k = i + 1 ; k < total_utilizados ; k++)
               if (caracter_actual == vector_privado[k])
                  conteo_frecuencia++;

            if (conteo_frecuencia > moda.frecuencia) {
               moda.frecuencia = conteo_frecuencia;
               moda.caracter   = caracter_actual;
            }
         }
      }
      
      return moda;
   }
};


int main(){
   SecuenciaCaracteres secuencia;
   int total_introducidos;
   int capacidad_secuencia;
   char caracter;
   FrecuenciaCaracter moda_secuencia;
   SecuenciaEnteros posiciones_ocurrencias;
   char caracter_buscado; 
   int pos_izda, pos_dcha; 

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   cout << "Introduce los caracteres seguidos del terminador <" << TERMINADOR << ">:\n" ; 
   total_introducidos = 0;
   caracter = cin.get();
   capacidad_secuencia = secuencia.Capacidad();

   while (caracter != TERMINADOR && total_introducidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_introducidos++;
      caracter = cin.get();
   }

   cout << "Introduce el caracter buscado seguido de la primera"
   << " y la ultima posicion entre las que buscarlo: ";

   cin >> caracter_buscado >> pos_izda >> pos_dcha; 

   if (pos_dcha > secuencia.TotalUtilizados())
      pos_dcha = secuencia.TotalUtilizados();
      
   posiciones_ocurrencias = secuencia.PosicionesOcurrencias(caracter_buscado, pos_izda, pos_dcha);
   
   cout << "\nCaracter:       " << "<" << caracter_buscado << ">"
        << "\nPosiciones de las Ocurrencias: " << posiciones_ocurrencias.ToString() << endl;
}

