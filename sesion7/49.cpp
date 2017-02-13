#include <iostream>
using namespace std; 

int main (){
	int numero, contador_ext, contador_int, suma, contador_salida;

	cout << "Introduce un numero entero positivo: ";
	cin >> numero;

	for (contador_ext = 1; contador_ext < numero; contador_ext++){
		suma = 0; 
		for (contador_int = contador_ext; suma < numero; contador_int++){
			suma = suma + contador_int; 
			if (suma == numero){
				contador_salida = contador_ext;
				do{
					cout << " " << contador_salida << " ";
					contador_salida++;
				}while (contador_salida <= contador_int);
				cout << " / "; 
			}	
		}
	}

}	