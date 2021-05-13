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

arbreBin<int> Control::i_construirArbre(vector<int> pre, int &first, int low, int high)
// Pre:
//Post:
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
    arbreBin<int> left = i_construirArbre(pre, first, low, mid - 1);
    root = arbreBin<int>(root.arrel(),left, arbreBin<int>());

    arbreBin<int> right = i_construirArbre(pre, first, mid + 1, high);
    root = arbreBin<int>(root.arrel(),left, right);

    return root;
}


void Control::construirArbre(vector<int> preOrd)
// Pre:
// Post:
{
    int first = 0;
    arbol = i_construirArbre(preOrd, first, 0, preOrd.size() - 1);
    //cout<<arbol<<endl;
}

int Control::distribuir(string id, int q, vector<Cambra> &almacen)
// Pre:
// Post:
{//       40
//        1   
//        39
//      20 19
//      2   3
//      16 10
//    8  8 5  5
//    4  5 6  7
//    0  0 0  0 + = cout<<0

int auxq = 0;
q = rec_preordre(id, q, almacen, arbol, auxq);
return q;
}


int Control::rec_preordre(string id, int q, vector<Cambra> &almacen, const arbreBin<int> &arbol, int &auxq)
// Pre: 
// Post: 
{
    int i = 0;
    if (not arbol.es_buit() and q>0) {
        q = almacen[arbol.arrel()-1].afegir_unitats(id,q,vacunas);
        if( q == -1 or almacen.size() == 1) return q;
        //cout<<"recursivo";
        if(q%2 != 0)  i = 1;
        rec_preordre(id, (q/2)+i, almacen, arbol.fe(), auxq);
        
        // H.I.: Afegeix a l els nodes del fill esquerra de A en preodre
        rec_preordre(id, q/2, almacen, arbol.fd(), auxq);
        // H.I.: Afegeix a l els nodes del fill dret de A en preodre
        if(arbol.fe().es_buit() and arbol.fd().es_buit()) auxq += q;
    }

    return auxq;
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