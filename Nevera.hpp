//Nombres
#ifndef NEVERA_HPP
#define NEVERA_HPP
#include <vector>
#include <string>
#include <iostream>
#include <map>
typedef vector<string> fila;
typedef vector<fila> matriu;
class Nevera {

private:
     
    Matriu Nevera;
    map <string,int> registro_vacunas;
   
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
    void distribuir(string s, int n);
    /* Pre: cert */
    /* Post: */
    void comprimir(int n);
    /* Pre: */
    /* Post: */
    void ordenar(int n);
    /* Pre: */
    /* Post: */
    void canviar_nevera(int n, int x, int y);
    /* Pre: */
    /* Post: */
    void afegir_unitats(int n, string id, int q);
        //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas a introducir.
        //POST: en caso de que exista la nevera, introducirá n vacunas de la id hasta rellenar todos los huecos disponibles

    void treure_unitats(int n, string id, int q);
        //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas que van a salir.
        //POST: en caso de que exista la nevera, retirará n vacunas de la id correspondiente

    //Consultor
    int consultar_cantidad(string id);
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
