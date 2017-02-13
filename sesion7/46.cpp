#include <iostream> 
using namespace std;

int main(){
// 	Debido a la sencillez del problema se usaran los siguientes nombres de variables.
	int n, contador_factorial_inter, contador_factorial_ext; 
	long long factorial, suma_factoriales; 

	cout << "Introduzca el valor de n: ";
	cin >> n;

	suma_factoriales = 0;
	for(contador_factorial_ext = 1; contador_factorial_ext <= n; contador_factorial_ext++){
		factorial = 1;
		for (contador_factorial_inter = 1; contador_factorial_inter <= contador_factorial_ext; contador_factorial_inter++){
			factorial = factorial * contador_factorial_inter;
		}
		
		suma_factoriales = suma_factoriales + factorial;
	}
	
	cout << "n! = " << suma_factoriales << endl; 

}

