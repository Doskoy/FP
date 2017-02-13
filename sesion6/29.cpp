#include <iostream>
using namespace std;

int main(){
	const int TERMINADOR = -1;
	int longitud, max_longitud, posicion_principio, posicion_actual, posicion_principio_max;
	double actual, anterior;

	cout << "-----------Maximo temperaturas-----------" << endl;
	cin >> actual;

	posicion_principio = 1;
	max_longitud = 1;
	longitud = 1;
	posicion_principio_max = posicion_principio;

	anterior = actual;
	cin >> actual;
	posicion_actual++;
	
	while(actual != TERMINADOR){
		if (anterior < actual)
			longitud = longitud + 1;
			else{
				longitud = 1; 
				posicion_principio = posicion_actual;
			}

		if (longitud > max_longitud){
			max_longitud = longitud;
			posicion_principio_max = posicion_actual;
		}

		anterior = actual;
		cin >> actual;
		posicion_actual++;
	}
	cout << posicion_principio_max << " " << max_longitud << endl;
}