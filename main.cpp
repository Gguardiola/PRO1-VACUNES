#include <iostream>
#include <sstream>
#include "Nevera.hpp"
#include "Control.hpp"
using namespace std;

int main(){

    vector<Nevera> almacen;
    int n,x,y;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        almacen.push_back(Nevera(x,y));
    } 

    Control control;

    string line;
    string action;
    int nevera_num;    
    string id;
    int amount;
    while(getline(cin,line)){
        istringstream ss(line);

        ss >> action;
        if(action == "escriure"){
            ss >> nevera_num;
            almacen[nevera_num-1].escriure();
        }
        else if(action == "afegir_unitats"){
            ss>>nevera_num;
            ss>>id;
            ss>>amount;
            almacen[nevera_num-1].afegir_unitats(id,amount,control.get_vacunas());

        }
        else if(action == "treure_unitats"){
            ss>>nevera_num;
            ss>>id;
            ss>>amount;
            almacen[nevera_num-1].treure_unitats(id,amount,control.get_vacunas());

        }        
        else if(action == "afegir_vac"){
            ss>>id;
            control.afegir_vac(id);
        }
        else if(action == "treure_vac"){
            ss>>id;
            control.treure_vac(id);
        }      
        else if(action == "consultar_vac"){
            ss>>id;
            control.consultar_vac(id,almacen);
        }  
        else if(action == "inventari"){
            ss>>id;
            control.inventari(almacen);
        }          
    }


}