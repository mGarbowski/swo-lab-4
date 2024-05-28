#ifndef SWO_WHITEBEAR_ITEM_H
#define SWO_WHITEBEAR_ITEM_H

#include <sstream>
#include <memory>
#include <vector>
#include <utility>
#include <string>
#include <iostream>

#define MIN_VALUE 0
#define MAX_VALUE 50
#define MIN_DAYS 0


class Item {
public:
    Item(std::string name, int daysRemaining, int quality)
            : name(std::move(name)), daysRemaining(daysRemaining), quality(quality) {}

    virtual ~Item() = default;

    std::string toString() const;

    virtual void updateQuality();

    const std::string &getName() const;

    int getDaysRemaining() const;

    int getQuality() const;

protected:
    std::string name;
    int daysRemaining;
    int quality;

    void decrementQuality(int amount);

    void incrementQuality(int amount);
};

std::ostream &operator<<(std::ostream &s, Item &item);

using UItem = std::unique_ptr<Item>;

#endif //SWO_WHITEBEAR_ITEM_H
