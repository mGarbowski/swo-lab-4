#include <WhiteBear.h>

#include <catch2/catch_test_macros.hpp>


#define CATCH_CONFIG_MAIN

TEST_CASE("Item toString method", "[toString]") {
    Item item("Test Item", 10, 20);
    REQUIRE(item.toString() == "Test Item, 10, 20");
}

TEST_CASE("Item updateQuality method", "[updateQuality]") {

    SECTION("Quality decreases by 1 when daysRemaining is positive") {
        Item item("Test Item", 10, 20);
        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, 9, 19");
    }

    SECTION("Quality decreases by 2 when daysRemaining is zero or less") {
        Item item("Test Item", 0, 20);
        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, -1, 18");

        Item item2("Test Item", -1, 20);
        item2.updateQuality();
        REQUIRE(item2.toString() == "Test Item, -2, 18");
    }

    SECTION("Quality does not go below MIN_VALUE") {
        Item item("Test Item", 0, 1);
        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, -1, 0");

        Item item2("Test Item", 10, 0);
        item2.updateQuality();
        REQUIRE(item2.toString() == "Test Item, 9, 0");

        Item item3("Test Item", -1, 0);
        item3.updateQuality();
        REQUIRE(item3.toString() == "Test Item, -2, 0");
    }

    SECTION("Days remaining decreases by 1 each update") {
        Item item("Test Item", 10, 20);
        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, 9, 19");

        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, 8, 18");
    }
}


