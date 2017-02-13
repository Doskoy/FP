#include <iostream> 
using namespace std;

long long potencia (int x, int n){
	int contador_potencia;
	long long ptencia;
	ptencia = x;
	for (contador_potencia = 1; contador_potencia < n; contador_potencia++){
		ptencia = ptencia * x;
	}
	return ptencia;
}

long long factorial (int n){
	long long fact = 1;
	int contador_factorial;

	for (contador_factorial = 2; contador_factorial <= n; contador_factorial++){
		fact = fact * contador_factorial; 
	}
	return fact; 
}

int main(){
// 	Debido a la sencillez del problema se usaran los siguientes nombres de variables.
	double x;
	int n;

	cout << "Introduzca el valor de x: ";
	cin >> x;

	do{
	cout << "Introduzca el valor de n: [1-20]"; 
	cin >> n;
	}while (n < 1 || n > 20);
	
	cout << x << " ^ " << n << ": " << potencia(x , n) << endl;

	cout << "n! = " << factorial(n) << endl;

}