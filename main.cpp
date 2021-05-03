#include <iostream>
#include <sstream>
#include "Cambra.hpp"
#include "Control.hpp"
using namespace std;

int main(){

    vector <Cambra> almacen;
    int n,x,y;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>x>>y;
        almacen.push_back(Cambra(x,y));
    } 

    Control control;
    string line, action, id;
    int nevera_num, amount;

    while(getline(cin,line) and action != "fi"){
        istringstream ss(line);
        ss >> action;
        if(action == "escriure"){
            ss >> nevera_num;
            cout<<line<<endl;
            almacen[nevera_num-1].escriure();
        }
        else if(action == "afegir_unitats"){
            ss>>nevera_num;
            ss>>id;
            ss>>amount;
            cout<<line<<endl;
            almacen[nevera_num-1].afegir_unitats(id,amount,control.get_vacunas());

        }
        else if(action == "treure_unitats"){
            ss>>nevera_num;
            ss>>id;
            ss>>amount;
            cout<<line<<endl;
            almacen[nevera_num-1].treure_unitats(id,amount,control.get_vacunas());

        }        
        else if(action == "afegir_vac"){
            ss>>id;
            cout<<line<<endl;
            control.afegir_vac(id);
        }
        else if(action == "treure_vac"){
            ss>>id;
            cout<<line<<endl;
            control.treure_vac(id);
        }      
        else if(action == "consultar_vac"){
            ss>>id;
            cout<<line<<endl;
            cout<<"  ";
            control.consultar_vac(id,almacen);
        }  
        else if(action == "inventari"){
            ss>>id;
            cout<<line<<endl;
            control.inventari(almacen);
        }
        else if(action == "canviar_nevera"){
            ss>>nevera_num;
            ss>>x;
            ss>>y;
            cout<<line<<endl;
            almacen[nevera_num-1].canviar_nevera(x,y);
        }
        else if(action == "comprimir"){
            ss>>nevera_num;
            cout<<line<<endl;
            almacen[nevera_num-1].comprimir();
        }   
        else if(action == "ordenar"){
            ss>>nevera_num;
            cout<<line<<endl;
            almacen[nevera_num-1].ordenar();
        }
        else if(action == "consultar_pos"){
            ss>>nevera_num;
            ss>>x;
            ss>>y;
            cout<<line<<endl;
            almacen[nevera_num-1].consultar_pos(x-1,y-1);

        } 
              
    }
    cout<<"fi"<<endl; //había un <<line y no salía el fi

}