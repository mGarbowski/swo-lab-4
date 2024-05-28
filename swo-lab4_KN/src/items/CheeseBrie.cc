#include "CheeseBrie.h"

void CheeseBrie::updateQuality() {
    incrementQuality(1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) {
        incrementQuality(1);
    }

}

CheeseBrie::CheeseBrie(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
