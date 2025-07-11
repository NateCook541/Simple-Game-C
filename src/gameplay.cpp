#include "raylib.h"
#include "gameplay.h"
#include "screens.h"
#include "inputManager.h"
#include "campingItems.h"
#include "sleep.h"
#include "config.h"
#include "travel.h"
#include "eat.h"
#include "drink.h"
#include "consumables.h"
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

    // Backpack system to cap how many animals a player can catch / hunt before they have to return to lodge / camp
    CampingItems smallBackPack("Small Backpack", 15, false);
    CampingItems largeBackPack("Large Backpack", 25, false);

    // Allows the player to collect 50 water from the lake at a single time
    CampingItems waterBottle("Water Bottle", 15, false);

    // CONSUMABLE ITEMS

    // Food
    Consumables candyBar("Candy Bar", 5, 0, 0, 10);
    Consumables jerky("Jerky", 10, 0, 0, 25);

    // Water
    Consumables waterTab("Water Purification Tablets", 5, 0, 0, 0);
    Consumables bottledWater("Bottled Water", 5, 0, 25, 0);

    // Health
    Consumables firstAidKit("First Aid Kit", 25, 0, 0, 0);

    // MAIN GAME LOOP


    // TODO 
    // Add water bottle functionality
    // Implement first add kit usage (Maybe if die give option to use it?)
    // Make it so only food items displays in the eat function
    // BUG FIXES

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayMainOptions();
        // FIX IN GRAPHICS UPDATE
        // displayMainMenuArt();
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
                travel(tent, cot, shitRod, goodRod, map, shitRifle, goodRifle, lighter, smallBackPack, largeBackPack, waterBottle, firstAidKit, waterTab, candyBar, jerky, bottledWater);
            }
            // Eat
            else if (userChoice == 3) {
                InputManager::resetInput();
                selectEatType(lighter);
            }
            // Drink
            else if (userChoice == 4) {
                InputManager::resetInput();
                // drink();
            }
            // Display stats
            else if (userChoice == 5)  {
                InputManager::resetInput();
                displayStats();
            }
             // Display inventory
            else if (userChoice == 6) {
                InputManager::resetInput();
                displayInventory();
            }
            // Quit
            else if (userChoice == 7) {
                break;
            }
        }

        // DEATH CHECKS

        // If player dies from health
        if (playerHealth == 0) {
            InputManager::resetInput();
            std::string deathText = "You lost all your health. Game over!";
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death(deathText);
                enterDeath();
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
            break;
        }
        // If player dies from lack of hunger
        else if (playerHunger == 0) {
            InputManager::resetInput();
            std::string deathText = "You died of hunger. Game over!";
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death(deathText);
                enterDeath();
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
            break;
        }
        // If player dies from lack thirst
        else if (playerThirst == 0) {
            InputManager::resetInput();
            std::string deathText = "You died of thirst. Game over!";
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death(deathText);
                enterDeath();
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
            break;
        }
        // If player dies from too much food
        else if (playerHunger == 125) {
            InputManager::resetInput();
            std::string deathText = "You died because you consumed too much food. Game over!";
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death(deathText);
                enterDeath();
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
            break;
        }
        // If player dies from too much water
        else if (playerThirst == 150) {
            InputManager::resetInput();
            std::string deathText = "You died because you drank too much water. Game over!";
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                death(deathText);
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
