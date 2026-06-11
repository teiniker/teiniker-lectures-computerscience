#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		Mail* _mail;
 
	public:                
		User(const int id, const std::string& username, Mail* mail);

		int id() const;
		void id(const int id);
		
		std::string username(void) const;
		void username(const std::string& username);

		Mail* mail() const;
		void maild(Mail* mail);		
 };

#endif /*_USER_H_ */
