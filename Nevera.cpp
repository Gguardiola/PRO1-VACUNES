//Nombres
#include "Nevera.hpp"
typedef vector<string> fila;
typedef vector<fila> matriu;

Nevera::Nevera()
/* Pre: cert */
/* Post: Crea una nevera de 0x0*/
{
    cout<<"ERROR"<<endl;
    ~Nevera();
}

Nevera::Nevera(int x, int y)
/* Pre: cert */
/* Post: Crea una nevera de x·y*/
{
    matriu n(x,fila(y,"NULL"));
}

Nevera::~Nevera()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
de visibilitat */
{
}

void Nevera::distribuir(string s, int n)
/* Pre: cert */
/* Post: */
{

}
void Nevera::comprimir(int n)
/* Pre: */
/* Post: */
{

}

void Nevera::ordenar(int n)
/* Pre: */
/* Post: */
{

}

void Nevera::canviar_nevera(int n, int x, int y)
/* Pre: */
/* Post: */
{

}
void Nevera::afegir_unitats(string id, int q, Control &control){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas a introducir.
    //POST: en caso de que exista la nevera, introducirá n vacunas de la id hasta rellenar todos los huecos disponibles

    if(control.consultar_vac(id)){
        unsigned int i = 0;
        while(i<n.size() and q!=0){
            for(unsigned int j = 0;j<n[i].size();j++){
                if(n[i][j] == "NULL"){
                    n[i][j]=id;
                    q--;
                }
            } 
            i++;
        }
        cout<<q<<endl;

    }else   cout<<"error"<<endl;
    
}
void Nevera::treure_unitats(string id, int q){
    //PRE: recibe el numero de la nevera, id de la vacuna y la cantidad de vacunas que van a salir.
    //POST: en caso de que exista la nevera, retirará n vacunas de la id correspondiente

}
int Nevera::consultar_cantidad(string id){
    n = 0;
    map<string,int>::const_iterator it = registro_vacunas.find(id);
    if(it != registro_vacunas.end()){
        cant = it->second;
    }

    return n;

}
string Nevera::consultar_pos(int x, int y) /*const*/
/* Pre: */
/* Post: */
{
    return n[x][y];
}

void Nevera::escriure() /*const*/
/* Pre: */
/* Post: */
{
    int num_vacunas = 0;
    for(unsigned int i = 0;i<n.size();i++){
        for(unsigned int j = 0;j<n[i].size();j++){
            cout<<n[i][j];
            if(n[i][j] != "NULL") num_vacunas++;
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
    