#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstring>
#include <ctime>
using namespace std;
long randomnumbergenerator()
{
    srand(time(0));
    int random = rand() % 9999999999 + 1000000000;
    return random;
}
bool isFileEmpty(const string &filename)
{
    ifstream file(filename); // Open file in read mode

    // Check if the file is empty by using `peek()`
    // `peek()` checks the next character without extracting it
    // If it returns `EOF`, the file is empty
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

private:
    int mpin1, mpin2;

    double account_balance;
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
        if (mpin1 != mpin2)
        {
            cout << "\n Congrulations ! Now , you can use the atm service provided by the bank " << endl;
        }
    }
};

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

    // ofstream file("data.txt"); // open the file in write mode
    // if (file.is_open())
    // {
    //     file << "Hello there! This is your text file." << endl;
    //     // file << "here we are learning about file handelling";
    //     file.close();
    //     cout << "the text is successfully written in the file " << endl;
    // }
    // else
    // {
    //     cout << "the file is not opened" << endl;
    // }
    // ifstream infile("data.txt");//open the file in read mode
    // if (infile.is_open())
    // {
    //     string line;
    //     while (getline(infile, line))
    //     {
    //         cout << line << endl;
    //     }
    //     infile.close();
    // }
    // else
    // {
    //     cout << "the file is not opeaed<<endl ";
    // }
    // file.close();

    switch (index)
    {
    case 1:
    {
        cin.ignore(); // Here,used to ignore the backline character from the buffer

        cout << "Enter your name :" << endl;

        getline(cin, p1.name);
        cout << "Phone number:";
        cin >> p1.phone_no;

        cin.ignore();
        cout << "Enter your age  :" << endl;
        cin >> p1.age;

        cin.ignore();
        cout << "Adress:";
        getline(cin, p1.adress);

        a1.account_No = randomnumbergenerator();
        // cin.ignore();

        cout << "If your are student press 'y' if not press any execpt 'y'";
        char check;
        //    cin>>check;
        // getch();
        check = getch();
        if (check == 'y')
        {
            // cout << "Enter student detail:" << endl;
            // cout << "REG NO :";
            // getline(cin, s1.REG_NO);
            // cin.ignore();
            cout << "\nSchool Name:" << endl;

            getline(cin, s1.name);

            // gfile << left << setw(12) << s1.REG_NO << "\n";
        }
        else
        {
            // gfile << "\n";
        }

        cout << "your account number : " << a1.account_No << endl;
        cout << "\nTo make your transection secure we need setup the mpin code " << endl;
        a1.setmpin();

        ofstream gfile("data.txt", ios::app);

        string line;
        string filename = "data.txt";
        if (isFileEmpty(filename))
        {
            gfile << left << setw(15) << "NAME" << left << setw(14) << "Phone_NO" << left << setw(6) << "AGE" << left << setw(13) << "Accoutn No" << left << setw(6) << "MPIN" << endl;
        }
        gfile << left << setw(15) << p1.name;
        gfile << left << setw(14) << p1.phone_no;
        gfile << left << setw(6) << p1.age;
        gfile << left << setw(13) << a1.account_No;
        gfile << left << setw(6) << a1.MPIN_code << "\n";
        gfile.close();
        break;
    }
    case 2:
    {
        cout << "This function is under development. We will be back soon.";
        break;
    }
    case 3:
    {
        cout << "This function is under development. We will be back soon.";
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