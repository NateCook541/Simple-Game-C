#include "raylib.h"
#include "config.h"
#include <cstdlib>
#include <ctime>

int main() {
    // For randomness in functions
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Run game
    configureWindow();
    startGame();
}
