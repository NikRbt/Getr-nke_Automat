#include <iostream>
#include <string>

using namespace std;

double purchase(double& current_coin, double price);
int security_menu(int select_drink);
double approved_coins(double& coin);
bool ask_for_change();

int main() {
    char choice;

    double current_coin = 0.0; // Initialize the coin balance outside the loop.

    do {
        double cola_price = 1.0, water_price = 2.0, sprite_price = 1.5;

        int selectedOption;

        cout << "Coins: " << current_coin << endl;
        cout << "\n1. Cola $1\n2. Water $2\n3. Sprite $1.5\n" << endl;
        cin >> selectedOption;

        selectedOption = security_menu(selectedOption);

        current_coin = purchase(current_coin, (selectedOption == 1) ? cola_price : (selectedOption == 2) ? water_price : sprite_price);

        cout << "\t\nAnything else? [y] yes [n] no:" << endl;
        cin >> choice;

    } while (choice == 'y');

    return 0;
}

double purchase(double& current_coin, double price) {
    double insertedCoin;
    double change;

    cout << "\t\nPlease insert money:" << endl;
    cin >> insertedCoin;

    insertedCoin = approved_coins(insertedCoin);

    current_coin += insertedCoin;
    cout << "Current Coins: " << current_coin << endl;

    if (current_coin >= price) {
        change = current_coin - price;
        cout << "\t\nYour change and drink: $" << change << endl;
        if (!ask_for_change()) {
            current_coin = 0.0;  // Reset the coin balance to 0 for the next purchase.
        } else {
            // Keep the change for the next transaction.
            current_coin = change;
        }
    } else {
        do {
            cout << "\t\nInsufficient funds. Please insert an additional $" << (price - current_coin) << ":" << endl;
            cin >> insertedCoin;

            insertedCoin = approved_coins(insertedCoin);
            current_coin += insertedCoin;

        } while (current_coin < price);

        change = current_coin - price;
        cout << "\t\nYour change and drink: $" << change << endl;
        if (!ask_for_change()) {
            current_coin = 0.0;  // Reset the coin balance to 0 for the next purchase.
        } else {
            // Keep the change for the next transaction.
            current_coin = change;
        }
    }

    return current_coin;
}

int security_menu(int select_drink) {
    while (select_drink > 3 || select_drink == 0) {
        cout << "\nYou can only choose from these 3 drinks. Please choose:" << endl;
        cout << "\n1. Cola $1\n2. Water $2\n3. Sprite $1.5\n" << endl;
        cin >> select_drink;
    }

    return select_drink;
}

double approved_coins(double& coin) {
    while (!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2)) {
        cout << "\nOnly the following coins are allowed:\n\t$0.1\t$0.2\t$0.5\t$1\t$2" << endl;
        cout << "\t\nPlease insert money:" << endl;
        cin >> coin;
    }

    return coin;
}

bool ask_for_change() { // Query for keeping change, this function returns a boolean.
    char response;
    cout << "\t\nDo you want to keep the change for the next purchase? [y] yes [n] no:" << endl;
    cin >> response;

    if (response == 'y' || response == 'Y'){
        return true;
    }
    else{
        return false;
    }
}
