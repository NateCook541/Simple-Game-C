#include "sleep.h"
#include "campingItems.h"
#include "config.h"
#include "raylib.h"
#include <cstdlib>
#include <ctime>

void sleep(const CampingItems& tent, const CampingItems& cot) {
    // Tent (Always pass night)
    if (tent.getOwned()) {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            const char *sleepText{"You have slept in a tent and passed the night"};
            int textWidth = MeasureText(sleepText, 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(sleepText, textX, 225, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
            EndDrawing();
        }
        playerHunger -= 25;
        playerThirst -= 25;
        daysPassed++;
    }
    // Cot
    else if (cot.getOwned()) {
        bool lose = healthLose(playerThirst, playerHunger, tent, cot);
        // Lose health
        if (lose) {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                const char *sleepText{"You have slept in a cot and lost health"};
                int textWidth = MeasureText(sleepText, 20);
                int textX = (screenWidth - textWidth) / 2;
                DrawText(sleepText, textX, 225, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
            playerHunger -= 25;
            playerThirst -= 25;
            daysPassed++;
            playerHealth--;
        }
        // Pass night
        else {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                const char *sleepText{"You have slept in a cot and passed the night"};
                int textWidth = MeasureText(sleepText, 20);
                int textX = (screenWidth - textWidth) / 2;
                DrawText(sleepText, textX, 225, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
            playerHunger -= 25;
            playerThirst -= 25;
            daysPassed++;
        }
    }
    // Ground
    else {
        bool lose = healthLose(playerThirst, playerHunger, tent, cot);
        // Lose health
        if (lose) {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                const char *sleepText{"You have slept on the ground and have lost health"};
                int textWidth = MeasureText(sleepText, 20);
                int textX = (screenWidth - textWidth) / 2;
                DrawText(sleepText, textX, 225, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
            playerHunger -= 25;
            playerThirst -= 25;
            daysPassed++;
            playerHealth--;
        }
        // Pass night
        else {
            while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                const char *sleepText{"You have slept on the ground and passed the night"};
                int textWidth = MeasureText(sleepText, 20);
                int textX = (screenWidth - textWidth) / 2;
                DrawText(sleepText, textX, 225, 20, DARKGRAY);
                if (IsKeyPressed(KEY_ENTER)) {
                    break;
                }
                EndDrawing();
            }
            playerHunger -= 25;
            playerThirst -= 25;
            daysPassed++;
        }
    }
}

bool healthLose(int thirst, int hunger, const CampingItems& tent, const CampingItems& cot) {
    float risk = 0.0;
    float thirstRisk = (100 - thirst) / 100.0f;
    float hungerRisk = (100 - hunger) / 100.0f;

    if (tent.getOwned() == true) {
        return false;
    }
    else if (cot.getOwned() == true) {
        risk = 0.2f + 0.4f * thirstRisk + 0.4f * hungerRisk;
    }
    else {
        risk = 0.5f + 0.3f * thirstRisk + 0.3f * hungerRisk;
    }

    if (risk > 1.0) {
        risk = 1.0;
    }
    
    float random = static_cast<float>(std::rand()) / RAND_MAX;

    return random < risk;
}
