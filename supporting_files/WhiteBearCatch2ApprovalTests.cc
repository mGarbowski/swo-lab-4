#include "catch2/catch_all.hpp"
#include "ApprovalTests.hpp"


//#include "CheeseItem.h"
//#include "ConcertTicketItem.h"
#include "WhiteBear.h"
//#include "NormalItem.h"
//#include "LegolasItem.h"

TEST_CASE("WhiteBearApprovalTests", "First Test") {

    WhiteBear app;

    app.addItem(ItemPointer{new NormalItem("+7 Yellow Vest", 10, 20)});
    app.addItem(ItemPointer{new CheeseItem("Cheese Brie", 10, 20)});
    app.addItem(ItemPointer{new ConcertTicketItem("Tickets to a concert", 10, 20)});
    app.addItem(ItemPointer{new LegolasItem("Legolas, Hand of Gollum", 10, 20)});

    std::stringstream output;

    for (int day = 0; day <= 20; ++day) {
        output << "Day is " << day << std::endl;
        app.updateQuality();
        app.printItems(output);
    }

    ApprovalTests::Approvals::verify(output.str());
}

