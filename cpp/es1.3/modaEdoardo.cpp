#include<iostream>
#include<fstream>
#include<vector>
#include<string>
//MAX parole più ripetute
#define MAX 10

using namespace std;

//struct dove salvare le parole
struct Word
{
    string word;
    int nTimes;
};

//algoritmo di sorting
vector<unsigned> bubleSort(vector<unsigned> numbers){
    bool esci;
    do{
        esci=true;
        for(int i=0;i<numbers.size()-1;i++){
            if(numbers.at(i)>numbers.at(i+1)){
                int app=numbers.at(i);
                numbers.at(i)=numbers.at(i+1);
                numbers.at(i+1)=app;
                esci=false;
            }
        }
    }
    while(!esci);
    return numbers;
}
int main(){
    //input da file
    ifstream input ("../canto1.txt");

    //variabili
    vector<Word> words;

    //input parole
    if(input.is_open()){
    do{
        Word add={"",1};
        char letter;
        add.word.clear();
        letter=input.get();
        while(letter!=' '&&letter!='\n'&&letter!='.'&&letter!=','&&letter!=';'&&letter!=':'&&letter!='\''&&letter!='!'&&letter!='\"'){
            add.word+=letter;
            letter=input.get();
        }
        if(add.word.size()>3){
            words.push_back(add);
            std::cout<<add.word<<endl;
        }
    }
    while(input.good());
    input.close();
    } else{
        std::cout<<"file mancante!";
    }

    //ciclo conteggio parole
    for(int i=0;i<words.size();i++){
        string app=words[i].word;
        for(int j=i+1;i<words.size();j++){
            if(words[j].word==app){
                words[i].nTimes++;
                words.erase(words.begin()+j);
            }
        }
    }
    /*
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
*/
    return 0;
}