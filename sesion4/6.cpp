#include <iostream>
using namespace std;

int main(){
	int horas_trabajadas, casos_resueltos, satisfaccion_media;
	double salario_hora, salario_final, aumento_4, aumento_2;

	cout << "Introduzca el salario por hora: ";
	cin >> salario_hora;

	cout << "Horas trabajadas: ";
	cin >> horas_trabajadas;

	cout << "Casos resueltos: ";
	cin >> casos_resueltos;

	cout << "Introduzca el grado medio de satisfacción: ";
	cin >> satisfaccion_media;

	aumento_4 = salario_hora * 0.04;
	aumento_2 = salario_hora * 0.02;

	if (casos_resueltos > 30 && satisfaccion_media >= 4)
		salario_final = salario_hora + aumento_4 + aumento_2;
		else 
			if (casos_resueltos > 30)
			salario_final = salario_hora + aumento_4;
				else 
					if (satisfaccion_media >= 4)
					salario_final = salario_hora + aumento_2; 
						else 
							salario_final = salario_hora;

	cout << "El salario mensual es: " << salario_final * horas_trabajadas << endl;

}