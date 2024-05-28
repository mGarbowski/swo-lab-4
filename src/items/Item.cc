#include "Item.h"

std::string Item::toString() const {
  std::stringstream result;
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

const std::string &Item::getName() const { return name; }

int Item::getDaysRemaining() const { return daysRemaining; }

int Item::getQuality() const { return quality; }

void Item::decrementQuality(int amount) {
  quality = std::max(MIN_VALUE, quality - amount);
}

void Item::incrementQuality(int amount) {
  quality = std::min(MAX_VALUE, quality + amount);
}

std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.toString();
  return s;
}