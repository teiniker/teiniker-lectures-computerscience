#include "admin.h"

using namespace std;

Admin::Admin(const int id, const string& username, const string& password, Mail* mail)
	: User(id, username, mail), _password{password}
{	
}
			
string Admin::password()
{
	return _password;
}
void Admin::password(const string& password)
{
	_password = password;
}
		
