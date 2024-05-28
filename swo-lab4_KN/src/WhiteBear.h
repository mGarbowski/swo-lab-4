#ifndef WHITE_BEAR_H
#define WHITE_BEAR_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class WhiteBear;

class Item {
public:
  Item(string name, int daysRemaining, int quality)
      : name(std::move(name)), daysRemaining(daysRemaining), quality(quality) {}
  friend class WhiteBear;
  std::string toString() const;


private:
  string name;
  int daysRemaining;
  int quality;
};


std::ostream &operator<<(std::ostream &s, Item &item);

class WhiteBear {
public:
  void printItems();
  void printItems(std::ostream& output);
  void addItem(const Item &item);
  void updateQuality();

private:
  vector<Item> items_;
};

const std::string CHEESE_BRIE = "Cheese Brie";
const std::string TICKETS = "Tickets to a concert";
const std::string LEGOLAS = "Legolas, Hand of Gollum";
const std::string VEST = "+7 Yellow Vest";
#endif // WHITE_BEAR_H
