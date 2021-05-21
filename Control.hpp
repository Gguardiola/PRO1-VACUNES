#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "arbreBin.hpp"
#include "Cambra.hpp"

class Control {

private:

    vector<string> vacunas;
    arbreBin<int> arbol;

    static arbreBin<int> construirArbre(vector<int> pre, int &first, int low, int high);
    /* Pre: L'entrada consisteix en rebre el vector amb els valors en preordre, la posició del primer element 
    i les posicions del nombre més petit i del més gran */
    /* Post: el resultat es un arbre binari on el seu nombre de nodes equival al tamany del nostre vector, ordenat en preordre a partir dels mateixos valors que el vector pre */
    static int distribuir(string id, int q, vector<Cambra> &almacen, const arbreBin<int> &arbol, int &auxq, vector<string> &Vacunas);
    /* Pre: a = A, q > 0*/
    /* Post: retorna un enter que indiqui quantes unitats no han cabut en totes les cambres */

public:

    //Constructors
    Control();
    /* Pre: cert */
    /* Post: Inicialitza el vector de vacunes */

    //Destructor
    ~Control();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit
    de visibilitat */

    //Modificadors
    void construirArbre(int n);
    /* Pre: cert */
    /* Post: el resultat es un arbre binari on el seu nombre de nodes equival al tamany del nostre vector, ordenat en preordre a partir dels mateixos valors que el vector pre */
    int distribuir(string id, int q, vector<Cambra> &almacen);
    /* Pre: cert */
    /* Post: retorna un enter que indiqui quantes unitats no han cabut en totes les cambres */
    bool afegir_vac(string id);
    /* Pre: la id de la vacuna NO ha d'existir en el vector on estan totes les vacunes declarades */
    /* Post: si la vacuna ja existia, es produeix un error; sinó, la vacuna es dona d'alta
    en el sistema amb 0 unitats */
    bool treure_vac(string id, vector<Cambra> &almacen);
    /* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
    /* Post: si la vacuna no existeix, o existeix i en queden unitats, es produeix un error.
    En cas contrari, la vacuna es dona de baixa del sistema */
    
    //Consultors
    vector<string> get_vacunas() const;
    /* Pre: cert */
    /* Post: retorna el vector de strings amb les IDs de les vacunes */
    int consultar_vac(string id, vector<Cambra> &almacen) const;
    /* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
    /* Post: Si la vacuna no existeix, es produeix un error. En cas contrari, escriu
    quantes unitats hi ha en total al magatzem */
    
    //Lectura i escriptura
    void inventari(vector<Cambra> &almacen) const;
    /* Pre: cert */
    /* Post: Per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu id
    i la quantitat total en el magatzem, ordenat per identificador de vacuna */
};
#endif
