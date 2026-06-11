#include "sequence.h"

int IntegerSequence::_value = 0; // static

IntegerSequence::IntegerSequence(void)
{
	_id = IntegerSequence::next();
}
		
void IntegerSequence::init(int value) // static
{
	_value = value;
}

int IntegerSequence::next(void)  // static
{
	return _value++;
}

int IntegerSequence::id(void)
{
	return _id;
}

