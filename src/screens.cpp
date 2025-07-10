#include "raylib.h"
#include "screens.h"
#include "config.h"
#include "inputManager.h"
#include "fish.h"
#include "forestAnimals.h"
#include "animals.h"
#include "campingItems.h"
#include <string>

// BASIC SCREENS

void welcomeScreen() {
    // Variables
    const char* welcomeText = "Welcome (Change later)";
    int textWidth = MeasureText(welcomeText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);
    // Draw
    DrawText(welcomeText, textX, textY, 20, DARKGRAY);
} // End welcomeScreen

void enterStart() {
    // Variables
    const char* enterText = "Hit enter to start";
    int textWidth = MeasureText(enterText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textWidth / 2) + 80;
    // Draw
    DrawText(enterText, textX, textY, 20, DARKGRAY);
} // End enterStart

void displayMainOptions() {
    // Display options and Enter
    DrawText("1. Sleep", 100, 100, 20, DARKGRAY);
    DrawText("2. Travel", 100, 130, 20, DARKGRAY);
    DrawText("3. Eat", 100, 160, 20, DARKGRAY);
    DrawText("4. Drink", 100, 190, 20, DARKGRAY);
    DrawText("5. Display stats", 100, 220, 20, DARKGRAY);
    DrawText("6. Display inventory", 100, 250, 20, DARKGRAY);
    DrawText("7. Quit", 100, 280, 20, DARKGRAY);
    DrawText("Enter your choice: ", 100, 320, 20, DARKGRAY);
} // End displayMainOptions

void displayTravelOptions() {
    // Display options and Enter
    DrawText("1. Lodge", 100, 100, 20, DARKGRAY);
    DrawText("2. Lodge sell", 100, 130, 20, DARKGRAY);
    DrawText("3. Lake North", 100, 160, 20, DARKGRAY);
    DrawText("4. Lake South", 100, 190, 20, DARKGRAY);
    DrawText("5. Deep woods", 100, 220, 20, DARKGRAY);
    DrawText("6. Close forest", 100, 250, 20, DARKGRAY);
    DrawText("7. Back", 100, 280, 20, DARKGRAY);
    DrawText("Enter your choice: ", 100, 320, 20, DARKGRAY);
} // End displayTravelOptions

void displayMainMenuArt() {

    const char* lakeArtMenuScreen = 
    R"(
                                        .---.
                      .----------------'     '-----------------.
                  .--'                                          '---.
               .-'                                                   '-.
             .'                                                        '.
            /                                                            \
            |                                                             |
            |                                                             |
             \                                                           /
              '.                                                       .'
                '-._                                               _.-'
                    '---------------------------------------------'
    )";

    int textWidth = MeasureText(lakeArtMenuScreen, 16);
    int textX = screenWidth - textWidth - 20;

    DrawText(lakeArtMenuScreen, textX, 50, 16, DARKGRAY);
} // End displayMainMenuArt

int getUserChoice() {
    // Check ready to accept input
    if (InputManager::isReady()) {
        if (IsKeyPressed(KEY_ONE))  { InputManager::lastKey = 1; InputManager::markProcessed(); return 1; }
        if (IsKeyPressed(KEY_TWO))  { InputManager::lastKey = 2; InputManager::markProcessed(); return 2; }
        if (IsKeyPressed(KEY_THREE)){ InputManager::lastKey = 3; InputManager::markProcessed(); return 3; }
        if (IsKeyPressed(KEY_FOUR)) { InputManager::lastKey = 4; InputManager::markProcessed(); return 4; }
        if (IsKeyPressed(KEY_FIVE)) { InputManager::lastKey = 5; InputManager::markProcessed(); return 5; }
        if (IsKeyPressed(KEY_SIX))  { InputManager::lastKey = 6; InputManager::markProcessed(); return 6; }
        if (IsKeyPressed(KEY_SEVEN)){ InputManager::lastKey = 7; InputManager::markProcessed(); return 7; }
        if (IsKeyPressed(KEY_EIGHT))  { InputManager::lastKey = 8; InputManager::markProcessed(); return 8; }
        if (IsKeyPressed(KEY_NINE)){ InputManager::lastKey = 9; InputManager::markProcessed(); return 9; }
    }
    // Reset processed if currently processed and no keys are pressed
    if (InputManager::processed && 
        !IsKeyPressed(KEY_ONE) && !IsKeyPressed(KEY_TWO) && !IsKeyPressed(KEY_THREE) &&
        !IsKeyPressed(KEY_FOUR) && !IsKeyPressed(KEY_FIVE) && !IsKeyPressed(KEY_SIX) &&
        !IsKeyPressed(KEY_SEVEN) && !IsKeyPressed(KEY_EIGHT) &&
        !IsKeyPressed(KEY_NINE)) {
        InputManager::processed = false;
    }
    return 0;
} // End getUserChoice

void death(std::string deathCauseText) {
    std::string deathText = deathCauseText;
    int textWidth = MeasureText(deathText.c_str(), 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);
    DrawText(deathText.c_str(), textX, textY, 20, DARKGRAY);
} // End death

void enterDeath() {
    // Variables
    const char* enterText = "Hit enter to quit";
    int textWidth = MeasureText(enterText, 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textWidth / 2) + 80;
    // Draw
    DrawText(enterText, textX, textY, 20, DARKGRAY);
} // End enterStart

// STATS

void displayStats() {
    while (!WindowShouldClose()) {
        std::string healthText = "Health - " + std::to_string(playerHealth);
        std::string hungerText = "Hunger - " + std::to_string(playerHunger);
        std::string waterText = "Water - " + std::to_string(playerThirst);
        std::string moneyText = "Money - " + std::to_string(playerMoney);
        std::string passedText = "Days passed - " + std::to_string(daysPassed);

        ClearBackground(RAYWHITE);
        
        DrawText(healthText.c_str(), 100, 100, 20, DARKGRAY);
        DrawText(hungerText.c_str(), 100, 130, 20, DARKGRAY);
        DrawText(waterText.c_str(), 100, 160, 20, DARKGRAY);
        DrawText(moneyText.c_str(), 100, 190, 20, DARKGRAY);
        DrawText(passedText.c_str(), 100, 220, 20, DARKGRAY);
        DrawText("Press ENTER to go back...", 100, 275, 20, DARKGRAY);
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
        EndDrawing();
    }
} // End displayStats

// LODGE SCREENS

void displayLodgeBuyOptions() {
    ClearBackground(RAYWHITE);
    // Display the options
    DrawText("1. Tent - 25$", 100, 100, 20, DARKGRAY);
    DrawText("2. Cot - 15$", 100, 130, 20, DARKGRAY);
    DrawText("3. Shit rod - 15$", 100, 160, 20, DARKGRAY);
    DrawText("4. Good rod - 25$", 100, 190, 20, DARKGRAY);
    DrawText("5. Map - 10$", 100, 220, 20, DARKGRAY);
    DrawText("6. Shit Rifle - 15$", 100, 250, 20, DARKGRAY);
    DrawText("7. Good Rifle - 25$", 100, 280, 20, DARKGRAY);
    DrawText("8. Lighter - 10$", 100, 310, 20, DARKGRAY);
    DrawText("9. Back", 100, 340, 20, DARKGRAY);
    DrawText("Hit RIGHT ALT to switch between screens", 100, 440, 20, DARKGRAY);
    // Prompt for user input
    DrawText("Enter your choice: ", 100, 420, 20, DARKGRAY);
} // End displayLodgeBuyOptions

void displayLodgeBuyOptionsTwo() {
    ClearBackground(RAYWHITE);
    // Display the options
    DrawText("1. Small backpack - 15$", 100, 100, 20, DARKGRAY);
    DrawText("2. Large backpack - 25$", 100, 130, 20, DARKGRAY);
    DrawText("9. Back", 100, 340, 20, DARKGRAY);
    DrawText("Hit RIGHT ALT to switch between screens", 100, 440, 20, DARKGRAY);
    // Prompt for user input
    DrawText("Enter your choice: ", 100, 420, 20, DARKGRAY);
} // End displayLodgeBuyOptions

// EAT SCREENS

void displayEatCookEat() {
    ClearBackground(RAYWHITE);
    // Display the options
    DrawText("1. - Cook caught food", 100, 100, 20, DARKGRAY);
    DrawText("2. - Eat purchased food", 100, 130, 20, DARKGRAY);
    DrawText("3. Back", 100, 160, 20, DARKGRAY);
    // Prompt for user input
    DrawText("Enter your choice: ", 100, 420, 20, DARKGRAY);
} // End displayEatCookEat

int getInventoryChoiceCook() {
    int page = 0;
    const int itemsPerPage = 5;
    int totalPages = (animalInventory.size() + itemsPerPage - 1) / itemsPerPage;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int y = 100;
        int startIndex = page * itemsPerPage;
        int endIndex = std::min(startIndex + itemsPerPage, (int)animalInventory.size());
        
        for (int i = startIndex; i < endIndex; ++i) {
            std::string itemText = std::to_string(i - startIndex + 1) + ". ";

            // Fish check
            Fish* fish = dynamic_cast<Fish*>(animalInventory[i]);
            if (fish) {
                itemText += fish->getType() + " ("
                    + std::to_string(fish->getWeight()) + " lbs, "
                    + std::to_string(fish->getLength()) + " in)";
            }
            // Animal check
            else {
                ForestAnimals* animal = dynamic_cast<ForestAnimals*>(animalInventory[i]);
                if (animal) {
                    itemText += animal->getType() + " ("
                        + std::to_string(animal->getWeight()) + " lbs, "
                        + std::to_string(animal->getHeight()) + " in tall)";
                } else {
                    itemText += animalInventory[i]->getType() + " ("
                        + std::to_string(animalInventory[i]->getWeight()) + " lbs)";
                }
            }
            DrawText(itemText.c_str(), 100, y, 20, DARKGRAY);
            y += 30;
        }

        std::string pageText = "Use LEFT/RIGHT to change page. 9 to cancel.";
        DrawText(pageText.c_str(), 100, y + 20, 20, DARKGRAY);

        EndDrawing();

        int choice = getUserChoice();
        if (choice >= 1 && choice <= (endIndex - startIndex)) {
            return startIndex + (choice - 1);
        }
        else if (choice == 9) {
            return -1;
        }

        if (IsKeyPressed(KEY_RIGHT) && page < totalPages - 1) {
            page++;
        }
        else if (IsKeyPressed(KEY_LEFT) && page > 0) {
            page--;
        }
    }
    return -1;
} // End getInventoryChoice

void displayWhatEaten(int index) {

    std::string eatText = "You have eaten a " + animalInventory[index]->getType() + " for " 
        + std::to_string(animalInventory[index]->getWeight()) + " food points";
    int textWidth = MeasureText(eatText.c_str(), 20);
    int textX = (screenWidth - textWidth) / 2;
    int textY = (textX / 2);

    const char* enterText = "Hit enter to escape";
    int textWidthEnter = MeasureText(enterText, 20);
    int textXEnter = (screenWidth - textWidthEnter) / 2;
    int textYEnter = (textWidth / 2) + 80;

    DrawText(eatText.c_str(), textX, textY, 20, DARKGRAY);
    DrawText(enterText, textXEnter, textYEnter, 20, DARKGRAY);
} // End displayWhatEaten

// INVENTORY

void displayInventory() {
    int page = 0;
    const int itemsPerPage = 5;
    int totalItems = animalInventory.size() + itemsInventory.size();
    int totalPages = (totalItems + itemsPerPage - 1) / itemsPerPage;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int y = 100;
        int startIndex = page * itemsPerPage;
        int endIndex = std::min(startIndex + itemsPerPage, totalItems);

        for (int i = startIndex; i < endIndex; ++i) {
            std::string itemText = std::to_string(i - startIndex + 1) + ". ";
            if (i < animalInventory.size()) {
                // Animal section
                Fish* fish = dynamic_cast<Fish*>(animalInventory[i]);
                if (fish) {
                    itemText += fish->getType() + " (" +
                        std::to_string(fish->getWeight()) + " lbs, " +
                        std::to_string(fish->getLength()) + " in)";
                } 
                else {
                    ForestAnimals* animal = dynamic_cast<ForestAnimals*>(animalInventory[i]);
                    if (animal) {
                        itemText += animal->getType() + " (" +
                            std::to_string(animal->getWeight()) + " lbs, " +
                            std::to_string(animal->getHeight()) + " in tall)";
                    } 
                    else {
                        itemText += animalInventory[i]->getType() + " (" +
                            std::to_string(animalInventory[i]->getWeight()) + " lbs)";
                    }
                }
            } 
            else {
                // Items section
                int itemIdx = i - animalInventory.size();
                CampingItems* campingItem = itemsInventory[itemIdx];
                if (campingItem) {
                    itemText += campingItem->getName() + " - $" + std::to_string(campingItem->getPrice());
                }
            }
            DrawText(itemText.c_str(), 100, y, 20, DARKGRAY);
            y += 30;
        }

        std::string pageText = "Use LEFT/RIGHT to change page. Press ENTER or 9 to go back.";
        DrawText(pageText.c_str(), 100, y + 20, 20, DARKGRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_NINE)) {
            break;
        }
        if (IsKeyPressed(KEY_RIGHT) && page < totalPages - 1) {
            page++;
        } 
        else if (IsKeyPressed(KEY_LEFT) && page > 0) {
            page--;
        }
    }
} // End displayInventory

void displayFullInventory(CampingItems& smallBackPack, CampingItems& largeBackPack) {
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        std::string fullText = "your inventory is full ";

        if (largeBackPack.getOwned()) {
            fullText += "you can carry 15 animals with your large backpack.";
        }
        else if (smallBackPack.getOwned()) {
            fullText += "you can carry 10 animals with your small backpack.";
        }
        else {
            fullText += "you can only carry 5 animals without a backpack";
        }

        int textWidth = MeasureText(fullText.c_str(), 20);
        int textX = (screenWidth - textWidth) / 2;
        int textY = (textX / 2);

        DrawText(fullText.c_str(), textX, textY, 20, DARKGRAY);
        DrawText("Press enter to go back...", textX, 350, 20, DARKGRAY);

        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
        EndDrawing();
    }
} // End displayFullInventory

// End screens.cpp
