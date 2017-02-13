#include <iostream>
using namespace std; 

int Max2 (int n1, int n2){
	int max; 
	if (n1 >= n2) 
		max = n1; 
	else 
		max = n2;
	return max;
}

int main(){
	//debido a la sencillez del programa se usaran los siguientes nombres de variables como caso excepcional.
	int n1, n2, n3, maximo; 
	cout << "Introduce los 3 numeros separados por espacios: ";
	cin >> n1 >> n2 >> n3;

	maximo = Max2(Max2(n1,n2),n3);

	cout << "El maximo de los 3 numeros es: " << maximo << endl;

}