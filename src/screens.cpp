#include "raylib.h"
#include "screens.h"
#include "config.h"

void welcomeScreen() {
    // Clear
    ClearBackground(RAYWHITE);
    // Variables
    const char* welcomeText = "Welcome (Change later)";
    int textWidth = MeasureText(welcomeText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);
    // Draw
    DrawText(welcomeText, textX, textY, 20, DARKGRAY);
} // End welcomeScreen

void enterStart() {
    // Clear
    ClearBackground(RAYWHITE);
    // Variables
    const char* enterText = "Hit enter to start";
    int textWidth = MeasureText(enterText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textWidth / 2) + 80;
    // Draw
    DrawText(enterText, textX, textY, 20, DARKGRAY);
} // End enterStart

// End screens.cpp
