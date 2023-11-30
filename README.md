# Getranke_Automat
Dieses Programm simuliert einen Getränkeautomaten, der drei Getränke anbietet: Cola, Sprite und Wasser. Alle drei Getränke haben unterschiedliche Preise. Man kann nur bestimmte Münzen einwerfen, nämlich  0.1, 0.2, 0.5, 1 und 2 . Falls man zu wenig einwirft, erscheint eine Meldung, die angibt, wie viel Geld noch übrig ist. Diese Meldung wird solange angezeigt, bis der Benutzer den genauen Betrag eingeworfen hat oder mehr als erforderlich. Wenn der Benutzer mehr einwirft, gibt das Programm am Ende das Rückgeld zurück. Es erscheint ebenfalls eine Fehlermeldung, wenn man andere Münzen als vorgeschrieben einwirft.


## menu_Sicherheit
Als Erstes habe ich eine Funktion für die Menüüberprüfung erstellt, names menu_Sicherheit:

`int menu_Sicherheit(int menu);`

Diese Funktion überprüft, welche Zahlen eingegeben werden, da es im Menü nur 3 Getränke gibt. Wenn eine andere Zahl eingegeben wird, wird der Benutzer aufgefordert, erneut eine der oben genannten Getränkeoptionen auszuwählen. Die Funktion gibt einen Integer-Wert zurück, nämlich menu:
 
 ```c++
 if(menu > 3 || menu == 0)
    {
        cout<<"\nSie konnen nur Diese 3 getranke Auswählen bitte wahlen sie "<<endl;
        cout << "\n1.Cola 1$\n2.Water 2$\n3.Sprite 1.5$\n" << endl;
        cin.sync();
        cin >> menu;

    }
     return menu;
```

Eine if-Verzweigung überprüft, ob die eingegebene Zahl größer oder gleich null ist. Falls dies der Fall ist, gibt die Meldung aus, dass nur die 3 oben genannten Getränke ausgewählt werden können, und fordert den Benutzer auf, erneut das Menü auszuwählen, solange die eingegebene Zahl nicht 1, 2 oder 3 ist. Nach Eingabe einer neuen Zahl wird diese in der Variable menu gespeichert und mit return menu; zurückgegeben.

Die Funktion menu_Sicherheit wird in der main-Funktion aufgerufen, nachdem abgefragt wurde, welches Getränk ausgewählt werden soll. Dies gewährleistet, dass eine eventuelle Fehleingabe durch die if-Verzweigung erkannt und der Benutzer aufgefordert wird, eine gültige Getränkeoption zu wählen.

  menu_sicherheit wird in variable m gespeichert 

  ` m = menu_Sicherheit(m);`

  So wird der aktualisierte Wert in der Variable m gespeichert, der dann später in einer switch-Anweisung verwendet wird, um die entsprechende Getränkeoption zu verarbeiten.



## approved_coins

Als Nächstes habe ich eine Funktion namens approved_coins erstellt:

`double approved_coins(double coin);`

Diese Funktion überprüft, ob die eingegebene Münze gültig ist, indem sie nur bestimmte Werte akzeptiert, nämlich 0.1, 0.2, 0.5, 1 und 2:

```c++
while(!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2))
{
    cout << "\nEs sind nur folgende Münzen zugelassen:\n\t0.1\t0.2\t0.5\t1\t2" << endl;
    cout << "\tBitte Münze einwerfen:" << endl;
    cin.sync();
    cin >> coin;
};
```
In einer Schleife wird überprüft, ob die eingegebene Münze nicht einer der zulässigen Werte entspricht. Falls nicht, wird dem Benutzer mitgeteilt, welche Münzwerte akzeptiert werden, und er wird aufgefordert, eine gültige Münze einzulegen. Die Schleife wird so lange wiederholt, bis eine gültige Münze eingegeben wird.

Die Funktion gibt die akzeptierte Münze zurück:

`return coin;`


In der main-Funktion kann diese Funktion genutzt werden, wenn der Benutzer Geld einwirft, um sicherzustellen, dass nur gültige Münzen akzeptiert werden:

`coin = approved_coins(coin);`


Auf diese Weise wird der eingegebene Münzwert überprüft und akzeptiert, bevor er weiter im Programm verwendet wird.

## kauf

Diese Funktion simuliert den Kaufprozess für ein Getränk. Der Benutzer wird aufgefordert, Geld einzulegen, und die Funktion approved_coins wird verwendet, um sicherzustellen, dass nur gültige Münzen akzeptiert werden. Dann wird überprüft, ob das eingeworfene Geld ausreicht, um das Getränk zu kaufen.

Falls genug Geld eingeworfen wurde, wird das Rückgeld berechnet und dem Benutzer angezeigt.
Falls das eingeworfene Geld genau dem Preis entspricht, wird dem Benutzer mitgeteilt, dass das Getränk ausgegeben wird.
Falls zu wenig Geld eingeworfen wurde, wird der Benutzer aufgefordert, den fehlenden Betrag nachzuwerfen, und dies wird so lange wiederholt, bis genug Geld vorhanden ist.
Die Funktion gibt den insgesamt eingeworfenen Betrag coin zurück, was auch für die spätere Verwendung in der main-Funktion wichtig sein könnte:

`coin = kauf(sprite);`

In diesem Beispiel wird die Funktion für den Kauf eines Sprite-Getränks aufgerufen, und der aktualisierte Geldbetrag wird zurückgegeben und in der Variable coin gespeichert.

# CODE
```c++
#include <iostream>
#include <string>

using namespace std;

double kauf(double& preis);
int menu_Sicherheit(int menu);
double approved_coins(double coin);

int main() {
    char j;
    double coin = 0;

    do {
        double cola = 1, water = 2, sprite = 1.5;
        double change = 0;
        int m;

        cout << "Coins:" << coin << endl;

        cout << "\n1.Cola 1$\n2.Water 2$\n3.Sprite 1.5$\n" << endl;
        cin.sync();
        cin >> m;

        m = menu_Sicherheit(m);

        switch (m) {
            case 1:
                kauf(cola);
                break;

            case 2:
                kauf(water);
                break;

            case 3:
                kauf(sprite);
                coin = kauf(sprite);
                break;
        }

        cout << "\t\nNoch etwas? [j]ja [n]nein:" << endl;
        cin.sync();
        cin >> j;

    } while (j == 'j');

    return 0;
}

double kauf(double& preis) {
    double coin, change;

    cout << "\t\nBitte Geld einwerfen:" << endl;
    cin.sync();
    cin >> coin;

    coin = approved_coins(coin);

    if (coin > preis) {
        change = coin - preis;
        cout << "\t\nIhr Rückgeld und Getränk: " << change << endl;
    } else if (coin == preis) {
        cout << "\t\nHier ist Ihr Getränk" << endl;
    } else {
        do {
            cout << "\t\nGeld nicht ausreichend. Bitte noch " << (preis = preis - coin) << " einwerfen:" << endl;
            cin.sync();
            cin >> coin;

            coin = approved_coins(coin);
        } while (preis > coin);

        change = coin - preis;

        cout << "\t\nIhr Rückgeld und Getränk: " << change << endl;
    }

    return coin;
}

int menu_Sicherheit(int menu) {
    if (menu > 3 || menu == 0) {
        cout << "\nSie können nur diese 3 Getränke auswählen. Bitte wählen Sie:" << endl;
        cout << "\n1.Cola 1$\n2.Water 2$\n3.Sprite 1.5$\n" << endl;
        cin.sync();
        cin >> menu;
    }

    return menu;
}

double approved_coins(double coin) {
    while (!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2)) {
        cout << "\nEs sind nur folgende Coins zugelassen:\n\t0.1\t0.2\t0.5\t1\t2" << endl;
        cout << "\t\nBitte Geld einwerfen:" << endl;
        cin.sync();
        cin >> coin;
    }

    return coin;
}





```