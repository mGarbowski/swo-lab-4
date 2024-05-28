#include "WhiteBear.h"
#include <memory>

using namespace std;

int main() {
  WhiteBear app;

  app.addItem(std::make_unique<Item>("+7 Yellow Vest", 10, 20));

  cout << "HAHAHA!" << endl;
  app.updateQuality();
  app.printItems();
}
