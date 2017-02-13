#include <iostream> 
using namespace std; 

int main() {
	int x, y, z, cambio; 

	cout << "Introduce el valor de x: ";
	cin >> x;

	cout << "Introduce el valor de y: ";
	cin >> y;

	cout << "Introduce el valor de z: ";
	cin >> z; 
	
	cambio = y;
	y = x; 
	x = z; 
	z = cambio;

	cout << "Nuevo valor de: "<< endl << "x -> " << x << "\ny -> " << y << "\nz -> " << z << endl; 
 
}