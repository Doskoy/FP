//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Parking con clases
/*
Ejemplo de entrada:

30 90 120 660 0.0412 0.0370 0.0311 0.0305 31.55
35 85 110 660 0.0402 0.0375 0.0319 0.0315 32
2 1 30 4 2 50
2 1 30 3 41 31
2 1 30 5 41 31
2 1 30 23 1 1 -1

-- Salida correcta:

4.4195 4.4262
3.767 3.7605
7.439 7.5445
31.55 32
47.1755
47.731
*/

#include <iostream>  
using namespace std; 

class Instante {
private:
   int hora;
   int minuto;
   int segundo;

public:
   /*Instante(int instante_hora, int instante_minuto, int instante_segundo){
      hora = instante_hora;
      minuto = instante_minuto;
      segundo = instante_segundo;
   }*/

   int MinutosEntreInstantes(Instante inicial, Instante final){
      const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
      int segundos_iniciales, segundos_finales, segundos_diferencia;

      segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
                                                  inicial.minuto) +
                           inicial.segundo;

      segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
                                                  final.minuto) +
                           final.segundo;

      segundos_diferencia = abs(segundos_finales - segundos_iniciales);

      return segundos_diferencia / SEGUNDOS_POR_MINUTO;
   }

   void SetHora (int instante_hora){
      hora = instante_hora;
   }

   void SetMinuto (int instante_minuto){
      minuto = instante_minuto;
   }

   void SetSegundo (int instante_segundo){
      segundo = instante_segundo;
   }
};

/*
struct InstanteTiempo{
   int hora;
   int minuto;
   int segundo;
};
*/
/*
int MinutosEntreInstantes (InstanteTiempo inicial, InstanteTiempo final){
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
   int segundos_iniciales, segundos_finales, segundos_diferencia;

   segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
                                               inicial.minuto) +
                        inicial.segundo;

   segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
                                               final.minuto) +
                       final.segundo;

   segundos_diferencia = abs(segundos_finales - segundos_iniciales);

   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
}
*/
// Prec:
// límites positivos y en orden de menor a mayor
// tarifas todas reales positivos
// minutos_estacionamiento positivo
/*
   Nota:
   Otra posibilidad pasaría por comprobar las precondiciones dentro de la función
   y si no se satisfacen, devolveríamos -1
*/

class Parking{
private:
   int lim_1, lim_2, lim_3, lim_4;
   double tarifa_1, tarifa_2, tarifa_3, tarifa_4;
   double tarifa_dia;
public:
   Parking  (int limite_tramo_1, int limite_tramo_2,
               int limite_tramo_3, int limite_tramo_4,
               double tarifa_tramo_1, double tarifa_tramo_2,
               double tarifa_tramo_3, double tarifa_tramo_4,
               double tarifa_dia_completo){
      lim_1 = limite_tramo_1;
      lim_2 = limite_tramo_2;
      lim_3 = limite_tramo_3;
      lim_4 = limite_tramo_4;
      tarifa_1 = tarifa_tramo_1;
      tarifa_2 = tarifa_tramo_2;
      tarifa_3 = tarifa_tramo_3;
      tarifa_4 = tarifa_tramo_4;
      tarifa_dia = tarifa_dia_completo;
   }
   
   double Tarifa(int minutos_estacionamiento){
      int minutos_tramo_1, minutos_tramo_2, minutos_tramo_3, minutos_tramo_4;
      double tarifa;
      bool tiempo_limite_rebasado;

      minutos_tramo_1 = 0;
      minutos_tramo_2 = 0;
      minutos_tramo_3 = 0;
      minutos_tramo_4 = 0;

      tiempo_limite_rebasado  = (minutos_estacionamiento > lim_4);

      if (!tiempo_limite_rebasado){
         if (minutos_estacionamiento < lim_1)
            minutos_tramo_1 = minutos_estacionamiento;
         else{
            minutos_tramo_1 = lim_1;

            if (minutos_estacionamiento < lim_2)
               minutos_tramo_2 = minutos_estacionamiento - lim_1;
            else{
               minutos_tramo_2 = lim_2 - lim_1;

               if (minutos_estacionamiento < lim_3)
                  minutos_tramo_3 = minutos_estacionamiento - lim_2;
               else{
                  minutos_tramo_3 = lim_3 - lim_2;
                  minutos_tramo_4 = minutos_estacionamiento - lim_3;
               }
            }
         }
      }

      if (tiempo_limite_rebasado)
         tarifa = tarifa_dia;
      else
         tarifa = minutos_tramo_1 * tarifa_1
                  +
                  minutos_tramo_2 * tarifa_2
                  +
                  minutos_tramo_3 * tarifa_3
                  +
                  minutos_tramo_4 * tarifa_4;

      return tarifa;
   }
};


int main(){   
   const int TERMINADOR_ENTRADA_DATOS = -1;
   int limite_tramo_1_parking_1, limite_tramo_2_parking_1, 
       limite_tramo_3_parking_1, limite_tramo_4_parking_1,
       limite_tramo_1_parking_2, limite_tramo_2_parking_2, 
       limite_tramo_3_parking_2, limite_tramo_4_parking_2;
       
   double tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, 
          tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
          tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, 
          tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2;
          
   double tarifa_dia_completo_parking_1, tarifa_dia_completo_parking_2;
   double tarifa_parking_1, tarifa_parking_2;
   double total_recaudado_parking_1, total_recaudado_parking_2;
   
   int minutos_estacionamiento;

   Instante instante_inicial, instante_final;

   int instante_inicial_hora, instante_inicial_minuto, instante_inicial_segundo;
   int instante_final_hora, instante_final_minuto, instante_final_segundo;

   cout << "Parking.\n\n";
 
   cin >> limite_tramo_1_parking_1;
   cin >> limite_tramo_2_parking_1;
   cin >> limite_tramo_3_parking_1;
   cin >> limite_tramo_4_parking_1;
   cin >> tarifa_tramo_1_parking_1;
   cin >> tarifa_tramo_2_parking_1;
   cin >> tarifa_tramo_3_parking_1;
   cin >> tarifa_tramo_4_parking_1;
   cin >> tarifa_dia_completo_parking_1;
   cin >> limite_tramo_1_parking_2;
   cin >> limite_tramo_2_parking_2;
   cin >> limite_tramo_3_parking_2;
   cin >> limite_tramo_4_parking_2;
   cin >> tarifa_tramo_1_parking_2;
   cin >> tarifa_tramo_2_parking_2;
   cin >> tarifa_tramo_3_parking_2;
   cin >> tarifa_tramo_4_parking_2;
   cin >> tarifa_dia_completo_parking_2;
   
   Parking parking_1(limite_tramo_1_parking_1, limite_tramo_2_parking_1,
                     limite_tramo_3_parking_1, limite_tramo_4_parking_1,
                     tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1,
                     tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
                     tarifa_dia_completo_parking_1);
                     
   Parking parking_2(limite_tramo_1_parking_2, limite_tramo_2_parking_2,
                     limite_tramo_3_parking_2, limite_tramo_4_parking_2,
                     tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2,
                     tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2,
                     tarifa_dia_completo_parking_2);

   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;

   cin >> instante_inicial_hora;
   instante_inicial.SetHora(instante_inicial_hora);
   
   while (instante_inicial_hora != TERMINADOR_ENTRADA_DATOS){
      cin >> instante_inicial_minuto;
      instante_inicial.SetMinuto(instante_inicial_minuto);
      cin >> instante_inicial_segundo;
      instante_inicial.SetSegundo(instante_inicial_segundo);

      cin >> instante_final_hora;
      instante_inicial.SetHora(instante_inicial_hora);
      cin >> instante_final_minuto;
      instante_inicial.SetMinuto(instante_inicial_minuto);
      cin >> instante_final_segundo;
      instante_inicial.SetSegundo(instante_inicial_segundo);

      minutos_estacionamiento =
         instante_inicial.MinutosEntreInstantes(instante_inicial, instante_final);

      tarifa_parking_1 = parking_1.Tarifa(minutos_estacionamiento);
      tarifa_parking_2 = parking_2.Tarifa(minutos_estacionamiento);
                                   
      cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cin >> instante_inicial_hora;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
}



