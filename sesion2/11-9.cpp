#include <iostream>
using namespace std; 

int main(){
	double salario_base;
	double salario_final; 

	cout << "Introduzca el salario base: ";
	cin >> salario_base;

	salario_final = salario_base * 1.02;

	cout << "Salario con un incremento de 2%: " << salario_final;

	salario_final = salario_final * 1.03;
	cout << "\nSalario con un incremento del 3% aplicado al 2% anterior: " << salario_final << endl; 
}