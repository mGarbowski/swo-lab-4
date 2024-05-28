#ifndef CPP_ConcertTicketItem_H
#define CPP_ConcertTicketItem_H

#include "IItem.h"

class ConcertTicketItem : public IItem{
public:
    ConcertTicketItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~ConcertTicketItem() = default;

    void update() override {

        //TODO
    };

private:
    int getQualityIncrementForConcertPass(int days_remaining) const {
        int quality_increment;
        if (days_remaining > 10)
            quality_increment = 1;
        else if (days_remaining > 5)
            quality_increment = 2;
        else
            quality_increment = 3;
        return quality_increment;
    };
};




#endif //CPP_ConcertTicketItem_H
