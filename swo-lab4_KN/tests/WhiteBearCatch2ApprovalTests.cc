#include "catch2/catch_all.hpp"
#include "ApprovalTests.hpp"
#include "WhiteBear.h"
#include <memory>

TEST_CASE("WhiteBearApprovalTests", "First Test") {

    WhiteBear app;

    app.addItem(std::make_unique<Item>("+7 Yellow Vest", 10, 20));
    app.addItem(std::make_unique<CheeseBrie>("Cheese Brie", 10, 20));
    app.addItem(std::make_unique<Ticket>("Tickets to a concert", 10, 20));
    app.addItem(std::make_unique<Legendary>("Legolas, Hand of Gollum", 10, 20));

    std::stringstream output;

    for (int day = 0; day <= 20; ++day) {
        output << "Day is " << day << std::endl;
        app.updateQuality();
        app.printItems(output);
    }

    ApprovalTests::Approvals::verify(output.str());
}

