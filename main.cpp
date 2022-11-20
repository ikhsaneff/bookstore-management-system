#include "admin.h"

using namespace std;

int main()
{
    Administrator admin;
    string username, password;

    while (true)
    {
        cout << "=== Login Page ===" << endl;
        cout << " Username: ";
        getline(cin, username);
        cout << " Password: ";
        getline(cin, password);

        transform(username.begin(), username.end(), username.begin(), ::tolower);

        int loginCondition = admin.verifyLogin(username, password);

        if (loginCondition == 1)
        {
            cout << "Login success";
            getche();
            system("cls");
            admin.adminMenu();
        }
        else if (loginCondition == 2)
        {
            cout << "You entered wrong password\n";
            cout << "Try again?";
            getche();
            system("cls");
        }
        else
        {
            cout << "User not found";
        }
    }

}
