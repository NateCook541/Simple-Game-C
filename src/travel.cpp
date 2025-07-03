#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "lodge.h"
#include "fishing.h"

void travel(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map)
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
                lodgeBuy(tent, cot);
                userChoice = 0;
            }
            // Fishing north
            else if (userChoice == 3) {
                InputManager::resetInput();
                fishingNorth(shitRod, goodRod);
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
                    fishingSouth(shitRod, goodRod);
                    userChoice = 0;
                }
            }
            // Back
            else if (userChoice == 7) {
                break;
            }
        }
        EndDrawing();
    }
}
