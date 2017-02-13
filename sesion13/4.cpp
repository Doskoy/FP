#include <iostream>
using namespace std;

static const char TERMINADOR = '#';
static const int TAMANIO  =  2e6;

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

   void EliminaOcurrencias(char a_borrar){
      for (int i = 0; i < TotalUtilizados(); i++)
         if(vector_privado[i] == a_borrar){
            Elimina(i);
            i--;
         }
   }

   void EliminaBloque(int primera, int ultima){
      int primera_pos = primera;
      int ultima_pos = ultima; 

      for (int i = primera_pos; i < ultima_pos; i++){
         Elimina(i);
         i--;
      }   
   }

   	SecuenciaCaracteres Descodifica(){
   		SecuenciaCaracteres copia_texto;
   		SecuenciaCaracteres descodificada;
   		int i, siguiente;
   		bool anterior_es_blanco;
   		i = 0;
  		anterior_es_blanco = true;

  		for (int i = 0; i < total_utilizados; i++)
  			copia_texto.Aniade(Elemento(i));

  		while (i < copia_texto.TotalUtilizados()){
      		siguiente = i+1;

     		if (copia_texto.Elemento(i) != ' '){
         		if (anterior_es_blanco ||
            	(siguiente < copia_texto.TotalUtilizados() && copia_texto.Elemento(siguiente) == ' ')){
               
            		descodificada.Aniade(copia_texto.Elemento(i));
            	}

         		anterior_es_blanco = false;
      		}
      		else
         	anterior_es_blanco = true;
      		
      		i = siguiente;
  		}

  		return descodificada; 
   	}

};

int LeeIntRango(int min, int max){
   int n;
   do{
      cout << "Introduce un numero en el rango " << "[" << min << "-" << max << "]: "; 
      cin >> n;
   }while (n < min || n > max);
   return n; 
}

int LeeIntMayorIgualQue(int x){
   int n;
   do{
      cout << "Introduce un numero mayor o igual que " << x << ": " ;
      cin >> n;
   }while(n < x);
   return n;
}


int main(){
   char caracter;
   SecuenciaCaracteres texto;
   SecuenciaCaracteres texto_descodificado;
   int i, siguiente;
   bool anterior_es_blanco;
   
   //////////////////////////////////////////////////////////////////
   // Lectura de los datos:

   cout << "Cadena codificada."
        << "\nIntroduzca caracteres con terminador " << TERMINADOR << "\n";

   caracter = cin.get();

   while (caracter != TERMINADOR && texto.TotalUtilizados() < TAMANIO){
      texto.Aniade(caracter);
      caracter = cin.get();
   }

   //////////////////////////////////////////////////////////////////
   
   texto_descodificado = texto.Descodifica();

   cout << "\nCadena descodificada:\n" << "<";
   for(int i = 0; i < texto_descodificado.TotalUtilizados(); i++){
   	cout << texto_descodificado.Elemento(i);
   }
   
   cout << ">\n";
}