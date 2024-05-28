#include "WhiteBear.h"

using namespace std;

int main() {
  WhiteBear app;

  app.addItem(Item("+7 Yellow Vest", 10, 20));

  cout << "HAHAHA!" << endl;
  app.updateQuality();
  app.printItems();
}
