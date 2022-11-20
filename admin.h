#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Administrator: public User
{
public:
    Administrator();
};

Administrator::Administrator()
{
    UserList.push("admin");
    PassList.push("Admin12345");
}

#endif // ADMIN_H
