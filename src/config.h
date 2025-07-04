#pragma once
#include <vector>

// Config variables
const int screenWidth = 800;
const int screenHeight = 450;

// Forward declaration
class Animal;

// Player variables
extern int playerHealth;
extern int playerHunger;
extern int playerThirst;
extern int playerMoney;
extern int daysPassed;
extern std::vector<Animal*> animalInventory;

// Functions
void configureWindow();
void startGame();
