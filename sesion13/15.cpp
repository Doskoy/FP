#include <cmath>  // NAN
#include <iostream>
using namespace std;

const double PI = 3.1415927;

class Punto2D{
private:
	double abscisa;
	double ordenada;
public:
	void SetAbscisa(double punto_abscisa){
		abscisa = punto_abscisa;
	}

	void SetOrdenada(double punto_ordenada){
		ordenada = punto_ordenada;
	}

	double GetAbscisa(){
		return abscisa;
	}

	double GetOrdenada(){
		return ordenada;
	}
};

/*
class SegmentoDirigido{
private:
	Punto2D origen;
	Punto2D final;

public:
	SegmentoDirigido(double origen_abscisa, double origen_ordenada,
					double final_abscisa, double final_ordenada)
		{
			origen.abscisa = origen_abscisa;
			origen.ordenada = origen_ordenada;
			final.abscisa = final_abscisa;
			final.ordenada = final.ordenada;
		}
	Punto2D Origen(){
		return origen;
	}
	Punto2D Final(){
		return final;
	}
	double Longitud(){
		double sumando_abscisa = origen.abscisa-final.abscisa;
		double sumando_ordenada = origen.ordenada-final.ordenada;

		return sqrt(sumando_abscisa * sumando_abscisa + 
					sumando_ordenada * sumando_ordenada);
	}
};
*/	
class Circunferencia{
private:
	Punto2D centro;
	double radio;
	
	bool EsCorrectoRadio(double long_radio){
	   return long_radio >= 0;
	}
public:
   
	Circunferencia(Punto2D centro_circunferencia, 
                  double longitud_radio)
   {
      if (EsCorrectoRadio(longitud_radio)){
         centro = centro_circunferencia;
         radio  = longitud_radio;
      }
	}
	
	double Longitud(){
		return 2*PI*radio;
	}
	
	double Area(){
		return PI*radio*radio;
	}
	
	bool Contiene(Punto2D un_punto){
		double diferencia_abscisas, diferencia_ordenadas;
		bool contiene;

		diferencia_abscisas = centro.GetAbscisa() - un_punto.GetAbscisa();
		diferencia_ordenadas = centro.GetOrdenada() - un_punto.GetOrdenada();

		contiene = diferencia_abscisas*diferencia_abscisas 
                 + 
                 diferencia_ordenadas*diferencia_ordenadas 
                 <= 
                 radio * radio; 
              
      return contiene;
	}

};

/*
// Ampliación:
//	En la siguiente versión se define PI como una constante estática de la clase Circunferencia.
//	El problema es que lo normal es que tengamos en este programa más clases relativas a 
// conceptos de Trigonometría y posiblemente también sea necesario acceder a PI desde dichas clases
// Por eso, en este ejemplo, es preferible definir PI como una constante global

// Un dato declarado como const en una clase declara un dato constante
//	en cada objeto, pero puede ser distinto entre objetos
// Para que sea la misma cte para todos los objetos, debemos declararla como static
// Las constantes enteras static se pueden incializar dentro de la clase
//	pero no las doubles!!! que deben asignarse fuera del class :-((

class Circunferencia{
private:
	Punto2D centro;
	double radio;
	static const double PI;
public:
	Circunferencia(Punto2D centro_circunferencia, double longitud_radio)
		: centro(centro_circunferencia),
		  radio(longitud_radio)
		{	
		}
	double Longitud(){
		return 2*PI*radio;
	}
	double Area(){
		return PI*radio*radio;
	}
};

const double Circunferencia::PI = 3.1416;
*/



int main(){
	Punto2D centro_circunf, punto;
	double radio;
	double longitud, area;
	bool esta_dentro;
	double longitud_segmento_radio;
	double abscisa, ordenada;

   cout << "Circunferencia\n\n";
   cout << "Introduzca las coordenadas del centro y la longitud del radio:\n";   
   cin >> abscisa;
   cin >> ordenada;
   cin >> radio;

   centro_circunf.SetAbscisa(abscisa);
   centro_circunf.SetOrdenada(ordenada);

   /*
   cout << "\nIntroduzca las coordenadas de otro punto:\n";
   cin >> abscisa;
   cin >> ordenada;
   	
   	punto.SetAbscisa(abscisa);
   	punto.SetOrdenada(ordenada);
	*/

	Circunferencia circunf(centro_circunf, radio);
	
	longitud    = circunf.Longitud();
	area        = circunf.Area();	

   cout << "\n\nLongitud: 				" << longitud;
   cout << "\nÁrea:       				" << area;   
	
}

