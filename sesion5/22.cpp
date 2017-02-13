#include <iostream>
#include <cmath> 
using namespace std; 

int main (){
	const double PI = 3.1416;
	int repeticion;
	double media, desviacion, x, gaussiana, minimo, maximo,
	incremento; 

	cout << "Introduzca el valor de la media: ";
	cin >> media; 

	do{
	cout << "Introduzca el valor de la desviacion tipica: "; 
	cin >> desviacion; 
	} while (desviacion < 0);

	cout << "Introduzca el valor minimo que tomara x: ";
	cin >> minimo; 

	do{
		cout << "Introduzca el valor maximo que tomara x: ";
		cin >> maximo;
		if (maximo < minimo) 
			cout << "Ha de ser mayor que el valor minimo" << endl;
	} while (maximo < minimo);

	do{
		cout << "Introduzca el incremento que se aplicara a x: ";
		cin >> incremento; 
		if (incremento <= 0) 
			cout << "El incremento ha de ser mayor que cero " << endl; 
	} while (incremento <= 0); 

	x = minimo; 
	repeticion = 0; 

	do{
		gaussiana = ((1 / ( desviacion * sqrt ( 2 * PI ) ) ) * exp (-0.5 * pow (( (x - media) / desviacion), 2)));
		cout << "El valor de la funcion gaussiana en " << x << " es: " << gaussiana << endl;

		repeticion++;
		x = minimo + incremento*repeticion; 
	}while (x <= maximo);

}