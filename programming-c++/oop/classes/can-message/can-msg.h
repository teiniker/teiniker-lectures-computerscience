#ifndef _CAN_MESSAGE_H_
#define _CAN_MESSAGE_H_

#include <cstdint>
#include <string>

class CanMsg
{
    public:
        CanMsg(uint32_t id, uint8_t dlc, const uint8_t *data);
        
        // Accessor methods
        uint32_t id() const;
        uint8_t dlc() const;
        uint8_t data(uint8_t index) const;

        // Methods
        std::string asString() const;

    private:
        uint32_t _id;
        uint8_t _dlc;
        uint8_t _data[8];
};

#endif 