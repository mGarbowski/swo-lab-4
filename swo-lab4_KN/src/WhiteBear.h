#ifndef WHITE_BEAR_H
#define WHITE_BEAR_H
#define MIN_VALUE 0
#define MAX_VALUE 50
#define MIN_DAYS 0
#define CONCERT_THRESHOLD_1 11
#define CONCERT_THRESHOLD_2 6

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>

using namespace std;

class WhiteBear;


class Item {
public:
    Item(string name, int daysRemaining, int quality)
            : name(std::move(name)), daysRemaining(daysRemaining), quality(quality) {}

    virtual ~Item() = default;

    std::string toString() const;

    virtual void updateQuality();


protected:
    string name;
    int daysRemaining;
    int quality;
};

using UItem = std::unique_ptr<Item>;

class Ticket : public Item {
public:
    void updateQuality() override;

    Ticket(const string &name, int daysRemaining, int quality);
};

class CheeseBrie : public Item {
public:
    CheeseBrie(const string &name, int daysRemaining, int quality);

    void updateQuality() override;
};

class Legendary : public Item {
public:
    Legendary(const string &name, int daysRemaining, int quality);

    void updateQuality() override;
};


std::ostream &operator<<(std::ostream &s, Item &item);

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
