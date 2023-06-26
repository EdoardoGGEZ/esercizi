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
void bubleSort(vector<Word> &vector){
    bool esci;
    do{
        esci=true;
        for(int i=0;i<vector.size();i++){
            if(vector[i].nTimes<vector[i+1].nTimes){
                swap(vector[i],vector[i+1]);
                esci=false;
            }
        }
    }
    while(!esci);
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
        }
    }
    while(input.eof());
    input.close();
    } else{
        std::cout<<"file mancante!";
    }
    std::cout<<"[input]\n";
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
    std::cout<<"[conteggio]\n";
    //riordina i numeri
    bubleSort(words);
    std::cout<<"[sort]\n";
    //stampa le MAX parole più ripetute
    for(int i=0;i<MAX;i++){
        std::cout<<i+1<<" parola piu' ripetuta: "<<words[i].word;
    }
    return 0;
}