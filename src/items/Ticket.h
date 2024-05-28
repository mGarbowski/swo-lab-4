#ifndef SWO_WHITEBEAR_TICKET_H
#define SWO_WHITEBEAR_TICKET_H

#include "Item.h"

#define CONCERT_THRESHOLD_1 11
#define CONCERT_THRESHOLD_2 6

class Ticket : public Item {
 public:
  void updateQuality() override;

  Ticket(const std::string &name, int daysRemaining, int quality);
};

#endif  // SWO_WHITEBEAR_TICKET_H
