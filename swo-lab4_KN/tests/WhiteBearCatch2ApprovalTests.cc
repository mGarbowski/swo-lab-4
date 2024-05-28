#include "catch2/catch_all.hpp"
#include "ApprovalTests.hpp"
#include "WhiteBear.h"


TEST_CASE("WhiteBearApprovalTests", "First Test") {

    WhiteBear app;

    app.addItem(Item("+7 Yellow Vest", 10, 20));
    app.addItem(Item("Cheese Brie", 10, 20));
    app.addItem(Item("Tickets to a concert", 10, 20));
    app.addItem(Item("Legolas, Hand of Gollum", 10, 20));

    std::stringstream output;

    for (int day = 0; day <= 20; ++day) {
        output << "Day is " << day << std::endl;
        app.updateQuality();
        app.printItems(output);
    }

    ApprovalTests::Approvals::verify(output.str());
}

