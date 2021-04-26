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
    void Nevera::distribuir(string s, int n)

    {

    }    
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

void Nevera::modificar_pos(int x, int y, string id){

    nevera[x][y] = id;
}
int Nevera::consultar_cantidad(string id){
    int cant = 0;
    map<string,int>::const_iterator it = registro_vacunas.find(id);
    if(it != registro_vacunas.end()){
        cant = it->second;
    }

    return cant;

}
pair<int,int> Nevera::consultar_dimensiones(){

    return dimensiones;
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
    