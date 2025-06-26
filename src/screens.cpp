#include "raylib.h"
#include "screens.h"
#include "config.h"
#include "inputManager.h"

void welcomeScreen() {
    // Variables
    const char* welcomeText = "Welcome (Change later)";
    int textWidth = MeasureText(welcomeText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);
    // Draw
    DrawText(welcomeText, textX, textY, 20, DARKGRAY);
} // End welcomeScreen

void enterStart() {
    // Variables
    const char* enterText = "Hit enter to start";
    int textWidth = MeasureText(enterText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textWidth / 2) + 80;
    // Draw
    DrawText(enterText, textX, textY, 20, DARKGRAY);
} // End enterStart

void displayMainOptions() {
    // Display options and Enter
    DrawText("1. Sleep", 100, 100, 20, DARKGRAY);
    DrawText("2. Travel", 100, 130, 20, DARKGRAY);
    DrawText("3. Eat", 100, 160, 20, DARKGRAY);
    DrawText("4. Display stats", 100, 190, 20, DARKGRAY);
    DrawText("5. Display inventory", 100, 220, 20, DARKGRAY);
    DrawText("6. Display map", 100, 250, 20, DARKGRAY);
    DrawText("7. Quit", 100, 280, 20, DARKGRAY);
    DrawText("Enter your choice: ", 100, 320, 20, DARKGRAY);
} // End displayMainOptions

void displayTravelOptions() {
    // Display options and Enter
    DrawText("1. Lodge", 100, 100, 20, DARKGRAY);
    DrawText("2. Lodge sell", 100, 130, 20, DARKGRAY);
    DrawText("3. Lake North", 100, 160, 20, DARKGRAY);
    DrawText("4. Lake South", 100, 190, 20, DARKGRAY);
    DrawText("5. Deep woods", 100, 220, 20, DARKGRAY);
    DrawText("6. Close forest", 100, 250, 20, DARKGRAY);
    DrawText("7. Back", 100, 280, 20, DARKGRAY);
    DrawText("Enter your choice: ", 100, 320, 20, DARKGRAY);
} // End displayTravelOptions

int getUserChoice() {
    // Variables to reset last input
    static int lastPressed = 0;
    static bool processed = false;
    if (!processed) {
        if (IsKeyPressed(KEY_ONE)) {
            lastPressed = 1;
            processed = true;
            return 1;
        }
        if (IsKeyPressed(KEY_TWO)) {
            lastPressed = 2;
            processed = true;
            return 2;
        }
        if (IsKeyPressed(KEY_THREE)) {
            lastPressed = 3;
            processed = true;
            return 3;
        }
        if (IsKeyPressed(KEY_FOUR)) {
            lastPressed = 4;
            processed = true;
            return 4;
        }
        if (IsKeyPressed(KEY_FIVE)) {
            lastPressed = 5;
            processed = true;
            return 5;
        }
        if (IsKeyPressed(KEY_SIX)) {
            lastPressed = 6;
            processed = true;
            return 6;
        }
        if (IsKeyPressed(KEY_SEVEN)) {
            lastPressed = 7;
            processed = true;
            return 7;
        }
        // Reset when no key is pressed
        if (!IsKeyPressed(KEY_ONE) && !IsKeyPressed(KEY_TWO) && !IsKeyPressed(KEY_THREE) &&
        !IsKeyPressed(KEY_FOUR) && !IsKeyPressed(KEY_FIVE) && !IsKeyPressed(KEY_SIX) &&
        !IsKeyPressed(KEY_SEVEN))
        {
            processed = false;
        }
        // No valid input
        return 0;
    }
    return 0;
} // End getUserChoice

// End screens.cpp
