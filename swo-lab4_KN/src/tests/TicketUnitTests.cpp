#include "items/Ticket.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ticket toString method", "[Ticket]") {
    Ticket ticket("Test Ticket", 10, 20);
    REQUIRE(ticket.getQuality() == 20);
    REQUIRE(ticket.getDaysRemaining() == 10);
}

TEST_CASE("Ticket updateQuality method", "[Ticket]") {

    SECTION("Quality increases by 1 when daysRemaining is more than 10") {
        Ticket ticket("Test Ticket", 11, 20);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 21);
        REQUIRE(ticket.getDaysRemaining() == 10);
    }

    SECTION("Quality increases by 2 when daysRemaining is 10 or less but more than 5") {
        Ticket ticket("Test Ticket", 10, 20);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 22);
        REQUIRE(ticket.getDaysRemaining() == 9);

        Ticket ticket2("Test Ticket", 6, 20);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 5, 22");
        REQUIRE(ticket2.getQuality() == 22);
        REQUIRE(ticket2.getDaysRemaining() == 5);
    }

    SECTION("Quality increases by 3 when daysRemaining is 5 or less but more than 0") {
        Ticket ticket("Test Ticket", 5, 20);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 23);
        REQUIRE(ticket.getDaysRemaining() == 4);

        Ticket ticket2("Test Ticket", 1, 20);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 0, 23");
        REQUIRE(ticket2.getQuality() == 23);
        REQUIRE(ticket2.getDaysRemaining() == 0);
    }

    SECTION("Quality drops to 0 after the concert") {
        Ticket ticket("Test Ticket", 0, 20);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 0);
        REQUIRE(ticket.getDaysRemaining() == -1);
    }

    SECTION("Quality does not go above MAX_VALUE") {
        Ticket ticket("Test Ticket", 11, 50);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 50);
        REQUIRE(ticket.getDaysRemaining() == 10);

        Ticket ticket2("Test Ticket", 10, 50);
        ticket2.updateQuality();
        REQUIRE(ticket2.toString() == "Test Ticket, 9, 50");
        REQUIRE(ticket2.getQuality() == 50);
        REQUIRE(ticket2.getDaysRemaining() == 9);

        Ticket ticket3("Test Ticket", 5, 50);
        ticket3.updateQuality();
        REQUIRE(ticket3.toString() == "Test Ticket, 4, 50");
        REQUIRE(ticket3.getQuality() == 50);
        REQUIRE(ticket3.getDaysRemaining() == 4);
    }

    SECTION("Days remaining decreases by 1 each update") {
        Ticket ticket("Test Ticket", 10, 20);
        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 22);
        REQUIRE(ticket.getDaysRemaining() == 9);

        ticket.updateQuality();
        REQUIRE(ticket.getQuality() == 24);
        REQUIRE(ticket.getDaysRemaining() == 8);
    }
}