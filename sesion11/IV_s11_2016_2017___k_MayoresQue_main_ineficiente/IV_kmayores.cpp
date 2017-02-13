//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// k valores ordenados mayores que otro

// Dada un vector, construir otro que contenga los k primeros valores
// que sean mayores que un valor de referencia.
// Dichos valores han de ordenarse.

// 5.2  2.5  7.3  4.2  3.1  4.9 -1  4.3  3
// 4.9  5.2  7.3

/*
 (Examen Septiembre 2016) Se dispone de un conjunto de reales positivos y se quiere
construir otro vector mayores_que que contenga los k primeros valores que son
mayores o iguales que otro valor de referencia. Los valores que se obtengan como
resultado deben estar ordenados de menor a mayor.
Por ejemplo, si el vector original es
{5.2 2.5 7.3 4.2 3.1 4.9}
y el valor de referencia es 4.3 , el vector mayores_que debe quedar así:
{4.9 5.2 7.3}
Construya un programa que vaya leyendo datos desde teclado e introdúzcalos en un
vector. La entrada de datos termina con el -1. A continuación lea el real
de referencia y el entero k. Calcule el vector mayores_que e imprímalo en pantalla.
Aplique el siguiente algoritmo:

   Copiar el vector original en "mayores_que"
   Ordenar el vector "mayores_que" de menor a mayor
   (utilizar el algoritmo de ordenación por inserción)

   Seleccionar los k primeros que sean mayores que la referencia

Utilice también el fichero de datos mayores_que.txt disponible en decsai . La
salida correcta se encuentra en el fichero mayores_que_solucion.txt
*/

#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   double dato, referencia;
   const int TAMANIO                 =  1e5;
   double vector[TAMANIO], mayores_que[TAMANIO];
   int utilizados_vector, utilizados_mayores_que, k;
   
   
   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   cout << "k valores mayores que."
        << "\nIntroduzca reales con terminador "
        << TERMINADOR << "\n"
        << "Luego introduzca el valor de referencia y k.\n";
        
   utilizados_vector = 0;
   cin >> dato;

   while (dato != TERMINADOR && utilizados_vector < TAMANIO){
      vector[utilizados_vector] = dato;
      utilizados_vector++;
      cin >> dato;
   }

   cin >> referencia;
   cin >> k;

   ///////////////////////////////////////////////////////////////

   /*
   Aproximación poco eficiente:

      Copiar el vector original en "mayores_que"

      Ordenar el vector "mayores_que" de menor a mayor
      (utilizar el algoritmo de ordenación por inserción)

      Seleccionar los k primeros que sean mayores que la referencia
   */


   int izda, j;
   double a_insertar;
   
   for (int i = 0; i < utilizados_vector; i++)
      mayores_que[i] = vector[i];

   for (izda = 1; izda < utilizados_vector; izda++){
      a_insertar = vector[izda];

      for (j = izda; j > 0 && a_insertar < vector[j-1]; j--)
         vector[j] = vector[j-1];

      vector[j] = a_insertar;
   }
   
   utilizados_mayores_que = 0;

   for (int i = 0; i < utilizados_vector && utilizados_mayores_que < k; i++){
      a_insertar = vector[i];
      
      if (a_insertar >= referencia){
         mayores_que[utilizados_mayores_que] = a_insertar;
         utilizados_mayores_que++;
      }
   }
   
   ///////////////////////////////////////////////////////////////

   for (int i = 0; i < utilizados_mayores_que; i++)
      cout << mayores_que[i] << " ";
}
   


