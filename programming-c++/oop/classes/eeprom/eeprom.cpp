#include "eeprom.h"

using namespace std;

EEPROM::EEPROM(const string& type, const size_t size)
	: _type{type}, _size{size}
{
	_memory = new uint8_t[_size]; // malloc(.. sizeof())
}

EEPROM::~EEPROM()
{
	delete[] _memory;  // free(memory_)
} 

string EEPROM::type(void) const 
{
	return _type;
}

uint8_t EEPROM::read(const uint32_t address) const
{
	// 0 <= address < size
	return _memory[address]; 
}

void EEPROM::write(const uint32_t address, const uint8_t value)
{
	// 0 <= address < size
	_memory[address] = value;
}
