# Beverage_Vending_Machine

This program simulates a beverage vending machine that offers three drinks: Cola, Sprite, and Water. Each drink has a different price. Only specific coins (0.1, 0.2, 0.5, 1, and 2) are accepted. If the user inserts insufficient money, the program displays a message indicating how much more money is needed. This message continues to be displayed until the user inserts the exact amount or more. If the user inserts more money than required, the program returns the change. An error message is displayed if the user inserts coins other than those specified.

## menu_Security

Firstly, a function named `menu_Security` has been created to check the validity of the selected menu option:

```cpp
int menu_Security(int menu);
```

This function validates the user input to ensure that only valid options (1, 2, or 3) are accepted for selecting a drink. If an invalid option is entered, the user is prompted to choose one of the specified drink options. The function returns the validated menu option:

```cpp
if(menu > 3 || menu == 0)
{
    cout<<"\nYou can only choose from these 3 drinks. Please choose:"<<endl;
    cout << "\n1. Cola $1\n2. Water $2\n3. Sprite $1.5\n" << endl;
    cin.sync();
    cin >> menu;
}

return menu;
```

The `menu_Security` function is called in the main function after querying the user for the selected drink. This ensures that any input errors are detected, and the user is prompted to choose a valid drink option.

```cpp
m = menu_Security(m);
```

This line saves the updated value in the variable `m`, which is then used later in a switch statement to process the corresponding drink option.

## approved_coins

The next function is named `approved_coins`:

```cpp
double approved_coins(double& coin);
```

This function checks whether the entered coin is valid by accepting only specific values (0.1, 0.2, 0.5, 1, and 2):

```cpp
while(!(coin == 0.1 || coin == 0.2 || coin == 0.5 || coin == 1 || coin == 2))
{
    cout << "\nOnly the following coins are allowed:\n\t$0.1\t$0.2\t$0.5\t$1\t$2" << endl;
    cout << "\tPlease insert money:" << endl;
    cin.sync();
    cin >> coin;
}
```

Within a loop, the function checks if the entered coin does not match any of the allowed values. If not, the user is informed of the acceptable coin values and prompted to insert a valid coin. The loop continues until a valid coin is entered. The function returns the accepted coin:

```cpp
return coin;
```

In the main function, this function can be used when the user inserts money to ensure that only valid coins are accepted:

```cpp
coin = approved_coins(coin);
```

This line validates the entered coin value before further use in the program.

## purchase

The `purchase` function simulates the process of purchasing a drink. The user is prompted to insert money, and the `approved_coins` function is utilized to ensure that only valid coins are accepted. It then checks whether the inserted money is sufficient to buy the drink.

If enough money is inserted, the change is calculated and displayed to the user.
If the inserted money exactly matches the price, the user is informed that the drink is dispensed.
If insufficient money is inserted, the user is prompted to add the missing amount until enough money is provided.
The function returns the total amount inserted (`current_coin`), which is essential for later use in the main function:

```cpp
coin = purchase(current_coin, (selectedOption == 1) ? cola_price : (selectedOption == 2) ? water_price : sprite_price);
```

In this example, the function is called for purchasing a Sprite drink, and the updated coin balance is returned and stored in the variable `coin`.

## CODE

```cpp
// Include necessary libraries
#include <iostream>
#include <string>

using namespace std;

// Function prototypes
double purchase(double& current_coin, double price);
int menu_Security(int select_drink);
double approved_coins(double& coin);
bool ask_for_change();

int main() {
    // Initialize variables
    char choice;
    double current_coin = 0.0; // Initialize the coin balance outside the loop.

    // Main loop for vending machine interactions
    do {
        // Set prices for drinks
        double cola_price = 1.0, water_price = 2.0, sprite_price = 1.5;

        // User's selected drink option
        int selectedOption;

        // Display current coin balance and drink options
        cout << "Coins: " << current_coin << endl;
        cout << "\n1. Cola $1\n2. Water $2\n3. Sprite $1.5\n" << endl;
        cin >> selectedOption;

        // Validate selected drink option
        selectedOption = menu_Security(selectedOption);

        // Process the purchase and update the coin balance
        current_coin = purchase(current_coin, (selectedOption == 1) ? cola_price : (selectedOption == 2) ? water_price : sprite_price);

        // Prompt user for additional purchases
        cout << "\t\nAnything else? [y] yes [n] no:" << endl;
        cin >> choice;

    } while (choice == 'y');

    return 0;
}

// Function to handle the purchase of a drink
double purchase(double& current_coin, double price) {
    double insertedCoin;
    double change;

    // Prompt user to insert money
    cout << "\t\nPlease insert money:" << endl;
    cin >> insertedCoin;

    // Validate the inserted coin
    insertedCoin = approved_coins(insertedCoin);

    // Update the current coin balance
    current_coin += insertedCoin;
    cout << "Current Coins: " << current_coin << endl;

    // Check if there is enough money to purchase the drink
    if (current_coin >= price) {
        // Calculate and display the change
        change = current_coin - price;
        cout << "\t\nYour change and drink: $" << change << endl;
        // Ask user if they want to keep the change for the next purchase
        if (!ask_for_change()) {
            current_coin = 0.0;  // Reset the coin balance to 0 for the next purchase.
        } else {
            // Keep the change for the next transaction.
            current_coin = change;
        }
    } else {
        // Insufficient funds, prompt user to insert additional money
        do {
            cout << "\t\nInsufficient funds. Please insert an additional $" << (price - current_coin) << ":" << endl;
            cin >> insertedCoin;

            // Validate the inserted coin
            insertedCoin = approved_coins(insertedCoin);
            current_coin += insertedCoin;

        } while (current_coin < price);

        // Calculate