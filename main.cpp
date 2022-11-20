#include "linked_list.h"

using namespace std;

int main()
{
     /* Start with the empty list */
    LinkedList usernameList, passwordList;
    string x = "haha";
    int index;
    string password;

    /* Use push() to construct below list
    14->21->11->30->10 */
    usernameList.insertNode("test1");
    usernameList.insertNode("test2");
    usernameList.insertNode("test3");
    usernameList.insertNode("test4");
    usernameList.insertNode("test5");

    passwordList.insertNode("pass1");
    passwordList.insertNode("pass2");
    passwordList.insertNode("pass3");
    passwordList.insertNode("pass4");
    passwordList.insertNode("pass5");


    usernameList.printList();
    cout << endl;
    passwordList.printList();
    cout << endl;

    usernameList.getIndex(x);

    cout << "index: " << usernameList.returnIndex() << endl;
    return 0;
}
