#pragma once
#include "campingItems.h"
#include "consumables.h"
#include <string>

void lodgeBuy(CampingItems& tent, CampingItems& cot, CampingItems& shitRod, CampingItems& goodRod, CampingItems& map, CampingItems& shitRifle, CampingItems& goodRifle, CampingItems& lighter, CampingItems& smallBackPack, CampingItems& largeBackPack, CampingItems& waterBottle, Consumables& firstAidKit, Consumables& waterPurificationTabs, Consumables& candyBar, Consumables& jerky, Consumables& bottledWater);
void purchaseScreen(CampingItems& item, const std::string& itemName);
void lodgeSell();
void sellScreen(int index);
void purchaseConsumablesScreen(Consumables& item, const std::string& itemName);
