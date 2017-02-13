#include <iostream>
using namespace std;

int main() {

	int dias, horas, minutos, segundos;

	cout << "Introduce las horas: ";
	cin >> horas;

	cout << "Introduce los minutos: "; 
	cin >> minutos;

	cout << "Introduce los segundos: ";
	cin >> segundos;

	minutos = minutos + (segundos / 60);
	segundos = segundos % 60;

	horas = horas + (minutos / 60);
	minutos = minutos % 60; 

	dias = horas / 24; 
	horas = horas % 24; 
	
	cout << endl << "Dias: " << dias << "\nHoras: " << horas << "\nMinutos: " << minutos << "\nSegundos: " << segundos << endl; 
}