#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

// Store all usernames and passwords
map<string, string> users;


// Load registered users from file
void loadUsers()
{
    ifstream file("users.txt");

    string username, password;

    while (file >> username >> password)
    {
        users[username] = password;
    }

    file.close();
}


// Sign Up Function
void signUp()
{
    string username, password, confirmPassword;

    cout << "\n========== CREATE ACCOUNT ==========\n";

    cout << "Enter New Username: ";
    cin >> username;

    // Check if username already exists
    if (users.find(username) != users.end())
    {
        cout << "\nUsername already exists! Try another.\n";
        return;
    }

    cout << "Create Password: ";
    cin >> password;

    cout << "Confirm Password: ";
    cin >> confirmPassword;

    // Check password confirmation
    if (password != confirmPassword)
    {
        cout << "\nPasswords do not match!\n";
        return;
    }

    // Save new account in memory
    users[username] = password;

    // Save account permanently in file
    ofstream file("users.txt", ios::app);

    file << username << " " << password << endl;

    file.close();

    cout << "\n___________________________________\n";
    cout << "Account Created Successfully!\n";
    cout << "You can now Login using your account.\n";
    cout << "___________________________________\n";
}


// Login Function
void login()
{
    string username, password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check username and password
    if (users.find(username) != users.end() &&
        users[username] == password)
    {
        cout << "\n___________________________________\n";
        cout << "Login Successful!\n";
        cout << "Welcome, " << username << "!\n";
        cout << "___________________________________\n";
    }
    else
    {
        cout << "\n___________________________________\n";
        cout << "Invalid Username or Password.\n";
        cout << "Please try again.\n";
        cout << "___________________________________\n";
    }
}


// Main Function
int main()
{
    // Predefined accounts from your original C++ program

    users["Somya"] = "123";
    users["Mayank"] = "234";
    users["Akshat"] = "456";
    users["Kratika"] = "789";
    users["Khushi"] = "000";


    // Load newly registered accounts
    loadUsers();


    int choice;

    do
    {
        cout << "\n===================================\n";
        cout << "          AUTHSHIELD LOGIN         \n";
        cout << "===================================\n";

        cout << "\n1. Login";
        cout << "\n2. Sign Up";
        cout << "\n3. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                login();
                break;

            case 2:
                signUp();
                break;

            case 3:
                cout << "\nThank you for using AuthShield!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while (choice != 3);


    return 0;
}
