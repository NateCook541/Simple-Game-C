#pragma once
#include "config.h"
#include <string>
#include <vector>

class Animal {
protected:
    std::string animalType;
    int weight;
public:
    Animal(const std::string& type, int w) : animalType(type), weight(w) {}
    // Converts food from fish/animal depending on weight
    void convertFood(Animal animalConvert) {
        playerHunger += animalConvert.weight;
    }
    // Adds to the inventory if a fish/animal is caught
    void addAnimalInventory(Animal& animalAdd) {
        animalInventory.push_back(animalAdd);
    }
};
