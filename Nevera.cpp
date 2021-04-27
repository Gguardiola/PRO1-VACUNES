#include <iostream>
#include "Nevera.hpp"
using namespace std;
typedef vector<string> fila;
typedef vector<fila> matriu;

Nevera::Nevera()
/* Pre: cert */
/* Post: Crea una nevera de 0x0*/
{
    cout<<"ERROR"<<endl;

}

Nevera::Nevera(int x, int y)
/* Pre: cert */
/* Post: Crea una nevera de x·y*/
{
    vector<string> aux;
    for(int j = 0; j<y;j++){
        aux.push_back("NULL");
    }    
    for(int i = 0; i<x;i++){            
        nevera.push_back(aux);
    }
    dimensiones.first = x;dimensiones.second = y;
}

Nevera:: ~Nevera()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
de visibilitat */
{
}
/*
 
*/
/*    
    void Nevera::comprimir(int n)

    {

    }
*/
/*
    void Nevera::ordenar(int n)
    {

    }
*/    
/*
    void Nevera::canviar_nevera(int n, int x, int y)

    {
}
*/
void Nevera::afegir_unitats(string id, int q, const vector<string> &vacunas){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas a introducir.
    //POST: en caso de que exista la nevera, introducirá n vacunas de la id hasta rellenar todos los huecos disponibles
    int auxq = q;
    bool exists = false;
    for (string i: vacunas){
        if(i == id) exists = true;
    }    
    if(exists){
        int i = nevera.size()-1,j = 0;
        while(i>=0 and q!=0){
            j = 0;
            while(j<nevera[i].size() and q!=0){
                if(nevera[i][j] == "NULL"){
                    nevera[i][j] = id;
                    q--;
                }
                j++;
            } 
            i--;
        }
        cout<<q<<endl;

        auxq-= q;
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it == registro_vacunas.end()){
            registro_vacunas.insert(make_pair(id,auxq));
        }else{
            it->second += auxq;
        }
    }else   cout<<"error"<<endl;
    
}
void Nevera::treure_unitats(string id, int q,const vector<string> &vacunas){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas que van a salir.
    //POST: en caso de que exista la nevera, retirará n vacunas de la id correspondiente
    int auxq = q;
    bool exists = false;
    for (string i: vacunas){
        if(i == id) exists = true;
    }    
    if(exists){
        int i = nevera.size()-1,j = 0;

        while(i>=0 and q!=0){
            j = 0;
            while(j<nevera[i].size() and q!=0){
                if(nevera[i][j] == id){
                    nevera[i][j] = "NULL";
                    q--;
                }
                j++;
            } 
            i--;
        }
        cout<<q<<endl;
        auxq-= q;
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it != registro_vacunas.end()){
            it->second -= auxq;
        }
    }else   cout<<"error"<<endl;    
}

int Nevera::consultar_cantidad(string id){
    int cant = 0;
    map<string,int>::const_iterator it = registro_vacunas.find(id);
    if(it != registro_vacunas.end()){
        cant = it->second;
    }

    return cant;

}

string Nevera::consultar_pos(int x, int y) /*const*/
/* Pre: */
/* Post: */
{
    return nevera[x][y];
}

void Nevera::escriure() /*const*/
/* Pre: */
/* Post: */
{
    int num_vacunas = 0;
    for(unsigned int i = 0;i<nevera.size();i++){
        for(unsigned int j = 0;j<nevera[i].size();j++){
            if(j != 0) cout<<" ";
            cout<<nevera[i][j];
            if(nevera[i][j] != "NULL") num_vacunas++;
        }    
        cout<<endl;
    }

    cout<<num_vacunas<<endl;

    for(map<string, int>::const_iterator it=registro_vacunas.begin();it!=registro_vacunas.end();it++){
        cout<<it->first<<" "<<it->second<<endl;

    }
}
/*
Añadir vector que sea identico a lo que muestra inventari() para después sumar
todos los vectores de todas las neveras
*/
    