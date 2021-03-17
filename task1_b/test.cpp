/**
* AUTHOR: <Amit Cohen>
* ID: <205451743>
*/

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_(.,.)( : )( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("_/_\\(o_o)(] [)> (   )"));
    CHECK(nospaces(snowman(12222212)) == nospaces(" _===_\\(o.o)/( : )(" ")"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_(.,.)( : )( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ .....(.,.)( : )( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("  _  /_\\ (.,.)( : )( : )"));

}

TEST_CASE("Bad snowman code")
{
    //Negative number
    CHECK_THROWS(snowman(-12345678));
    //digits bettwen 1-7 ,9
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12345));
    CHECK_THROWS(snowman(123456));
    CHECK_THROWS(snowman(1234567));
    CHECK_THROWS(snowman(123456789));
    //digits out of range (1-4)
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(99999999));
    CHECK_THROWS(snowman(00000000));
    CHECK_THROWS(snowman(55555555));
}