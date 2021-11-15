#pragma once
#include<string>
using namespace std;

enum ErrorCode {
	NegativeSize,
	IndexOutOfReach,
	Weather,
	Article,
	Gender,
	PriceNotFound
};

class Error {
private:
	ErrorCode code;
public:
	Error(ErrorCode code);
	string ToString();
};