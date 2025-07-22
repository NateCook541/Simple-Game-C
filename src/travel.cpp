#include "raylib.h"
#include "campingItems.h"
#include "screens.h"
#include "inputManager.h"
#include "lodge.h"
#include "fishing.h"
#include "hunting.h"

// Struct of locations
// Just use a struct for now because im to lazy to convert to class LOL
struct Location {
    const char* name;
    Rectangle area;
    bool needsMap;
    enum {
        LODGE, FISH_N, FISH_S, CLOSE_WOODS, DEEP_WOODS
    } type;
};

// Object types in travel screen
enum ObstacleType {
    TREE, ROCK
};

// Another struct, at least this one makes more sense but still this code is really shit
struct Obstacle {
    Rectangle rect;
    ObstacleType type;
};

void travel(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map, CampingItems& shitRifle, CampingItems& goodRifle, CampingItems& lighter, CampingItems& smallBackPack, CampingItems& largeBackPack, CampingItems& waterBottle, Consumables& firstAidKit, Consumables& waterPurificationTabs, Consumables& candyBar, Consumables& jerky, Consumables& bottledWater) {
    // Map and player marker setup
    int mapleft = 100;
    int mapTop = 100;
    int mapW = 600;
    int mapH = 300;

    float playerX = mapleft;
    float playerY = mapTop + mapH / 2;

    float speed = 2.0f;

    // Obstacle generation
    const int maxObstacles = 10;
    Obstacle obstacles[maxObstacles];
    
    for (int i = 0; i < maxObstacles; i++) {
        float w = GetRandomValue(20, 40);
        float h = GetRandomValue(20, 40);
        float x = GetRandomValue(mapleft + 10, mapleft + mapW - (int)w - 10);
        float y = GetRandomValue(mapTop + 10, mapTop + mapH - (int)h - 10);
        
        ObstacleType type = (GetRandomValue(0, 1) == 0) ? TREE : ROCK;

        obstacles[i] = { {x, y, w, h}, type};
    }

    // Make array of where locations are
    Location locations[] = {
        {"Lodge", {mapleft+270, mapTop+130, 60, 40}, false, Location::LODGE},
        {"Fishing North", {mapleft+100, mapTop+30, 80, 40}, false, Location::FISH_N},
        {"Fishing South", {mapleft+420, mapTop+30, 80, 40}, true, Location::FISH_S},
        {"Close Woods", {mapleft+100, mapTop+230, 80, 40}, false, Location::CLOSE_WOODS},
        {"Deep woods", {mapleft+420, mapTop+230, 80, 40}, true, Location::DEEP_WOODS},
    };
    int locationCount = sizeof(locations)/sizeof(locations[0]);

    while (!WindowShouldClose()) {

        // Previous position
        float prevX = playerX;
        float prevY = playerY;

        // Player movement
        if (IsKeyDown(KEY_RIGHT)) playerX += speed;
        if (IsKeyDown(KEY_LEFT)) playerX -= speed;
        if (IsKeyDown(KEY_UP)) playerY -= speed;
        if (IsKeyDown(KEY_DOWN)) playerY += speed;

        // Clamp out of bounds
        if (playerX < mapleft) playerX = mapleft;
        if (playerX > mapleft+mapW) playerX = mapleft+mapW;
        if (playerY < mapTop) playerY = mapTop;
        if (playerY > mapTop+mapH) playerY = mapTop+mapH;
        
        // Check for if player hits obstacle
        Rectangle playerRect = { playerX - 4, playerY - 4, 8, 8 };
        for (int i = 0; i < maxObstacles; i++) {
            if (CheckCollisionRecs(playerRect, obstacles[i].rect)) {
                playerX = prevX;
                playerY = prevY;
                break;
            }
        }

        // Start drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangleLines(mapleft, mapTop, mapW, mapH, DARKGRAY);

        // Draw locations
        for (int i = 0; i < locationCount; i++) {
            if (locations[i].needsMap && !map.getOwned()) {
                continue;
            }
            DrawRectangleRec(locations[i].area, Fade(GREEN, 0.2f));
            DrawText(locations[i].name, locations[i].area.x+5, locations[i].area.y+5, 16, DARKGRAY);
        }

        // Draw obstacles
        for (int i = 0; i < maxObstacles; i++) {
            Color color = (obstacles[i].type == TREE) ? DARKGREEN : GRAY;
            DrawRectangleRec(obstacles[i].rect, color);
        }

        // Player
        DrawCircle((int)playerX, (int)playerY, 7, RED);
        DrawText("Press ESC to go back...", 100, 450, 20, DARKGRAY);

        EndDrawing();

        // Player enters location
        for (int i = 0; i < locationCount; i++) {
            if (locations[i].needsMap && !map.getOwned()) {
                continue;
            }
            if (CheckCollisionPointRec({playerX, playerY}, locations[i].area)) {
                if (IsKeyPressed(KEY_ENTER)) {
                    InputManager::resetInput();
                    switch (locations[i].type) {
                        case Location::LODGE:
                            while (!WindowShouldClose()) {
                                BeginDrawing();
                                ClearBackground(RAYWHITE);
                                displayLodgeSellBuy();
                                EndDrawing();
                                int choice = getUserChoice();
                                if (choice == 1) {
                                    InputManager::clearInputQueue();
                                    lodgeBuy(tent, cot, shitRod, goodRod, map, shitRifle, goodRifle, lighter, smallBackPack, largeBackPack, waterBottle, firstAidKit, waterPurificationTabs, candyBar, jerky, bottledWater);
                                    break;
                                }
                                else if (choice == 2) {
                                    InputManager::clearInputQueue();
                                    lodgeSell();
                                    break;
                                }
                                else if (choice == 3) {
                                    break;
                                }
                            }
                            break;
                        case Location::FISH_N:
                            InputManager::clearInputQueue();
                            fishing(shitRod, goodRod, true, smallBackPack, largeBackPack);
                            break;
                        case Location::FISH_S:
                            InputManager::clearInputQueue();
                            fishing(shitRod, goodRod, false, smallBackPack, largeBackPack);
                            break;
                        case Location::CLOSE_WOODS:
                            InputManager::clearInputQueue();
                            hunting(shitRifle, goodRifle, false, smallBackPack, largeBackPack);
                            break;
                        case Location::DEEP_WOODS:
                            InputManager::clearInputQueue();
                            hunting(shitRifle, goodRifle, true, smallBackPack, largeBackPack);
                            break;
                    }
                }
            }
        }
        // Exit
        if (IsKeyPressed(KEY_ENTER)) {
            break;
        }
    }
}
