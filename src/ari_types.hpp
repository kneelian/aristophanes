#include "utf8.h"
#include <string>
#include <vector>
#include <algorithm>

namespace ari {

struct unit
{
	uint32_t breathing : 2; 
	uint32_t accent    : 2;
	uint32_t length    : 2;
	uint32_t iota      : 1;
	
	uint32_t RESERVED  : 4;

	uint32_t codept    : 21;
};

struct word
{
	std::vector<unit> data;
	word() {}
   ~word() {}
};

word normalise(std::string& in)
/*
	This function takes a string containing a Greek
	word encoded in UTF-8 in arbitrary case with 
	potentially mismatched accent encodings, missing
	breathings, etc. and converts it into the internal 
	word format  
*/
{
	return word{};
}

void denormalise(std::string& tgt, word& in)
/*
	This function takes a word encoded in the
	internal word format and converts it
	to a UTF-8 string.
*/
{
	return;
}

}
