#include "drink.h"
#include "consumables.h"
#include "raylib.h"
#include "config.h"
#include "screens.h"
#include "inputManager.h"
#include <random>

void drink(CampingItems& waterBottle, Consumables& fillTabs) {
    bool ifTabs = false;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (ifTabs) {
            std::string noTabsText = "You do not own any purification tablets.";
            std::string enterText = "Press ENTER to go back...";
            int textWidth = MeasureText(noTabsText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(noTabsText.c_str(), textX, 300, 20, DARKGRAY);
            DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
            EndDrawing();
            continue;
        }

        displayDrinkWaterTabs();
        EndDrawing();
        
        int choice = getUserChoice();
        if (choice != 0) {
            // Use purification tablets
            if (choice == 1) {
                // Has purification tablets
                if (fillTabs.hasItem()) {
                    // Water bottle
                    if (waterBottle.getOwned()) {
                        fillTabs.removeQty();
                        playerThirst += 50;
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(true, true, true);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                    // No water
                    else {
                        fillTabs.removeQty();
                        playerThirst += 25;
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(false, true, true);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                }
                // Does not have purification tablets
                else {
                    ifTabs = true;
                }
            }
            // No purification tablets
            else if (choice == 2) {
                // Water bottle
                if (waterBottle.getOwned()) {
                    playerThirst += 50;
                    bool healthLose = (rand() % 2) == 0;
                    if (healthLose) {
                        playerHealth--;
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(true, false, false);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                    else {
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(true, false, true);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                }
                else {
                    playerThirst += 25;
                    bool healthLose = (rand() % 2) == 0;
                    if (healthLose) {
                        playerHealth--;
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(false, false, false);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                    else {
                        while (!WindowShouldClose()) {
                            BeginDrawing();
                            ClearBackground(RAYWHITE);
                            drinkMessage(false, false, true);
                            EndDrawing();
                            if (IsKeyPressed(KEY_ENTER)) {
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            else if (choice == 3) {
                break;
            }
        }
    }
}
