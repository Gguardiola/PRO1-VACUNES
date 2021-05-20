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
    while(i < int(vacunas.size()) and not exist){
        if(vacunas[i] == id) exist = true;
        i++;
    }
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
    return trobat;
}

arbreBin<int> Control::construirArbre(vector<int> pre, int &first, int low, int high)
/* Pre: */
/* Post: Retorna arbre amb n (=pre.size()) nodes */
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
    arbreBin<int> left = construirArbre(pre, first, low, mid - 1);
    /* HI: arbre esq */
    /* FF: mid - 1 */
    root = arbreBin<int>(root.arrel(),left, arbreBin<int>());

    arbreBin<int> right = construirArbre(pre, first, mid + 1, high);
    /* HI: arbre dret */
    /* FF: mid + 1 */
    root = arbreBin<int>(root.arrel(),left, right);

    return root;
}


void Control::construirArbre(int n)
/* Pre: */
/* Post: */
{
    vector<int> preOrd;
    int nodes, first = 0;
    for(int i = 0; i < (n*2)+1; i++){
        cin>>nodes;
        if (nodes !=0) preOrd.push_back(nodes);
    }
    arbol = construirArbre(preOrd, first, 0, preOrd.size() - 1);
}

int Control::distribuir(string id, int q, vector<Cambra> &almacen, const arbreBin<int> &arbol, int &auxq, vector<string> &Vacunas)
/* Pre: */
/* Post: */
{
    int i = 0;
    if (not arbol.es_buit() and q>0) {
        q = almacen[arbol.arrel()-1].afegir_unitats(id,q,Vacunas);
        if( q == -1 or almacen.size() == 1) return q;
        if(q%2 != 0)  i = 1;
        distribuir(id, (q/2)+i, almacen, arbol.fe(), auxq,Vacunas);
        /* HI:  */
        /* FF: arbol.fe */

        // H.I.: Afegeix a l els nodes del fill esquerra de A en preodre
        distribuir(id, q/2, almacen, arbol.fd(), auxq,Vacunas);
        /* HI:  */
        /* FF: arbol.fd */
        // H.I.: Afegeix a l els nodes del fill dret de A en preodre
        if(arbol.fe().es_buit() and arbol.fd().es_buit()) auxq += q;
    }
    return auxq;
}

int Control::distribuir(string id, int q, vector<Cambra> &almacen)
/* Pre: */
/* Post: */
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
    for (string i: vacunas){
        if(i == id) exists = true;
    }
    int cantidad = -1;
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
    for(int i = 0; i < int(vacunas.size()); ++i){
        amount = consultar_vac(vacunas[i],almacen);
        cout<<"  "<<vacunas[i]<<" "<<amount<<endl;
    }
}
