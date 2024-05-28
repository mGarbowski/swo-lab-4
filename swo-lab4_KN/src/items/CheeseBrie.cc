#include "CheeseBrie.h"

void CheeseBrie::updateQuality() {
    quality = min(MAX_VALUE, quality + 1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = min(MAX_VALUE, quality + 1); }

}

CheeseBrie::CheeseBrie(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
