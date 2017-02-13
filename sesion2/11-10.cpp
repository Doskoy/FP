#include <iostream>
#include <cmath> 
using namespace std; 

int main (){
	const double PI = 3.1416;
	double media, desviacion, x, gaussiana; 
	cout << "Introduzca el valor de la desviacion tipica: "; 
	cin >> desviacion; 
	cout << "Introduzca el valor de la media: ";
	cin >> media; 
	cout << "Introduzca el valor de x: ";
	cin >> x; 
	
	gaussiana = ((1 / ( desviacion * sqrt ( 2 * PI ) ) ) * exp (-0.5 * pow (( (x - media) / desviacion), 2)));

	cout << "El valor de la funcion gaussiana en " << x << " es: " << gaussiana << endl; 

}