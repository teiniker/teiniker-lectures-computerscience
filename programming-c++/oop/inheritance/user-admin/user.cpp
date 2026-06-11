#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, Mail* mail)
	: _id{id}, _username{username}, _mail{mail}
{
}
	
int User::id() const
{
	return _id;
}
void User::id(const int id)
{
	_id = id;
}
		
string User::username(void) const
{
	return _username;
}
void User::username(const string& username)
{
	_username = username;	
}
		
Mail* User::mail() const
{
	return _mail;
}
void User::maild(Mail* mail)
{
	_mail = mail;
}		
