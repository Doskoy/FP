//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pol�gono

/*
Un pol�gono regular de n caras tiene n lados de
la misma longitud y todos los �ngulos interiores son iguales. Su centro geom�trico es
el centro de la circunferencia circunscrita (la que lo envuelve). Supondremos que dos
pol�gonos son distintos si se diferencian o bien en sus centros geom�tricos, o bien en
el n�mero de lados o bien en la longitud de cualquiera de ellos. As� pues, por ejemplo,
no tendremos en cuenta las distintas posiciones en el plano que se podr�an obtener
girando el pol�gono sobre su centro.

Si llamamos n al n�mero de lados y l la longitud de cualquiera de ellos, tenemos que:
� la longitud r del radio de la circunferencia circunscrita viene definida por
r = l/(2sin(pi/n))
� El �rea del pol�gono es A = (n/2) � r^2 sin(2 pi/n)
� Si queremos construir un pol�gono inscrito en la misma circunferencia, pero mul-
tiplicando por un entero k el n�mero de lados, la longitud de cada uno de los kn
lados viene dada por
l'= r sqrt{ 2(1 - cos(2 pi/(kn))) }.
Se quiere dise�ar la clase PoligonoRegular para poder representar este tipo de
pol�gonos y realizar las siguientes tareas:
� Calcular el per�metro del pol�gono.
� Calcular el �rea del pol�gono.
� Calcular la diferencia entre el �rea del pol�gono y la del c�rculo correspondiente a
la circunferencia circunscrita.
� Comprobar si un pol�gono es m�s grande que otro (considerando al �rea de cada
uno)
� Construir un nuevo pol�gono que tenga la misma circunferencia circunscrita y con
un n�mero de lados que sea m�ltiplo del n�mero de lados del pol�gono.

Debe tener los siguientes constructores:
� Un constructor sin par�metros en el que los valores a asignar por defecto sean:
3 para el n�mero de lados (tri�ngulo), 1 para la longitud y (0,0) para las coorde-
nadas del centro.
� Un constructor que cree un pol�gono regular con una longitud y n�mero de lados
concretos y deje como centro el valor por defecto (0,0).

� Un constructor que cree un pol�gono regular con una longitud, n�mero de lados
y centro concretos.
Defina un programa que realice lo siguiente:
� Cree dos pol�gonos, poligono1 con los valores por defecto y poligono2 con 6
lados de longitud 4 y centrado en (0,0). El programa comprobar� si poligono1
es m�s grande que poligono2 .
� Construya un nuevo pol�gono a partir de poligono1 , con la misma circunferen-
cia circunscrita y con el doble n�mero de lados. El programa imprimir� en pantalla
el �rea del nuevo pol�gono.
� Repita el proceso anterior generando pol�gonos con el doble n�mero de lados
en cada iteraci�n, hasta que el pol�gono generado tenga un �rea similar a la
del c�rculo delimitado por la circunferencia circunscrita. Consideraremos que las
�reas son similares si no se diferencian en m�s de 10^(-5).
El programa mostrar� el n�mero de lados del pol�gono que aproxima a la circun-
ferencia (el resultado con poligono1 es 1536 lados)
*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.1415927;  // Cte global por si la necesitamos en otras clases

bool SonIguales(double uno, double otro)
{
	return (abs(uno-otro) <= 1e-5);
}


/////////////////////////////////////////////////////////////////////////
class Punto2D{
private:
   double abscisa  = NAN;
   double ordenada = NAN;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto)
   {
      SetCoordenadas(abscisaPunto, ordenadaPunto);
   }
   
   double Abscisa(){
      return abscisa;
   }
   
   double Ordenada(){
      return ordenada;
   }
   
   void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
      abscisa = abscisaPunto;
      ordenada = ordenadaPunto;
   }
   
   bool EsIgual_a (Punto2D otro_punto){
      return (SonIguales(abscisa, otro_punto.abscisa)
              &&
              SonIguales(ordenada, otro_punto.ordenada));
   }
   
   string ToString(){
		return "(" + to_string(abscisa) + " , " + to_string(ordenada) + ")";
	}
};


   /*
   Supongamos los siguientes casos:

   1. Hemos a�adido un constructor sin par�metros a la clase Punto2D

      class Punto2D{
      private:
         double abscisa;
         double ordenada;
      public:
         Punto2D(){
            SetCoordenadas(0.0, 0.0);
         }
         Punto2D(double abscisaPunto, double ordenadaPunto){
            SetCoordenadas(abscisaPunto, ordenadaPunto);
         }

      En este caso, al centro del pol�gono le podemos asignar
      un valor concreto (un objeto punto) FUERA de la lista
      de inicializaci�n del constructor (pero dentro
      del constructor):

      PoligonoRegular() {
         Punto2D centro_defecto(0.0, 0.0);
         centro = centro_defecto;            // Correcto siempre que Punto2D tenga un constructor sin par�metros
      }

      En cualquier caso, C++ recomienda inicializar SIEMPRE los objetos
      en la lista de inicializaci�n del constructor.
      En el siguiente punto se ve c�mo hacerlo.

   2. NO Hemos definido ning�n constructor sin par�metros en la clase Punto2D

      class Punto2D{
      private:
         double abscisa  = NAN;
         double ordenada = NAN;
      public:
         Punto2D(double abscisaPunto, double ordenadaPunto){
            SetCoordenadas(abscisaPunto, ordenadaPunto);
         }

      En este caso, para asignar un centro por defecto, lo podemos hacer
      de dos formas:

      2.a) En la declaraci�n del objeto dato miembro, inicializamos
            sus datos miembros entre llaves (C++ 11).
            Los otros datos miembros se inicializan como siempre.

            class PoligonoRegular{
            private:
            	Punto2D centro    = {0.0, 0.0};
            	int 	  num_lados = 3;
            	double  longitud  = 1;

            Hacemos uso de la caracter�stica de C++11 de que
            los constructores pueden llamarse entre s�:

               PoligonoRegular()
            	{ }

            	PoligonoRegular (int num_lados_poligono, double longitud_lado_poligono)
            	{
                  if (EsCorrecto(num_lados_poligono, longitud_lado_poligono)) {
                     num_lados = num_lados_poligono;
                     longitud = longitud_lado_poligono;
                  }
               }

               PoligonoRegular (Punto2D centro_poligono,
                    int num_lados_poligono,
                    double longitud_lado_poligono
                    )
            		:PoligonoRegular (num_lados_poligono, longitud_lado_poligono)
            	{
            	   centro = centro_poligono;   // Lo puedo asignar as� porque
                                              // se construy� en la declaraci�n:
                                              // Punto2D centro    = {0.0, 0.0};
               }


      2.b) Lo hacemos en la lista de inicializaci�n del constructor.
            Para ello, se crea un objeto Punto2D sin nombre, usando
            directamente el nombre de la clase y entre par�ntesis
            los par�metros:

            PoligonoRegular (int num_lados_poligono,
                             double longitud_lado_poligono
                             )
         		:centro (Punto2D(0.0, 0.0)),        //  <- Creaci�n de un objeto sin nombre
         		 num_lados(num_lados_poligono),
                longitud(longitud_lado_poligono)
         	{ }

	        Seguimos esta aproximaci�n.

	        Nos quedar�a lo siguiente:

            PoligonoRegular (Punto2D centro_poligono,
                             int num_lados_poligono,
                             double longitud_lado_poligono
                             )
         		:centro (centro_poligono),
         		 num_lados(num_lados_poligono),
                longitud(longitud_lado_poligono)
         	{ }

         	PoligonoRegular (int num_lados_poligono, double longitud_lado_poligono)
         		:centro (Punto2D(0.0,0.0)),
         		 num_lados(num_lados_poligono),
                longitud(longitud_lado_poligono)
         	{
            }

         	PoligonoRegular()
               :centro (Punto2D(0.0,0.0)),
                num_lados(3),
                longitud(1)
         	{
            }
   */

   /*
   Se puede apreciar que se repite algo de c�digo en la versi�n anterior.
   Por ejemplo, el valor concreto (0.0, 0.0) aparece dos veces,
   as� como la asignaci�n de los lados y la longitud.
   Para resolverlo, hacemos uso de la nueva caracter�stica de C++11
   que permite que un constructor pueda llamar a otro.

   Al igual que us�bamos un objeto sin nombre para asignarlo al centro,
   lo podemos usar tambi�n en la llamada de un constructor a otro:

      : PoligonoRegular ( Punto2D(0.0,0.0) , ......
   */


class PoligonoRegular{
private:
   /*
   Como datos miembro �nicamente incluiremos los indispensables.
   As� pues, por ejemplo, la longitud, el per�metro y el �rea no ser�n datos miembro
   ya que se pueden obtener a partir del centro, num_lados y longitud.
   */
   
	Punto2D centro;       // Centro de la circunferencia circunscrita que envuelve al pol�gono.
	int 	  num_lados ;   // N�mero de lados del pol�gono
	double  longitud  ;   // Longitud de cada lado
	
	//////////////////////////////////////////////////////////////////
   // Devuelve la longitud del lado del nuevo poligono resultado de 
	// multiplicar por factor_multiplicativo el n�mero de lados. 
	double NuevaLongitudLado (int factor_multiplicativo){
		int nuevo_numero_lados;
		
		nuevo_numero_lados = factor_multiplicativo * num_lados;

		return Radio() * sqrt(2 * (1 - cos(2*PI / nuevo_numero_lados)));
	}
	
	bool EsCorrecto(int num_lados, double longitud){
	  return 0 < num_lados && 0 < longitud; 
   }

public:
   PoligonoRegular (Punto2D centro_poligono,
                    int num_lados_poligono,
                    double longitud_lado_poligono
                    )
		:centro (centro_poligono)
	{
      if (EsCorrecto(num_lados_poligono, longitud_lado_poligono))
         num_lados = num_lados_poligono;
         longitud = longitud_lado_poligono;
   }


	// Este constructor llama al anterior (el de los 3 par�metros)
	PoligonoRegular (int num_lados_poligono, double longitud_lado_poligono)
		: PoligonoRegular (Punto2D(0.0,0.0), num_lados_poligono, longitud_lado_poligono)
	{ }

	// Este constructor llama al anterior (el de los 2 par�metros)
	PoligonoRegular()
      :PoligonoRegular (3 , 1)
	{ }

	Punto2D Centro(){
		return centro;	
	}

	double Longitud(){
		return longitud;	
	}
	
	int NumLados(){
		return num_lados;	
	}
	
	double Radio(){
		return longitud / (2.0 * sin(PI / num_lados));	
	}

	double Perimetro(){
		return longitud * num_lados;	
	}
	
	double Area(){
		double radio;
      
      radio = Radio();
		return 0.5 * num_lados * radio * radio * sin(2*PI / num_lados);					
	}

	bool EsMayorQue(PoligonoRegular otro){
		return Area() > otro.Area();
	}
	
	// Develve un nuevo pol�gono, inscrito en la misma circunferencia, 
	// pero multiplicando por un entero factor_multiplicativo el n�mero de lados.
   // El radio sigue siendo el mismo 
	// porque el nuevo pol�gono est� inscrito en la misma circunferencia. 
	
	PoligonoRegular Multiplica (int factor_multiplicativo){
		PoligonoRegular nuevo (centro,
                             num_lados * factor_multiplicativo, 
                             NuevaLongitudLado(factor_multiplicativo));
		return nuevo;
	}
	
	double Ajuste(){
	   double radio = Radio();
	   
	   return PI * radio * radio - Area();
   }
	
};


////////////////////////////////////////////////////////////////////////

int main (){
	PoligonoRegular poligono1;
	PoligonoRegular poligono2 (6, 4);
	
	if (poligono1.EsMayorQue(poligono2))
		cout << "El area de poligono1 es mayor que la de poligono2";
	else 
		cout << "El area de poligono2 es mayor que la de poligono1";		

   PoligonoRegular poligono_doble (poligono1.Multiplica(2));
   
   cout << "\n\n�rea del pol�gono con doble n�mero de lados: " 
        << poligono_doble.Area();
   
   ///////////////////////////////////////////////////////////
	
	while (! SonIguales(0.0 , poligono_doble.Ajuste())) {
		poligono_doble = poligono_doble.Multiplica(2);
	}
	
	// O bien:
	/*
	double radio = poligono1.Radio();
	double area_objetivo = PI * radio * radio;

	while (! SonIguales(area_objetivo , poligono_doble.Area())) {
		poligono_doble = poligono_doble.Multiplica(2);
	}
	*/

	cout << "\n\nEl pol�gono envolvente tiene " 
	     << poligono_doble.NumLados() << " lados\n\n";
}

