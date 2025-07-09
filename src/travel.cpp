#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "lodge.h"
#include "fishing.h"
#include "hunting.h"

void travel(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map, CampingItems& shitRifle, CampingItems& goodRifle, CampingItems& lighter, CampingItems& smallBackPack, CampingItems& largeBackPack)
{
    int userChoice;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayTravelOptions();
        userChoice = getUserChoice();
        if (userChoice != 0) {
            // Lodge buy
            if (userChoice == 1) {
                InputManager::resetInput();
                lodgeBuy(tent, cot, shitRod, goodRod, map, shitRifle, goodRifle, lighter, smallBackPack, largeBackPack);
                userChoice = 0;
            }
            // Fishing north
            else if (userChoice == 3) {
                InputManager::resetInput();
                fishing(shitRod, goodRod, true, smallBackPack, largeBackPack);
                userChoice = 0;
            }
            // Fishing south
            else if (userChoice == 4) {
                if (map.getOwned() == false) {
                    while (!WindowShouldClose()) {
                        BeginDrawing();
                        ClearBackground(RAYWHITE);

                        std::string noMapText = "You do not own a map. You can buy one from the lodge.";
                        std::string enterText = "Press ENTER to go back...";
                        int textWidth = MeasureText(noMapText.c_str(), 20);
                        int textX = (screenWidth - textWidth) / 2;

                        DrawText(noMapText.c_str(), textX, 300, 20, DARKGRAY);
                        DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
                        if (IsKeyPressed(KEY_ENTER)) {
                            break;
                        }
                        EndDrawing();
                    }
                }
                else {
                    InputManager::resetInput();
                    fishing(shitRod, goodRod, false, smallBackPack, largeBackPack);
                    userChoice = 0;
                }
            }
            // Deep woods
            else if (userChoice == 5) {
                if (map.getOwned() == false) {
                    while (!WindowShouldClose()) {
                        BeginDrawing();
                        ClearBackground(RAYWHITE);

                        std::string noMapText = "You do not own a map. You can buy one from the lodge.";
                        std::string enterText = "Press ENTER to go back...";
                        int textWidth = MeasureText(noMapText.c_str(), 20);
                        int textX = (screenWidth - textWidth) / 2;

                        DrawText(noMapText.c_str(), textX, 300, 20, DARKGRAY);
                        DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
                        if (IsKeyPressed(KEY_ENTER)) {
                            break;
                        }
                        EndDrawing();
                    }
                }
                else {
                    InputManager::resetInput();
                    hunting(shitRifle, goodRifle, true);
                    userChoice = 0;
                }
            }
            // Close woods
            else if (userChoice == 6) {
                InputManager::resetInput();
                hunting(shitRifle, goodRifle, false);
                userChoice = 0;
            }
            // Back
            else if (userChoice == 7) {
                break;
            }
        }
        EndDrawing();
    }
}
