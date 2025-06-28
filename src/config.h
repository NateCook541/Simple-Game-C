#pragma once

// Config variables
const int screenWidth = 800;
const int screenHeight = 450;

// Player variables
extern int playerHealth;
extern int playerHunger;
extern int playerThirst;
extern int playerMoney;
extern int daysPassed;

// Functions
void configureWindow();
void startGame();
