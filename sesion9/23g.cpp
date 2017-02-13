#include <iostream>
using namespace std;

class Recta{
private:
	double a;
	double b;
	double c;

	bool DatosCorrectos(double n1, double n2){
		if (n1 == 0 && n2 == 0)
			return false;
		else 
			return true;
	}

public: 
	Recta(double n1, double n2, double n3){
		SetCoeficientes(n1, n2, n3);
	};

	bool SetCoeficientes(double n1, double n2, double n3){
		if (DatosCorrectos(n1, n2)){
			a = n1;
			b = n2;
			c = n3;
			return false;
		}
		else
		return true;

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
	//Tambien se podria utilizar el constructor por defecto lo cual inicializaria todos los
	//datos miembro a 0: 
	/*
	Recta recta1(), recta2();
	*/
	Recta recta1(0, 0, 0), recta2(0, 0, 0);
	double a1, b1, c1, a2, b2, c2;
	double x, y; 
	bool datosNulos1, datosNulos2;
	do{
	cout << "Introduce las coordenadas de la primera recta separadas por un espacio: ";
	cin >> a1 >> b1 >> c1;
	cout << "Introduce las coordenadas de la segunda recta separadas por un espacio: "; 
	cin >> a2 >> b2 >> c2; 

	datosNulos1 = recta1.SetCoeficientes(a1, b1, c1);
	datosNulos2 = recta2.SetCoeficientes(a2, b2, c2);
	} while (datosNulos1 == true || datosNulos2 == true);
	/*
	recta1.SetA(a1);
	recta1.SetB(b1);
	recta1.SetC(c1);
	recta2.SetA(a2);
	recta2.SetB(b2);
	recta2.SetC(c2);
	*/

	cout << "La pendiente de la primera recta es: " << recta1.PendienteRecta() << endl;
	cout << "La pendiente de la segunda recta es: " << recta2.PendienteRecta() << endl;

	cout << "Introduce valor de la abscisa (x) y de la ordenada (y) separados por un espacio: ";
	cin >> x >> y; 

	cout << "El valor calculado de la abscisa (x) es: " << recta1.CalculoAbscisa(y) << endl;
	cout << "El valor calculado de la ordenada (y) es: " << recta1.CalculoOrdenada(x) << endl;
}