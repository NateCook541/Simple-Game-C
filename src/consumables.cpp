#include "consumables.h"
#include "config.h"
#include <string>

// Constructor

Consumables::Consumables(std::string name, int price, int qty, int water, int hunger) :
    name(name), price(price), qty(qty), water(water), hunger(hunger) {}

// Getters

std::string Consumables::getNameCon() const {
    return name;
}

int Consumables::getPriceCon() const {
    return price;
}

int Consumables::getQty() const {
    return qty;
}

int Consumables::getWater() const {
    return water;
}

int Consumables::getHunger() const {
    return hunger;
}

// Setter

void Consumables::setNameCon(const std::string nameNew) {
    name = nameNew;
}

void Consumables::setPriceCon(const int priceNew) {
    price = priceNew;
}

void Consumables::setQty(const int qtyNew) {
    qty = qtyNew;
}

void Consumables::setWater(const int waterNew) {
    water = waterNew;
}

void Consumables::setHunger(const int hungerNew) {
    hunger = hungerNew;
}

// Functions

void Consumables::addQty() {
    qty++;
}

void Consumables::removeQty() {
    qty--;
}

void Consumables::consumeFood() {
    qty--;
    if (hunger > 0) {
        playerHunger += hunger;
    }
}

void Consumables::consumeWater() {
    qty--;
    if (water > 0) {
        playerThirst += water;
    }
}

bool Consumables::hasItem() const {
    return qty > 0;
}
