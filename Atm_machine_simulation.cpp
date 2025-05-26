#include <iostream>

#include "backend.h"
using namespace std;
void enterdata(person &p1, ATM &a1);
int withdraw(ATM &a);
int deposit(ATM &a);
int main()
{
    person p1;
    student s1;
    ATM a1;
    cout << "Press according to intex given below\n";
    cout << "1:TO open bank account\n";
    cout << "2:TO withdraw money form bank account\n";
    cout << "3:TO diposit money\n";
    cout << "4:TO to request form the loan\n";
    cout << "5:TO exit the program \n";
    int index;
    cin >> index;

    switch (index)// switch case to handle the operation .
    {
    case 1:
    {
        enterdata(p1, a1);
        break;
    }
    case 2:
    {
        withdraw(a1);
        break;
    }
    case 3:
    {
        deposit(a1);// to deposit the amoutn in the bank account 
        break;
    }
    case 4:
    {
        cout << "This funciton is under development. We will be back soon.";
        break;
    }
    case 5:
    {
        cout << "Here, you exit the program ";
        exit(0);
        break;
    }
    }
    return 0;
}
