#ifndef _MAIL_H_
#define _MAIL_H_

#include <string>

class Mail 
{
	private:
		std::string _address; 
 
	public:
		Mail(const std::string& address);
		//~Mail(void) {}
    
		std::string address() const;
		void address(const std::string& address);
 };

#endif /*_MAIL_H_ */
