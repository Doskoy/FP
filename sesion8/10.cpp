#include <iostream>
using namespace std;

int LeeIntRango(int min, int max){
	int n;
	do{
		cout << "Introduce un numero en el rango " << "[" << min << "-" << max << "]: "; 
		cin >> n;
	}while (n < min || n > max);
	return n; 
}

int LeeIntMayorIgualQue(int x){
	int n;
	do{
		cout << "Introduce un numero mayor o igual que " << x << ": " ;
		cin >> n;
	}while(n < x);
	return n;
}

long long PoblacionFutura (int anios, long long poblacion_inicial, double indice_variacion_tasa_global){
	long long poblacion_final = poblacion_inicial;
	poblacion_final = poblacion_inicial;
	for (int contador = 1; contador <= anios; contador++ )
		poblacion_final = poblacion_final * indice_variacion_tasa_global;
	
	return poblacion_final;

}

int AniosMultiplicarPoblacion (int multiplicador, long long poblacion_inicial, double indice_variacion_tasa_global){
	
	long long poblacion_multiplicada = poblacion_inicial * multiplicador;
	long long calculo_poblacion = poblacion_inicial;
	int anios_necesarios_multiplicar_poblacion = 0;

	for(anios_necesarios_multiplicar_poblacion; calculo_poblacion <= poblacion_multiplicada; anios_necesarios_multiplicar_poblacion++){
		calculo_poblacion = calculo_poblacion * indice_variacion_tasa_global;
	}
}

int main (){
	long long poblacion_inicial, doble_poblacion, diferencia_poblacion;
	int tasa_natalidad, tasa_mortalidad, tasa_migracion, numero_de_anios;
	double indice_variacion_tasa_global;

	cout << "Poblacion inicial" << endl;
	poblacion_inicial = LeeIntMayorIgualQue(1);
	
	cout << "Tasa de natalidad" << endl;
	tasa_natalidad = LeeIntRango(0, 1000);
		
	cout << "Tasa de mortalidad" << endl;
	tasa_mortalidad = LeeIntRango(0, 1000);

	cout << "Tasa de migracion" << endl;
	tasa_migracion = LeeIntRango(0, 1000);

	cout << "Numero de años a calcular" << endl;
	numero_de_anios = LeeIntMayorIgualQue(1);


	diferencia_poblacion = tasa_natalidad - tasa_mortalidad + tasa_migracion;
	indice_variacion_tasa_global = 1 + diferencia_poblacion / 1000.0;
	doble_poblacion = poblacion_inicial * 2; 

	cout << "La estimacion de poblacion dentro de " << numero_de_anios << " años es de: " << PoblacionFutura(numero_de_anios, poblacion_inicial, indice_variacion_tasa_global) << endl; 

	cout << "Numero de años necesarios para doblar la poblacion inicial: " << AniosMultiplicarPoblacion(2, poblacion_inicial, indice_variacion_tasa_global) << endl;	
}