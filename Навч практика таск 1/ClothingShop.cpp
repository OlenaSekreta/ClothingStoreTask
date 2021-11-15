#include "ClothesClass.h"
#include "Command.h"
#include "Error.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

ClothingStore::ClothingStore(string gender, string article, int size, int price) {
	this->gender = gender;
	this->article = article;
	this->size = size;
	this->price = price;

	if (size < 0 || size > 100) {
		throw Error(ErrorCode::NegativeSize);
	}
	if (article != "") {
		if (article != "skirt" && article != "shirt" && article != "coat" && article != "trousers"
			&& article != "dress" && article != "blouse" && article != "scarf" && article != "mittens") {
			throw Error(ErrorCode::Article);
		}
	}
	if (gender != "") {
		if (gender != "female" && gender != "male" && gender != "unisex") {
			throw Error(ErrorCode::Gender);
		}
	}
}

ClothingStore::ClothingStore(int, string line) {
	stringstream ss(line);
	string priceStr;

	getline(ss, gender, ',');
	getline(ss, article, ',');
	size = 10;
	getline(ss, priceStr, ',');

	price = stoi(priceStr);
}

string ClothingStore::ToString() {
	return "Clothing item: " + gender + " " + article + " size " + to_string(size) + " price $" + to_string(price);
}

string ClothingStore::ToString(int) {
	return gender + "," + article + "," + to_string(price);
}

//getters

int ClothingStore::GetPrice() {
	return price;
}

string ClothingStore::GetGender() {
	return gender;
}

string ClothingStore::GetArticle() {
	return article;
}

int ClothingStore::GetSize() {
	return size;
}

//setters
void ClothingStore::SetSize(int size) {
	this->size = size;
}

void ClothingStore::SetArticle(string article) {
	this->article = article;
}

void ClothingStore::SetGender(string gender) {
	this->gender = gender;
}
//operators

istream& operator>>(istream& personIn, ClothingStore& clothes) {
	string gender;
	string article;
	int size;

	cout << "Gender: \n";
	personIn >> gender;

	cout << "Article: \n";
	personIn >> article;

	cout << "Size: \n";
	personIn >> size;

	cout << endl;

	clothes.SetArticle(article);
	clothes.SetSize(size);
	clothes.SetGender(gender);

	return personIn;
}

ostream& operator <<(ostream& ostr, ClothingStore& clothes) {
	ostr << clothes.ToString();
	return ostr;
}
