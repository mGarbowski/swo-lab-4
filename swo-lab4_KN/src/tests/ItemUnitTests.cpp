#include "items/Item.h"
#include <catch2/catch_test_macros.hpp>


#define CATCH_CONFIG_MAIN

TEST_CASE("Item toString method", "[Item]") {
    Item item("Test Item", 10, 20);
    REQUIRE(item.getQuality() == 20);
    REQUIRE(item.getDaysRemaining() == 10);
}

TEST_CASE("Item updateQuality method", "[Item]") {

    SECTION("Quality decreases by 1 when daysRemaining is positive") {
        Item item("Test Item", 10, 20);
        item.updateQuality();
        REQUIRE(item.getQuality() == 19);
        REQUIRE(item.getDaysRemaining() == 9);
    }

    SECTION("Quality decreases by 2 when daysRemaining is zero or less") {
        Item item("Test Item", 0, 20);
        item.updateQuality();
        REQUIRE(item.getQuality() == 18);
        REQUIRE(item.getDaysRemaining() == -1);

        Item item2("Test Item", -1, 20);
        item2.updateQuality();
        REQUIRE(item2.getQuality() == 18);
        REQUIRE(item2.getDaysRemaining() == -2);
    }

    SECTION("Quality does not go below MIN_VALUE") {
        Item item("Test Item", 0, 1);
        item.updateQuality();
        REQUIRE(item.getQuality() == 0);
        REQUIRE(item.getDaysRemaining() == -1);

        Item item2("Test Item", 10, 0);
        item2.updateQuality();
        REQUIRE(item2.getQuality() == 0);
        REQUIRE(item2.getDaysRemaining() == 9);

        Item item3("Test Item", -1, 0);
        item3.updateQuality();
        REQUIRE(item3.getQuality() == 0);
        REQUIRE(item3.getDaysRemaining() == -2);
    }

    SECTION("Days remaining decreases by 1 each update") {
        Item item("Test Item", 10, 20);
        item.updateQuality();
        REQUIRE(item.getQuality() == 19);
        REQUIRE(item.getDaysRemaining() == 9);

        item.updateQuality();
        REQUIRE(item.getQuality() == 18);
        REQUIRE(item.getDaysRemaining() == 8);
    }
}


