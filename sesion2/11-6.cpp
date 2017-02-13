#include <iostream>
using namespace std;

int main(){
	int segundos_inicio, minutos_inicio, horas_inicio; //Variables que contendran la hora inicial.
	int segundos_final, minutos_final, horas_final; //Variables que contendran la hora final.
	int diferencia_segundos;

	// Declaracion de la hora desde la cual empezar a contar.
	cout << "Introduzca la hora inicial: ";
	cin >> horas_inicio;
	cout << "introduzca los minutos iniciales: ";
	cin >> minutos_inicio;
	cout << "Introduzca los segundos iniciales: "; 
	cin >> segundos_inicio;

	// Declaracion de la hora final
	cout << "\n \nIntroduzca la hora final: ";
	cin >> horas_final;
	cout << "Introduzca los minutos finales: ";
	cin >> minutos_final;
	cout << "Introduzca los segundos finales: ";
	cin >> segundos_final;

	// Se calcula la diferencia de segundos obteniendo la diferencia entre las horas y los minutos finales e iniciales
	// y multiplicando esto por el numero de segundos que en una hora y en un minuto respectivamente.

	diferencia_segundos = ((horas_final - horas_inicio) * 3600) + ((minutos_final - minutos_inicio) * 60) + (segundos_final - segundos_inicio);
	cout << "El numero de segundos entre los dos instantes de tiempo es de: " << diferencia_segundos; 
}