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
    if(!trobat)  vacunas.push_back(id);
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
void Control::afegir_unitats(string id, int q, Nevera &n){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas a introducir.
    //POST: en caso de que exista la nevera, introducirá n vacunas de la id hasta rellenar todos los huecos disponibles
    if(consultar_vac(id)){
        unsigned int i = 0;
        pair<int,int> size = n.consultar_dimensiones();
        while(i<size.first and q!=0){
            for(unsigned int j = 0;j<size.second;j++){
                if(q!=0){
                    if(n.consultar_pos(i,j) == "NULL"){
                        n.modificar_pos(i,j,id);
                        q--;
                    }
                }
            } 
            i++;
        }
        cout<<q<<endl;

    }else   cout<<"error"<<endl;
    
}
void Control::treure_unitats(string id, int q,Nevera &n){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas que van a salir.
    //POST: en caso de que exista la nevera, retirará n vacunas de la id correspondiente
    if(consultar_vac(id)){
        unsigned int i = 0;
        pair<int,int> size = n.consultar_dimensiones();
        while(i<size.first and q!=0){
            for(unsigned int j = 0;j<size.second;j++){
                if(q!=0){
                    if(n.consultar_pos(i,j) == id){
                        n.modificar_pos(i,j,"NULL");
                        q--;
                    }
                }
            } 
            i++;
        }
        cout<<q<<endl;

    }else   cout<<"error"<<endl;    
}
//void update_inventario(string id, int n)

//consultors
void Control::consultar_vac(string id, vector<Nevera> &almacen) const{
    //PRE: string de la id de la vacuna
    //POST: comprueba si la vacuna esta definida o no.
    //Si existe, devuelve la cantidad total de vacunas con esa id que existe en todas las neveras. En caso de no existir devuelve 0.
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

    }   

}
//sobrecarga
bool Control::consultar_vac(string id) const{
    //PRE: string de la id de la vacuna
    //POST: comprueba si la vacuna esta definida o no.
    //Si existe, devuelve la cantidad total de vacunas con esa id que existe en todas las neveras. En caso de no existir devuelve 0.
    bool exists = false;
    
    for (string i: vacunas){
        if(i == id) exists = true;
    }

    return exists;

}
void Control::inventari() const{
    //PRE: cert
    //POST: imprime la id de las vacunas y su cantidad en todas las neveras
}