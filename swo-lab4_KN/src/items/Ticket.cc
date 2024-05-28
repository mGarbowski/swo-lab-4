#include "Ticket.h"

void Ticket::updateQuality() {
    quality = min(MAX_VALUE, quality + 1);
    if (daysRemaining < CONCERT_THRESHOLD_1) { quality = min(MAX_VALUE, quality + 1); }
    if (daysRemaining < CONCERT_THRESHOLD_2) { quality = min(MAX_VALUE, quality + 1); }
    daysRemaining--;
    if (daysRemaining < MIN_DAYS) { quality = MIN_VALUE; }
}

Ticket::Ticket(const string &name, int daysRemaining, int quality) : Item(name, daysRemaining, quality) {}
