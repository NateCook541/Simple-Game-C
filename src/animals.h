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
    // Virtual class to make it polymorphic
    virtual ~Animal() {}
    // Converts food from fish/animal depending on weight
    void convertFood(Animal animalConvert) {
        playerHunger += animalConvert.weight;
    }
    // Converts money from fish/animal depending on weight
    void convertMoney(Animal animalConvert) {
        playerMoney += animalConvert.weight;
    }
    // Adds to the inventory if a fish/animal is caught
    void addAnimalInventory(Animal* animalAdd) {
        animalInventory.push_back(animalAdd);
    }
    // Getter for fallback display
    std::string getType() {
        return animalType;
    }
    // Getter for fallback display
    int getWeight() {
        return weight;
    }
};
