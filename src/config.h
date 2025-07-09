#pragma once
#include <vector>

// Config variables
const int screenWidth = 800;
const int screenHeight = 500;

// Forward declaration
class Animal;
class CampingItems;

// Player variables
extern int playerHealth;
extern int playerHunger;
extern int playerThirst;
extern int playerMoney;
extern int daysPassed;
extern std::vector<Animal*> animalInventory;
extern std::vector<CampingItems*> itemsInventory;

// Functions
void configureWindow();
void startGame();
int getInventoryLimit(CampingItems& smallBackPack, CampingItems& largeBackPack);
bool returnInventoryLimit(CampingItems& smallBackPack, CampingItems& largeBackPack);
