#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code) {
	this->code = code;
}

string Error::ToString() {
	switch (code)
	{
	case NegativeSize:
		return "this size doesnt exist";
	case IndexOutOfReach:
		return "this index doesnt exist";
	case Weather:
		return "weather";
	case Article:
		return "sorry, item not available for purchase";
	case Gender:
		return "sorry, im not being politically incorrect";
	case PriceNotFound:
		return "price not found";
	default:
		return "did svyryd";
	}
}

