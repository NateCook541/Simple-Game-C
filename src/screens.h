#pragma once
#include "campingItems.h"
#include "consumables.h"
#include <string>

// Welcome screens
void welcomeScreen();
void enterStart();
void displayMainMenuArt();

// Display choices screens and Getters
void displayMainOptions();
void displayTravelOptions();
void displayLodgeSellBuy();
void displayLodgeBuyOptions();
void displayLodgeBuyOptionsTwo();
void displayEatCookEat();
void displayWhatEaten(int index);
int getInventoryChoiceCook();
int getUserChoice();
int getInventoryChoiceConsumables();
void displayWhatEatenConsumables(int index);
void displayDrinkWaterTabs();
void drinkMessage(bool waterBottle, bool waterTabs, bool successful);

// Display stats and inventory
void displayStats();
void displayInventory(Consumables& firstAidKit);
void displayFullInventory(CampingItems& smallBackPack, CampingItems& largeBackPack);

// Ending screens
void death(std::string deathCauseText);
void enterDeath();
