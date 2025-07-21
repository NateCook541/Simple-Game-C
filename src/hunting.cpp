#include "hunting.h"
#include "campingItems.h"
#include "forestAnimals.h"
#include "config.h"
#include "raylib.h"
#include "screens.h"
#include "inputManager.h"
#include <string>
#include <vector>
#include <random>

ForestAnimals huntingMiniGame(CampingItems& shitRifle, CampingItems& goodRifle, bool deepCloseWoods) {

    // BASE VARIABLES
    float crosshairX = 0.0f;
    float crosshairSpeed = 200.0f;
    bool right = true;

    const int targetX = screenWidth / 2;
    const int targetY = 200;
    const int targetRadius = 20;
    const int hitZoneWidth = 40;

    bool shotFired = false;
    bool success = false;

    float timer = 10.0f;

    if (goodRifle.getOwned()) {
        timer = 20.0f;
    }
    else if (shitRifle.getOwned()) {
        timer = 10.0f;
    }

    while (!WindowShouldClose()) {
        float frame = GetFrameTime();

        if (!shotFired) {
            // MOVE CROSSHAIR
            if (right) {
                crosshairX += crosshairSpeed * frame;
                if (crosshairX >= screenWidth) {
                    crosshairX = screenWidth;
                    right = false;
                }
            }
            else {
                crosshairX -= crosshairSpeed * frame;
                if (crosshairX <= 0) {
                    crosshairX = 0;
                    right = true;
                }
            }

            // CHECK SHOT FIRED
            if (IsKeyPressed(KEY_SPACE)) {
                float hitZoneLeft = targetX - hitZoneWidth / 2;
                float hitZoneRight = targetX + hitZoneWidth / 2;
                if (crosshairX >= hitZoneLeft && crosshairX <= hitZoneRight) {
                    success = true;
                }
                shotFired = true;
            }
        }

    // DRAWING
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawText("Press SPACE when the crosshair is in the center of the target!", 100, 50, 20, DARKGRAY);

    DrawCircle(targetX, targetY, targetRadius, PURPLE);
    DrawRectangle(targetX - hitZoneWidth / 2, targetY - 30, hitZoneWidth, 60, Fade(GREEN, 0.2f));

    DrawLine((int)crosshairX, targetY - 40, (int)crosshairX, targetY + 40, RED);

    // TIMER DRAWING
    std::string timerText = "Time left: " + std::to_string((int)timer) + "s";
    DrawText(timerText.c_str(), 100, 300, 20, DARKGRAY);

    timer -= GetFrameTime();

    // ENDING RETURN IF
    if (shotFired) {
        if (success) {
            DrawText("You have caught the Animal!", 100, 350, 20, GREEN);
            EndDrawing();
            return ForestAnimals::createRandomAnimal(shitRifle, goodRifle, deepCloseWoods);
        }
        else {
            DrawText("The animal got away.", 100, 350, 20, GREEN);
            EndDrawing();
            return ForestAnimals();
        }
    }

    if (timer <= 0) {
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
