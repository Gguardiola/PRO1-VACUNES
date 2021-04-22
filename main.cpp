#include <iostream>
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
    


}