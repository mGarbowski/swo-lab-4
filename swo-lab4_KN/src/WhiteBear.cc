#include "WhiteBear.h"
#include <sstream>

std::string Item::toString() const {
    stringstream result;
    result << t << ", " << d << ", " << v;
    return result.str();
}

std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.toString();
  return s;
}

/**
const std::string item1 = "Cheese Brie";
const std::string item2 = "Tickets to a concert";
const std::string item3 = "Legolas, Hand of Gollum";
*/

void WhiteBear::updateQuality() {
  for (unsigned i = 0; i < items_.size(); i++) {
    if (items_[i].t != item1 && items_[i].t != item2) {
      if (items_[i].v > 0) {
        if (items_[i].t != item3) {
          items_[i].v -= 1;
        }
      }
    } else {
      if (items_[i].v < 50) {
        items_[i].v = items_[i].v + 1;
        if (items_[i].t == item2) {
          if (items_[i].d < 11) {
            if (items_[i].v < 50) {
              items_[i].v += 1;
            }
          }
          if (items_[i].d < 6) {
            if (items_[i].v < 50) {
              items_[i].v++;
            }
          }
        }
      }
    }
    if (items_[i].t != item3) {
      --items_[i].d;
    }
    if (items_[i].d < 0) {
      if (items_[i].t != item1) {
        if (items_[i].t != item2) {
          if (items_[i].v > 0) {
            if (items_[i].t != item3) {
              items_[i].v = items_[i].v - 1;
            }
          }
        } else {
          items_[i].v = items_[i].v - items_[i].v;
        }
      } else {
        if (items_[i].v < 50) {
          ++items_[i].v;
        }
      }
    }
  }
}

void WhiteBear::addItem(const Item &item) { items_.push_back(item); }

void WhiteBear::printItems() {
  for (vector<Item>::iterator i = items_.begin(); i != items_.end(); i++) {
    std::cout << *i << std::endl;
  }
}

void WhiteBear::printItems(std::ostream& output) {
  for (unsigned i = 0; i < items_.size(); i++) {
    //output << *i << std::endl;
	std::string s;
	output << items_[i].t << ", " << items_[i].d << ", " << items_[i].v << std::endl;
  }
  output << std::endl;
}

