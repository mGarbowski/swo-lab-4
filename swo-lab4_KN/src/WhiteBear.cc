#include "WhiteBear.h"
#include <sstream>
#include <memory>


/**
const std::string CHEESE_BRIE = "Cheese Brie";
const std::string TICKETS = "Tickets to a concert";
const std::string LEGOLAS = "Legolas, Hand of Gollum";
*/

void WhiteBear::updateQuality() {
    for (auto &item: items_) {
        item->updateQuality();
    }
}

void WhiteBear::addItem(UItem item) { items_.push_back(std::move(item)); }

void WhiteBear::printItems() {
    for (auto &item: items_) {
        std::cout << *item << std::endl;
    }
}

void WhiteBear::printItems(std::ostream &output) {
    for (auto &item: items_) {
        output << *item << std::endl;
    }
    output << std::endl;
}

