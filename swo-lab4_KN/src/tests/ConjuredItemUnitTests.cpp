#include <catch2/catch_test_macros.hpp>
#include "items/ConjuredItem.h"

TEST_CASE("ConjuredItem toString method", "[toString]") {
    ConjuredItem conjuredItem("Test ConjuredItem", 10, 20);
    REQUIRE(conjuredItem.toString() == "Test ConjuredItem, 10, 20");
}


TEST_CASE("ConjuredItem updateQuality method", "[updateQuality]") {
    SECTION("Quality decreases by 2 when daysRemaining is positive") {
        ConjuredItem conjuredItem("Test ConjuredItem", 10, 20);
        conjuredItem.updateQuality();
        REQUIRE(conjuredItem.getDaysRemaining() == 9);
        REQUIRE(conjuredItem.getQuality() == 18);
    }

    SECTION("Quality decreases by 4 when daysRemaining is zero or less") {
        ConjuredItem conjuredItem("Test ConjuredItem", 0, 20);
        conjuredItem.updateQuality();
        REQUIRE(conjuredItem.getDaysRemaining() == -1);
        REQUIRE(conjuredItem.getQuality() == 16);
    }

    SECTION("Quality is never negative") {
        ConjuredItem conjuredItem("Test ConjuredItem", 10, 0);
        conjuredItem.updateQuality();
        conjuredItem.updateQuality();
        REQUIRE(conjuredItem.getDaysRemaining() == 8);
        REQUIRE(conjuredItem.getQuality() == 0);
    }
}