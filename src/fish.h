#pragma once
#include "animals.h"
#include "campingItems.h"
#include <string>
#include <random>

class Fish : public Animal {
    private:
        int length;
        bool caught;
    public:
        Fish() : Animal("", 0), length(0), caught(false) {}

        Fish(const std::string& type, int w, int l) : Animal(type, w), length(l), caught(true) {}

        static Fish getFishType(int w, int l) {
            std::string fishTypes[] = {"Bass", "Trout", "Catfish", "Sturgeon"};
            std::string chosenType;

            if (l >= 1 && l <= 3) {
                chosenType = fishTypes[0];
            }
            else if (l >= 4 && l <= 6) {
                chosenType = fishTypes[1];
            }
            else if (l >= 7 && l <= 8) {
                chosenType = fishTypes[2];
            }
            else if (l >= 9 && l <= 10) {
                chosenType = fishTypes[3];
            }
            else {
                chosenType = "Unknown";
            }
            return Fish(chosenType, w, l);
        }
        
        static Fish createRandomFish(CampingItems& shitRod, CampingItems& goodRod, bool NorthSouth) {
            bool bad = shitRod.getOwned();
            bool good = goodRod.getOwned();
            int minLength = 1;
            int minWeight = 1;
            int maxLength = 10;
            int maxWeight = 10;

            if (!NorthSouth) {
                minLength += 2;
                minWeight += 2;
                maxLength += 2;
                maxWeight += 2;
            }

            if (good) {
                minLength += 2;
                minWeight += 2;
                maxLength += 2;
                maxWeight += 2;
            } 
            else if (bad) {
                maxLength -= 2;
                maxWeight -= 2;
            }

            if (minLength > maxLength) {
                minLength = maxLength;
            }
            if (minWeight > maxWeight) {
                minWeight = maxWeight;
            }

            int length = minLength + (std::rand() % (maxLength - minLength + 1));
            int weight = minWeight + (std::rand() % (maxWeight - minWeight + 1));

            return Fish::getFishType(weight, length);
        }

        bool getCaught() {
            return caught;
        }

        int getWeight() {
            return weight;
        }

        int getLength() {
            return length;
        }

        std::string getType() {
            return animalType;
        }
};
