#include "Control.hpp"

//constructors
Control::Control(){

}

//default destructor
Control::~Control(){    
}
//finalizar programa
void Control::fi(){

}
//modificadors
void Control::afegir_vac(string id){
    //PRE: recibe la id de la vacuna
    //POST: añade al vector vacunas la nueva id en caso de que no exista previamente    
    bool trobat = false;
    int i = 0;
    while(i<vacunas.size() and not trobat){
        if(vacunas[i] == id) trobat = true;
        i++;
    }
    if(!trobat){
        vacunas.push_back(id);
        sort(vacunas.begin(),vacunas.end());
    }
    else        cout<<"error"<<endl;
    
}
void Control::treure_vac(string id){
    //PRE: recibe la id de la vacuna
    //POST: retira del vector vacunas la vacuna con la id correspondiente
    bool trobat = false;    
    int i = 0;
    while(i<vacunas.size() and not trobat){
        if(vacunas[i] == id) trobat = true;
        i++;
    }

    if(trobat) vacunas.erase(vacunas.begin()+i);
    else cout<<"error"<<endl;
}

//void update_inventario(string id, int n)

//consultors
vector<string> Control::get_vacunas() const{
    return vacunas;
}
void Control::consultar_vac(string id, vector<Nevera> &almacen) const{
    //PRE: string de la id de la vacuna
    //POST: comprueba si la vacuna esta definida o no.
    //Si existe, devuelve la cantidad total de vacunas con esa id que existe en todas las neveras. En caso de no existir devuelve error.
    bool exists = false;
    int cantidad = 0;
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    if(!exists) cout<<"error"<<endl;
    else{
        for(unsigned int i = 0;i<almacen.size();i++){
            cantidad+= almacen[i].consultar_cantidad(id);
        }

        cout<<cantidad<<endl;
    }   
}

void Control::inventari(vector<Nevera> &almacen) const{
    //PRE: cert
    //POST: imprime la id de las vacunas y su cantidad en todas las neveras
    for(int i=0; i < vacunas.size(); ++i){
            cout<<vacunas[i]<<" ";
            consultar_vac(vacunas[i],almacen);
    }
}