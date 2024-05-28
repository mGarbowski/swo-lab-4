#include <memory>

#include "WhiteBear.h"

int main() {
  WhiteBear app;

  app.addItem(std::make_unique<Item>("+7 Yellow Vest", 10, 20));

  std::cout << "HAHAHA!" << std::endl;
  app.updateQuality();
  app.printItems();
}
