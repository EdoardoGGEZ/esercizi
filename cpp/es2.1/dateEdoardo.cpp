#include<iostream>

using namespace std;

//classe Date
class Date {
    private:
        //attributi
        int day;
        int month;
        int year;

    public:
        //costruttori
        Date() {day=1; month=1; year=1970;}
        Date(int day, int month, int year) {this->day=day; this->month=month; this->year=year;}
        //getters
        int getDay() {return day;}
        int getMonth() {return month;}
        int getYear() {return year;}
        //friends
        friend ostream& operator<<(ostream &out, Date &pt);
        friend bool operator==(Date &first, Date &second);
        //modifica
        void addDays(int n){
            day+=n;
            adjust();
        }
        void addMonth(int n){
            month+=n;
            while(month<1||month>12){
                if(month<1){
                    month+=12;
                    year--;
                }
                if(month>12){
                    month-=12;
                    year++;
                }
            }
            adjust();
        }
        void addYear(int n){
            year+=n;
            adjust();
        }
        //sistema data
        void adjust(){
        bool esc;
        do{
            esc=true;
            int months[12]{31,28,31,30,31,30,31,31,30,31,30,31};
            if(year%4==0)
                months[1]=29;

            if(day>months[month-1]){
                esc=false;
                day-=months[month-1];
                month++;
            }
            else if(day<1){
                esc=false;
                if (month==1)
                    day+=months[11];
                else
                    day+=months[month-2];
                month--;
            }

            if(month>12){
                esc=false;
                month-=12;
                year++;
            }
            else if(month<1){
                esc=false;
                month+=12;
                year--;
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
    //test costruttore default
    {    cout<<"\n[costruttore di default]";
        Date test;
        if(test.getDay()==1&&test.getMonth()==1&&test.getYear()==1970)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    //test costruttore
    {
        cout<<"\n[costruttore]";
        Date test{26,11,2005};
        if(test.getDay()==26&&test.getMonth()==11&&test.getYear()==2005)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    //test operator==
    {
        cout<<"\n[operator==]";
        Date test1{15,6,1990};
        Date test2{15,6,1990};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{15,7,1990};
        Date test2{15,6,1990};
        if(test1==test2)
            cout<<"\n[FAIL]";
        else
            cout<<"\n[OK]";
    }
    {
        Date test1{16,6,1990};
        Date test2{15,6,1990};
        if(test1==test2)
            cout<<"\n[FAIL]";
        else
            cout<<"\n[OK]";
    }
    {
        Date test1{15,6,1990};
        Date test2{15,6,1989};
        if(test1==test2)
            cout<<"\n[FAIL]";
        else
            cout<<"\n[OK]";
    }
    //test add days
    {
        cout<<"\n[addDays]";
        Date test1{20,1,2000};
        test1.addDays(6);
        Date test2{26,1,2000};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{30,6,2007};
        test1.addDays(87);
        Date test2{25,9,2007};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{20,1,2000};
        test1.addDays(-10);
        Date test2{10,1,2000};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{1,1,2000};
        test1.addDays(-32);
        Date test2{30,11,1999};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    //test addMonth
    {
        cout<<"\n[addMonth]";
        Date test1{20,1,2000};
        test1.addMonth(3);
        Date test2{20,4,2000};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{13,11,2022};
        test1.addMonth(21);
        Date test2{13,8,2024};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{30,3,1977};
        test1.addMonth(-1);
        Date test2{2,3,1977};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{29,2,2012};
        test1.addMonth(-48);
        Date test2{29,2,2008};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    //test addYear
    {
        cout<<"\n[addYear]";
        Date test1{20,1,2000};
        test1.addYear(2);
        Date test2{20,1,2002};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{29,2,2004};
        test1.addYear(7);
        Date test2{1,3,2011};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{1,4,2024};
        test1.addYear(-100);
        Date test2{1,4,1924};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    {
        Date test1{29,2,2004};
        test1.addYear(-3);
        Date test2{1,3,2001};
        if(test1==test2)
            cout<<"\n[OK]";
        else
            cout<<"\n[FAIL]";
    }
    return 0;
}