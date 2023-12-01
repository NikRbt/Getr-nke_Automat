// TODO: re-write the code in ENGLISH!!!!!!!!!!!!
#include <iostream>
#include <string>

using namespace std;

double kauf(double& preis, double change); // TODO: <- declare change in this function and pass it each do while iteration
int menu_Sicherheit(int select_drink);
double approved_coins(double coin);




int main() {
    char j;
    double coin = 0.0; // TODO: rename this to currenct_coin
    // TODO: defined total_change here!!!
    double totalChange = 0.0;

    do {
        double cola = 1.0, water = 2.0, sprite = 1.5;

        int m; // TODO: renamed this properly


        cout << "Coins:" << totalChange << endl; // TODO: change + coin
        cout << "\n1.Cola 1$\n2.Water 2$\n3.Sprite 1.5$\n" << endl;
        cin.sync();
        cin >> m;

        m = menu_Sicherheit(m);

        switch (m) {
            case 1:
              totalChange = 2; // TODO: <- pass change here!
                break;

            case 2:
              totalChange = kauf(water,totalChange);
                break;

            case 3:
               totalChange = kauf(sprite,totalChange);
                break;
        }



        cout << "\t\nNoch etwas? [j]ja [n]nein:" << endl;
        cin.sync();
        cin >> j;

    } while (j == 'j');

    return 0;
}

double kauf(double& preis,double change) {
    double coin; // TODO: remove change from here
    char j;

    if(change != 0)
        {
            cout<<"Will you use change to previous purchase \nj[yes] \nn[no] "<<endl;
            cin.sync();
            cin>>j;

            if(j == 'j')
            {
              return change;
            }

        }

    cout << "\t\nBitte Geld einwerfen:" << endl;
    cin.sync();
    cin >> coin
    ;

    coin = approved_coins(coin);

    if (coin > preis) {
        coin = coin - preis;
        cout << "\t\nIhr R�ckgeld und Getr�nk: " << coin << endl;
    } else if (coin == preis) {
        cout << "\t\nHier ist Ihr Getr�nk" << endl;
        coin = coin - preis;
    } else {
        do {
            cout << "\t\nGeld nicht ausreichend. Bitte noch " << (preis = preis - coin) << " einwerfen:" << endl;
            cin.sync();
            cin >> coin;

            coin = approved_coins(coin);
        } while (preis > coin);

        // TODO: if total_change is not zero ask the user if he wants to use he change from the previous purchase

        change = coin - preis;

        cout << "\t\nIhr R�ckgeld und Getr�nk: " << change << endl;
    }

    return coin;
}

int menu_Sicherheit(int select_drink) {
    if (select_drink > 3 || select_drink == 0) {
        cout << "\nSie konnen nur diese 3 Getranke auswahlen. Bitte wahlen Sie:" << endl;
        cout << "\n1.Cola 1$\n2.Water 2$\n3.Sprite 1.5$\n" << endl;
        cin.sync();
        cin >> select_drink;
    }

    return select_drink;
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
