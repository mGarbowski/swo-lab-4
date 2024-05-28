#ifndef SWO_WHITEBEAR_LEGENDARY_H
#define SWO_WHITEBEAR_LEGENDARY_H

#include "Item.h"

class Legendary : public Item {
 public:
  Legendary(const std::string &name, int daysRemaining, int quality);

  void updateQuality() override;
};

#endif  // SWO_WHITEBEAR_LEGENDARY_H
