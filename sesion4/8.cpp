#include <iostream>
using namespace std;

int main() {
	int anio;
	bool bisiesto = false;

	cout << "Introduzca un anio: ";
	cin >> anio;

	if (anio % 4 == 0 && anio % 100 != 0)
		bisiesto = true;
		else
			if (anio % 400 == 0)
				bisiesto = true;

	if (bisiesto == true)
		cout << "El anio es bisiesto" << endl; 
		else 
			cout << "el anio no es bisiesto" << endl;
				
}