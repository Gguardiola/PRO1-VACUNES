#include <iostream>
#include <sstream>
#include "Cambra.hpp"
#include "Control.hpp"
#include "arbreBin.hpp"
#include <queue>
#include <list>
using namespace std;
/*
// A function that constructs Balanced
//Binary Search Tree from a sorted array 
arbreBin<int> sortedArrayToBST(vector<int> arr, int start, int end) 
{ 
    // Base Case 
    if (start > end) 
    return arbreBin<int>(); 
  
    // Get the middle element and make it root /
    int mid = (start + end)/2; 
    arbreBin<int> root = arbreBin<int>(arr[i], arbreBin<int>(), arbreBin<int>()); 
    //cout<<"root"<<endl<<root<<endl;
    
    // Recursively construct the left subtree 
    //and make it left child of root /
    arbreBin<int> left = sortedArrayToBST(arr, start, mid - 1); 
    root = arbreBin<int>(root.arrel(),left, arbreBin<int>());
    // Recursively construct the right subtree 
    //and make it right child of root /
    arbreBin<int> right = sortedArrayToBST(arr, mid + 1, end); 
    root = arbreBin<int>(root.arrel(),left, right);
    return root; 
}*/

// A recursive function to construct Full from pre[].
// preIndex is used to keep track of index in pre[].
arbreBin<int> construirArbre(vector<int> pre, int &first, int low, int high)
{
    // Caso base
    if (first >= pre.size() || low > high)
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
    root = arbreBin<int>(root.arrel(),left, arbreBin<int>());

    arbreBin<int> right = construirArbre(pre, first, mid + 1, high);
    root = arbreBin<int>(root.arrel(),left, right);

    return root;
}










/*
// The main function that constructs 
//balanced BST and returns root of it. 
//head_ref --> Pointer to pointer to 
//head node of linked list n --> No.
//of nodes in Linked List 
arbreBin<int> sortedListToBSTRecur(list<int> head_ref,const int n) 
{ 
    // Base Case 
    if (n <= 0) {
        cout<<"esta vacio"<<endl;
        return arbreBin<int>(); 
        
    }
    // Recursively construct the left subtree 
    arbreBin<int> left = sortedListToBSTRecur(head_ref, n/2); 
    cout<<"left "<<endl<<left<<endl;
    // Allocate memory for root, and 
    //link the above constructed left 
    //subtree with root 
    arbreBin<int> root = arbreBin<int>(*(head_ref.begin()), left, arbreBin<int>()); 
    cout<<"root "<<endl<<root<<endl;
  
    // Change head pointer of Linked List
    //for parent recursive calls 
    head_ref.erase(head_ref.begin());
  
    // Recursively construct the right 
    //    subtree and link it with root 
    //    The number of nodes in right subtree
    //    is total nodes - nodes in 
    //    left subtree - 1 (for root) which is n-n/2-1
    root = arbreBin<int>(*(head_ref.begin()), left, sortedListToBSTRecur(head_ref, n - n / 2 - 1)); 
    cout<<"right "<<endl<<root<<endl;
    //root->right = sortedListToBSTRecur(head_ref, n - n / 2 - 1); 
  
    return root; 
} */









int main(){

    vector<int> q;

    vector <Cambra> almacen;
    int n, x, y;
    Control control;
    string line, action, id;
    int nevera_num, amount;
    bool end = false;
    cin >> n;       //Nota: Com no sabem si s'ha de tractar quan no hi hagi cap nevera, hem posat un if temporal. T'ho preguntarem en la sessió 12
    
    int llista;
    for(int i = 0; i < (n*2)+1; i++){
        cin>>llista;
        if (llista !=0) q.push_back(llista);
    }
    
    int first = 0;
    arbreBin<int> lele = construirArbre(q, first, 0, n-1);
    cout<<"funcion"<<endl<<lele<<endl;
    
    if(n!=0){
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            almacen.push_back(Cambra(x,y));
        } 
    }else{
        end=true;
        cout<<"fi"<<endl;
    }


    while(not end and getline(cin,line)){
        istringstream ss(line);
        ss >> action;
        if(action == "escriure"){
            ss >> nevera_num;
            cout << line << endl;
            almacen[nevera_num-1].escriure();
        }
        else if(action == "afegir_unitats"){
            ss >> nevera_num;
            ss >> id;
            ss >> amount;
            cout << line << endl;
            almacen[nevera_num-1].afegir_unitats(id,amount,control.get_vacunas());
        }
        else if(action == "treure_unitats"){
            ss >> nevera_num;
            ss >> id;
            ss >> amount;
            cout << line << endl;
            almacen[nevera_num-1].treure_unitats(id,amount,control.get_vacunas());
        }        
        else if(action == "afegir_vac"){
            ss >> id;
            cout << line << endl;
            control.afegir_vac(id);
        }
        else if(action == "treure_vac"){
            ss >> id;
            cout << line << endl;
            control.treure_vac(id,almacen);
        }      
        else if(action == "consultar_vac"){
            ss >> id;
            cout << line << endl;
            cout<<"  ";
            control.consultar_vac(id,almacen);
        }  
        else if(action == "inventari"){
            ss >> id;
            cout << line << endl;
            control.inventari(almacen);
        }
        else if(action == "canviar_nevera"){
            ss >> nevera_num;
            ss >> x;
            ss >> y;
            cout << line << endl;
            almacen[nevera_num-1].canviar_nevera(x,y);
        }
        else if(action == "comprimir"){
            ss >> nevera_num;
            cout << line << endl;
            almacen[nevera_num-1].comprimir();
        }   
        else if(action == "ordenar"){
            ss >> nevera_num;
            cout << line << endl;
            almacen[nevera_num-1].ordenar();
        }
        else if(action == "consultar_pos"){
            ss >> nevera_num;
            ss >> x;
            ss >> y;
            cout << line << endl;
            almacen[nevera_num-1].consultar_pos(x-1,y-1);
        }
        else if(action == "fi"){
            cout << line << endl;
            end = true;
        }      
    }
}




/*arbreBin<int> rec_preordre(queue<int> &q, int start, int end)
// Pre: a = A, l = L 
// Post: a L s'han afegit al final els nodes d'A recorreguts en preordre 

{
    arbreBin<int> ar_tmp, vacio;
	int mid = (start + end) / 2;
    if(not q.empty()){

    //ar_tmp = arbreBin<int>(ar_tmp, vacio, vacio);
    int x = q.front();
    
    arbreBin<int> afe = rec_preordre(q, start, mid - 1); 
    
    arbreBin<int> afd = rec_preordre(q, mid + 1, end); 

    ar_tmp = arbreBin<int>(x, afe, afd);
    }

	//if(p.empty()){
	//	sum=0;
	//}else{
		//int x = p.top();
		//p.pop();
		//int sum1= sumaPila(p);
		// HI: sum1 es la suma del elements de P tret del cim 
		// Fita: la mida de p 
		//sum= sum1 + x;
	//}
	return ar_tmp;
}*/
