#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "lodge.h"
#include "fishing.h"

void travel(CampingItems &tent, CampingItems &cot)
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
                fishingNorth();
                userChoice = 0;
            }
            // Fishing south
            else if (userChoice == 4) {
                InputManager::resetInput();
                fishingSouth();
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
