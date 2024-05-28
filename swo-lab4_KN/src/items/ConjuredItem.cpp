#include "ConjuredItem.h"

void ConjuredItem::updateQuality() {
    decrementQuality(2);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) {
        decrementQuality(2);
    }
}

ConjuredItem::ConjuredItem(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
