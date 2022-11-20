#ifndef USER_H
#define USER_H

#include "linkedlist.h"

class User
{
public:
    LinkedList userList;
    LinkedList passList;
    int verifyLogin(string, string);
};

int User::verifyLogin(string username, string password)
{
    userList.getIndex(username);
    int userIndex = userList.returnIndex();

    passList.getNth(userIndex);
    string userPass = passList.returnData();

    if (userList.find(username))
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
