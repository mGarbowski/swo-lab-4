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

const string &Item::getName() const {
    return name;
}

int Item::getDaysRemaining() const {
    return daysRemaining;
}

int Item::getQuality() const {
    return quality;
}

void Item::decrementQuality(int amount) {
    quality = max(MIN_VALUE, quality - amount);
}

void Item::incrementQuality(int amount) {
    quality = min(MAX_VALUE, quality + amount);
}

std::ostream &operator<<(std::ostream &s, Item &item) {
    s << item.toString();
    return s;
}