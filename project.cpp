#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void login();
void registration();

int main()
{
    int choice;

    while (true) 
	{
		cout<<"----------------------------------------------------------"<<endl;
		cout<<"Project Is Made by Javed Iqbal"<<endl;
		cout<<"----------------------------------------------------------"<<endl;
		cout<<endl;
        cout<< "          Welcome to the Login Page      \n\n";
        cout<< "_________        MENU        ____________\n\n";
        cout<< "Press 1 to LOGIN\n";
        cout<< "Press 2 to REGISTER\n";
        cout<< "Press 3 to EXIT\n";
        cout<< "Please enter your choice: ";
        cin>> choice;
        cout<< endl;

        if (choice == 1) {
            login();
        } else if (choice == 2) {
            registration();
        } else if (choice == 3) {
            cout << "Thank you!\n";
            break;
        } else {
            cout << "Please select a valid option from the menu\n" << endl;
        }
    }
    return 0;
}

void login()
{
    string userId, password, id, pass;
    int count = 0;

    cout<< "Please enter the username and password:\n";
    cout<< "USERNAME: ";
    cin>> userId;
    cout<< "PASSWORD: ";
    cin>> password;

    ifstream input("records.txt");

    while(input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout<< userId<< "\nYour LOGIN is successful\nThanks for logging in!\n";
    }
    else
    {
        cout<< "\nLOGIN ERROR\nPlease check your username and password\n";
    }
}

void registration()
{
    string ruserId, rpassword;
    cout<< "Enter the username: ";
    cin>> ruserId;
    cout<< "Enter the password: ";
    cin>> rpassword;
    ofstream f1("records.txt", ios::app);
    f1<< ruserId << " " << rpassword << endl;
    cout<< "\nRegistration is successful!\n";
}
