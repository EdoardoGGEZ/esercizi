#include<iostream>
#include<vector>

using namespace std;

vector<double> bubleSort(vector<double> n){//algoritmo di sorting
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
    vector<double> n;
    int lengh, som=0;//variabili
    double mediana;
    bool pari;
    do{
        cout<<"Quanti numeri vuoi calcolarne la mediana? minimo 2\n";
        cin>>lengh;
    }
    while(lengh<2);//controllo input

    if(lengh%2==0)
        pari=true;
    else
        pari=false;

    for(int i=0;i<lengh;i++){//input numeri
        cout<<"Numero "<<i+1<<": ";
        int app;
        cin>>app;
        n.push_back(app);
    }

    n=bubleSort(n);//riordina i numeri

    if(pari)
        mediana=(n.at(lengh/2)+n.at(lengh/2-1))/2;
    else
        mediana=n.at(lengh/2);

    cout<<"mediana: "<<mediana<<endl;
    return 0;
}