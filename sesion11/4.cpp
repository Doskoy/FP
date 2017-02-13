#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct FrecuenciaCaracter{
   char caracter;
   int frecuencia;
};

int main(){
   const char TERMINADOR = '#';    
   const int TAMANIO = 25e+5;
   const int TAMANIOAUX = 255;
   char vector[TAMANIO];
   FrecuenciaCaracter char_procesados[TAMANIOAUX];
   int total_utilizados;
   int total_utilizados_aux;
   char caracter;
   bool encontrado = false; 
   FrecuenciaCaracter maximo;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_utilizados = 0;
   total_utilizados_aux = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_utilizados < TAMANIO){
      vector[total_utilizados] = caracter;
      total_utilizados++;
      caracter = cin.get();
   }
   //////////////////////////////////////////////////////////////////
   //Procesado del texto
   //////////////////////////////////////////////////////////////////
   int j = 0;
   for (int i = 0; i <= total_utilizados-1; i++){ // Recorro el vector del texto
      while (j <= total_utilizados_aux && !encontrado){ //Recorro el vector de procesados
         if (vector[i] == char_procesados[j].caracter){
            encontrado = true;
         }
         else{
            j++;
         }
      }
      if(encontrado = false){
         total_utilizados_aux++;
         char_procesados[total_utilizados_aux].caracter = vector[i];
         char_procesados[total_utilizados_aux].frecuencia = 1;
      }
      else{
         char_procesados[j].frecuencia++;
      }
     
   }
   //////////////////////////////////////////////////////////////////
   //Calculo del maximo
   //////////////////////////////////////////////////////////////////
      maximo.caracter = char_procesados[0].caracter;
      maximo.frecuencia = char_procesados[0].frecuencia;
   for (int i = 0; i < total_utilizados_aux; i++){
      if(maximo.frecuencia > char_procesados[i].frecuencia){
         maximo.caracter = char_procesados[i].caracter;
         maximo.frecuencia = char_procesados[i].frecuencia;
      }
   }
   //////////////////////////////////////////////////////////////////
   cout << "El caracter que se ha repetido mas es '" << maximo.caracter << "' con un total de " << maximo.frecuencia << "veces.\n "; 
}