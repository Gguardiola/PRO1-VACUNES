#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "Cambra.hpp"

class Control {

private:

    vector<string> vacunas;

public:

    //Constructors
    Control();
    
    //Destructor
    ~Control();
    /* Post: esborra automaticament els objectes locals en sortir d'un ambit
    de visibilitat */

    //Modificadors
    void afegir_vac(string id);
    /* Pre: cert */
    //la id de la vacuna NO ha d'existir en el vector on estan totes les vacunes declarades
    /* Post: si la vacuna ja existia, es produeix un error; sinó, la vacuna es dona d'alta
    en el sistema amb 0 unitats */
    void treure_vac(string id);
    /* Pre: cert */
    //la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades
    /* Post: si la vacuna no existeix, o existeix i en queden unitats, es produeix un error.
    En cas contrari, la vacuna es dona de baixa del sistema */
    //Tenemos en cuenta cuando quedan unidades?
    //Consultors
    vector<string> get_vacunas() const;
    /* Pre: cert */
    /* Post: retorna el vector de strings amb les IDs de les vacunes */
    void consultar_vac(string id, vector<Cambra> &almacen) const;
    /* Pre: cert */
    //la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades
    /* Post: Si la vacuna no existeix, es produeix un error. En cas contrari, escriu
    quantes unitats hi ha en total al magatzem */
    
    //Lectura i escriptura
    void inventari(vector<Cambra> &almacen) const;
    /* Pre: cert */
    /* Post: Per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu id
    i la quantitat total en el magatzem, ordenat per identificador de vacuna */
};
#endif
