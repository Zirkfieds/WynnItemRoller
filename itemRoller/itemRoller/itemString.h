#pragma once
#include"itemRoller.h"

#include<regex>

#define STARTER 0xF5FF0
#define TERMINATOR 0xF5FF1
#define SEPARATOR 0xF5FF2
#define BASE_OFFSET 0xF5000

/**
 * Encodes the given item, as long as it is a standard gear item, into the following format
 *
 * START character (U+F5FF0)
 * Item name (optionally encoded)
 * SEPARATOR character (U+F5FF2)
 * Identifications/stars (encoded)
 * SEPARATOR (only if powdered)
 * Powders (encoded) (only if powdered)
 * Rerolls (encoded)
 * END character (U+F5FF1)
 *
 * Any encoded "value" is added to the OFFSET character value U+F5000 and then converted into the corresponding Unicode character:
 *
 * The name is encoded based on the ASCII value of each character minus 32
 *
 * Identifications are encoded either as the raw value minus the minimum value of that ID, or if the range is larger than 100,
 * the percent value 0 to 100 of the given roll.
 * Regardless of either case, this number is multiplied by 4, and the number of stars present on that ID is added.
 * This ensures that the value and star count can be encoded into a single character and be decoded later.
 *
 * Powders are encoded as numerical values 1-5. Up to 4 powders are encoded into a single character - for each new powder,
 * the running total is multiplied by 6 before the new powder value is added. Thus, each individual powder can be decoded.
 *
 * Rerolls are simply encoded as a raw number.
 *
 */

class ItemScreenshot {
private:
	string finalProduct;
	

public:


};