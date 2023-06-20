#include<iostream>

using namespace std;

int main(){
    int lengh, som=0, media;//variabili
    do{
        cout<<"Quanti numeri vuoi sommare e calcolarne la media? minimo 2\n";
        cin>>lengh;
    }
    while(lengh<2);//controllo input

    for(int i=0;i<lengh;i++){//input numeri e somma
        cout<<"Numero "<<i+1<<": ";
        int app;
        cin>>app;
        som+=app;
    }

    media=som/lengh;//calcolo media

    cout<<"somma: "<<som<<endl<<"media: "<<media<<endl;
    return 0;
}