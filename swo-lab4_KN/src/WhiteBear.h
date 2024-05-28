#ifndef WHITE_BEAR_H
#define WHITE_BEAR_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WhiteBear;

class Item {
public:
  Item(string name, int days_remaining, int quality)
      : t(name), d(days_remaining), v(quality) {}
  friend class WhiteBear;
  friend std::ostream &operator<<(std::ostream &s, Item &item);

private:
  string t;
  int d;
  int v;
};

class WhiteBear {
public:
  void printItems();
  void printItems(std::ostream& output);
  void addItem(const Item &item);
  void updateQuality();

private:
  vector<Item> items_;
};

const std::string item1 = "Cheese Brie";
const std::string item2 = "Tickets to a concert";
const std::string item3 = "Legolas, Hand of Gollum";
#endif // WHITE_BEAR_H
