#include <iostream>
#include <string>

using namespace std;

double purchase(double& price);
int security_menu(int select_drink);
double approved_coins(double coin);

int main() {
    char j;
    double coin = 0.0; // TODO: rename this to current_coin
    // TODO: define total_change here!!!
    double totalChange = 0.0;

    do {
        double cola = 1.0, water = 2.0, sprite = 1.5;

        int m; // TODO: rename this properly

        cout << "Coins:" << totalChange << endl; // TODO: change + coin
        cout << "\n1.Cola $1\n2.Water $2\n3.Sprite $1.5\n" << endl;
        cin.sync();
        cin >> m;

        m = security_menu(m);

        switch (m) {
            case 1:
                purchase(cola); // TODO: <- pass change here!
                break;

            case 2:
                purchase(water);
                break;

            case 3:
                purchase(sprite);
                break;
        }

        cout << "\t\nAnything else? [j]yes [n]no:" << endl;
        cin.sync();
        cin >> j;

    } while (j == 'j');

    return 0;
}

double purchase(double& price) {
    double coin;
    char j;

    cout << "\t\nPlease insert money:" << endl;
    cin.sync();
    cin >> coin;

    coin = approved_coins(coin);

    if (coin > price) {
        coin = coin - price;
        cout << "\t\nYour change and drink: $" << coin << endl;
    } else if (coin == price) {
        cout << "\t\nHere is your drink" << endl;
        coin = coin - price;
    } else {
        do {
            cout << "\t\nInsufficient funds. Please insert an additional $" << (price = price - coin) << ":" << endl;
            cin.sync();
            cin >> coin;

            coin = approved_coins(coin);
        } while (price > coin);

        coin = coin - price;

        cout << "\t\nYour change and drink: $" << coin << endl;
    }

    return coin;
}

int security_menu(int select_drink) {
    if (select_drink > 3 || select_drink == 0) {
        cout << "\nYou can only choose from these 3 drinks. Please choose:" << endl;
        cout << "\n1.Cola $1\n2.Water $2\n3.Sprite $1.5\n" << endl;
        cin.sync();
        cin >> select_drink;
    }

    return select_drink;
}

double approved_coins(double coin) {
    while (!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2)) {
        cout << "\nOnly the following coins are allowed:\n\t$0.1\t$0.2\t$0.5\t$1\t$2" << endl;
        cout << "\t\nPlease insert money:" << endl;
        cin.sync();
        cin >> coin;
    }

    return coin;
}
