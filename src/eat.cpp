#include "eat.h"
#include "campingItems.h"
#include "config.h"
#include "screens.h"
#include "raylib.h"
#include "inputManager.h"
#include "consumables.h"

bool cookMiniGame(CampingItems& lighter) {
    float currentProgress = 0.0f;
    float progressGoal = 100.0f;
    float timer = 10.0f;
    bool gameResult = false;
    bool gameEnded = false;
    while (!WindowShouldClose() && !gameEnded) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press SPACE to start the fire!", 100, 200, 20, DARKGRAY);
        if (IsKeyPressed(KEY_SPACE)) {
            currentProgress += 10.0f;
        }

        timer -= GetFrameTime();
        DrawRectangle(100, 250, (int)currentProgress, 20, GREEN);
        DrawRectangleLines(100, 250, (int)progressGoal, 20, BLACK);

        std::string timerText = "Time left: " + std::to_string((int)timer) + "s";
        DrawText(timerText.c_str(), 100, 300, 20, DARKGRAY);
        
        if (currentProgress >= progressGoal) {
            DrawText("You have started the fire!", 100, 350, 20, GREEN);
            gameResult = true;
            gameEnded = true;
        }
        else if (timer <= 0) {
            DrawText("The fire did not start. Try again!", 100, 350, 20, GREEN);
            gameResult = false;
            gameEnded = true;
        }
        EndDrawing();

        if (gameEnded) {
            float waitTime = 0.0f;
            while (waitTime < 2.0f && !IsKeyPressed(KEY_ENTER)) {
                waitTime += GetFrameTime();
            }
        }
    }
    return gameResult;
}

void eatCook() {
    while (!WindowShouldClose()) {
        int index = getInventoryChoiceCook();
        if (index == -1) {
            break;
        }

        if (index >= 0 && index < animalInventory.size()) {
            animalInventory[index]->convertFood(*animalInventory[index]);

            while(!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                displayWhatEaten(index);
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }

            delete animalInventory[index];
            animalInventory.erase(animalInventory.begin() + index);
        }
    }
}

void selectEatType(CampingItems& lighter) {
    bool ifLighter = false;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // If no lighter
        if (ifLighter) {
            std::string noLighterText = "You do not own a lighter. You can buy one from the lodge.";
            std::string enterText = "Press ENTER to go back...";
            int textWidth = MeasureText(noLighterText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(noLighterText.c_str(), textX, 300, 20, DARKGRAY);
            DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                ifLighter = false;
            }
            EndDrawing();
            continue;
        }

        displayEatCookEat();
        EndDrawing();

        int choice = getUserChoice();
        if (choice != 0) {
            // Cook food caught
            if (choice == 1) {
                if (!lighter.getOwned()) {
                    ifLighter = true;
                } else {
                    InputManager::resetInput();
                    bool fireDone = cookMiniGame(lighter);
                    if (fireDone) {
                        eatCook();
                    }
                }
                choice = 0;
            }
            // Eat purchased food
            else if (choice == 2) {
                InputManager::resetInput();
                eatConsumableFood();
                choice = 0;
            }
            // Go back
            else if (choice == 3) {
                break;
            }
        }
    }
}

void eatConsumableFood() {
    while (!WindowShouldClose()) {
        int choice = getInventoryChoiceConsumables();
        if (choice == -1) {
            break;
        }

        if (choice >= 0 && choice < consumablesInventory.size()) {

            consumablesInventory[choice]->consumeFood();

            while(!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                displayWhatEatenConsumables(choice);
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
            }
        }
        InputManager::resetInput();
    }
}

