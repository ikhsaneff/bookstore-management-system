#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Administrator: public User
{
public:
    Administrator();
    void adminMenu();
    void registerAdmin();
    void showAdmin();
};

Administrator::Administrator()
{
    userList.push("admin");
    passList.push("Admin12345");
}

void Administrator::adminMenu()
{
    int prompt;

    while (true)
    {
        cout << " 1) Register New Admin\n";
        cout << " 2) Register User\n";
        cout << " 3) Register New Faculty or Course\n";
        cout << " 4) Assign Course\n";
        cout << " 0) Log Out\n";
        cout << "Enter: ";
        cin >> prompt;
        system("cls");

        if (prompt == 1)
        {
            registerAdmin();
        }
        else if (prompt == 0)
        {
            cin.ignore();
            return;
        }
    }

}

void Administrator::registerAdmin()
{
    int prompt;
    string newAdmin;
    string newPass;

    while (true)
    {
        cout << " 1) List records\n";
        cout << " 2) Add records\n";
        cout << " 3) Delete records\n";
        cout << " 4) Modify records\n";
        cout << " 0) Back\n";
        cout << "Enter: ";
        cin >> prompt;
        system("cls");

        if (prompt == 1)
        {
            showAdmin();
            system("cls");
        }
        else if (prompt == 2)
        {
            char again;

            while (true)
            {
                cin.ignore();
                cout << "Enter username: ";
                getline(cin, newAdmin);
                cout << "Enter password: ";
                getline(cin, newPass);


                userList.push(newAdmin);
                passList.push(newPass);

                cout << "Add again? (y/n): ";
                cin >> again;
                system("cls");

                if (again == 'n')
                {
                    break;
                }
            }

        }
        else if (prompt == 3)
        {
        }
        else if (prompt == 0)
        {
            return;
        }
    }

}

void Administrator::showAdmin()
{
    while (true)
    {
        int prompt, userNum;
        string userName, userPass;

        userList.printList();
        cout << "1: Show details | 0: Back\n";
        cout << "Enter: ";
        cin >> prompt;

        if (prompt == 1)
        {
            cout << "Which user: ";
            cin >> userNum;
            system("cls");

            userList.getNth(userNum-1);
            passList.getNth(userNum-1);

            userName = userList.returnData();
            userPass = passList.returnData();

            cout << "Username: " << userName << endl;
            cout << "Password: " << userPass << endl;
            getche();
            system("cls");
        }
        else
        {
            return;
        }
    }
}

#endif // ADMIN_H
