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
    while(getline(cin,line)){
        istringstream ss(line);

        ss >> action;
        if(action == "escriure"){
            ss >> nevera_num;
            almacen[nevera_num-1].escriure();
        }
    }


}