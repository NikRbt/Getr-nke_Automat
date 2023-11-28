#include <iostream>
#include <string>

using namespace std;

double kauf(double& preis);
int menu_Sicherheit(int menu);
double approved_coins(double coin);
double PayChange(double change);

int main() {


        char j;
        double coin = 0;
do {
    double cola = 1, water = 2, sprite = 1.5;
    double change ;
    int m;

        cout << "Coins:" <<coin<< endl;

        cout << "1.Cola\n2.Water\n3.Sprite\n" << endl;
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

double kauf(double& preis)
{

    double coin,change;

    coin = PayChange(change);

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

int menu_Sicherheit(int menu)
{

    if(menu > 3 || menu == 0)
    {
        cout<<"\nSie konnen nur Diese 3 getranke Auswählen bitte wahlen sie "<<endl;
        cout << "\n1.Cola\n2.Water\n3.Sprite\n" << endl;
        cin.sync();
        cin >> menu;

    }

    return menu;

}

double approved_coins(double coin)
{

while(!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2))

{

        cout<<"\nEs sind nur folgende coins zugelassen:\n\t0.1\t0.2\t0.5\t1\t2"<<endl;
        cout << "\t\nBitte Geld einwerfen:" << endl;
        cin.sync();
        cin >> coin;

};

    return coin;
}

double PayChange(double change)
{
 double coin;
 char j;

    if(change > 0)
    {
        cout<<"Wollen sie mit ihr wechselgeld bezahlen? j[ja] n[nein]"<<endl;
        cin.sync();
        cin>>j;

        do
        {
                coin = change;

        }while(j != 'j');

    }


    return coin;
}
