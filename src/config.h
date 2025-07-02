#pragma once
#include <vector>
#include "animals.h"

// Config variables
const int screenWidth = 800;
const int screenHeight = 450;

// Player variables
extern int playerHealth;
extern int playerHunger;
extern int playerThirst;
extern int playerMoney;
extern int daysPassed;
extern std::vector <Animal>;

// Functions
void configureWindow();
void startGame();
