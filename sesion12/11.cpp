  
#include <iostream>
using namespace std;

static const char TERMINADOR = '#';
static const int TAMANIO  =  2e6;
const int CARACTERES_ASCII = 256;



struct FrecuenciaCaracter{
   char caracter;
   int  frecuencia;
};

class  SecuenciaCaracteres{
private:
   char vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentesDirectamente (int izda, int dcha){
      char intermedia;

      intermedia = vector_privado[izda];
      vector_privado[izda] = vector_privado[dcha];
      vector_privado[dcha] = intermedia;
   }
public:
   SecuenciaCaracteres()
      :total_utilizados(0)        
   {    
   }
   
   int TotalUtilizados(){
      return  total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void Aniade(char  nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados]  =  nuevo;
         total_utilizados++;
      }
   }

   void Elimina(int posicion_eliminar){
      if(posicion_eliminar >= 0 && posicion_eliminar < TotalUtilizados()){
         int tope = TotalUtilizados() - 1;

         for (int i = posicion_eliminar; i < tope; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;    
      }
   }
   
   char Elemento(int  indice){
      return  vector_privado[indice];
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Modifica (int indice_componente, char nuevo){
      if (indice_componente >= 0  &&  indice_componente < total_utilizados)
         vector_privado[indice_componente] = nuevo;
   }

   string ToString(){

      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);

      return cadena;
   }
   
   int NumeroMayusculas(){
      int numero_mayusculas = 0;
      
      for (int i = 0; i < total_utilizados; i++){
         if (isupper(vector_privado[i]))
            numero_mayusculas++;  
      }
      
      return numero_mayusculas;
   }

   bool EsPalindromo(){
      bool es_palindromo;
      int izda, dcha;

      es_palindromo = true;
      izda = 0;
      dcha = total_utilizados - 1;

      while (izda < dcha && es_palindromo){
         if (vector_privado[izda] != vector_privado[dcha])
            es_palindromo = false;
         else{
            izda++;
            dcha--;
         }
      }

      return es_palindromo;
   }
   

   void IntercambiaComponentes (int izda, int dcha){
      if (izda >= 0  &&  izda < dcha  &&  dcha < total_utilizados)
         IntercambiaComponentesDirectamente (izda, dcha);
   }

   void Invierte(){
      int izda, dcha;

      izda = 0;
      dcha = total_utilizados - 1;

      while (izda < dcha){
         IntercambiaComponentesDirectamente(izda, dcha);
         izda++;
         dcha--;
      }
   }

   FrecuenciaCaracter Moda(){
      FrecuenciaCaracter moda;
      char caracter_actual;
      int conteo_frecuencia;
      int utilizados_procesados;
      bool encontrado;
      utilizados_procesados = 0;
      moda.frecuencia = 0;
      moda.caracter = TERMINADOR;
      char vector_procesados[CARACTERES_ASCII];

      for (int i = 0 ; i < TotalUtilizados() ; i++){
         caracter_actual = Elemento(i);
         encontrado = false;
      
         for (int j = 0; j < utilizados_procesados && !encontrado; j++){
            if (caracter_actual == vector_procesados[j])
               encontrado = true;
         }

         if (! encontrado){
            vector_procesados[utilizados_procesados] = caracter_actual;
            utilizados_procesados++;
         
            conteo_frecuencia = 1;

            for (int k = i + 1 ; k < TotalUtilizados() ; k++)
               if (caracter_actual == Elemento(k));
                  conteo_frecuencia++;

            if (conteo_frecuencia > moda.frecuencia) {
               moda.frecuencia = conteo_frecuencia;
               moda.caracter   = caracter_actual;
            }
         }
      }
      return moda;
   }

   void EliminaOcurrencias(char a_borrar){
      for (int i = 0; i < TotalUtilizados(); i++)
         if(vector_privado[i] == a_borrar){
            Elimina(i);
            i--;
         }
   }
};


int main(){
   char caracter;
   SecuenciaCaracteres secuencia;   
   FrecuenciaCaracter moda;
 
   int total_introducidos;
   int capacidad_secuencia;
   char caracter_eliminar;

   cout << "Elimina Ocurrencias."
        << "\nIntroduzca caracteres con terminador " << TERMINADOR << "\n";
        
   total_introducidos = 0;
   caracter = cin.get();
   capacidad_secuencia = secuencia.Capacidad();
   
   while (caracter != TERMINADOR && total_introducidos < capacidad_secuencia){
      secuencia.Aniade(caracter);
      total_introducidos++;
      caracter = cin.get();
   }

   cout << "Introduce el caracter a eliminar: "; 
   cin >> caracter_eliminar;

   secuencia.EliminaOcurrencias(caracter_eliminar); 

   for(int i = 0; i < secuencia.TotalUtilizados(); i++) 
      cout << secuencia.Elemento(i);

}