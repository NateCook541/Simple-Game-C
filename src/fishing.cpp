#include "fishing.h"
#include "fish.h"
#include "campingItems.h"
#include "config.h"
#include "raylib.h"
#include <string>
#include <vector>
#include <random>

Fish fishingMiniGame(CampingItems& shitRod, CampingItems& goodRod, bool northSouthFishing) {
    float currentProgress = 0.0f;
    float progressGoal = 100.0f;
    float timer = 10.0f;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Press SPACE to catch the fish!", 100, 200, 20, DARKGRAY);
        if (IsKeyPressed(KEY_SPACE)) {
            currentProgress += 10.0f;
        }

        timer -= GetFrameTime();
        DrawRectangle(100, 250, (int)currentProgress, 20, GREEN);
        DrawRectangleLines(100, 250, (int)progressGoal, 20, BLACK);
        std::string timerText = "Time left: " + std::to_string((int)timer) + "s";
        DrawText(timerText.c_str(), 100, 300, 20, DARKGRAY);
        
        if (currentProgress >= progressGoal) {
            DrawText("You have caught the fish!", 100, 350, 20, GREEN);
            EndDrawing();
            return Fish::createRandomFish(shitRod, goodRod, northSouthFishing);
        }
        else if (timer <= 0) {
            DrawText("The fish got away.", 100, 350, 20, GREEN);
            EndDrawing();
        }
        EndDrawing();
    }
}

void fishingNorth(CampingItems& shitRod, CampingItems& goodRod) {
    if (goodRod.getOwned()) {
        Fish Caught = fishingMiniGame(shitRod, goodRod, true);
        if (Caught) {

            Fish caught = fishCaught.getFishType();
            fishInventory.push_back(fishTypeCaught);

            while (!WindowShouldClose())
            {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                std::string fishText = "You caught a " + fishTypeCaught.fishType + "! It weighs " + std::to_string((int)fishWeight) + "lbs" +
                                       " and it is " + std::to_string((int)fishLength) + "in long";

                int textWidth = MeasureText(fishText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(fishText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText("Press ENTER to go back...", textX, 350, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ENTER))
                {
                    break;
                }

                EndDrawing();
            }
        }
        else
        {
            while (!WindowShouldClose())
            {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                std::string noCatchText = "You have not caught a fish.";
                std::string enterText = "Press ENTER to go back...";

                int textWidth = MeasureText(noCatchText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(noCatchText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ENTER))
                {
                    break;
                }

                EndDrawing();
            }
        }
    }
    else if (shitRod.getIsOwned())
    {
        int fishWeight = distOneFive(gen);
        int fishLength = distOneFive(gen);

        bool fishCaught = fishingMiniGame(shitRod, goodRod);

        if (fishCaught)
        {

            Fish fishTypeCaught = returnFishType(fishWeight, fishLength);
            fishInventory.push_back(fishTypeCaught);

            while (!WindowShouldClose())
            {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                std::string fishText = "You caught a " + fishTypeCaught.fishType + "! It weighs " + std::to_string((int)fishWeight) + "lbs" +
                                       " and it is " + std::to_string((int)fishLength) + "in long";

                int textWidth = MeasureText(fishText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(fishText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText("Press ENTER to go back...", textX, 350, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ENTER))
                {
                    break;
                }

                EndDrawing();
            }
        }
        else
        {
            while (!WindowShouldClose())
            {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                std::string noCatchText = "You have not caught a fish.";
                std::string enterText = "Press ENTER to go back...";

                int textWidth = MeasureText(noCatchText.c_str(), 20);
                int textX = (screenWidth - textWidth) / 2;

                DrawText(noCatchText.c_str(), textX, 300, 20, DARKGRAY);
                DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);

                if (IsKeyPressed(KEY_ENTER))
                {
                    break;
                }

                EndDrawing();
            }
        }
    }
    else
    {
        while (!WindowShouldClose())
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            std::string noRodText = "You do not own a fishing rod. You can buy one from the lodge.";
            std::string enterText = "Press ENTER to go back...";

            int textWidth = MeasureText(noRodText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;

            DrawText(noRodText.c_str(), textX, 300, 20, DARKGRAY);
            DrawText(enterText.c_str(), textX, 350, 20, DARKGRAY);

            if (IsKeyPressed(KEY_ENTER))
            {
                break;
            }

            EndDrawing();
        }
    }
}
void fishingSouth(CampingItems& shitRod, CampingItems& goodRod) {

}

