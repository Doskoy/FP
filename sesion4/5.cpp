#include <iostream>
using namespace std;

int main(){
	int horas_trabajadas, casos_resueltos, satisfaccion_media;
	double salario_hora, salario_final;

	cout << "Introduzca el salario por hora: ";
	cin >> salario_hora;

	cout << "Horas trabajadas: ";
	cin >> horas_trabajadas;

	cout << "Casos resueltos: ";
	cin >> casos_resueltos;

	cout << "Introduzca el grado medio de satisfacción: ";
	cin >> 

	if (casos_resueltos > 30){
		salario_final = salario_hora * 1.04;
		}
		else {
			cout << "El trabajador no reune las condiciones necesarias para obtener un aumento de salario" << endl;
			salario_final = salario_hora;	
		}

	cout << "El salario mensual es: " << salario_final * horas_trabajadas << endl;

}