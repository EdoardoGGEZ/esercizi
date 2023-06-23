#include<iostream>
#include<vector>
#include<string>
#define MAX 10

using namespace std;

//algoritmo di sorting
vector<unsigned> bubleSort(vector<unsigned> n){
    bool esci;
    do{
        esci=true;
        for(int i=0;i<n.size()-1;i++){
            if(n.at(i)>n.at(i+1)){
                int app=n.at(i);
                n.at(i)=n.at(i+1);
                n.at(i+1)=app;
                esci=false;
            }
        }
    }
    while(!esci);
    return n;
}
int main(){
    //input da file
    freopen("canto1.txt","r",stdin);

    //variabili
    bool esci =false;
    vector<string> parole;
    vector<unsigned> nParole;
    //input parole
    do{
        string app;
        cin>>app;
        if(app.size()>3)
            parole.push_back(app);
    }
    while(!esci);

    // Suggerimento: usare `std::map` o `std::unordered_map`

    //ciclo delle parole
    for(int i=0;i<parole.size();i++){
        string app=parole.at(i);
        nParole.push_back(1);
        for(int j=i+1;i<parole.size();j++){
            if(parole.at(j)==app){
                nParole.at(i)++;
                //parole.erase(j);
            }
        }
    }

    //riordina i numeri
    vector<unsigned> ordine=bubleSort(nParole);

    //stampa le MAX parole più ripetute
    for(int i=0;i<MAX;i++){
        string parola;
        for(int j=0;j<nParole.size();j++){
            if(nParole.at(j)==ordine.at(i)){
                parola=parole.at(j);
                //parole.erase(j);
                //nParole.erase(j);
                j--;
            }
        }
        cout<<i<<" parola piu' ripetuta: "<<parola;
    }

    return 0;
}