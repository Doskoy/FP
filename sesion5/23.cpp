#include <iostream>
using namespace std;

int main (){
	long long poblacion_inicial, doble_poblacion, calculo_doble_poblacion, poblacion_final, diferencia_poblacion;
	int repeticion, tasa_natalidad, tasa_mortalidad, tasa_migracion, numero_de_anios, numeros_de_anios_necesarios_doblar;
	double indice_variacion_tasa_global;
	do{
		cout << "Introduzca la poblacion inicial: "; 
		cin >> poblacion_inicial;
		if (poblacion_inicial <= 0)
			cout << "introduce un entero positivo mayor que 0" << endl; 
 	} while (poblacion_inicial <= 0); 
	
	do{
		cout << "Introduzca la tasa de natalidad: "; 
		cin >> tasa_natalidad;
		if (tasa_natalidad < 0 || tasa_natalidad > 1000)
			cout << "Introduce un entero positivo menor que 1000 " << endl; 
	} while (tasa_natalidad < 0 || tasa_natalidad > 1000);
	
	do{
		cout << "Introduzca la tasa de mortalidad: ";
		cin >> tasa_mortalidad;
		if (tasa_mortalidad < 0 || tasa_natalidad > 1000)
			cout << "Introduce un entero positivo menor que 1000 " << endl;
	} while (tasa_mortalidad < 0 || tasa_natalidad > 1000);

	do{
		cout << "Introduzca la tasa de migracion: "; 
		cin >> tasa_migracion;
		if (tasa_migracion < 0 || tasa_migracion > 1000)
			cout << "Introduce un entero positivo menor que 1000 " << endl;	
	} while (tasa_migracion < 0 || tasa_migracion > 1000);
	
	do{
		cout << "Introduzca el numero de años: ";
		cin >> numero_de_anios;
		if (numero_de_anios <= 0)
			cout << "Introduce un entero positivo " << endl;
	} while (numero_de_anios <= 0);

	diferencia_poblacion = tasa_natalidad - tasa_mortalidad + tasa_migracion;
	indice_variacion_tasa_global = 1 + diferencia_poblacion / 1000.0;

	poblacion_final = poblacion_inicial;
	repeticion = 1;
	doble_poblacion = poblacion_inicial * 2; 

	while (repeticion <= numero_de_anios){
		poblacion_final = poblacion_final * indice_variacion_tasa_global;
		repeticion++; 
	}

	cout << "La estimacion de poblacion dentro de " << numero_de_anios << " años es de: " << poblacion_final << endl; 

	numeros_de_anios_necesarios_doblar = 0;
	calculo_doble_poblacion = poblacion_inicial;
	do{
		calculo_doble_poblacion = calculo_doble_poblacion * indice_variacion_tasa_global;
		numeros_de_anios_necesarios_doblar++;
	} while (calculo_doble_poblacion <= doble_poblacion);
	
	cout << "Numero de años necesarios para doblar la poblacion inicial: " << numeros_de_anios_necesarios_doblar << endl;
	cout << "Poblacion transcurridos " << numeros_de_anios_necesarios_doblar << "años: " << calculo_doble_poblacion << endl;
	
}