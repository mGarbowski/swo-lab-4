#ifndef WHITE_BEAR_H
#define WHITE_BEAR_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include "items/Item.h"

using namespace std;

class WhiteBear;


class WhiteBear {
public:
    void printItems();

    void printItems(std::ostream &output);

    void addItem(UItem item);

    void updateQuality();

private:
    vector<UItem> items_;
};

const std::string CHEESE_BRIE = "Cheese Brie";
const std::string TICKETS = "Tickets to a concert";
const std::string LEGOLAS = "Legolas, Hand of Gollum";
const std::string VEST = "+7 Yellow Vest";
#endif // WHITE_BEAR_H
