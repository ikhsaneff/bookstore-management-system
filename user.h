#ifndef USER_H
#define USER_H

#include "linkedlist.h"

class User
{
public:
    LinkedList UserList;
    LinkedList PassList;
    int verifyLogin(string, string);
};

int User::verifyLogin(string username, string password)
{
    UserList.getIndex(username);
    int userIndex = UserList.returnIndex();

    PassList.getNth(userIndex);
    string userPass = PassList.returnData();

    if (UserList.find(username))
    {
        if (password == userPass)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
        return 0;
}

#endif
