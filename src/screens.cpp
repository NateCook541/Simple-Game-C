#include "raylib.h"
#include "screens.h"
#include "config.h"
#include "inputManager.h"
#include <string>

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
    // Check ready to accept input
    if (InputManager::isReady()) {
        if (IsKeyPressed(KEY_ONE))  { InputManager::lastKey = 1; InputManager::markProcessed(); return 1; }
        if (IsKeyPressed(KEY_TWO))  { InputManager::lastKey = 2; InputManager::markProcessed(); return 2; }
        if (IsKeyPressed(KEY_THREE)){ InputManager::lastKey = 3; InputManager::markProcessed(); return 3; }
        if (IsKeyPressed(KEY_FOUR)) { InputManager::lastKey = 4; InputManager::markProcessed(); return 4; }
        if (IsKeyPressed(KEY_FIVE)) { InputManager::lastKey = 5; InputManager::markProcessed(); return 5; }
        if (IsKeyPressed(KEY_SIX))  { InputManager::lastKey = 6; InputManager::markProcessed(); return 6; }
        if (IsKeyPressed(KEY_SEVEN)){ InputManager::lastKey = 7; InputManager::markProcessed(); return 7; }
        if (IsKeyPressed(KEY_EIGHT))  { InputManager::lastKey = 8; InputManager::markProcessed(); return 8; }
        if (IsKeyPressed(KEY_NINE)){ InputManager::lastKey = 9; InputManager::markProcessed(); return 9; }
    }
    // Reset processed if currently processed and no keys are pressed
    if (InputManager::processed && 
        !IsKeyPressed(KEY_ONE) && !IsKeyPressed(KEY_TWO) && !IsKeyPressed(KEY_THREE) &&
        !IsKeyPressed(KEY_FOUR) && !IsKeyPressed(KEY_FIVE) && !IsKeyPressed(KEY_SIX) &&
        !IsKeyPressed(KEY_SEVEN) && !IsKeyPressed(KEY_EIGHT) &&
        !IsKeyPressed(KEY_NINE)) {
        InputManager::processed = false;
    }
    return 0;
} // End getUserChoice

void displayStats() {
    while (!WindowShouldClose()) {
        std::string healthText = "Health - " + std::to_string(playerHealth);
        std::string hungerText = "Hunger - " + std::to_string(playerHunger);
        std::string waterText = "Water - " + std::to_string(playerThirst);
        std::string moneyText = "Money - " + std::to_string(playerMoney);
        std::string passedText = "Days passed - " + std::to_string(daysPassed);

        ClearBackground(RAYWHITE);
        
        DrawText(healthText.c_str(), 100, 100, 20, DARKGRAY);
        DrawText(hungerText.c_str(), 100, 130, 20, DARKGRAY);
        DrawText(waterText.c_str(), 100, 160, 20, DARKGRAY);
        DrawText(moneyText.c_str(), 100, 190, 20, DARKGRAY);
        DrawText(passedText.c_str(), 100, 220, 20, DARKGRAY);
        DrawText("Press ENTER to go back...", 100, 275, 20, DARKGRAY);
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
        EndDrawing();
    }
} // End displayStats

void death() {
    const char* deathText = "You have died. Game over!";
    int textWidth = MeasureText(deathText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);
    DrawText(deathText, textX, textY, 20, DARKGRAY);
} // End death

void enterDeath() {
    // Variables
    const char* enterText = "Hit enter to quit";
    int textWidth = MeasureText(enterText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textWidth / 2) + 80;
    // Draw
    DrawText(enterText, textX, textY, 20, DARKGRAY);
} // End enterStart

void displayLodgeBuyOptions() {
    ClearBackground(RAYWHITE);
    // Display the options
    DrawText("1. Tent - 25$", 100, 100, 20, DARKGRAY);
    DrawText("2. Cot - 15$", 100, 130, 20, DARKGRAY);
    DrawText("3. Shit rod - 15$", 100, 160, 20, DARKGRAY);
    DrawText("4. Good rod - 25$", 100, 190, 20, DARKGRAY);
    DrawText("5. Map - 10$", 100, 220, 20, DARKGRAY);
    DrawText("6. Shit Rifle - 15$", 100, 250, 20, DARKGRAY);
    DrawText("7. Good Rifle - 25$", 100, 280, 20, DARKGRAY);
    DrawText("8. Lighter - 10$", 100, 310, 20, DARKGRAY);
    DrawText("9. Back", 100, 340, 20, DARKGRAY);
    // Prompt for user input
    DrawText("Enter your choice: ", 100, 420, 20, DARKGRAY);
} // End displayLodgeBuyOptions

// End screens.cpp
