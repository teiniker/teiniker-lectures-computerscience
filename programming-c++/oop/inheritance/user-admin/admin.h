#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <string>

#include "user.h"
#include "mail.h"

class Admin : public User
{
	private:
		std::string _password;
 
	public:                
		Admin(int id, const std::string& username, const std::string& password, Mail* mail);

		std::string password();
		void password(const std::string& password);
 };

#endif /*_USER_H_ */
