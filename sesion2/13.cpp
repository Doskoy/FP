#include <iostream> 
using namespace std;

int main() {
	int numero_inicio;
	int centena, decena, unidades;

	cout << "Introduce un numero entero de 3 cifras: ";
	cin >> numero_inicio;

	centena = numero_inicio / 100; 
	decena = (numero_inicio % 100) / 10; 
	unidades = ((numero_inicio % 100) % 10);

	cout << "El numero separado es: " << centena << "  " << decena << "  " << unidades;
}