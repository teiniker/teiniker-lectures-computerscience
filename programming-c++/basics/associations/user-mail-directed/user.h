#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		User(const int id, const std::string& username, const std::string& password, Mail* mail);

		int id(void) const;
		void id(const int id);
		
		std::string username(void) const;
		void username(const std::string& username);
		
		std::string password() const;
		void password(const std::string& password);
		
		// ---[1]-> Mail
		Mail* mail(void) const;
		void mail(Mail* mail);
 };

#endif /*_USER_H_ */
