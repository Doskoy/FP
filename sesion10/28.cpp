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

class Poblacion{
private:
	long long poblacion_inicial;
	int tasa_natalidad;
	int tasa_mortalidad;
	int tasa_migracion;

public:
	double indice_variacion_tasa_global;

	double diferencia_poblacion = tasa_natalidad - tasa_mortalidad + tasa_migracion;
	double indice_variacion_tasa_global = 1 + diferencia_poblacion / 1000.0;

	void SetPoblacionIni(long long poblacion){
		poblacion = poblacion_inicial;
	}

	void SetTasaNatalidad(int natalidad){
		tasa_natalidad = natalidad;
	}

	void SetTasaMortalidad(int mortalidad){
		tasa_mortalidad = mortalidad;
	}

	void SetTasaMigracion(int migracion){
		tasa_migracion = migracion;
	}

	long long AniosMultiplicarPoblacion (int multiplicador){
		long long poblacion_multiplicada = poblacion_inicial * multiplicador;
		long long calculo_poblacion = poblacion_inicial;
		int anios_necesarios_multiplicar_poblacion = 0;

		for(anios_necesarios_multiplicar_poblacion; calculo_poblacion <= poblacion_multiplicada; anios_necesarios_multiplicar_poblacion++){
			calculo_poblacion = calculo_poblacion * indice_variacion_tasa_global;
		}
	return calculo_poblacion

	}

	long long PoblacionFutura (int anios){
		long long poblacion_final = poblacion_inicial;
		poblacion_final = poblacion_inicial;
		for (int contador = 1; contador <= anios; contador++)
			poblacion_final = poblacion_final * indice_variacion_tasa_global;
	
	return poblacion_final;
	}
};

int main (){
	long long poblacion_inicial, doble_poblacion, diferencia_poblacion, poblacion_futura;
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

	Poblacion poblacion;
	poblacion.SetPoblacionIni(poblacion_inicial);
	poblacion.SetTasaNatalidad(tasa_natalidad);
	poblacion.SetTasaMortalidad(tasa_mortalidad);
	poblacion.SetTasaMigracion(tasa_migracion);
	poblacion_futura = poblacion.PoblacionFutura(numero_de_anios)

	cout << "La estimacion de poblacion dentro de " << numero_de_anios << " años es de: " << PoblacionFutura(numero_de_anios, poblacion_inicial, indice_variacion_tasa_global) << endl; 

}