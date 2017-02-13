#include <iostream>
using namespace std;

static const char TERMINADOR = '#'; 
static const int TAMANIO = 3e+6; 
static const int NUMERO_CARACTERES_ASCII = 256; 

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

   int NumeroOcurrencias(char buscado, int izda, int dcha){
       SecuenciaCaracteres procesados;
       int ocurrencias = 0; 
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
            ocurrencias++;
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
   int ocurrencias_caracter;
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
      
   ocurrencias_caracter = secuencia.NumeroOcurrencias(caracter_buscado, pos_izda, pos_dcha);
   
   cout << "\nCaracter:       " << "<" << caracter_buscado << ">"
        << "\nOcurrencias: " << ocurrencias_caracter << endl;
}

