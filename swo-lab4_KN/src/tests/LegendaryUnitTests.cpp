#include <WhiteBear.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Legendary updateQuality method", "[updateQuality]") {

    SECTION("Quality and days remaining do not change") {
        Legendary item("Test Item", 10, 20);
        item.updateQuality();
        REQUIRE(item.toString() == "Test Item, 10, 20");
    }
}