#pragma once

class InputManager {
    public:
        // Variables
        static int lastKey;
        static bool processed;

        // Functions
        static void resetInput() {
            lastKey = 0;
            processed = false;

        }
        static bool isReady() {
            return !processed;
        }
        static void markProcessed() {
            processed = true;
        }
        static void clearInputQueue() {
            while (GetKeyPressed() != 0) {

            }
    
            BeginDrawing();
            EndDrawing();
        }
};

inline int InputManager::lastKey = 0;
inline bool InputManager::processed = false;
