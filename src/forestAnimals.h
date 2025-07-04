#pragma once
#include "animals.h"
#include "campingItems.h"
#include <string>
#include <random>

class ForestAnimals : public Animal {
    private:
        int height;
        bool caught;
    public:
        ForestAnimals() : Animal("", 0), height(0), caught(false) {}

        ForestAnimals(const std::string& type, int w, int h) : Animal(type, w), height(h), caught(true) {}

        static ForestAnimals getForestAnimalType(int w, int h) {
            std::string forestAnimalType[] = {"Bird", "Rabbit", "Squirrel", "Deer"};
            std::string chosenType;

            if (h >= 1 && h <= 3) {
                chosenType = forestAnimalType[0];
            }
            else if (h >= 4 && h <= 6) {
                chosenType = forestAnimalType[1];
            }
            else if (h >= 7 && h <= 8) {
                chosenType = forestAnimalType[2];
            }
            else if (h >= 9 && h <= 10) {
                chosenType = forestAnimalType[3];
            }
            else {
                chosenType = "Unknown";
            }
            return ForestAnimals(chosenType, w, h);
        }
        
        static ForestAnimals createRandomAnimal(CampingItems& shitRifle, CampingItems& goodRifle, bool deepCloseWoods) {
            bool bad = shitRifle.getOwned();
            bool good = goodRifle.getOwned();
            int minheight = 1;
            int minWeight = 1;
            int maxheight = 10;
            int maxWeight = 10;

            if (deepCloseWoods) {
                minheight += 2;
                minWeight += 2;
                maxheight += 2;
                maxWeight += 2;
            }

            if (good) {
                minheight += 2;
                minWeight += 2;
                maxheight += 2;
                maxWeight += 2;
            } 
            else if (bad) {
                maxheight -= 2;
                maxWeight -= 2;
            }

            if (minheight > maxheight) {
                minheight = maxheight;
            }
            if (minWeight > maxWeight) {
                minWeight = maxWeight;
            }

            int height = minheight + (std::rand() % (maxheight - minheight + 1));
            int weight = minWeight + (std::rand() % (maxWeight - minWeight + 1));

            return ForestAnimals::getForestAnimalType(weight, height);
        }

        bool getCaught() {
            return caught;
        }

        int getWeight() {
            return weight;
        }

        int getHeight() {
            return height;
        }

        std::string getType() {
            return animalType;
        }
};