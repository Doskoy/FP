//Fernando Roldán Zafra
//El programa produce un error logico pero no consigo encontrar cual es el origen de este :( 

#include <iostream> 
using namespace std;

int main(){
	const int TERMINADOR = -1;
	double salario, satisfaccion_media, satisfaccion_empleado1, satisfaccion_empleado2, satisfaccion_empleado3 = 0;	
	double mejor_satisfaccion;
	int empleado, numero_casos_total, numero_casos_empleado1, numero_casos_empleado2, numero_casos_empleado3, duracion_llamada, n_resuelto;
	int mejor_empleado;
	bool resuelto;

	cout << "Salario/horas: ";
	cin >> salario; 

	cout << "nro empleado: ";
	cin >> empleado;

	numero_casos_total, numero_casos_empleado1, numero_casos_empleado2, numero_casos_empleado3 = 0;
	satisfaccion_media, satisfaccion_empleado1, satisfaccion_empleado2, satisfaccion_empleado3 = 0;

	while (empleado != TERMINADOR){
		while (empleado < 1 && empleado > 3 && empleado != TERMINADOR){
			cout << "nro incorrecto";
			cin >> empleado;

		}

		cout << "segundos llamada: ";
		cin >> duracion_llamada;

		do{
			cout << "caso resuelto s/n: ";
			cin >> n_resuelto;
		} while(n_resuelto != 0 && n_resuelto != 1);

		if (n_resuelto == 1)
			resuelto = true;
			else if (n_resuelto == 0)
				resuelto = false;

		do{
			cout << "grado satisfaccion media: ";
			cin >> satisfaccion_media;
		} while (satisfaccion_media < 0 || satisfaccion_media > 5);

		if (empleado == 1){
			satisfaccion_empleado1 = satisfaccion_empleado1 + satisfaccion_media;
			numero_casos_empleado1++;
		}	else if (empleado == 2){
				satisfaccion_empleado2 = satisfaccion_empleado2 + satisfaccion_media;
				numero_casos_empleado2++;
			}	else {
					satisfaccion_empleado3 = satisfaccion_empleado3 + satisfaccion_media;
					numero_casos_empleado3++;
				}
		numero_casos_total++;
		cout << "nro empleado: ";
		cin >> empleado;
	}
	satisfaccion_empleado1 = satisfaccion_empleado1 / numero_casos_empleado1;
	satisfaccion_empleado2 = satisfaccion_empleado2 / numero_casos_empleado2;
	satisfaccion_empleado3 = satisfaccion_empleado3 / numero_casos_empleado3;
	
	if (satisfaccion_empleado1 >= satisfaccion_empleado2){
		mejor_satisfaccion = satisfaccion_empleado1;
		mejor_empleado = 1;
	}
	else{
		mejor_satisfaccion = satisfaccion_empleado2;
		mejor_empleado = 2;
	}

	if (satisfaccion_empleado3 > mejor_satisfaccion){
		mejor_satisfaccion = satisfaccion_empleado3;
		mejor_empleado = 3;
	}

	cout << numero_casos_total << " " << mejor_empleado << " " << mejor_satisfaccion << endl;

}