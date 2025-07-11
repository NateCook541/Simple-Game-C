#pragma once

#include <string>

class Consumables {
private:
    std::string name;
    int price;
    int qty;
    int water;
    int hunger;

public:
    // Constructor
    Consumables(std::string name, int price, int qty = 0, int water = 0, int hunger = 0);

    // Getters
    std::string getNameCon() const;
    int getPriceCon() const;
    int getQty() const;
    int getWater() const;
    int getHunger() const;

    // Setters
    void setNameCon(const std::string nameNew);
    void setPriceCon(const int priceNew);
    void setQty(const int qtyNew);
    void setWater(const int waterNew);
    void setHunger(const int hungerNew);

    // Functions

    // Adds 1 to qty of item
    void addQty();

    // Removes 1 to qty of item
    void removeQty();

    // Minus 1 of item used and gives the user the hunger points the item has
    void consumeFood();

    // Minus 1 of item used and gives the user the thirst points the item has
    void consumeWater();

    // Returns true if user has the item in inventory
    bool hasItem() const;

};
