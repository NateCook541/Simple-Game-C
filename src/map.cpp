#include "map.h"
#include "raylib.h"
#include "config.h"
#include "screens.h"

void displayNoMap() {
    const char* mainMapArt = R"(
                FISHING NORTH    
                                |                
                    ----------|--
                                |
          <-SITE             |                LODGE->
        ----------------------------------------------------------------------  
                            |
                            |
                            |              
                            |              
                CLOSE WOODS      
    )";

    int fontSize = 25;
    int textWidth = MeasureText(mainMapArt, fontSize);
    int x = (screenWidth - textWidth) / 2;
    int y = screenHeight / 2 - 250;

    DrawText(mainMapArt, x, y, fontSize, DARKGRAY);
}

void displayMapAll() {
    const char* mainMapArt = R"(
                FISHING NORTH    FISHING SOUTH
                                |                 | 
                    ----------|-------------|
                                |
           <-SITE            |                LODGE->
        ----------------------------------------------------------------------  
                            |
                            |-----------|
                            |              |------
                            |              |
                CLOSE WOODS      DEEP WOODS
    )";

    int fontSize = 25;
    int textWidth = MeasureText(mainMapArt, fontSize);
    int x = (screenWidth - textWidth) / 2;
    int y = screenHeight / 2 - 250;

    DrawText(mainMapArt, x, y, fontSize, DARKGRAY);
}

void mapFunc(CampingItems& map) {
    if (map.getOwned()) {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            displayMapAll();
            DrawText("Press ENTER to go back...", 20, screenHeight - 40, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
            EndDrawing();
        }
    } 
    else {
        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            displayNoMap();
            DrawText("Press ENTER to go back...", 20, screenHeight - 40, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ENTER)) {
                break;
            }
            EndDrawing();
        }
    }
}
