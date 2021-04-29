//Nombres
#ifndef NEVERA_HPP
#define NEVERA_HPP
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
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
    /* Pre: cert */
    /* Post: */
    void comprimir();
    /* Pre: */
    /* Post: */
    void ordenar();
    /* Pre: */
    /* Post: */
    void canviar_nevera(int x, int y);
    /* Pre: */
    /* Post: */
    void afegir_unitats(string id, int q, const vector<string> &vacunas);    
    void treure_unitats(string id, int q, const vector<string> &vacunas);

    //Consultor
    int consultar_cantidad(string id);
    void consultar_pos(int x, int y) /*const*/;
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
