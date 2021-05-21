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

bool Control::afegir_vac(string id)
/* Pre: la id de la vacuna NO ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna ja existia, es produeix un error; sinó, la vacuna es dona d'alta
en el sistema amb 0 unitats */
{
    bool exist = false;
    int i = 0;
    //UPDATE: Es mira si existeix la vacuna
    while(i < int(vacunas.size()) and not exist){
        if(vacunas[i] == id) exist = true;
        i++;
    }
    //UPDATE: afegim la vacuna al vector vacunas
    if(!exist){
        vacunas.push_back(id);
        sort(vacunas.begin(),vacunas.end());
    }
    return exist;
}

bool Control::treure_vac(string id, vector<Cambra> &almacen)
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: si la vacuna no existeix, o existeix i en queden unitats, es produeix un error.
En cas contrari, la vacuna es dona de baixa del sistema */
{
    bool trobat = false;    
    int i = 0, cantidad = 0;
    vector<string>::iterator it = vacunas.begin();
    //UPDATE: sumem les quantitats per obtenir la total
    for(unsigned int i = 0; i < almacen.size(); i++){
        cantidad += almacen[i].consultar_cantidad(id);      //consultar_cantidad explicat en Cambra.cpp
    }
    //UPDATE: es mira si existeix la vacuna i guardem la posició del it
    while(i < int(vacunas.size()) and not trobat){
        if(vacunas[i] == id) trobat = true;
        else {
            i++;
            it++;
        }
    }
    //UPDATE: eliminem l'element del vector vacunas
    if(trobat and cantidad==0) {
        vacunas.erase(it);
    }
    return trobat;
}

arbreBin<int> Control::construirArbre(vector<int> pre, int &first, int low, int high)
/* Pre: L'entrada consisteix en rebre el vector amb els valors en preordre, la posició del primer element 
i les posicions del nombre més petit i del més gran */
/* Post: el resultat es un arbre binari on el seu nombre de nodes equival al tamany del nostre vector, ordenat en preordre a partir dels mateixos valors que el vector pre */
{
    // Caso base
    if (first >= pre.size() or low > high)
        return arbreBin<int>();
    // La primera posició del vector es l'arrel, llavors 
    // ho construim i avancem de posició
    arbreBin<int> root = arbreBin<int>(pre[first],arbreBin<int>(),arbreBin<int>());
    first++;
    
    //Si el nostre vector només te 1 valor, s'acaba
    if (pre.size() == 1) return root;

    // "mid" es la meitat del nostre vector
    int mid = (low + high)/2;

    // i l'utilitzarem per dividir el vector en dues parts,
    // l'arbre de l'esquerra i el de la dreta
    arbreBin<int> left = construirArbre(pre, first, low, mid - 1);      //Ex. visual: 1 2 -> 4 <- 5 3 6 7 || 1 -> 2 4 5 <- 3 6 7 || 1 2 4 5 3 -> 6 <- 7 
    /* HI: el resultat es un arbre binari on el seu nombre de nodes equival al tamany dels elements del nostre vector que pertanyen a l'arbre esquerra, 
    ordenat en preordre a partir dels mateixos valors que el vector pre */
    /* FF: es redueix el valor de mid (el parametre high equival a mid - 1)*/
    root = arbreBin<int>(root.arrel(),left, arbreBin<int>());
    
    arbreBin<int> right = construirArbre(pre, first, mid + 1, high);    //Ex. visual: 1 2 4 -> 5 <- 3 6 7 || 1 2 4 5 3 6 -> 7 <- || 1 2 4 5 -> 3 6 7 <-
    /* HI: el resultat es un arbre binari on el seu nombre de nodes equival al tamany dels elements del nostre vector que pertanyen a l'arbre dret, 
    ordenat en preordre a partir dels mateixos valors que el vector pre */
    /* FF: s'augmenta el valor de mid (el parametre low equival a mid + 1)*/
    root = arbreBin<int>(root.arrel(),left, right);
    
    return root;
}


void Control::construirArbre(int n)
/* Pre: cert */
/* Post: el resultat es un arbre binari on el seu nombre de nodes equival al tamany del nostre vector, ordenat en preordre a partir dels mateixos valors que el vector pre */
{
    vector<int> preOrd;
    int nodes, first = 0;
    //Construim el vector en preordre
    for(int i = 0; i < (n*2)+1; i++){
        cin>>nodes;
        if (nodes !=0) preOrd.push_back(nodes);
    }
    arbol = construirArbre(preOrd, first, 0, preOrd.size() - 1);
}

int Control::distribuir(string id, int q, vector<Cambra> &almacen, const arbreBin<int> &a, int &auxq, vector<string> &Vacunas)
/* Pre: a = A, q > 0*/
/* Post: retorna un enter que indiqui quantes unitats no han cabut en totes les cambres */
{
    int i = 0;
    if (not a.es_buit() and q > 0) {
        //Actualitzem q amb les unitats que no han cabut
        q = almacen[a.arrel()-1].afegir_unitats(id,q,Vacunas);
        if( q == -1 or almacen.size() == 1) return q;   //-1 és una bona senyalització per donar a entendre que s'ha produït un error
        if(q%2 != 0)  i = 1;
        distribuir(id, (q/2)+i, almacen, a.fe(), auxq,Vacunas);
        /* HI: el resultat és un enter que indica quantes unitats no han cabut en cada node de l'arbre esquerra */
        /* FF: mida de l'arbre esquerra */
        distribuir(id, q/2, almacen, a.fd(), auxq,Vacunas);
        /* HI: el resultat és un enter que indica quantes unitats no han cabut en cada node de l'arbre dret */
        /* FF: mida de l'arbre dret */
        if(a.fe().es_buit() and a.fd().es_buit()) auxq += q;
    }
    return auxq;
}

int Control::distribuir(string id, int q, vector<Cambra> &almacen)
/* Pre: cert */
/* Post: retorna un enter que indiqui quantes unitats no han cabut en totes les cambres */
{
int auxq = 0;
q = distribuir(id, q, almacen, arbol, auxq, vacunas);
return q;
}

vector<string> Control::get_vacunas() const
/* Pre: cert */
/* Post: retorna el vector de strings amb les IDs de les vacunes */
{
    return vacunas;
}

int Control::consultar_vac(string id, vector<Cambra> &almacen) const
/* Pre: la id de la vacuna ha d'existir en el vector on estan totes les vacunes declarades */
/* Post: Si la vacuna no existeix, es produeix un error. En cas contrari, escriu
quantes unitats hi ha en total al magatzem */
{
    bool exists = false;
    //UPDATE: Es mira si existeix la vacuna
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    int cantidad = -1;  //UPDATE: -1 és una bona senyalització per donar a entendre que s'ha produït un error
    //UPDATE: sumem les quantitats per obtenir la total
    if(exists){
        cantidad = 0;
        for(unsigned int i = 0; i < almacen.size(); i++){
            cantidad += almacen[i].consultar_cantidad(id);      //consultar_cantidad explicat en Cambra.cpp
        }
    }
    return cantidad;
}

void Control::inventari(vector<Cambra> &almacen) const
/* Pre: cert */
/* Post: Per cada tipus de vacuna que hi hagi en el sistema s'escriu el seu id
i la quantitat total en el magatzem, ordenat per identificador de vacuna */
{
    int amount = 0;
    //UPDATE: mostrem per pantalla les id de les vacunes i les seves quantitats
    for(int i = 0; i < int(vacunas.size()); ++i){
        amount = consultar_vac(vacunas[i],almacen);
        cout<<"  "<<vacunas[i]<<" "<<amount<<endl;
    }
}
