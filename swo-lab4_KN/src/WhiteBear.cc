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
    if (item.name != CHEESE_BRIE && item.name != TICKETS) {
      if (item.quality > 0) {
        if (item.name != LEGOLAS) {
          item.quality -= 1;
        }
      }
    } else {
      if (item.quality < 50) {
        item.quality = item.quality + 1;
        if (item.name == TICKETS) {
          if (item.daysRemaining < 11) {
            if (item.quality < 50) {
              item.quality += 1;
            }
          }
          if (item.daysRemaining < 6) {
            if (item.quality < 50) {
              item.quality++;
            }
          }
        }
      }
    }
    if (item.name != LEGOLAS) {
      --item.daysRemaining;
    }
    if (item.daysRemaining < 0) {
      if (item.name != CHEESE_BRIE) {
        if (item.name != TICKETS) {
          if (item.quality > 0) {
            if (item.name != LEGOLAS) {
              item.quality = item.quality - 1;
            }
          }
        } else {
          item.quality = item.quality - item.quality;
        }
      } else {
        if (item.quality < 50) {
          ++item.quality;
        }
      }
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

