#include "can-msg.h"

using namespace std;

CanMsg::CanMsg(uint32_t id, uint8_t dlc, const uint8_t *data)
{
    _id = id;
    _dlc = dlc;
    for (int i = 0; i < 8; i++)
    {
        _data[i] = data[i];
    }
}

// Accessor methods
uint32_t CanMsg::id() const
{
    return _id;
}

uint8_t CanMsg::dlc() const
{
    return _dlc;
}

uint8_t CanMsg::data(uint8_t index) const
{
    return _data[index];
}

// Methods
std::string CanMsg::asString() const
{
    char s[35];
    sprintf(s, "CAN:%03x|%x|", _id, _dlc);
    for(uint8_t i = 0; i<_dlc; i++)
    {
        sprintf(s+10+i*3, " %02x", _data[i]);
    }
    return string(s);
}
