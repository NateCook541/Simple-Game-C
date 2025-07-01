#pragma once
#include "config.h"
#include <string>
#include <vector>

class Animal {
    protected:
        std::string animalType;
        int weight;
        std::vector<Animal> animalInventory;
    public:
        void convertFood(Animal animalConvert) {
            playerHunger += animalConvert.weight;
        }
        void addAnimalInventory(Animal animalAdd) {
            animalInventory.push_back(animalAdd);
        }
};
