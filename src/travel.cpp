#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"

void travel(CampingItems &tent, CampingItems &cot)
{
    int userChoice{};
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayTravelOptions();
        InputManager::resetInput();
        userChoice = getUserChoice();
        if (userChoice != 0) {
            // Lodge buy
            if (userChoice == 1) {
                InputManager::resetInput();
            }
            // Fishing north
            else if (userChoice == 3) {
                InputManager::resetInput();
            }
            // Fishing south
            else if (userChoice == 4) {
                InputManager::resetInput();
            }
            // Back
            else if (userChoice == 7) {
                break;
            }
        }
        EndDrawing();
    }
}
