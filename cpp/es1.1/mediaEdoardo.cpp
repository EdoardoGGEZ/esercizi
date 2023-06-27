#include <iostream>

using namespace std;

int main()
{
    // variabili
    int length;
    int sum = 0;
    int average;

    // controllo input
    do
    {
        cout << "Quanti numeri vuoi summare e calcolarne la average? minimo 2\n";
        cin >> length;
    } while (length < 2); 

    // input numeri e somma
    for (int i = 0; i < length; i++)
    { 
        cout << "Numero " << i + 1 << ": ";
        int app;
        cin >> app;
        sum += app;
    }

    // calcolo average
    average = sum / length; 

    //stampa
    cout << "summa: " << sum << endl
         << "average: " << average << endl;
    return 0;
}