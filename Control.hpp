#ifndef CONTROL_HPP
#define CONTROL_HPP
#include "Nevera.hpp"
#include <vector>
#include <map>
class Control {

private:
    vector<string> vacunas;
public:
    //constructors
    Control();
    //default destructor
    ~Control();
    //finalizar programa
    void fi();
    //modificadors
    void afegir_vac(string id);
    //PRE: recibe la id de la vacuna
    //POST: añade al vector vacunas la nueva id en caso de que no exista previamente
    void treure_vac(string id);
    //PRE: recibe la id de la vacuna
    //POST: retira del vector vacunas la vacuna con la id correspondiente
    void afegir_unitats(int n, string id, int q);
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas a introducir.
    //POST: en caso de que exista la nevera, introducirá n vacunas de la id hasta rellenar todos los huecos disponibles
    void treure_unitats(int n, string id, int q);    
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas que van a salir.
    //POST: en caso de que exista la nevera, retirará n vacunas de la id correspondiente
    
    //void update_inventario(string id, int n)

    //consultors
    int consultar_vac(string id) const;
    //PRE: string de la id de la vacuna
    //POST: comprueba si la vacuna esta definida o no.
    //Si existe, devuelve la cantidad total de vacunas con esa id que existe en todas las neveras. En caso de no existir devuelve  "error".
    void inventari() const;
    //PRE: cert
    //POST: imprime la id de las vacunas y su cantidad en todas las neveras



};
#endif
