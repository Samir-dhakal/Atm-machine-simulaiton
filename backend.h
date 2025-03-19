#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <ctime>

using namespace std;
long long randomnumbergenerator()
{
    srand(time(0));
    int random = rand() % 9999999999LL + 1000000000LL;
    return random;
}
bool isFileEmpty(const string &filename)
{
    ifstream file(filename);
    if (!file)
        return true; // If file does not exist, consider it empty
    return file.peek() == ifstream::traits_type::eof();
}

class person
{
public:
    string name;
    int age;
    char gender;
    string country;
    string adress;
    long long phone_no;

private:
    double bank_accout;
};
class student : public person
{
public:
    string school;
    string REG_NO;
};
class ATM : public student
{
public:
    long long account_No;

    int MPIN_code;

    int mpin1, mpin2;

    double account_balance = 0;
    void show_account_balance()
    {
        cout << "current_balance:" << account_balance << endl;
    }

public:
    void setmpin()
    {
        do
        {
            cout << "Set your mpin code :";
            cin >> mpin1;
            cin.ignore();
            cout << "Confirm code:";
            cin >> mpin2;
            if (mpin2 == mpin1)
            {
                MPIN_code = mpin1;
                cout << "code confirmed";
            }
            else
            {
                cout << "\nyour code doesnot match.\n TRY AGAIN!!" << endl;
            }

        } while (mpin1 != mpin2);
        cout << "You have to deposit certain amount of money to open the account";
        cin >> account_balance;
        cout << "\n Congrulations ! Now , you can use the atm service provided by the bank " << endl;
    }
};
int withdraw(ATM &a)
{

    ifstream gfile("data.txt");
    if (gfile.is_open())
    {
        string account_no;
        string line;
        cout << "enter the your account number :";
        cin >> account_no;
        bool found = false;
        long long file_account_number;
        string name, phone, mpin;
        int age;
        while (getline(gfile, line))
        {
            // getline(gfile, line);
            if (line.find(account_no) == string::npos)
            {
                found = true;
                cout << "Hello sir you are welcome to our bank ";
                cout << "enter the amount you want to withdraw";
                int withdraw_amount;
                cin >> withdraw_amount;
                if (a.account_balance > withdraw_amount)
                {
                    cout << "Withdrawn successfull";
                    a.account_balance -= withdraw_amount;
                }
                else
                {
                    cout << "insufficient balance ";
                }
                break; // stop searching on found
            }
            if (found = true)
            {
                break;
            }
        }
    }
}
// funciton to enter the data
void enterdata(person &p, ATM &a)
{

    cin.ignore(); // Here,used to ignore the backline character from the buffer

    cout << "Enter your name :" << endl;

    getline(cin, p.name);
    cout << "Phone number:";
    cin >> p.phone_no;

    cin.ignore();
    cout << "Enter your age  :" << endl;
    cin >> p.age;

    cin.ignore();
    // cout << "Adress:";
    // getline(cin, p1.adress);

    a.account_No = randomnumbergenerator();

    cout << "your account number : " << a.account_No << endl;
    cout << "\nTo make your transection secure we need setup the mpin code " << endl;
    a.setmpin();

    ofstream gfile("data.txt", ios::app);

    string line;
    string filename = "data.txt";
    if (isFileEmpty(filename))
    {
        gfile << left << setw(15) << "NAME" << left << setw(14) << "Phone_NO" << left << setw(6) << "AGE" << left << setw(13) << "Accoutn No" << left << setw(6) << "MPIN" << left << setw(10) << "Bank Balance" << endl;
    }
    gfile << left << setw(15) << p.name;
    gfile << left << setw(14) << p.phone_no;
    gfile << left << setw(6) << p.age;
    gfile << left << setw(13) << a.account_No;
    gfile << left << setw(6) << a.MPIN_code;
    gfile << left << setw(10) << a.account_balance << "\n";
    gfile.close();
}
