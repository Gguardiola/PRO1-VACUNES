#include "Cambra.hpp"

Cambra::Cambra()
/* Pre: cert */
/* Post: crida al destructor de la clase. No es pot crear una nevera sense dimensions */
{
cout<<"error mida de la cambra buida"<<endl;
this -> ~Cambra();
}

Cambra::Cambra(int x, int y)
/* Pre: cert */
/* Post: crea una nevera de x·y */
{
    vector<string> aux;
    for(int j = 0; j < y; j++){
        aux.push_back("NULL");
    }    
    for(int i = 0; i < x; i++){            
        nevera.push_back(aux);
    }
}

Cambra:: ~Cambra()
/* Post: esborra automaticament els objectes locals en sortir d'un ambit
de visibilitat */
{

}

void Cambra::comprimir()
/* Pre: cert */
/* Post: es desplacen les vacunes cap a l’esquerra i cap avall sense restar cap forat entre dues vacunes ni abans de cap vacuna, tot mantenint l’ordre relatiu de les vacunes */
{
    int FIL = nevera.size()-1, i = nevera.size()-1;
    int COL = 0, j = 0;
    while(i>=0 and FIL>=0){

        while(j<nevera[i].size() and COL<nevera[FIL].size()){
            if(nevera[i][j]=="NULL" and nevera[FIL][COL]!="NULL"){
                nevera[i][j]=nevera[FIL][COL];
                nevera[FIL][COL]="NULL";
                j++; 
                COL++;
            }
            else if(nevera[i][j]=="NULL" and nevera[FIL][COL]=="NULL") COL++;
            else if(nevera[i][j]!="NULL" and nevera[FIL][COL]=="NULL") j++;
            
            else{
                j++;
                COL++;
            }
        }
        if(j== nevera[i].size()){
            i--;
            j=0;
        }
        if(COL== nevera[FIL].size()){
            FIL--;
            COL=0;
        }
    } 

}


void Cambra::ordenar()
/* Pre: cert */
/* Post: s’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats entre elles ni abans de cap vacuna */
{
    
    vector<string> neveraAux(nevera.size()*nevera[0].size());
    int s=0;
    for(int i = nevera.size()-1; i >=0; i--){
        for(int j = nevera[i].size()-1; j >=0; j--, s++){
            neveraAux[s]= nevera[i][j];
        }
    }
    sort(neveraAux.begin(), neveraAux.end());
    s=0;
    for(int i = nevera.size()-1; i >=0; i--){
        for(int j = 0; j < nevera[i].size(); j++, s++){
            nevera[i][j] = neveraAux[s];
        }
    }

}

void Cambra::canviar_nevera(int x, int y)
/* Pre: cert */
/* Post: es redimensiona la nevera. Si les vacunes que hi ha a la nevera inicial de
        la cambra no caben en les dimensions de la nova nevera, es produeix un error. En cas
        contrari, es fa el canvi de mides de la nevera */
{
    if((x*y) >= (nevera.size()*nevera[0].size())){
        matriu aux(x,fila(y,"NULL"));
        int FIL = nevera.size()-1, i = aux.size()-1;
        int COL = 0, j = 0;
        while(FIL>=0 and i>=0){

            while(j<aux[i].size() and COL<nevera[FIL].size()){
                
                aux[i][j] = nevera[FIL][COL];
                j++;
                ++COL;
            }
            if(j== aux[i].size()){
                i--;
                j=0;
            }
            if(COL== nevera[FIL].size()){
                --FIL;
                COL=0;
            }
        }
        nevera=aux;
        comprimir();


    }else{
        cout<<"  "<<"error"<<endl;

    }

}

void Cambra::afegir_unitats(string id, int q, const vector<string> &vacunas)
/* Pre: rep l'id de la vacuna, la quantitat de vacunes a introduir i un vector amb el total de vacunes declarades */
/* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es posen tantes unitats com càpiguen 
        en la cambra i es torna un enter que indiqui quantes unitats no han cabut */ 
{
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
        cout<<"  "<<q<<endl;

        auxq-= q;
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it == registro_vacunas.end()){
            registro_vacunas.insert(make_pair(id,auxq));
        }else{
            it->second += auxq;
        }
    }else   cout<<"  "<<"error"<<endl;
    
}

void Cambra::treure_unitats(string id, int q,const vector<string> &vacunas)
/* Pre: rep l'id de la vacuna, la quantitat de vacunes a treure i un vector amb el total de vacunes declarades */
/* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es
        treuen tantes unitats com es pugui i es torna un enter que indiqui quantes
        unitats no s'han pogut treure perquè no hi havia prou unitats a la cambra */ 
{
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
        cout<<"  "<<q<<endl;
        auxq-= q;
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it != registro_vacunas.end()){
            it->second -= auxq;
        }
    }else   cout<<"  "<<"error"<<endl;    
}

int Cambra::consultar_cantidad(string id) const
/* Pre: cert */
/* Post: retorna la quantitat de vacunes que hi ha dins de la nevera amb l'id que s'ha demanat */
{
    int cant = 0;
    map<string,int>::const_iterator it = registro_vacunas.find(id);
    if(it != registro_vacunas.end()){
        cant = it->second;
    }
    return cant;

}

void Cambra::consultar_pos(int x, int y) const
/* Pre: cert */
/* Post: s’indica quina vacuna hi ha en la posició corresponent de la nevera de la cambra. 
        Si no hi ha cap vacuna, s’escriu NULL */
{
    cout<<"  "<<nevera[x][y]<<endl;
}

void Cambra::escriure() const
/* Pre: cert */
/* Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta.
        També s’escriu quantes unitats hi ha en total i, per ordre d’identificador de vacuna
        existent en la nevera, s’escriuen l’identificador de vacuna i la seva quantitat */
{
    int num_vacunas = 0;
    for(unsigned int i = 0;i<nevera.size();i++){
        cout<<"  ";
        for(unsigned int j = 0;j<nevera[i].size();j++){
            if(j != 0) cout<<" ";
            cout<<nevera[i][j];
            if(nevera[i][j] != "NULL") num_vacunas++;
        }    
        cout<<endl;
    }

    cout<<"  "<<num_vacunas<<endl;

    for(map<string, int>::const_iterator it=registro_vacunas.begin();it!=registro_vacunas.end();it++){
        cout<<"  ";
        cout<<it->first<<" "<<it->second<<endl;

    }
}