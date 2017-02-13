//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Palíndromo e Invierte en el main

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main(){
   const char TERMINADOR = '#';    
   const int TAMANIO = 100;
   char vector[TAMANIO];
   int total_utilizados;
   char caracter;   
   bool es_palindromo;
   int  izda, dcha;
   char intercambia;

   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:
   
   total_utilizados = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_utilizados < TAMANIO){
      vector[total_utilizados] = caracter;
      total_utilizados++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // Palíndromo:
   /////////////////////////////////////////////////////////////////
   /*
	Nota de clase: en vez de utilizar izda y dcha se puede utilizar un indice i para la [izda] y [totalutil-1 -i]
	de forma que el while quedaria asi: 
	while(i < (totalutil-1 -i) && es_palindromo){
		if (vector[i] ! = vector [total_util-1 -i])
			es_palindromo = false;
		else{
		izda++;
		dcha--;
		}
	}
   */

   es_palindromo = true;
   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha && es_palindromo){
      if (vector[izda] != vector[dcha])
         es_palindromo = false;
      else{
         izda++;
         dcha--;
      }
   }

   if (es_palindromo)
      cout << "\nEs palíndromo";
   else
      cout << "\nNo Es palíndromo";
  
   //////////////////////////////////////////////////////////////////
   // Invierte:   

   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha){
      intercambia = vector[izda];
      vector[izda] = vector[dcha];
      vector[dcha] = intercambia;
      izda++;
      dcha--;
   }
   
   cout << "\nComponentes del vector después de invertirlo: <";
   
   for (int i = 0; i < total_utilizados; i++)
      cout  << vector[i] << " ";
   
   cout << ">\n";

}
