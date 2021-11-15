#pragma once
#include <string>
using namespace std;

const int FromFile = 1;
const int ToFile = 1;

class ClothingStore
{
private:
	string gender;
	string article;
	int size;
	int price;

public:
	ClothingStore(string gender = "", string article = "", int size = 0, int price = 0);
	ClothingStore(int, string line);

	string ToString();
	string ToString(int);

	int GetPrice();
	string GetGender();
	string GetArticle();
	int GetSize();

	void SetGender(string gender);
	void SetArticle(string article);
	void SetSize(int size);

	friend istream& operator >>(istream& in, ClothingStore& clothes);
	friend ostream& operator <<(ostream& ostr, ClothingStore& clothes);

};

