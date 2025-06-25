#include "raylib.h"
#include "gameplay.h"
#include "screens.h"
#include "inputManager.h"
#include <iostream>

void mainGameLoop() {

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayMainOptions();
        int userChoice = getUserChoice();
        if (userChoice != 0)
        {
            // Sleep
            if (userChoice == 1) {   
                InputManager::resetInput();
                std::cout << "1";
            }
            // Travel
            else if (userChoice == 2) {
                InputManager::resetInput();
            }
            // Eat
            else if (userChoice == 3) {
                InputManager::resetInput();
            }
            // Display stats
            else if (userChoice == 4) {
                InputManager::resetInput();
            }
            // Display inventory
            else if (userChoice == 5)  {
                InputManager::resetInput();
            }
            // Quit
            else if (userChoice == 7) {
                break;
            }
        }
    }
    EndDrawing();
} // End mainGameLoop

// End gameplay.cpp
