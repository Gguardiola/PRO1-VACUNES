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
    //UPDATE: construim les neveres
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
/* Post: es desplacen les vacunes cap a l’esquerra i cap avall sense restar cap forat 
entre dues vacunes ni abans de cap vacuna, tot mantenint l’ordre relatiu de les vacunes */
{
    int FIL = nevera.size()-1, i = nevera.size()-1;
    int COL = 0, j = 0;
    //[i][j] són les coordenades originals de la matriu (nevera) primitiva
    //[FIL][COL] són les segones coordenades de la matriu primitiva que farán de "segona" matriu (nevera) per poder recórrer-la
    while(i >= 0 and FIL >= 0){

        while(j < int(nevera[i].size()) and COL < int(nevera[FIL].size())){
            //Hi ha 4 possibles combinacions entre les dues neveres, ja que poden estar o amb una vacuna o amb "NULL"
            //Si la primitiva té NULL i la segona té una vacuna, cambiem de posició la vacuna per el "NULL" i avancem de posició
            if(nevera[i][j] == "NULL" and nevera[FIL][COL] != "NULL"){
                nevera[i][j] = nevera[FIL][COL];
                nevera[FIL][COL] = "NULL";
                j++; 
                COL++;
            }
            //Si les dues tenen "NULL", només avancem posició de la segona ja que volem omplir el "NULL" de la primitiva
            else if(nevera[i][j] == "NULL" and nevera[FIL][COL] == "NULL") COL++;
            //Si la primitiva té una vacuna i la segona té "NULL", avancem posició de la primera ja que al tenir una vacuna, no volem solapar-la
            else if(nevera[i][j] != "NULL" and nevera[FIL][COL] == "NULL") j++;
            //I quan les dues tenen una vacuna, avancem de posició
            else{
                j++;
                COL++;
            }
        }
        //Quan una de les coordenades arribi al "límit", que avanci de fila
        //Avançar seguent fila
        if(j == int(nevera[i].size())){
            i--;
            j = 0;
        }
        //Avançar seguent fila
        if(COL == int(nevera[FIL].size())){
            FIL--;
            COL = 0;
        }
    }

}

void Cambra::ordenar()
/* Pre: cert */
/* Post: s’ordenen alfabèticament les vacunes de la nevera que conté sense deixar forats 
entre elles ni abans de cap vacuna */
{
    
    vector<string> neveraAux(nevera.size()*nevera[0].size());
    int s=0;
    //Insertar la matriu (nevera) en un vector
    for(int i = nevera.size()-1; i >= 0; i--){
        for(int j = nevera[i].size()-1; j >=0; j--, s++){
            neveraAux[s]= nevera[i][j];
        }
    }
    //Ordenar el vector
    sort(neveraAux.begin(), neveraAux.end());
    s=0;
    //Matriu ordenada
    for(int i = nevera.size()-1; i >= 0; i--){
        for(int j = 0; j < int(nevera[i].size()); j++, s++){
            nevera[i][j] = neveraAux[s];
        }
    }

}

bool Cambra::canviar_nevera(int x, int y)
/* Pre: La nova dimensió de la nevera ha de ser més gran o igual a la quantitat total de vacunes,
o sigui, (x*y) >= total_vacunas, en cas contrari no fa res */
/* Post: es redimensiona la nevera. Si les vacunes que hi ha a la nevera inicial de
la cambra no caben en les dimensions de la nova nevera, es produeix un error. En cas
contrari, es fa el canvi de mides de la nevera */
{
    //UPDATE: Recorre el diccionari registro_vacunas i sumem i guardem el value de les vacunes de cada nevera, així obtenim el total.
    int total_vacunas = 0;
    for(map<string, int>::const_iterator it=registro_vacunas.begin();it!=registro_vacunas.end();it++){
        if(it->second!=0)   total_vacunas += it->second;
    }
    bool canvia = true;
    if((x*y) >= total_vacunas){
        matriu aux(x,fila(y,"NULL"));
        int FIL = nevera.size()-1, i = aux.size()-1;
        int COL = 0, j = 0;
        //[i][j] són les coordenades de la matriu (nevera) auxiliar
        //[FIL][COL] són les coordenades de la matriu (nevera) primitiva
        while(FIL >= 0 and i >= 0){

            while(j < int(aux[i].size()) and COL < int(nevera[FIL].size())){
                //Omplim aux amb els continguts de la nevera i avancem les coordenades de posició
                aux[i][j] = nevera[FIL][COL];
                j++;
                ++COL;
            }
            //Quan una de les coordenades arribi al "límit" avança de fila
            //Avançar seguent fila
            if(j == aux[i].size()){
                i--;
                j = 0;
            }
            //Avançar seguent fila
            if(COL == nevera[FIL].size()){
                --FIL;
                COL = 0;
            }
        }
        nevera = aux;
        comprimir();
        //UPDATE: canvia és true i s'ha pogut canviar
    }else   canvia = false; //UPDATE: no s'ha pogut canviar
    return canvia;
}

int Cambra::afegir_unitats(string id, int q, const vector<string> &vacunas)
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es posen tantes unitats
com càpiguen en la cambra i es torna un enter que indiqui quantes unitats no han cabut */ 
{
    int auxq = q;
    bool exists = false;
    //UPDATE: Es mira si existeix la vacuna
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    //UPDATE: afegim la màxima quantitat d'unitats que es pugui a la cambra
    if(exists){
        int i = nevera.size()-1,j = 0;
        while(i >= 0 and q != 0){
            j = 0;
            while(j < int(nevera[i].size()) and q != 0){
                if(nevera[i][j] == "NULL"){
                    nevera[i][j] = id;
                    q--;
                }
                j++;
            } 
            i--;
        }

        auxq -= q;
        //Busquem en el diccionari si existeix una vacuna amb aquesta id (key), i si la troba, li sumem la quantitat (value) que s'ha afegit a la nevera
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it == registro_vacunas.end()){
            registro_vacunas.insert(make_pair(id,auxq));
        }
        else{
            it->second += auxq;
        }
    }else   q = -1; //UPDATE: -1 és una bona senyalització per donar a entendre que s'ha produït un error
    return q;
}

int Cambra::treure_unitats(string id, int q,const vector<string> &vacunas)
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna no existeix, es produeix un error. En cas contrari, es treuen 
tantes unitats com es pugui i es torna un enter que indiqui quantes unitats 
no s'han pogut treure perquè no hi havia prou unitats a la cambra */ 
{
    int auxq = q;
    bool exists = false;
    //UPDATE: Es mira si existeix la vacuna
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    //UPDATE: treiem la màxima quantitat d'unitats que es pugui de la cambra
    if(exists){
        int i = nevera.size()-1,j = 0;

        while(i >= 0 and q != 0){
            j = 0;
            while(j < int(nevera[i].size()) and q != 0){
                if(nevera[i][j] == id){
                    nevera[i][j] = "NULL";
                    q--;
                }
                j++;
            } 
            i--;
        }
        auxq -= q;
        //Busquem en el diccionari si existeix una vacuna amb aquesta id (key), i si la troba, li restem la quantitat (value) que s'ha eliminat de la nevera
        map<string,int>::iterator it = registro_vacunas.find(id);
        if(it != registro_vacunas.end()){
            it->second -= auxq;
        }
    }else   q = -1; //UPDATE: -1 és una bona senyalització per donar a entendre que s'ha produït un error
    return q;
}

int Cambra::consultar_cantidad(string id) const
/* Pre: cert */
/* Post: retorna la quantitat de vacunes que hi ha dins de la nevera amb l'id que s'ha demanat */
{
    int cant = 0;
    //Si en registro_vacunas troba la vacuna (key), retorna la quantitat (value) que hi ha a la nevera
    map<string,int>::const_iterator it = registro_vacunas.find(id);
    if(it != registro_vacunas.end()){
        cant = it->second;
    }
    return cant;

}

string Cambra::consultar_pos(int x, int y) const
/* Pre: cert */
/* Post: s’indica quina vacuna hi ha en la posició corresponent de la nevera de la cambra. 
Si no hi ha cap vacuna, s’escriu NULL */
{
    return nevera[x][y];
}

void Cambra::escriure() const
/* Pre: cert */
/* Post: S’escriu el contingut de la nevera de la cambra de dalt a baix i d’esquerra a dreta.
També s’escriu quantes unitats hi ha en total i, per ordre d’identificador de vacuna
existent en la nevera, s’escriuen l’identificador de vacuna i la seva quantitat */
{
    int num_vacunas = 0;
    //UPDATE: mostrem per pantalla la cambra sencera i calculem la quantitat de vacunes
    for(unsigned int i = 0; i < nevera.size(); i++){
        cout<<"  ";
        for(unsigned int j = 0; j < nevera[i].size(); j++){
            if(j != 0) cout<<" ";
            cout<<nevera[i][j];
            if(nevera[i][j] != "NULL") num_vacunas++;
        }    
        cout<<endl;
    }

    cout<<"  "<<num_vacunas<<endl;

    //Recorre el diccionari registro_vacunas i imprimeix per pantalla la seva key i el value. EJ.: J0BX0M3 3
    for(map<string, int>::const_iterator it=registro_vacunas.begin();it!=registro_vacunas.end();it++){
        if(it->second!=0){
        cout<<"  "<<it->first<<" "<<it->second<<endl;
        }
    }
}
