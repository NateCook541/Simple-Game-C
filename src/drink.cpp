#include "drink.h"
#include "consumables.h"
#include "raylib.h"
#include "config.h"
#include <random>

// If user has purification tabs then remove 1 and return true, else 50% percent chance to lose health
bool drinkLoseHealth(Consumables& fillTabs) {
    if (fillTabs.getQty() > 0) {
        fillTabs.removeQty();
        return true;
    }
    else {
        return (rand() % 2) == 0;
    }
}

void drink(CampingItems& waterBottle, Consumables& fillTabs) {
    bool loseHealth = drinkLoseHealth(fillTabs);

    if (waterBottle.getOwned()) {
        if (!loseHealth) {
        // Display lose health
        }
        else {
            playerThirst += 50;
        }
    }
    else {
        if (!loseHealth) {
        // Display lose health
        }
        else {
            playerThirst += 25;
        }
    }
}
