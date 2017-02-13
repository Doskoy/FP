#include <iostream>
#include <cctype>
#include <cmath>

const double PI = 3.1415927;   // Global por si la necesitamos en otras funciones

using namespace std;

class Gaussiana{
private:
	double esperanza;
	double desviacion;

public: 
	void SetEsperanza(double esperanz){
		esperanza = esperanz;
	}

	void SetDesviacion(double desv){
		desviacion = desv;
	}

	double EvaluaGaussiana(double x){
		double valor_tipificado, exponente;
		double ordenada;
	
		valor_tipificado = (x - esperanza) / desviacion;
   		exponente = -0.5 * valor_tipificado * valor_tipificado;
   		ordenada = exp(exponente) / ( desviacion * sqrt(2*PI) );

	return ordenada;
	}

// -----------------------------------------------------------------------
// Área hasta x que queda por debajo de la Gaussiana
	double AreaHastaGaussiana(double x){
		const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
			b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
		double area_hasta;
		double t;

		t = 1 / (1 + b0 * x);
		area_hasta = 1 -  EvaluaGaussiana(x)*
		(b1*t + b2 * Potencia(t,2) + b3 * Potencia(t,3) +
        b4*Potencia(t,4) + b5*Potencia(t,5));

	return area_hasta;
}

};

// -----------------------------------------------------------------------
double LeeDoubleMayorIgualQue(double minimo, string mensaje){
   cin >> mensaje;
   double a_leer;

   do{
      cout << mensaje;
      cin >> a_leer;
   }while (minimo > a_leer);

   return a_leer;
}

// -----------------------------------------------------------------------
//	Potencia de un número elevado a un entero.
double Potencia(double la_base, int el_exponente){

	double potencia;
	int exponente_positivo;

	if (la_base == 0 && el_exponente == 0)
		potencia = NAN;
	else{
		exponente_positivo = abs(el_exponente);
		potencia = 1;

		for (int i = 1; i <= exponente_positivo; i++)
			potencia = potencia * la_base;
	}

	if (el_exponente < 0)
		potencia = 1/potencia;

return potencia;
}

bool Menu2OpcionesContinuarSalir(string mensaje,
                                char opcion_salir,
                                char opcion_seguir){
   char opcion_menu;
   bool eligio_salir, es_correcta_opcion;
   
   cout << mensaje;
   
   do{
      cout << "\nIntroduzca la opción (" << opcion_seguir
           << "/" << opcion_salir << ") ";
      cin >> opcion_menu;
      opcion_menu = toupper(opcion_menu);
      eligio_salir = opcion_menu == opcion_salir;
      es_correcta_opcion = eligio_salir || opcion_menu == opcion_seguir;
   }while (! es_correcta_opcion);
   
   return eligio_salir;
}
      
// -----------------------------------------------------------------------
int main(){
       
   const char OPCION_INTRO_PARAMETROS = 'P',
              OPCION_SALIR = 'S',
              OPCION_INTRO_RANGO = 'R',
              OPCION_VOLVER = 'V';
   bool eligio_salir_ppal, eligio_salir_secundario;
	
	const string
      MSJ_MENU_PPAL =
	   "\n\n---------------------\nMenú Principal\n\nParámetros\nSalir\n",
	   MSJ_MENU_SECUNDARIO =
	   "\n\nMenú Secundario\n\nRango\nVolver\n",
      MSJ_INTRO_ESPERANZA =
      "\nIntroduzca el valor del parámetro 'esperanza': ",
      MSJ_INTRO_DESVIACION =
      "\nIntroduzca el valor del parámetro 'desviacion'. Debe ser un número positivo: ",
      MSJ_INTRO_MINIMO =
      "\nIntroduzca el valor mínimo de la abscisa: ",
      MSJ_INTRO_MAXIMO =
      "\nIntroduzca el valor máximo de la abscisa. Debe ser un número positivo: ",
      MSJ_INTRO_INCREMENTO =
      "\nIntroduzca el valor del incremento. Debe ser un número positivo: ";
      
	double esperanza, desviacion, x, min_x, max_x, incremento;
	double y, cdf;
	Gaussiana funcion1;
   cout << "Gaussiana";
   
   do{
      eligio_salir_ppal = Menu2OpcionesContinuarSalir(
                                                MSJ_MENU_PPAL,
                                                OPCION_SALIR,
                                                OPCION_INTRO_PARAMETROS);
      
      if (! eligio_salir_ppal){
         cout << MSJ_INTRO_ESPERANZA;
      	cin >> esperanza;
         desviacion = LeeDoubleMayorIgualQue(0, MSJ_INTRO_DESVIACION);
         funcion1.SetEsperanza(esperanza);
         funcion1.SetDesviacion(desviacion);

         do{
            eligio_salir_secundario = Menu2OpcionesContinuarSalir(
                                                      MSJ_MENU_SECUNDARIO,
                                                      OPCION_VOLVER,
                                                      OPCION_INTRO_RANGO);
            
            if (! eligio_salir_secundario){
               cout << MSJ_INTRO_MINIMO;
            	cin >> min_x;
            	max_x      = LeeDoubleMayorIgualQue(min_x, MSJ_INTRO_MAXIMO);
               incremento = LeeDoubleMayorIgualQue(0, MSJ_INTRO_INCREMENTO);
               
               for(x = min_x; x <= max_x; x = x + incremento){               
                  y   = funcion1.EvaluaGaussiana(x);
                  cdf = funcion1.AreaHastaGaussiana(x);
                  
                  cout << "\nf(" << x << ")= " << y;
                  cout << "\n\t\t\tCDF(" << x << ")= " << cdf;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}