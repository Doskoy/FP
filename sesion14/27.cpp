#include <iostream>
using namespace std;

int main(){
	int util_filas;
	int util_columnas;
	int matriz[util_filas][util_columnas];
	int traspuesta[util_filas][util_columnas];

	cout << "Introduce el numero de filas: ";
	cin >> util_filas;

	cout << "Introduce el numero de columnas: ";
	cin >> util_columnas;

	for (int i = 0; i < util_filas; i++){
		for(int j = 0; j < util_columnas; j++){
			cin >> matriz[i][j];
			cout << "ñ" << matriz[0][0];
		}
	}

	for (int i = 0; i < util_filas; i++){
		for(int j = 0; j < util_columnas; j++){
			cout << "  " << matriz[i][j] << "  ";
		}
		cout << endl;
	}

	for (int i = 0; i < util_filas; i++){
		for(int j = 0; j < util_columnas; j++){
			traspuesta[i][j] = matriz[j][i];
		}
	}

	//for (int i = 0; i < util_filas; i++){
	//	for(int j = 0; j < util_columnas; j++){
	//		cout << "  " << traspuesta[i][j] << "  ";
	//	}
	//}

}