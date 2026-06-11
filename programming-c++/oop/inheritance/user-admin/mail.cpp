#include "mail.h"

using namespace std;

Mail::Mail(const string& address) 
    : _address{address} 
{
}
    
string Mail::address() const
{
    return _address;
}

void Mail::address(const string& address)
{
    _address = address;
}
