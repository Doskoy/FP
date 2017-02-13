#include <iostream>
using namespace std;

int main(){
   const int TERMINADOR = -1;
   double dato, referencia;
   const int TAMANIO =  1e5;
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

   //////////////////////////////////////////////////////////////

   int izda, dcha;
   double a_insertar;

   utilizados_mayores_que = 0; 

   for (int i = 0; i < utilizados_vector; i++)
      if (vector[i] >= referencia){
         valor_insertar = vector[i]
         for(int v = utilizados_mayores_que-1; v >= 0; v--){
            if(valor_insertar <= )
         }

         mayores_que[utilizados_mayores_que] = vector[i];
         utilizados_mayores_que++;
      }

   //////////////////////////////////////////////////////////////
   /*
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
   */
   ///////////////////////////////////////////////////////////////

   for (int i = 0; i < utilizados_mayores_que; i++)
      cout << mayores_que[i] << " ";
}
   


