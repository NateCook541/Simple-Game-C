#include "raylib.h"
#include "gameplay.h"
#include "screens.h"
#include "inputManager.h"
#include "campingItems.h"
#include "sleep.h"
#include "config.h"
#include "travel.h"
#include "eat.h"
#include <string>

void mainGameLoop() {

    // CREATE ITEMS HERE

    // Sleeping items
    CampingItems tent("Tent", 25, false);
    CampingItems cot("Cot", 15, false);

    // Fishing poles
    CampingItems shitRod("Shit Rod", 15, false);
    CampingItems goodRod("Good Rod", 25, false);

    // Hunting rifles
    CampingItems shitRifle("Shit Rifle", 15, false);
    CampingItems goodRifle("Good Rifle", 25, false);

    // Allows player to access south fishing and deep woods
    CampingItems map("Map", 10, false);

    // Allows the player to light fires to cook food from animals
    CampingItems lighter("Lighter", 10, false);

    // Maybe a backpack system to cap how many animals a player can catch / hunt before they have to return to lodge / camp
    CampingItems smallBackPack("Small Backpack", 15, false);
    CampingItems largeBackPack("Large Backpack", 25, false);

    // MAIN GAME LOOP

    // WHAT TO ADD
    // MAIN MENU ART
    // PURCHASABLE FOOD
    // WATER / THIRST SYSTEM
    // TRAVEL REWORK
    // ADD STATS DECREASING PER DAY AND DEATH CHECKS FOR THEM AS WELL
    // MORE ETC

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayMainOptions();
        int userChoice = getUserChoice();
        if (userChoice != 0) {
            // Sleep
            if (userChoice == 1) {   
                InputManager::resetInput();
                sleep(tent, cot);
            }
            // Travel
            else if (userChoice == 2) {
                InputManager::resetInput();
                travel(tent, cot, shitRod, goodRod, map, shitRifle, goodRifle, lighter, smallBackPack, largeBackPack);
            }
            // Eat
            else if (userChoice == 3) {
                InputManager::resetInput();
                selectEatType(lighter);
            }
            // Display stats
            else if (userChoice == 4) {
                InputManager::resetInput();
                displayStats();
            }
            // Display inventory
            else if (userChoice == 5)  {
                InputManager::resetInput();
                displayInventory();
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
