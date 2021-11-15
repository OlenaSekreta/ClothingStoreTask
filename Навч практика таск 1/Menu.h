#pragma once
#include "Command.h"

class Menu {
private:
	Command command;
	void showMainMenu();
	void showAndHandleAddItem();
	void showAndHandleRemoveClothingItem();
	void handleUserInput(int userInput);
	void handleWeather();
	int handlePrice();
	void Purchase();
	void handleCatalog();
public:
	void ShowMenu();
	
};

