#include <iostream>
#include <sstream>
#include "Cambra.hpp"
#include "Control.hpp"
#include <queue>
#include <list>
using namespace std;

/*
NOTA: ACTUALIZACIONES DE LA PRIMERA ENTREGA
 - Arreglado canviar_nevera
 - Mejorada la modularización de las clases:
    · Ahora los siguientes metodos tienen return en vez de void:
        - afegir_unitats
        - treure_unitats
        - canviar_nevera
        - consultar_pos
        - afegir_vac
        - treure_vac
        - consultar_vac
        Esto quiere decir que se han tenido que adaptar algunas lineas de codigo.

 - Hemos puesto más comentarios
   - Se pueden buscar con el find (ctrl + F en algunos editores) con la palabra clave UPDATE:)

 */


int main(){

    vector <Cambra> almacen;
    int n, x, y, nevera_num, amount;
    string line, action, id;
    bool end = false;

    Control control;
    cin >> n;
    //es truca al mètode construirArbre per a generar l'arbre en preordre
    control.construirArbre(n);

    if(n!=0){ //En cas que es tracti quan no hi hagi cap cambra
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
            amount = almacen[nevera_num-1].afegir_unitats(id,amount,control.get_vacunas());;
            if(amount >= 0)   cout<<"  "<<amount<<endl;
            else cout<<"  error"<<endl;
        }
        else if(action == "treure_unitats"){
            ss >> nevera_num;
            ss >> id;
            ss >> amount;
            cout << line << endl;
            amount = almacen[nevera_num-1].treure_unitats(id,amount,control.get_vacunas());
            if(amount >= 0)   cout<<"  "<<amount<<endl;
            else cout<<"  error"<<endl;
        }        
        else if(action == "afegir_vac"){
            ss >> id;
            cout << line << endl;
            bool exist = control.afegir_vac(id);
            if(exist) cout<<"  error"<<endl;
        }
        else if(action == "treure_vac"){
            ss >> id;
            cout << line << endl;
            bool trobat = control.treure_vac(id,almacen);
            if(!trobat) cout<<"  error"<<endl;
        }      
        else if(action == "consultar_vac"){
            ss >> id;
            cout << line << endl;
            amount = control.consultar_vac(id,almacen);
            if(amount >= 0)   cout<<"  "<<amount<<endl;
            else cout<<"  error"<<endl;
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
            bool canvia = almacen[nevera_num-1].canviar_nevera(x,y);
            if(!canvia)    cout<<"  error"<<endl;
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
            cout<<"  "<<almacen[nevera_num-1].consultar_pos(x-1,y-1)<<endl;
        }
        else if(action == "distribuir"){
            ss >> id;
            ss >> amount;
            cout << line << endl;
            amount = control.distribuir(id,amount,almacen);
            if( amount >= 0)   cout<<"  "<<amount<<endl;
            else cout<<"  error"<<endl;
        }
        else if(action == "fi"){
            cout << line << endl;
            end = true;
        }      
    }
}
