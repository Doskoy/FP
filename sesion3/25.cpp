#include <iostream>
using namespace std;

int main(){

	const int DIFERENCIA = 'a' - 'A'; 
	char caracter; 
	char caracter_minus; 

	cout << "Introduzca una letra en mayuscula: ";
	cin >> caracter; 

	caracter_minus = caracter + DIFERENCIA	; 

	cout << "La letra en minuscula es: " << caracter_minus << endl;



}