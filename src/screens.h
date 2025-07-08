#pragma once

// Welcome screens
void welcomeScreen();
void enterStart();
void displayMainMenuArt();

// Display choices screens and Getters
void displayMainOptions();
void displayTravelOptions();
void displayLodgeBuyOptions();
void displayLodgeBuyOptionsTwo();
void displayEatCookEat();
void displayWhatEaten(int index);
int getInventoryChoiceCook();
int getUserChoice();

// Display stats and inventory
void displayStats();
void displayInventory();

// Ending screens
void death();
void enterDeath();

