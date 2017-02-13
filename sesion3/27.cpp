#include <iostream>
#include <cctype>
using namespace std;

int main() {

	char letra;
	bool es_minus, rango_edad, rango_numero, anio_bisiesto; 
	int edad, adivine, anio;

	cout << "Introduzca una letra: "; 
	cin >> letra;

	cout << "Introduzca la edad: ";
	cin >> edad;

	cout << "Introduzca un numero: ";
	cin >> adivine;

	cout << "Introduzca el año: "; 
	cin >> anio;

	//Calculo de si un literal de tipo char es mayuscula o minuscula.
	//Solucion 1: Utilizando la funcion "islower()" de la libreria "cctype".
	es_minus = islower (letra);
	
	//Solucion 2: Utilizando el caracter 'a' como referencia. 
	/*
	if (letra < 'a')
		es_minus = true; 
	*/

	//Calculo de si la edad no esta en el rango 18 - 65
	if (edad < 18 || edad > 65)
		rango_edad = true;
		else 
			rango_edad = false; 
	//Calculo de si un numero esta en el rango 1 - 100 
	if (adivine > 1 && edad < 100)
		rango_numero = true;
		else 
			rango_numero = false;

	//Calculo de un año es
	if ((anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0))
		anio_bisiesto = true; 
		else
			anio_bisiesto = false;

	//Salida///////////////
	cout << es_minus << "\t" << rango_edad << "\t" << rango_numero << "\t" << anio_bisiesto << endl;
}