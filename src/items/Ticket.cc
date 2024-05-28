#include "Ticket.h"

void Ticket::updateQuality() {
  incrementQuality(1);
  if (daysRemaining < CONCERT_THRESHOLD_1) {
    incrementQuality(1);
  }
  if (daysRemaining < CONCERT_THRESHOLD_2) {
    incrementQuality(1);
  }

  daysRemaining--;
  if (daysRemaining < MIN_DAYS) {
    quality = MIN_VALUE;
  }
}

Ticket::Ticket(const std::string &name, int daysRemaining, int quality)
    : Item(name, daysRemaining, quality) {}
