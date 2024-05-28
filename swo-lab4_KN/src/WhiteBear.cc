#include "WhiteBear.h"
#include <sstream>
#include <memory>

std::string Item::toString() const {
    stringstream result;
    result << name << ", " << daysRemaining << ", " << quality;
    return result.str();
}

std::ostream &operator<<(std::ostream &s, Item &item) {
    s << item.toString();
    return s;
}


void Item::updateQuality() {
    quality = max(MIN_VALUE, quality - 1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = max(MIN_VALUE, quality - 1); }
}

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

void Ticket::updateQuality() {
    quality = min(MAX_VALUE, quality + 1);
    if (daysRemaining < CONCERT_THRESHOLD_1) { quality = min(MAX_VALUE, quality + 1); }
    if (daysRemaining < CONCERT_THRESHOLD_2) { quality = min(MAX_VALUE, quality + 1); }
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = MIN_VALUE; }
}

Ticket::Ticket(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}

void CheeseBrie::updateQuality() {
    quality = min(MAX_VALUE, quality + 1);
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = min(MAX_VALUE, quality + 1); }

}

CheeseBrie::CheeseBrie(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}

void Legendary::updateQuality() {}

Legendary::Legendary(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
