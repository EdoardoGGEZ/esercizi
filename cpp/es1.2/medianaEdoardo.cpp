#include<iostream>
#include<vector>

using namespace std;

//algoritmo di sorting
vector<double> bubleSort(vector<double> numbers){
    bool esc;
    do{
        esc=true;
        for(int i=0;i<numbers.size()-1;i++){
            if(numbers.at(i)>numbers.at(i+1)){
                int app=numbers.at(i);
                numbers.at(i)=numbers.at(i+1);
                numbers.at(i+1)=app;
                esc=false;
            }
        }
    }
    while(!esc);
    return numbers;
}
int main(){
    //variabili
    vector<double> numbers;
    int length;
    double median;
    bool even;

    //controllo input
    do{
        cout<<"Di quanti numeri vuoi calcolarne la mediana? minimo 2\n";
        cin>>length;
    }
    while(length<2);

    //controllo parità
    if(length%2==0)
        even=true;
    else
        even=false;

    //input numeri
    for(int i=0;i<length;i++){
        cout<<"Numero "<<i+1<<": ";
        int app;
        cin>>app;
        numbers.push_back(app);
    }

    //riordina i numeri
    numbers=bubleSort(numbers);

    //calcolo media
    if(even)
        median=(numbers.at(length/2)+numbers.at(length/2-1))/2;
    else
        median=numbers.at(length/2);
 
    //stampa
    cout<<"mediana: "<<median<<endl;
    return 0;
}