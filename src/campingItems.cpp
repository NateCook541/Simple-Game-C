#include "campingItems.h"
#include "config.h"
#include <iostream>

CampingItems::CampingItems(std::string name, int price, bool owned) : 
    name(name), price(price), owned(owned) {}

// Getters

std::string CampingItems::getName() const {
    return name;
}

int CampingItems::getPrice() const {
    return price;
}

bool CampingItems::getOwned() const {
    return owned;
}

// Setters

void CampingItems::setName(const std::string newName) {
    name = newName;
}

void CampingItems::setPrice(const int newPrice) {
    price = newPrice;
}

void CampingItems::setOwned(const bool newOwned) {
    owned = newOwned;
}
