#ifndef WHITE_BEAR_H
#define WHITE_BEAR_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "items/Item.h"

class WhiteBear {
 public:
  void printItems();

  void printItems(std::ostream &output);

  void addItem(UItem item);

  void updateQuality();

 private:
  std::vector<UItem> items_;
};

#endif  // WHITE_BEAR_H
