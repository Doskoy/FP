#include <iostream>
using namespace std;

class Recta{
private:
	double a;
	double b;
	double c;

public: 
	Recta(double n1, double n2, double n3){
		SetCoeficientes(n1, n2, n3);
	};

	void SetCoeficientes(double n1, double n2, double n3){
		a = n1;
		b = n2;
		c = n3;
	}

	void SetA(double n){
		a = n;
	}

	void SetB(double n){
		b = n;
	}	

	void SetC(double n){
		c = n;
	}

	double GetA(){
		return a;
	}

	double GetB(){
		return b;
	}

	double GetC(){
		return c;
	}
	//No debemos definir la pendiente como un dato miembro dado que es un valor 
	//que se calcula con un metodo.
	double PendienteRecta(){
		double pendiente; 
		pendiente = -a / b;
	return pendiente;
	}

	double CalculoAbscisa(double y){
		double x;
		x = (-c - (y * b)) / a; 
		return x;
	}

	double CalculoOrdenada(double x){
		double y;
		y = (-c - (x * a)) / b; 
		return y;
	}

};

int main(){

	double a1, b1, c1, a2, b2, c2;
	double x, y; 
	cout << endl << recta1.GetA() << endl;
	cout << "Introduce las coordenadas de la primera recta separadas por un espacio: ";
	cin >> a1 >> b1 >> c1;
	cout << "Introduce las coordenadas de la segunda recta separadas por un espacio: "; 
	cin >> a2 >> b2 >> c2; 
	
	Recta recta1(a1, b1, c1), recta2(a2, b2, c2);

	cout << "La pendiente de la primera recta es: " << recta1.PendienteRecta() << endl;
	cout << "La pendiente de la segunda recta es: " << recta2.PendienteRecta() << endl;

	cout << "Introduce valor de la abscisa (x) y de la ordenada (y) separados por un espacio: ";
	cin >> x >> y; 

	cout << "El valor calculado de la abscisa (x) es: " << recta1.CalculoAbscisa(y) << endl;
	cout << "El valor calculado de la ordenada (y) es: " << recta1.CalculoOrdenada(x) << endl;
}