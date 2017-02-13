#include <iostream>
using namespace std;

int main (){
	long int poblacion_inicial, poblacion_final, diferencia_poblacion;
	int tasa_natalidad, tasa_mortalidad, tasa_migracion;

	cout << "Introduzca la poblacion inicial: "; 
	cin >> poblacion_inicial;

	cout << "Introduzca la tasa de natalidad: "; 
	cin >> tasa_natalidad;

	cout << "Introduzca la tasa de mortalidad: ";
	cin >> tasa_mortalidad;

	cout << "Introduzca la tasa de migracion: "; 
	cin >> tasa_migracion;

	diferencia_poblacion = tasa_natalidad - tasa_mortalidad + tasa_migracion;

	poblacion_final = poblacion_inicial + (diferencia_poblacion * poblacion_inicial / 1000);

	poblacion_final = poblacion_final + (diferencia_poblacion * poblacion_final / 1000);

	poblacion_final = poblacion_final + (diferencia_poblacion * poblacion_final / 1000);

	cout << "La estimacion de poblacion dentro de 3 años es de: " << poblacion_final << endl; 
}