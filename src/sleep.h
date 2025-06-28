#pragma once
#include "campingItems.h"

void sleep(const CampingItems& tent, const CampingItems& cot);
bool healthLose(int thirst, int hunger, const CampingItems& tent, const CampingItems& cot);
