#include "Command.h"
#include "ClothesClass.h"
#include "Error.h"
#include <iostream>
#include <fstream>
using namespace std;

Command::Command() { }

int Command::find(vector<string> vec, string s)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == s)
        {
            return i;
        }
    }

    return -1;
}

int Command::findMax(vector<int> vec)
{
    int maxIndex = 0;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > vec[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

void Command::AddItem(ClothingStore& clothingItem) {
   // ordered.push_back(clothingItem);
    *this+=clothingItem;
}

void Command::RemoveItem(int index) {
    if (index<0 || index>clothes.size()) {
        throw Error(ErrorCode::IndexOutOfReach);
    }
   // ordered.erase(ordered.begin() + index);
    *this-index;
}

void Command::RemoveAll() {
    ordered.clear();   
    //operator instead
}

void Command::PrintItems() {
    cout << "Clothes: \n";
    for (int i = 0; i < ordered.size(); i++) {
       // cout << i << "-" << ordered[i].ToString() << endl;
        cout << i << "-" << ordered[i] << endl;
    }
}

void Command::GetTotal() {
    int total = 0;

    for (int i = 0; i < ordered.size(); i++) {
        total += ordered[i].GetPrice();
    }

    cout << "total: $" << total << endl;

    WriteClothesToFile();
    //RemoveAll();
    --(*this);

    cout << "The most ordered clothing item is " << GetMostCommon().ToString() << endl;
}

void Command::ReadClothesFromFile() {
    string line;
    ifstream fin("catalog.txt");

    if (fin.is_open()) {
        while (getline(fin, line)) {
            cout << line << endl;
        }
    }

    fin.close();
}

void Command::GetClothesFromFile() {
    string line;
    ifstream fin("catalog.txt");

    if (fin.is_open()) {
        while (getline(fin, line)) {
            clothes.push_back(ClothingStore(FromFile, line));
        }
    }

    fin.close();
}

void Command::WriteClothesToFile() {
    ofstream fout("clothing.txt", ios::app);

    for (int i = 0;i < ordered.size();i++) {
        fout << clothes[i].ToString(ToFile);
        fout << endl;
    }
    fout.close();
}

int Command::FindPrice(string gender, string article) {
    for (int i = 0; i < clothes.size(); i++)
    {
        if ((gender == clothes[i].GetGender()) && (article == clothes[i].GetArticle()))
        {
            return clothes[i].GetPrice();
        }
    }
     throw Error(ErrorCode::PriceNotFound);
}

ClothingStore Command::GetMostCommon() {
    vector<string> allClothes;
    vector<int> occurancies;

    ifstream fin("clothing.txt");
    string line;
    int index;

    while (getline(fin, line))
    {
        if ((index = find(allClothes, line)) != -1)
        {
            occurancies[index]++;
        }
        else
        {
            allClothes.push_back(line);
            occurancies.push_back(1);
        }
    }

    fin.close();
    return ClothingStore(FromFile, allClothes[findMax(occurancies)]);
}

//operators

void Command::operator+= (ClothingStore clothingItem) {
    ordered.push_back(clothingItem);
}

void Command::operator- (int index) {
    ordered.erase(ordered.begin() + index);
}

void Command::operator-- () {
    ordered.clear();
}


