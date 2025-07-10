#include "hunting.h"
#include "campingItems.h"
#include "forestAnimals.h"
#include "config.h"
#include "raylib.h"
#include "screens.h"
#include <string>
#include <vector>
#include <random>

ForestAnimals huntingMiniGame(CampingItems& shitRifle, CampingItems& goodRifle, bool deepCloseWoods) {
    float currentProgress = 0.0f;
    float progressGoal = 100.0f;
    float timer = 10.0f;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press SPACE to hunt the animal!", 100, 200, 20, DARKGRAY);
        if (IsKeyPressed(KEY_SPACE)) {
            currentProgress += 10.0f;
        }

        timer -= GetFrameTime();
        DrawRectangle(100, 250, (int)currentProgress, 20, GREEN);
        DrawRectangleLines(100, 250, (int)progressGoal, 20, BLACK);
        std::string timerText = "Time left: " + std::to_string((int)timer) + "s";
        DrawText(timerText.c_str(), 100, 300, 20, DARKGRAY);
        
        if (currentProgress >= progressGoal) {
            DrawText("You have caught the Animal!", 100, 350, 20, GREEN);
            EndDrawing();
            return ForestAnimals::createRandomAnimal(shitRifle, goodRifle, deepCloseWoods);
        }
        else if (timer <= 0) {
            DrawText("The animal got away.", 100, 350, 20, GREEN);
            EndDrawing();
            return ForestAnimals();
        }
        EndDrawing();
    }
}

void hunting(CampingItems& shitRifle, CampingItems& goodRifle, bool deepCloseWoods, CampingItems& smallBackPack, CampingItems& largeBackPack) {
    // Limit check
    bool animalLimit = returnInventoryLimit(smallBackPack, largeBackPack);
    if (animalLimit) {
        displayFullInventory(smallBackPack, largeBackPack);
        return;
    }
    
    // User has a good rifle
    if (goodRifle.getOwned()) {
        ForestAnimals caught = huntingMiniGame(shitRifle, goodRifle, deepCloseWoods);
        // User catches a animal
        if (caught.getCaught()) {
            animalInventory.push_back(new ForestAnimals(caught));
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                std::string animalText = "You caught a " + caught.getType() + "! It weighs " 
                    + std::to_string(caught.getWeight()) + "lbs"
                    + " and it is " + std::to_string(caught.getHeight()) + " tall";

                int textWidth = MeasureText(animalText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;
                DrawText(animalText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText("Press ENTER to go back...", textX, 350, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
        }
        // User does not catch a animal
        else {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                std::string noCatchText = "You have not caught a animal.";
                std::string enterText = "Press ENTER to go back...";
                int textWidth = MeasureText(noCatchText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(noCatchText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
        }
    }
    // User has a bad rifle
    else if (shitRifle.getOwned()) {
        ForestAnimals caught = huntingMiniGame(shitRifle, goodRifle, deepCloseWoods);
        // User catches a animal
        if (caught.getCaught()) {
            animalInventory.push_back(new ForestAnimals(caught));
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                std::string animalText = "You caught a " + caught.getType() + "! It weighs " 
                    + std::to_string(caught.getWeight()) + "lbs"
                    + " and it is " + std::to_string(caught.getHeight()) + " tall";
                int textWidth = MeasureText(animalText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(animalText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText("Press ENTER to go back...", textX, 350, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
        }
        // User does not catch a animal
        else {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);

                std::string noCatchText = "You have not caught a animal.";
                std::string enterText = "Press ENTER to go back...";
                int textWidth = MeasureText(noCatchText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(noCatchText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
        }
    }
    // User does not own a rifle
    else {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);

            std::string noRifleText = "You do not own a rifle. You can buy one from the lodge.";
            std::string enterText = "Press ENTER to go back...";

            int textWidth = MeasureText(noRifleText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(noRifleText.c_str(), textX, 300, 20, DARKGRAY);
            DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);

            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
            EndDrawing();
        }
    }
}
