#include "WhiteBear.h"


std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.t << ", " << item.d << ", " << item.v;
  return s;
}

/**
const std::string item1 = "Cheese Brie";
const std::string item2 = "Tickets to a concert";
const std::string item3 = "Legolas, Hand of Gollum";
*/

void WhiteBear::updateQuality() {
  for (auto & item : items_) {
    if (item.t != item1 && item.t != item2) {
      if (item.v > 0) {
        if (item.t != item3) {
          item.v -= 1;
        }
      }
    } else {
      if (item.v < 50) {
        item.v = item.v + 1;
        if (item.t == item2) {
          if (item.d < 11) {
            if (item.v < 50) {
              item.v += 1;
            }
          }
          if (item.d < 6) {
            if (item.v < 50) {
              item.v++;
            }
          }
        }
      }
    }
    if (item.t != item3) {
      --item.d;
    }
    if (item.d < 0) {
      if (item.t != item1) {
        if (item.t != item2) {
          if (item.v > 0) {
            if (item.t != item3) {
              item.v = item.v - 1;
            }
          }
        } else {
          item.v = item.v - item.v;
        }
      } else {
        if (item.v < 50) {
          ++item.v;
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
	output << item.t << ", " << item.d << ", " << item.v << std::endl;
  }
  output << std::endl;
}
