#include <iostream>

using namespace std;

int main()
{
    // variabili
    int length;
    int sum = 0;
    int average;
    do
    {
        cout << "Quanti numeri vuoi summare e calcolarne la average? minimo 2\n";
        cin >> length;
    } while (length < 2); // controllo input

    for (int i = 0; i < length; i++)
    { // input numeri e summa
        cout << "Numero " << i + 1 << ": ";
        int app;
        cin >> app;
        sum += app;
    }

    average = sum / length; // calcolo average

    cout << "summa: " << sum << endl
         << "average: " << average << endl;
    return 0;
}