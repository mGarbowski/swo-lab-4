#include "items/Ticket.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ticket toString method", "[toString]") {
    Ticket ticket("Test Ticket", 10, 20);
    REQUIRE(ticket.toString() == "Test Ticket, 10, 20");
}

TEST_CASE("Ticket updateQuality method", "[updateQuality]") {

    SECTION("Quality increases by 1 when daysRemaining is more than 10") {
        Ticket ticket("Test Ticket", 11, 20);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 10, 21");
    }

    SECTION("Quality increases by 2 when daysRemaining is 10 or less but more than 5") {
        Ticket ticket("Test Ticket", 10, 20);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 9, 22");

        Ticket ticket2("Test Ticket", 6, 20);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 5, 22");
    }

    SECTION("Quality increases by 3 when daysRemaining is 5 or less but more than 0") {
        Ticket ticket("Test Ticket", 5, 20);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 4, 23");

        Ticket ticket2("Test Ticket", 1, 20);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 0, 23");
    }

    SECTION("Quality drops to 0 after the concert") {
        Ticket ticket("Test Ticket", 0, 20);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, -1, 0");
    }

    SECTION("Quality does not go above MAX_VALUE") {
        Ticket ticket("Test Ticket", 11, 50);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 10, 50");

        Ticket ticket2("Test Ticket", 10, 50);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 9, 50");

        Ticket ticket3("Test Ticket", 5, 50);
        ticket3.updateQuality();
        REQUIRE(ticket3.toString() == "Test Ticket, 4, 50");
    }

    SECTION("Days remaining decreases by 1 each update") {
        Ticket ticket("Test Ticket", 10, 20);
        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 9, 22");

        ticket.updateQuality();
        REQUIRE(ticket.toString() == "Test Ticket, 8, 24");
    }
}