#pragma once

#include <vector>
#include "ClothesClass.h"
#include "Repository.h"

class Command : public Repository<ClothingStore> {
	int find(vector<string> vec, string s);
	int findMax(vector<int> vec);
public:
	Command();

	void AddItem(ClothingStore& clothingItem);
	void RemoveItem(int index);
	void RemoveAll();
	void PrintItems();
	void GetTotal();

	void ReadClothesFromFile();
	void WriteClothesToFile();
	void GetPriceFromFile();
	void GetClothesFromFile();
	int FindPrice(string gender, string article);
	ClothingStore GetMostCommon();

	void operator+= (ClothingStore clothingItem);
	void operator- (int index);
	void operator-- ();

};