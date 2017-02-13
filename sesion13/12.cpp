#include <iostream>
#include <cmath>
using namespace std;

static const double PI = 3.1415;

struct Punto2D{
	double x;
	double y;
};

class PoligonoRegular{
private:
	int n_lados;
	double longitud; 
	Punto2D centro;
public:
	PoligonoRegular(){
		n_lados = 3;
		longitud = 1;
		centro.x = centro.y = 0;
	}
	PoligonoRegular(int lados, double longit){
		n_lados = lados;
		longitud = longit; 
	}
	PoligonoRegular(int lados, double longit, Punto2D punto_centro){
		n_lados = lados;
		longitud = longit;
		centro = punto_centro;
	}

	int GetLados(){
		return n_lados;
	}

	double RadioPoligono(){
		double radio;
		radio = longitud/(2 * sin(PI/n_lados));
		return radio;
	}
	double AreaPoligono(){
		double area;
		double radio;
		radio = RadioPoligono();

		area = ((n_lados/2) * pow(radio, 2) * sin(2*PI/n_lados));

		return area;
	}

	double LongitudLadosMultiplo(int k){
		double l;
		l = RadioPoligono() * sqrt(2 * (1 - cos(2 * PI / (k * n_lados))));
		return l;
	}

	bool PoligonoMayor(PoligonoRegular poligono){
		bool es_mayor;
		if(AreaPoligono() > poligono.AreaPoligono()){
			es_mayor = true;
		}
		else{
			es_mayor = false;
		}
		return es_mayor;
	}

	double DiferenciaAreaCirculo(){
		double diferencia;
		diferencia = (PI*pow(RadioPoligono(),2)) - AreaPoligono();
		if(diferencia < 0)
			diferencia = diferencia * -1;
		return diferencia;
	}

	PoligonoRegular PoligonoCircunscrito(int k){
		PoligonoRegular nuevo_poligono(k*n_lados, LongitudLadosMultiplo(k), centro);
		return nuevo_poligono;
	}

};

int main(){
	PoligonoRegular poligono1;
	PoligonoRegular poligono2(6, 4, {0,0});
	int contador_multiplo;
	
	if(poligono1.PoligonoMayor(poligono2))
		cout << "\nPoligono1 es mayor que Poligono2 :D \n";
	else
		cout <<"\nPoligono2 es mayor que Poligono1 :D \n";

	PoligonoRegular nuevo_poligono = poligono1.PoligonoCircunscrito(2);

	cout << "area del nuevo poligono: " << nuevo_poligono.AreaPoligono() << endl;

	//En el calculo del numero de lados se queda justo una iteracion atras, con una mas 
	//da el resultado correcto, no se por que ocurre esto :(
	contador_multiplo = 2; 
	while (nuevo_poligono.DiferenciaAreaCirculo() > 10.0e-5){
		nuevo_poligono = poligono1.PoligonoCircunscrito(contador_multiplo);
		contador_multiplo = contador_multiplo * 2; 
	}
	
	cout << "Numero de lados " << nuevo_poligono.GetLados() << endl;
	cout << "Area circulo: " << PI*pow(nuevo_poligono.RadioPoligono(),2) << endl;
	cout << "Area poligono: " << nuevo_poligono.AreaPoligono() << endl;
 };