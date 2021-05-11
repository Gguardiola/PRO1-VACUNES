#include <iostream>
#include <sstream>
#include "Cambra.hpp"
#include "Control.hpp"
#include "arbreBin.hpp"
#include <queue>
using namespace std;

void suma_arbre(queue<int> q)
/* Pre: a = A */
/* Post:  */
{
	arbreBin<int> ar_tmp;
	if (not q.empty()){
                cout<<q.front();
        q.pop();

        suma_arbre(q);
        cout<<"test"<<endl;
        
        if(not q.empty()) cout<<q.front()<<endl;



        if(q.empty()){


        }
		
	} 
    else cout<<"dumped"<<endl;
}
/*}


	  U node;
  int size, nf;
  std::stack<arbreBin<U> > p;

  cin >> size;  
  while (size > 0) {
    cin >> node >> nf;
    if (nf == 0) {  //fills buits
      p.push(arbreBin<U>(node, arbreBin<U>(), arbreBin<U>()));
    } else if (nf == -1) {  //nf=-1 --> nomes un fill, l'esquerre
      arbreBin<U> fe = p.top();
      p.pop();
      p.push(arbreBin<U>(node, fe, arbreBin<U>()));
    }
    else if (nf == 1) {  //nf=1 --> nomes un fill, el dret
      arbreBin<U> fd = p.top();
      p.pop();
      p.push(arbreBin<U>(node, arbreBin<U>(), fd));
    } else {  //nf=2 --> dos fills no buits
      arbreBin<U> fd = p.top();
      p.pop();
      arbreBin<U> fe = p.top();
      p.pop();
      p.push(arbreBin<U>(node, fe, fd));
    }
    --size;
  }
  if (not p.empty()) x = p.top();
  return cin;
}*/

int main(){

    queue<int> q;
    vector <Cambra> almacen;
    int n, x, y;
    Control control;
    string line, action, id;
    int nevera_num, amount;
    bool end = false;
    cin >> n;       //Nota: Com no sabem si s'ha de tractar quan no hi hagi cap nevera, hem posat un if temporal. T'ho preguntarem en la sessió 12
    int llista;
    for(int i = 0; i < n; i++){
        cin>>llista;
        q.push(llista);
    }
    cout<<"here"<<endl;
    suma_arbre(q);
    

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
