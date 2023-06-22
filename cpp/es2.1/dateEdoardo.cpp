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
        void addDays(int n){
            day+=n;
            adjust();
        }
        void addMonth(int n){
            month+=n;
            adjust();
        }
        void addYear(int n){
            year+=n;
            adjust();
        }
        void adjust(){
        bool esc;
        do{
            esc=true;
            int days;
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                days=31;
            else if(month==4||month==6||month==9||month==11)
                days=30;
            else
                if(year%4==0)
                    days=29;
                else
                    days=28;

            if(day>days){
                esc=false;
                day-=days;
                month++;
            }

            if(month>12){
                esc=false;
                month-=12;
                year++;
            }
        }
        while(!esc);
    }
};
ostream& operator<<(ostream &out, Date &pt){
    out<<pt.day<<"-"<<pt.month<<"-"<<pt.year<<endl;
    return out;
}
bool operator==(Date &first, Date &second){
    return (first.day==second.day)&&(first.month==second.month)&&(first.year==second.year);
}

int main(){
    cout<<"1) inserire data\n2) data default (1 gen 1970)\n";
    int scelta;
    Date date;
    cin>>scelta;
    if(scelta==1){
        int year, month, day;
        cout<<"year?\n";
        cin>>year;
        cout<<"month?\n";
        cin>>month;
        cout<<"day?\n";
        cin>>day;
        Date date {day, month, year};
    }
    
    do{
        cout<<"1) informazine\n2) data\n3) confronto data\n4) tempo passato\n0) esc\n";//raw string
        cin>>scelta;
        switch (scelta)
        {
        case 1:
            int app;
            cout<<"1) year\n2) month\n3) day\n";
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
            int year, month, day;
            cout<<"year?\n";
            cin>>year;
            cout<<"month?\n";
            cin>>month;
            cout<<"day?\n";
            cin>>day;
            Date date2 {day, month, year};
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
                date.addDays(n);
            }
            else if(app=2){
                do{
                    cout<<"quanti mesi sono passati?";
                    cin>>n;
                }
                while(!(n>=0));
                date.addMonth(n);
            }
            else{
                do{
                    cout<<"quanti anni sono passati?";
                    cin>>n;
                }
                while(!(n>=0));
                date.addYear(n);
            }
            break;
            }
        }
    }
    while(scelta!=0);
}