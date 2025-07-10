#include "drink.h"
#include "campingItems.h"
#include "raylib.h"
#include "config.h"
#include <random>

bool drinkLoseHealth(CampingItems& fillTabs) {
    if (fillTabs.getOwned()) {
        return true;
    }
    else {
        return (rand() % 2) == 0;
    }
}

void drink(CampingItems& waterBottle, CampingItems& fillTabs) {
    bool loseHealth = drinkLoseHealth(fillTabs);
    if (waterBottle.getOwned()) {

    }
}
