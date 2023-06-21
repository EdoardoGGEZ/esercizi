#include<iostream>
#include<vector>
#include<string>
#define MAX 10

using namespace std;

vector<unsigned> bubleSort(vector<unsigned> n){//algoritmo di sorting
    bool esci;
    do{
        esci=true;//condizione di uscita
        for(int i=0;i<n.size()-1;i++){
            if(n.at(i)>n.at(i+1)){//se il vector non è in ordine
                int app=n.at(i);
                n.at(i)=n.at(i+1);
                n.at(i+1)=app;
                esci=false;//condizione di uscita falsa
            }
        }
    }
    while(!esci);
    return n;
}
int main(){
    freopen("canto1.txt","r",stdin);//input da file

    bool esci =false;//variabili
    vector<string> parole;
    vector<unsigned> nParole;
    do{//input parole
        string app;
        cin>>app;
        if(app.size()>3)//controllo parola
            parole.push_back(app);
    }
    while(!esci);

    // Suggerimento: usare `std::map` o `std::unordered_map`

    for(int i=0;i<parole.size();i++){//ciclo delle parole
        string app=parole.at(i);
        nParole.push_back(1);
        for(int j=i+1;i<parole.size();j++){//conto delle parole doppioni
            if(parole.at(j)==app){
                nParole.at(i)++;
            //    parole.erase(j);
            }
        }
    }

    vector<unsigned> ordine=bubleSort(nParole);//riordina i numeri

    for(int i=0;i<MAX;i++){//scrive le MAX parole più ripetute
        string parola;
        for(int j=0;j<nParole.size();j++){
            if(nParole.at(j)==ordine.at(i)){
                parola=parole.at(j);
            //    parole.erase(j);
            //    nParole.erase(j);
                j--;
            }
        }
        cout<<i<<" parola piu' ripetuta: "<<parola;
    }

    return 0;
}