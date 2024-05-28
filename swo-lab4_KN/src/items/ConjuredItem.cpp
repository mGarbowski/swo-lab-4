#include "ConjuredItem.h"

void ConjuredItem::updateQuality() {
    quality = max(MIN_VALUE, quality - 2);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = max(MIN_VALUE, quality - 2); }
}

ConjuredItem::ConjuredItem(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
