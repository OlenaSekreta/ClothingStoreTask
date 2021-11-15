#include "Menu.h"
#include "ClothesClass.h"
#include "Command.h"
#include "Error.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::showMainMenu() {
    cout << "Clothing Store!\nPlease select an action:\n";
    cout << "1. See Catalog\n";
    cout << "2. Do you need a recommendation for warmer/colder weather?\n";
    cout << "3. Add a clothing item to bag\n";
    cout << "4. See your shopping bag\n";
    cout << "5. Remove a clothing item from bag\n";
    cout << "6. Purchase clothing\n";
    cout << "0. Exit shop\n";
}

void Menu::handleWeather() {
    string weather;

    cout << "pls input colder/warmer accordingly\n";
    cin >> weather;

    if (weather == "colder") {
        cout << "coats are available for purchase, scarfs and mittens can also come in handy\n";
    }
    else if (weather == "warmer") {
        cout << "we can recommend shorts, as well as dresses, and blouses\n";
    }
    else
        throw Error(ErrorCode::Weather);
}

void Menu::showAndHandleAddItem() {
    /* 
    string gender;
    string article;
    int size;


    cout << "Gender: \n";
    cin >> gender;

    cout << "Article: \n";
    cin >> article;

    cout << "Size: \n";
    cin >> size;

    cout << endl;


    ClothingStore clothes(gender, article, size, command.FindPrice(gender, article));
    */
    ClothingStore clothes;
    string gender;
    string article;
    int size;

    cin >> clothes;

    gender = clothes.GetGender();
    article = clothes.GetArticle();
    size = clothes.GetSize();

    clothes =  ClothingStore(gender, article, size, command.FindPrice(gender, article));
    command.AddItem(clothes);

    cout << "Item added!\n";
}

void Menu::showAndHandleRemoveClothingItem()
{
    int index;
    cout << "Which item would you like to remove\n";
    cin >> index;

    command.RemoveItem(index);
    cout << "Item removed!\n";
}

void Menu::handleCatalog() {
    command.ReadClothesFromFile();
}

void Menu::handleUserInput(int userInput) {
    try {
        switch (userInput)
        {
        case(1): {
            handleCatalog();
            break;
        }
        case(2): {
            handleWeather();
            break;
        }
        case(3): {
            showAndHandleAddItem();
            break;
        }
        case(4): {
            command.PrintItems();
           
            cout << endl;
            
            break;
        }
        case(5): {
            showAndHandleRemoveClothingItem();
            break;
        }
        case(6): {
            command.GetTotal();
            break;
        }
        case(0):
            break;
        default:
            cout << "Wrong operation chosen\n";
            break;
        }
    }
    catch (Error& error) {
        cout << "error: " << error.ToString() << endl;
    }
    catch (...) {
        cout << "an unknown error occured, sorry!\n";
    }
}

void Menu::ShowMenu() {
    int userInput;
    command.GetClothesFromFile();

    do {
        showMainMenu();
        cin >> userInput;
        handleUserInput(userInput);
        cout << endl;
    } while (userInput != 0);
}

