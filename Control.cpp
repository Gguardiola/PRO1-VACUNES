#include "Control.hpp"

Control::Control()
/* Pre: cert */
/* Post: Inicialitza el vector de vacunes */
{

}

Control::~Control()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
de visibilitat */
{  

}

void Control::afegir_vac(string id)
/* Pre: la id de la vacuna NO ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna ja existia, es produeix un error; sinó, la vacuna es dona d'alta
en el sistema amb 0 unitats */
{
    bool trobat = false;
    int i = 0;
    while(i < int(vacunas.size()) and not trobat){
        if(vacunas[i] == id) trobat = true;
        i++;
    }
    if(!trobat){
        vacunas.push_back(id);
        sort(vacunas.begin(),vacunas.end());
    }
    else        cout<<"  error"<<endl;  
}

void Control::treure_vac(string id, vector<Cambra> &almacen)
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna no existeix, o existeix i en queden unitats, es produeix un error.
En cas contrari, la vacuna es dona de baixa del sistema */
{
    bool trobat = false;    
    int i = 0, cantidad = 0;
    vector<string>::iterator it = vacunas.begin();

    for(unsigned int i = 0; i < almacen.size(); i++){
        cantidad += almacen[i].consultar_cantidad(id);      //consultar_cantidad explicat en Cambra.cpp
    }

    while(i < int(vacunas.size()) and not trobat){
        if(vacunas[i] == id) trobat = true;
        else {
            i++;
            it++;
        }
    }

    if(trobat and cantidad==0) {
        vacunas.erase(it);
    }
    else cout<<"  error"<<endl;
}

vector<string> Control::get_vacunas() const
/* Pre: cert */
/* Post: retorna el vector de strings amb les IDs de les vacunes */
{
    return vacunas;
}

void Control::consultar_vac(string id, vector<Cambra> &almacen) const
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: Si la vacuna no existeix, es produeix un error. En cas contrari, escriu
quantes unitats hi ha en total al magatzem */
{
    bool exists = false;
    int cantidad = 0;
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    if(exists){
        for(unsigned int i = 0; i < almacen.size(); i++){
            cantidad += almacen[i].consultar_cantidad(id);      //consultar_cantidad explicat en Cambra.cpp
        }
        cout<<cantidad<<endl;
    }
    else    cout<<"error"<<endl;
}

void Control::inventari(vector<Cambra> &almacen) const
/* Pre: cert */
/* Post: Per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu id
i la quantitat total en el magatzem, ordenat per identificador de vacuna */
{
    for(int i=0; i < int(vacunas.size()); ++i){
        cout<<"  "<<vacunas[i]<<" ";
        consultar_vac(vacunas[i],almacen);
    }
}