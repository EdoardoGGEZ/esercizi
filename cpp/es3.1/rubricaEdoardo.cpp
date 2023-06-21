#include<iostream>
#include<vector>

using namespace std;

struct Contact {
    string nome, cognome;
    long long numero;
    friend ostream& operator<<(ostream &out, Contact &pt);
};
class PhoneBook
{
private:
    vector<Contact> contatti;
public:
    void append(Contact add){contatti.push_back(add);}
    Contact* find(string nome){
        Contact *pt;
        for (int i = 0; i < contatti.size(); i++){
            if(contatti[i].nome==nome){
                pt=&contatti[i];
            }
        }
        return pt;
    }
    vector<Contact> filter(int scelta){
        vector<Contact> ris;
        switch (scelta)
        {
        case 1:
            string lett;
            cout<<"iniziale del nome: ";
            cin>>lett;
            ris=nameStartWith(lett);
            break;
        }
    }
    vector<Contact> nameStartWith(string lett){
        vector<Contact> ris;
        for(int i=0;i<contatti.size();i++){
            if(contatti[i].nome==lett)
                ris.push_back(contatti[i]);
        }
        return ris;
    }
    friend ostream& operator<<(ostream &out, PhoneBook &pt);
};
ostream& operator<<(ostream &out, Contact &pt){
    out<<"nome: "<<pt.nome<<" cognome: "<<pt.cognome<<" numero di telefono: "<<pt.numero<<endl;
    return out;
}
ostream& operator<<(ostream &out, PhoneBook &pt){
    for (int i = 0; i < pt.contatti.size(); i++)
    {
        out<<pt.contatti[i]<<endl;
    }
    return out;
}
int main(){
    PhoneBook rubrica=PhoneBook();
    int scelta;
    do{
        cout<<"aggiungere numero? 1)si 2)no\n";
        cin>>scelta;
        if(scelta==1){
            string nome,cognome;
            long long numero;
            cout<<"nome? ";
            cin>>nome;
            cout<<"cognome? ";
            cin>>cognome;
            cout<<"numero di telefono? ";
            cin>>numero;
            Contact app={nome,cognome,numero};
            rubrica.append(app);
        }
    }
    while(scelta!=2);

    string cognome;
    cout<<"nome di un contatto: ";
    cin>>cognome;
    Contact *contatto=rubrica.find(cognome);
    cout<<*contatto;

    cout<<endl<<endl<<rubrica;

    do{
        cout<<"1) filtro per nome 0)esci"<<endl;
        cin>>scelta;
        vector<Contact> app=rubrica.filter(scelta);
    }
    while(scelta!=0);
}