#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "config.h"
#include "lodge.h"
#include "animals.h"
#include "consumables.h"
#include <string>

void lodgeBuy(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map, CampingItems& shitRifle, CampingItems& goodRifle, CampingItems& lighter, CampingItems& smallBackPack, CampingItems& largeBackPack, CampingItems& waterBottle, Consumables& firstAidKit, Consumables& waterPurificationTabs, Consumables& candyBar, Consumables& jerky, Consumables& bottledWater) {
    int buyChoice = 0;
    int skipFrames = 5;
    int page = 1;
    InputManager::resetInput();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (page == 1) {
            displayLodgeBuyOptions();
        }
        else {
            displayLodgeBuyOptionsTwo();
        }
        if (skipFrames > 0) {
            skipFrames--;
        } else if (buyChoice == 0) {
            buyChoice = getUserChoice();
        }
        if (buyChoice != 0) {
            if (page == 1) {
                if (buyChoice == 1) { purchaseScreen(tent, "Tent"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(tent)); }
                else if (buyChoice == 2) { purchaseScreen(cot, "Cot"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(cot)); }
                else if (buyChoice == 3) { purchaseScreen(shitRod, "Shit Rod"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(shitRod)); }
                else if (buyChoice == 4) { purchaseScreen(goodRod, "Good Rod"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(goodRod)); }
                else if (buyChoice == 5) { purchaseScreen(map, "Map"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(map)); }
                else if (buyChoice == 6) { purchaseScreen(shitRifle, "Shit Rifle"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(shitRifle)); }
                else if (buyChoice == 7) { purchaseScreen(goodRifle, "Good Rifle"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(goodRifle)); }
                else if (buyChoice == 8) { purchaseScreen(lighter, "Lighter"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(lighter)); }
                else if (buyChoice == 9) { InputManager::resetInput(); break; }
            } else if (page == 2) {
                if (buyChoice == 1) { purchaseScreen(largeBackPack, "Large backpack"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(largeBackPack)); }
                else if (buyChoice == 2) { purchaseScreen(smallBackPack, "Small backpack"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(smallBackPack)); }
                else if (buyChoice == 3) { purchaseScreen(waterBottle, "Water Bottle"); InputManager::resetInput(); itemsInventory.push_back(new CampingItems(waterBottle)); }
                else if (buyChoice == 4) { 
                    purchaseConsumablesScreen(jerky, "Jerky"); 
                    InputManager::resetInput(); 
                    if (jerky.hasItem() && std::find(consumablesInventory.begin(), consumablesInventory.end(), &jerky) == consumablesInventory.end()) {
                        consumablesInventory.push_back(&jerky);
                    }
                }
                else if (buyChoice == 5) { 
                    purchaseConsumablesScreen(candyBar, "Candy Bar"); 
                    InputManager::resetInput(); 
                    if (candyBar.hasItem() && std::find(consumablesInventory.begin(), consumablesInventory.end(), &candyBar) == consumablesInventory.end()) {
                        consumablesInventory.push_back(&candyBar);
                    }
                }
                else if (buyChoice == 6) { 
                    purchaseConsumablesScreen(firstAidKit, "First Aid Kit"); 
                    InputManager::resetInput(); 
                    if (firstAidKit.hasItem() && std::find(consumablesInventory.begin(), consumablesInventory.end(), &firstAidKit) == consumablesInventory.end()) {
                        consumablesInventory.push_back(&firstAidKit);
                    } 
                }
                else if (buyChoice == 7) { 
                    purchaseConsumablesScreen(waterPurificationTabs, "Water Purification Tabs"); 
                    InputManager::resetInput(); 
                    if (waterPurificationTabs.hasItem() && std::find(consumablesInventory.begin(), consumablesInventory.end(), &waterPurificationTabs) == consumablesInventory.end()) {
                        consumablesInventory.push_back(&waterPurificationTabs);
                    } 
                }
                else if (buyChoice == 8) { 
                    purchaseConsumablesScreen(bottledWater, "Bottled Water"); 
                    InputManager::resetInput(); 
                    if (bottledWater.hasItem() && std::find(consumablesInventory.begin(), consumablesInventory.end(), &bottledWater) == consumablesInventory.end()) {
                        consumablesInventory.push_back(&bottledWater);
                    } 
                }
                else if (buyChoice == 9) { 
                    InputManager::resetInput(); 
                    page = 1;
                    buyChoice = 0; 
                    skipFrames = 5;
                    EndDrawing();
                    continue;
                }
            }
            buyChoice = 0;
        }
        if (IsKeyPressed(KEY_RIGHT_ALT)) {
            InputManager::resetInput();
            page = (page == 1) ? 2 : 1;
            buyChoice = 0;
            skipFrames = 5;
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

void lodgeSell() {
    while (!WindowShouldClose()) {
        int index = getInventoryChoiceCook();
        
        if (index == -1) {
            break;
        }

        if (index >= 0 && index < animalInventory.size()) {
            animalInventory[index]->convertMoney(*animalInventory[index]);
        
            while(!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                sellScreen(index);
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

void sellScreen(int index) {
    std::string ownText = "You have sold " + animalInventory[index]->getType() + " for "
        + std::to_string(animalInventory[index]->getWeight()) + "$";
    int textWidth = MeasureText(ownText.c_str(), 20);
    int textX = (screenWidth - textWidth) / 2;
    DrawText(ownText.c_str(), textX, 225, 20, RED);
    DrawText("Press ENTER to go back...", textX, 275, 20, DARKGRAY);
}

void purchaseConsumablesScreen(Consumables& item, const std::string& itemName) {
    int cost = item.getPriceCon();

    if (playerMoney >= cost) {
        item.addQty();
        playerMoney -= cost;

        while(!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            std::string buyText = "You have bought " + itemName + " for " +
                std::to_string(item.getPriceCon()) + "$";
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
    else {
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
