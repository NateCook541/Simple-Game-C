#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "config.h"
#include "lodge.h"
#include <string>

void lodgeBuy(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map, CampingItems& shitRifle, CampingItems& goodRifle, CampingItems& lighter) {
    int buyChoice = 0;
    InputManager::resetInput();
    int skipFrames = 5;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        displayLodgeBuyOptions();
        if (skipFrames > 0) {
            skipFrames--;
        } else if (buyChoice == 0) {
            buyChoice = getUserChoice();
        }
        if (buyChoice != 0) {
            // Tent
            if (buyChoice == 1) {
                purchaseScreen(tent, "tent");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Cot
            else if (buyChoice == 2) {
                purchaseScreen(cot, "cot");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Shit Rod
            else if (buyChoice == 3) {
                purchaseScreen(shitRod, "Shit Rod");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Good Rod
            else if (buyChoice == 4) {
                purchaseScreen(goodRod, "Good Rod");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Map
            else if (buyChoice == 5) {
                purchaseScreen(map, "map");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Shit Rifle
            else if (buyChoice == 6) {
                purchaseScreen(shitRifle, "Shit Rifle");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Good Rifle
            else if (buyChoice == 7) {
                purchaseScreen(goodRifle, "Good Rifle");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Lighter
            else if (buyChoice == 8) {
                purchaseScreen(lighter, "Lighter");
                InputManager::resetInput();
                buyChoice = 0;
            }
            // Back                            
            else if (buyChoice == 9) {
                InputManager::resetInput();
                break;
            }
        }
        EndDrawing();
    }
}

void purchaseScreen(CampingItems& item, const std::string& itemName) {
    if (item.getOwned() == true) {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            std::string ownText = "You already own this item";
            int textWidth = MeasureText(ownText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(ownText.c_str(), textX, 225, 20, RED);
            DrawText("Press ENTER to go back...", textX, 275, 20, DARKGRAY);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
        }
    }
    else if (playerMoney >= item.getPrice()) {
        item.setOwned(true);
        playerMoney -= item.getPrice();
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            std::string buyText = "You have bought a " + itemName + " for " +
                std::to_string(item.getPrice()) + "$";
            int textWidth = MeasureText(buyText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(buyText.c_str(), textX, 225, 20, RED);
            DrawText("Press ENTER to continue...", textX, 275, 20, DARKGRAY);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
        }
    }
    else if (playerMoney < item.getPrice()) {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            std::string brokeText = "Your card declined (Ur broke...)";
            int textWidth = MeasureText(brokeText.c_str(), 20);
            int textX = (screenWidth - textWidth) / 2;
            DrawText(brokeText.c_str(), textX, 225, 20, RED);
            DrawText("Press ENTER to go back...", textX, 275, 20, DARKGRAY);
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
        }
    }
}
