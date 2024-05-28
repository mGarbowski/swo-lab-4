#include "WhiteBear.h"
#include <sstream>

std::string Item::toString() const {
    stringstream result;
    result << name << ", " << daysRemaining << ", " << quality;
    return result.str();
}

std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.toString();
  return s;
}

/**
const std::string CHEESE_BRIE = "Cheese Brie";
const std::string TICKETS = "Tickets to a concert";
const std::string LEGOLAS = "Legolas, Hand of Gollum";
*/

void WhiteBear::updateQuality() {
  for (auto & item : items_) {
      if (item.name == VEST) {
          item.quality = max(MIN_VALUE, item.quality - 1);
          item.daysRemaining--;
          if (item.daysRemaining < MIN_DAYS) { item.quality = max(MIN_VALUE, item.quality - 1); }
      }
      if (item.name == CHEESE_BRIE) {
          item.quality = min(MAX_VALUE, item.quality + 1);
          item.daysRemaining--;
          if (item.daysRemaining < MIN_DAYS) { item.quality = min(MAX_VALUE, item.quality + 1); }
      }
      if (item.name == TICKETS) {
          item.quality = min(MAX_VALUE, item.quality + 1);
          if (item.daysRemaining < CONCERT_THRESHOLD_1) { item.quality = min(MAX_VALUE, item.quality + 1); }
          if (item.daysRemaining < CONCERT_THRESHOLD_2) { item.quality = min(MAX_VALUE, item.quality + 1); }
          item.daysRemaining--;
          if (item.daysRemaining < MIN_DAYS) { item.quality = MIN_VALUE; }
      }
  }
}

void WhiteBear::addItem(const Item &item) { items_.push_back(item); }

void WhiteBear::printItems() {
  for (auto & item : items_) {
    std::cout << item << std::endl;
  }
}

void WhiteBear::printItems(std::ostream& output) {
  for (auto & item : items_) {
    //output << *i << std::endl;
	std::string s;
	output << item.name << ", " << item.daysRemaining << ", " << item.quality << std::endl;
  }
  output << std::endl;
}

