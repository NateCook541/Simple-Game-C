#pragma once
#include <string>

class CampingItems {
    private:
        std::string name;
        int price;
        bool owned;
    public:
        // Constructor
        CampingItems(std::string name, int price, bool owned);
        // Getters
        std::string getName() const;
        int getPrice() const;
        bool getOwned() const;
        // Setters
        void setName(const std::string newName);
        void setPrice(const int newPrice);
        void setOwned(const bool newOwned);
        // Public methods
        // Remove money from player and set owned to true
        void purchaseItem();
        // Display item in raylib window
        void displayItem();
};
