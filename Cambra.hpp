//Nombres
#ifndef CAMBRA_HPP
#define CAMBRA_HPP
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef vector<string> fila;
typedef vector<fila> matriu;

class Cambra {

private:
     
    matriu nevera;
    map <string,int> registro_vacunas;  //Aquest diccionari emmagatzema les vacunes i la quantitat d'unitats que hi ha en la nevera
   
public:

    //Constructors
    Cambra();
    /* Pre: cert */
    /* Post: crida al destructor de la clase. No es pot crear una nevera sense dimensions */
    Cambra(int x, int y);
    /* Pre: cert */
    /* Post: crea una nevera de x·y*/
   
    //Destructor 
    ~Cambra();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit
    de visibilitat */

    //Modificadors
    void comprimir();
    /* Pre: cert */
    /* Post: es desplacen les vacunes cap a l’esquerra i cap avall sense restar cap forat 
    entre dues vacunes ni abans de cap vacuna, tot mantenint l’ordre relatiu de les vacunes */
    void ordenar();
    /* Pre: cert */
    /* Post: s’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats 
    entre elles ni abans de cap vacuna */
    void canviar_nevera(int x, int y);
    /* Pre: La nova dimensió de la nevera ha de ser més gran o igual a l'anterior,
    o sigui, (x*y) >= (nevera.size()*nevera[0].size()), en cas contrari no fa res */
    /* Post: es redimensiona la nevera. Si les vacunes que hi ha a la nevera inicial de
    la cambra no caben en les dimensions de la nova nevera, es produeix un error. En cas
    contrari, es fa el canvi de mides de la nevera */
    void afegir_unitats(string id, int q, const vector<string> &vacunas);
    /* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
    /* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es posen tantes unitats
    com càpiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut */ 
    void treure_unitats(string id, int q, const vector<string> &vacunas);
    /* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
    /* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es treuen 
    tantes unitats com es pugui i es torna un enter que indiqui quantes unitats 
    no s'han pogut treure perquè no hi havia prou unitats a la cambra */ 

    //Consultor
    int consultar_cantidad(string id) const;
    /* Pre: cert */
    /* Post: retorna la quantitat de vacunes que hi ha dins de la nevera amb l'id que s'ha demanat */
    void consultar_pos(int x, int y) const;
    /* Pre: cert */
    /* Post: s’indica quina vacuna hi ha en la posició corresponent de la nevera de la cambra. 
    Si no hi ha cap vacuna, s’escriu NULL */

    //Lectura i escriptura
    void escriure() const;
    /* Pre: cert */
    /* Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta.
    També s’escriu quantes unitats hi ha en total i, per ordre d’identificador de vacuna
    existent en la nevera, s’escriuen l’identificador de vacuna i la seva quantitat */
};
#endif
