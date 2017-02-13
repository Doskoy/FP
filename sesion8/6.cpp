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

long long Factorial (int n){
	long long fact = 1;

	for (int contador = 1; contador <= n; contador++){
			fact = fact * contador;
	}
	return fact;
}
/*
long long SumaFactoriales(int n){
	long long sumaFactoriales = 0;
	for (int contador = 1; contador <= n; contador++){
		sumaFactoriales = sumaFactoriales + Factorial(contador);
	}
	return sumaFactoriales;
}
*/

long long SumaFactoriales(int n){
	long long sumaFactoriales = 0, fact = 1;
	for (int contador = 0; contador <= n; contador++){
		fact = fact * contador;
		sumaFactoriales = sumaFactoriales + fact;
	}
	
	return sumaFactoriales;
}

int main() {
	int min = 1;
	int max = 20;
	int n = LeeIntRango(min, max);
	cout << "n ->>>> " << n << endl;
	cout << "n! = " << SumaFactoriales(n) << endl;
}
