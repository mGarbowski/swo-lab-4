#include "Item.h"

string Item::toString() const {
    stringstream result;
    result << name << ", " << daysRemaining << ", " << quality;
    return result.str();
}

void Item::updateQuality() {
    decrementQuality(1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) {
        decrementQuality(1);
    }
}

void Item::decrementQuality(int amount) {
    quality = max(MIN_VALUE, quality - amount);
}

const string &Item::getName() const {
    return name;
}

int Item::getDaysRemaining() const {
    return daysRemaining;
}

int Item::getQuality() const {
    return quality;
}

std::ostream &operator<<(std::ostream &s, Item &item) {
    s << item.toString();
    return s;
}