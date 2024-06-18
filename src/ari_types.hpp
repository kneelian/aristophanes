#include "utf8.h"
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

#define NONE   0x0
#define ROUGH  0x2
#define SMOOTH 0x3

#define ACUTE  0x1
#define GRAVE  0x2
#define CIRCU  0x3

#define SHORT  0x2
#define LONG   0x3

#define IOTA   0x1

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
	if(!utf8::is_valid(in)) { return word{}; } // do not try to fix broken string, return empty

	word tmp{};
	auto iter = in.begin();

	while(iter != in.end())
	{
		uint32_t ch = utf8::next(iter, in.end());
		uint32_t breath = NONE, acc = NONE, leng = NONE, iota = NONE, res = 0, code = 0x0;
		switch(ch)
		{
		case 0x1f00:
		case 0x1f08:
		case 0x1f04:
		case 0x1f0c:
		case 0x1f84:
		case 0x1f8c:
		case 0x1f02:
		case 0x1f0a:
		case 0x1f82:
		case 0x1f8a:
		case 0x1f06:
		case 0x1f0e:
		case 0x1f86:
		case 0x1f8e:
		case 0x1f80:
		case 0x1f88:
			breath = SMOOTH;
			break;

		case 0x1f01:
		case 0x1f09:
		case 0x1f05:
		case 0x1f0d:
		case 0x1f85:
		case 0x1f8d:
		case 0x1f03:
		case 0x1f0b:
		case 0x1f83:
		case 0x1f8b:
		case 0x1f81:
		case 0x1f89:
		case 0x1f07:
		case 0x1f0f:
		case 0x1f87:
		case 0x1f8f:
			breath = ROUGH;
			break;

		}
	}


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
