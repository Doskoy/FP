#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;
const double PI = 3.1415927; 

double Gaussiana (double x, double esperanza, double desviacion){
  double y;
  double valor_tipificado, exponente;

  valor_tipificado = (x - esperanza) / desviacion;
  exponente = -0.5 * valor_tipificado * valor_tipificado;
  y = exp(exponente) / ( desviacion * sqrt(2*PI) );
  return y;
}


int main(){
	 /*
    Como norma general no usaremos nombres de variables como x, y, etc.
    Hacemos una excepción en este programa ya que son nombres
      omnipresentes en Matemáticas.
  */
  
  /*
  (P)arámetros  -> [cin esperanza y desviación] -> (R)ango -> [cin min, max, incremento] -> Resultados ->|
  (S)alir       <--------------------------------- (V)olver <--------------------------------------------|  
  */
  /*
  do{
    Mostrar Menú Ppal (Parámetros o Salir)
    Leer opcion_menu_ppal
    
    if opcion_ppal no es Salir
       Lectura de esperanza y desviación
       
       do{
          Mostrar Menú (Rango o Volver)
          Leer opcion_menu_secundario
          
          if opcion_menu_secundario no es Volver
             Lectura de min, max e incremento
             Mostrar resultados
        }while (opcion_menu_secundario != 'V')
   }while (opcion_ppal != 'S')
   */  
 
   const char OPCION_INTRO_PARAMETROS  = 'P',
              OPCION_SALIR             = 'S',
              OPCION_INTRO_RANGO       = 'R',
              OPCION_VOLVER            = 'V';
   char opcion_menu_ppal, opcion_menu_secundario;
   bool eligio_salir_ppal, eligio_salir_secundario;
   bool es_correcta_opcion_ppal, es_correcta_opcion_secundario;
	double esperanza, desviacion, x, min_x, max_x, incremento, y;	                             
	
   
   cout << "Gaussiana";
   
   do{
      cout << "\n\n---------------------\n" 
           << "Menú Principal\n\n"
           << "Parámetros\n"
           << "Salir\n";
      
      do{
         cout << "\nIntroduzca la opción (" << OPCION_INTRO_PARAMETROS 
              << "/" << OPCION_SALIR << ") ";
         cin >> opcion_menu_ppal;
         opcion_menu_ppal = toupper(opcion_menu_ppal);
         eligio_salir_ppal = opcion_menu_ppal == OPCION_SALIR;
         es_correcta_opcion_ppal = eligio_salir_ppal ||
                                   opcion_menu_ppal == OPCION_INTRO_PARAMETROS;
      }while (! es_correcta_opcion_ppal);
      
      if (! eligio_salir_ppal){
         cout << "\nIntroduzca el valor del parámetro 'esperanza': ";
      	cin >> esperanza;
      
         do{
            cout << "\nIntroduzca el valor del parámetro 'desviacion'. "
                 << "Debe ser un número positivo: ";
      	   cin >> desviacion;
         }while (desviacion < 0);
         
         do{
            cout << "\n\n" 
              << "Menú Secundario\n\n"
              << "Rango\n"
              << "Volver\n";
              
            do{
               cout << "\nIntroduzca la opción (" << OPCION_INTRO_RANGO 
                    << "/" << OPCION_VOLVER << ") ";
               cin >> opcion_menu_secundario;
               opcion_menu_secundario = toupper(opcion_menu_secundario);
               eligio_salir_secundario = opcion_menu_secundario == OPCION_VOLVER;
               es_correcta_opcion_secundario  = eligio_salir_secundario ||
                                         opcion_menu_secundario == OPCION_INTRO_RANGO;
            }while (! es_correcta_opcion_secundario);                                               
            
            if (! eligio_salir_secundario){
               cout << "\nIntroduzca el valor mínimo de la abscisa: ";
            	cin >> min_x;
            	
            	do{
                  cout << "\nIntroduzca el valor máximo de la abscisa. "
                       << "Debe ser un número positivo: ";
            	   cin >> max_x;
               }while (max_x < min_x);
            
               do{
            	   cout << "\nIntroduzca el valor del incremento. "
                       << "Debe ser un número positivo: ";
            	   cin >> incremento;
               }while (incremento < 0);
            
            
               x = min_x;
               
               for(x = min_x; x <= max_x; x = x + incremento){
                  y = Gaussiana(x, esperanza, desviacion);                 
                  cout << "\nf(" << x << ")= " << y;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}
