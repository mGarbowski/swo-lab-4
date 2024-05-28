#include <memory>

#include "ApprovalTests.hpp"
#include "WhiteBear.h"
#include "catch2/catch_all.hpp"
#include "items/CheeseBrie.h"
#include "items/ConjuredItem.h"
#include "items/Legendary.h"
#include "items/Ticket.h"

TEST_CASE("WhiteBearApprovalTests", "First Test") {
  WhiteBear app;

  app.addItem(std::make_unique<Item>("+7 Yellow Vest", 10, 20));
  app.addItem(std::make_unique<CheeseBrie>("Cheese Brie", 10, 20));
  app.addItem(std::make_unique<Ticket>("Tickets to a concert", 10, 20));
  app.addItem(std::make_unique<Legendary>("Legolas, Hand of Gollum", 10, 20));
  app.addItem(std::make_unique<ConjuredItem>("Conjured Item", 10, 40));

  std::stringstream output;

  for (int day = 0; day <= 20; ++day) {
    output << "Day is " << day << std::endl;
    app.updateQuality();
    app.printItems(output);
  }

  ApprovalTests::Approvals::verify(output.str());
}
