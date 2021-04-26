//Nombres
#ifndef NEVERA_HPP
#define NEVERA_HPP
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef vector<string> fila;
typedef vector<fila> matriu;

class Nevera {

private:
     
    matriu nevera;
    map <string,int> registro_vacunas;
    pair<int,int> dimensiones;
   
public:
    

    //Constructors
    Nevera();
    /* Pre: cert */
    /* Post: Crea una nevera de 0x0*/
    Nevera(int x, int y);
    /* Pre: cert */
    /* Post: Crea una nevera de x·y*/
   
    //Destructor 
    ~Nevera();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit
    de visibilitat */

    //Modificadors
 //   void distribuir(string s, int n);
    /* Pre: cert */
    /* Post: */
  //  void comprimir(int n);
    /* Pre: */
    /* Post: */
  //  void ordenar(int n);
    /* Pre: */
    /* Post: */
   // void canviar_nevera(int n, int x, int y);
    /* Pre: */
    /* Post: */
    void modificar_pos(int x, int y, string id);

    //Consultor
    int consultar_cantidad(string id);
    pair<int,int> consultar_dimensiones();
    string consultar_pos(int x, int y) /*const*/;
    /* Pre: */
    /* Post: */

    //Lectura i escriptura
    void escriure() /*const*/;
    /* Pre: */
    /* Post: */
    /*
    Añadir vector que sea identico a lo que muestra inventari() para después sumar
    todos los vectores de todas las neveras
    */
    
};
#endif
