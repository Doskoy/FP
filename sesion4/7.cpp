#include <iostream>
using namespace std;

int main() {
	int numero1, numero2, numero3; 
	bool ordenado;

	cout << "Introduce los 3 numeros separados por un espacio: ";
	cin >> numero1 >> numero2 >> numero3;

	if (numero1 <= numero2 <= numero3)
		ordenado = true; 
		else 
			if (numero1 >= numero2 >= numero3)
				ordenado = true;
				else 
					ordenado = false; 

	if (ordenado)
		cout << "Los numeros estan ordenados" << endl;
			else		
			 	cout << "Los numeros estan ordenados" << endl;	
}