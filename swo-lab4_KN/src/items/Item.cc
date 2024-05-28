#include "Item.h"

string Item::toString() const {
    stringstream result;
    result << name << ", " << daysRemaining << ", " << quality;
    return result.str();
}

void Item::updateQuality() {
    quality = max(MIN_VALUE, quality - 1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = max(MIN_VALUE, quality - 1); }
}

std::ostream &operator<<(std::ostream &s, Item &item) {
    s << item.toString();
    return s;
}