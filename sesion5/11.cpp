#include <iostream>
using namespace std;

int main(){
	const double PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS	= 0.04,
				 PORC_SUBIDA_MEDIO_CASOS_RESUELTOS	= 0.03,
				 PORC_SUBIDA_SATISFACCION_USUARIOS	= 0.02;

	const double LIMITE_INFERIOR_MUCHOS_CASOS 			= 30,
				 LIMITE_INFERIOR_CASOS_RESUELTOS_MEDIO  = 20,
				 LIMITE_SUPERIOR_CASOS_RESUELTOS_MEDIO 	= 30,
				 LIMITE_INFERIOR_SATISFACCION_USUARIOS	= 4.0;

	int horas_trabajadas, casos_resueltos;
	double salario_hora, salario_final, porcentaje_incremento_salarial, salario_base,
	satisfaccion_media;

	cout << "Introduzca el salario por hora: ";
	cin >> salario_hora;

	cout << "Horas trabajadas: ";
	cin >> horas_trabajadas;

	cout << "Casos resueltos: ";
	cin >> casos_resueltos;

	cout << "Introduzca el grado medio de satisfacción: ";
	cin >> satisfaccion_media;
	/*
	forma de resolverlo sin repetir codigo
	if (casos_resueltos >= 30)
		aumento 4%
		else if (casos > 20)
			aumento 3%
	*/

	porcentaje_incremento_salarial = 0.0;

	if (casos_resueltos > LIMITE_INFERIOR_MUCHOS_CASOS)
		porcentaje_incremento_salarial = porcentaje_incremento_salarial 
										 +
										 PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS;

	if (casos_resueltos > LIMITE_INFERIOR_CASOS_RESUELTOS_MEDIO && 
		casos_resueltos < LIMITE_SUPERIOR_CASOS_RESUELTOS_MEDIO)
		porcentaje_incremento_salarial = porcentaje_incremento_salarial
										 +
										 PORC_SUBIDA_MEDIO_CASOS_RESUELTOS;

	if (satisfaccion_media >= LIMITE_INFERIOR_SATISFACCION_USUARIOS)
		porcentaje_incremento_salarial = porcentaje_incremento_salarial
										 +
										 PORC_SUBIDA_SATISFACCION_USUARIOS;

	salario_base = salario_hora * horas_trabajadas;
	salario_final = salario_base * (1 + porcentaje_incremento_salarial);

	cout << "El salario mensual es: " << salario_final << endl;

}