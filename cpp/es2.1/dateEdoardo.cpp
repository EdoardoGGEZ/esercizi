#include<iostream>

using namespace std;

class Date {
    private:
        int day, month, year;

    public:
        Date() {day=1; month=1; year=1970;}
        Date(int day, int month, int year) {this->day=day; this->month=month; this->year=year;}
        int getDay() {return day;}
        int getMonth() {return month;}
        int getYear() {return year;}
        friend ostream& operator<<(ostream &out, Date &pt);
        friend bool operator==(Date &first, Date &second);
        friend void addDays(int n, Date d);
        friend void addMonth(int n, Date d);
        friend void addYear(int n, Date d);
        friend void adjust(Date d);
};
ostream& operator<<(ostream &out, Date &pt){
    out<<pt.day<<"-"<<pt.month<<"-"<<pt.year<<endl;
    return out;
}
bool operator==(Date &first, Date &second){
    return (first.day==second.day)&&(first.month==second.month)&&(first.year==second.year);
}
void addDays(int n, Date d){
    d.day+=n;
    adjust(d);
}
void addMonth(int n, Date d){
    d.month+=n;
    adjust(d);
}
void addYear(int n, Date d){
    d.year+=n;
    adjust(d);
}
void adjust(Date d){
    bool esci;
    do{
    esci=true;
    int days;
    if(d.month==1||d.month==3||d.month==5||d.month==7||d.month==8||d.month==10||d.month==12)
        days=31;
    else if(d.month==4||d.month==6||d.month==9||d.month==11)
        days=30;
    else
        if(d.year%4==0)
            days=29;
        else
            days=28;

    if(d.day>days){
        esci=false;
        d.day-=days;
        d.month++;
    }

    if(d.month>12){
        esci=false;
        d.month-=12;
        d.year++;
    }
    }
    while(!esci);
}
int main(){
    cout<<"1) inserire data\n2) data default (1 gen 1970)\n";
    int scelta;
    Date date;
    cin>>scelta;
    if(scelta==1){
        int anno, mese, giorno;
        cout<<"anno?\n";
        cin>>anno;
        cout<<"mese?\n";
        cin>>mese;
        cout<<"giorno?\n";
        cin>>giorno;
        Date date {giorno, mese, anno};
    }
    
    do{
        cout<<"1) informazine\n2) data\n3) confronto data\n4) tempo passato\n0) esci\n";//raw string
        cin>>scelta;
        switch (scelta)
        {
        case 1:
            int app;
            cout<<"1) anno\n2) mese\n3) giorno\n";
            cin>>app;
            if(app==1)
                cout<<date.getYear()<<endl;
            else if(app==2)
                cout<<date.getMonth()<<endl;
            else
                cout<<date.getDay()<<endl;
            break;
        case 2:
            cout<<date;
            break;
        case 3:{
            int anno, mese, giorno;
            cout<<"anno?\n";
            cin>>anno;
            cout<<"mese?\n";
            cin>>mese;
            cout<<"giorno?\n";
            cin>>giorno;
            Date date2 {giorno, mese, anno};
            if(date==date2)
                cout<<"le date coincidono\n";
            else
                cout<<"le date non coincidono\n";
            break;
            }
        case 4:{
            cout<<"1) giorni\n2) mesi\n3) anni\n";
            cin>>app;
            int n;
            if(app==1){
                do{
                    cout<<"quanti giorni sono passati?";
                    cin>>n;
                }
                while(!(n>=0));
                addDays(n,date);
            }
            else if(app=2){
                do{
                    cout<<"quanti mesi sono passati?";
                    cin>>n;
                }
                while(!(n>=0));
                addMonth(n,date);
            }
            else{
                do{
                    cout<<"quanti anni sono passati?";
                    cin>>n;
                }
                while(!(n>=0));
                addYear(n,date);
            }
            break;
            }
        }
    }
    while(scelta!=0);
}