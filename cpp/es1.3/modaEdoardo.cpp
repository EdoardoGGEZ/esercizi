#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <map>
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
        for(int i=0;i<vector.size()-1;i++){
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

    std::map<std::string, int> words_map;

    //input parole
    if(input.is_open()){
        while (!input.eof()) {
            Word add={"",1};
            int letter;
            add.word.clear();
            letter=input.get();
            if (letter == std::char_traits<char>::eof())
                break;
            while(letter!=' '&&letter!='\n'&&letter!='.'&&letter!=','&&letter!=';'&&letter!=':'&&letter!='\''&&letter!='!'&&letter!='\"'){
                add.word+=letter;
                letter=input.get();
            }
            if(add.word.size()>3){
                words_map[add.word] ++;
            }
        }
        input.close();
    } else {
        std::cout<<"file mancante!";
    }
    std::cout<<"[input]\n";
    //ciclo conteggio parole

    for (const auto &pair : words_map) {
        words.push_back({pair.first, pair.second});
    }
    std::cout<<"[conteggio]\n";
    //riordina i numeri
    bubleSort(words);
    std::cout<<"[sort]\n";
    //stampa le MAX parole più ripetute
    for(int i=0;i<MAX;i++){
        std::cout<<i+1<<" parola piu' ripetuta: "<<words[i].word << endl;
    }
    return 0;
}