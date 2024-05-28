#ifndef SWO_WHITEBEAR_CONJUREDITEM_H
#define SWO_WHITEBEAR_CONJUREDITEM_H


#include "Item.h"

class ConjuredItem : public Item {
public:
    ConjuredItem(const std::string &name, int daysRemaining, int quality);

    void updateQuality() override;
};


#endif //SWO_WHITEBEAR_CONJUREDITEM_H
