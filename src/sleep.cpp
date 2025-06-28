#include "sleep.h"
#include "campingItems.h"
#include "config.h"
#include <cstdlib>
#include <ctime>

void sleep(const CampingItems& tent, const CampingItems& cot) {

}

bool healthLose(int thirst, int hunger, const CampingItems& tent, const CampingItems& cot) {
    float risk = 0.0;
    float thirstRisk = (100 - thirst) / 100.0;
    float hungerRisk = (100 - hunger) / 100.0;

    if (tent.getOwned() == true) {
        return false;
    }
    else if (cot.getOwned() == true) {
        risk = 0.2 + 0.4 * thirstRisk + 0.4 * hungerRisk;
    }
    else {
        risk = 0.5 + 0.3 * thirstRisk + 0.3 * hungerRisk;
    }

    if (risk > 1.0) {
        risk = 1.0;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    float random = static_cast<double>(std::rand()) / RAND_MAX;

    return random < risk;
}
