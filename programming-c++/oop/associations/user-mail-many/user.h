#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "mail.h"

class User
{
    private:
        int         _id;
        std::string _username;
        std::string _password;
        std::vector<Mail*> _mails;      // ---[*]-> Mail

    public:
        User(const int id, const std::string& username,
             const std::string& password);

        int id() const;
        void id(const int id);

        std::string username() const;
        void username(const std::string& username);

        std::string password() const;
        void password(const std::string& password);

        // ---[*]-> Mail
        void   addMail(Mail* mail);
        Mail*  mail(int index) const;
        size_t mailCount() const;
};

#endif /* _USER_H_ */
