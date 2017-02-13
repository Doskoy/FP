#include <iostream>
using namespace std;

int main(){
	const double PI = 3.1416;
	double longitud, area, radio; 

	cout << "Introduzca el radio: ";
	cin >> radio;

	longitud = 2 * PI * radio; 
	area = PI * radio * radio; 

	cout << "longitud: " << longitud << "\narea: " << area << endl;

}