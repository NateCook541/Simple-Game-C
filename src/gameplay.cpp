#include "raylib.h"
#include "gameplay.h"
#include "screens.h"
#include "inputManager.h"
#include "campingItems.h"
#include "sleep.h"
#include "config.h"
#include <iostream>

void mainGameLoop() {

    // Create Items here
    CampingItems tent("Tent", 25, false);
    CampingItems cot("Cot", 15, false);

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
                sleep(tent, cot);
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
                displayStats();
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
        // If player dies
        if (playerHealth == 0 || playerHunger == 0 || playerThirst == 0) {
            InputManager::resetInput();
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death();
                enterDeath();
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
            break;
        }
        EndDrawing();
    }

} // End mainGameLoop

// End gameplay.cpp
