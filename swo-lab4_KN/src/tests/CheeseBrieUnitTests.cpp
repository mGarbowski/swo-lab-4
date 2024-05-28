#include <WhiteBear.h>
#include "../items/CheeseBrie.h"

#include <catch2/catch_test_macros.hpp>


#define CATCH_CONFIG_MAIN


TEST_CASE("CheeseBrie updateQuality", "[CheeseBrie]") {

    SECTION("Quality increases by 1 when daysRemaining is positive") {
        CheeseBrie cheese("Cheese Brie", 10, 20);
        cheese.updateQuality();
        REQUIRE(cheese.toString() == "Cheese Brie, 9, 21");
    }

    SECTION("Quality increases by 1 when daysRemaining is one") {
        CheeseBrie cheese("Cheese Brie", 1, 20);
        cheese.updateQuality();
        REQUIRE(cheese.toString() == "Cheese Brie, 0, 21");
    }

    SECTION("Quality increases by 1 when daysRemaining is zero") {
        CheeseBrie cheese("Cheese Brie", 0, 20);
        cheese.updateQuality();
        REQUIRE(cheese.toString() == "Cheese Brie, -1, 22");
    }

    SECTION("Quality increases by 1 when daysRemaining is negative") {
        CheeseBrie cheese("Cheese Brie", -5, 20);
        cheese.updateQuality();
        REQUIRE(cheese.toString() == "Cheese Brie, -6, 22");
    }
}


