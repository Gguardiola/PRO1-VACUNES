#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "Cambra.hpp"

class Control {

private:
    vector<string> vacunas;
public:
    //constructors
    Control();
    //default destructor
    ~Control();
    //modificadors
    void afegir_vac(string id);
    //PRE: recibe la id de la vacuna
    //POST: añade al vector vacunas la nueva id en caso de que no exista previamente
    void treure_vac(string id);
    //PRE: recibe la id de la vacuna
    //POST: retira del vector vacunas la vacuna con la id correspondiente

    //void update_inventario(string id, int n)

    //consultors
    vector<string> get_vacunas() const;
    //PRE:cert
    //POST: devuelve vector de strings con las ID de las vacunas
    void consultar_vac(string id, vector<Cambra> &almacen) const;

    //PRE: string de la id de la vacuna
    //POST: comprueba si la vacuna esta definida o no.
    //Si existe, devuelve la cantidad total de vacunas con esa id que existe en todas las neveras. En caso de no existir devuelve  "error".
    void inventari(vector<Cambra> &almacen) const;
    //PRE: cert
    //POST: imprime la id de las vacunas y su cantidad en todas las neveras



};
#endif
