#pragma once
#include "config.h"
#include <string>
#include <vector>

class Animal {
    protected:
        std::string animalType;
        int weight;
    public:
        // Converts food from fish/animal depending on weight
        void convertFood(Animal animalConvert) {
            playerHunger += animalConvert.weight;
        }
        // Adds to the inventory if a fish/animal is caught
        // The inventory should be a reference from the main inventory in config
        void addAnimalInventory(Animal& animalAdd) {
            animalInventory.push_back(animalAdd);
        }
};
