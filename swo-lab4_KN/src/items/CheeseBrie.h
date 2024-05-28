#ifndef SWO_WHITEBEAR_CHEESEBRIE_H
#define SWO_WHITEBEAR_CHEESEBRIE_H

#include "Item.h"
#include <string>

class CheeseBrie : public Item {
public:
    CheeseBrie(const std::string &name, int daysRemaining, int quality);

    void updateQuality() override;
};

#endif //SWO_WHITEBEAR_CHEESEBRIE_H
