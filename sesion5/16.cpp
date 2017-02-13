/*
 Hay dos versiones del programa ya que mi compilador no acepta la gramatica 
 que explico el dia anterior en clase de teoria para declarar el tipo enum
 la primera y no comentada es con la gramatica que explico, la segunda con 
 la antigua. Perdon por las molestias.
*/

#include <iostream>
using namespace std;

enum class Ordenado {ordenado_creciente, ordenado_decreciente, no_ordenado};

int main() {
	int numero1, numero2, numero3; 
	Ordenado tipo_orden;

	cout << "Introduce los 3 numeros separados por un espacio: ";
	cin >> numero1 >> numero2 >> numero3;

/*
Si no cumple ninguno de los siguientes condicionales tipo_orden permanece
tal y como se ha inicializado ya que los numeros no estaran ordenados.
*/
	tipo_orden = Ordenado::no_ordenado; 

	if (numero1 <= numero2 && numero2 <= numero3) 
		tipo_orden = Ordenado::ordenado_creciente;

		else if (numero1 >= numero2 && numero2 >= numero3)
			tipo_orden = Ordenado::ordenado_decreciente;
				else
					tipo_orden = Ordenado::no_ordenado;

	if (tipo_orden == Ordenado::ordenado_creciente)
		cout << "Los numeros estan ordenados de forma creciente" << endl;
			else if	(tipo_orden == Ordenado::ordenado_decreciente)
				cout << "Los numeros estan ordenados de forma decreciente" << endl;
				else if (tipo_orden == Ordenado::no_ordenado)
			 		cout << "Los numeros no estan ordenados" << endl;	
}




/*

#include <iostream>
using namespace std;

enum Ordenado {ordenado_creciente, ordenado_decreciente, no_ordenado};

int main() {
	int numero1, numero2, numero3; 
	Ordenado tipo_orden;

	cout << "Introduce los 3 numeros separados por un espacio: ";
	cin >> numero1 >> numero2 >> numero3;

	tipo_orden = no_ordenado; 

	if (numero1 <= numero2 && numero2 <= numero3) 
		tipo_orden = ordenado_creciente;
			else if (numero1 >= numero2 && numero2 >= numero3)
				tipo_orden = ordenado_decreciente;
					else
						tipo_orden = no_ordenado;

	if (tipo_orden == ordenado_creciente)
		cout << "Los numeros estan ordenados de forma creciente" << endl;
			else if	(tipo_orden == ordenado_decreciente)
				cout << "Los numeros estan ordenados de forma decreciente" << endl;
				else if (tipo_orden == no_ordenado)
			 		cout << "Los numeros no estan ordenados" << endl;	
}

*/