#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <limits>

int main()
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'?!.,;:"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr=-+*^%$"};
    bool run = true;
    char choice{};

    do
    {
        cout << "A - to encrypt a message" << endl;
        cout << "B - to decrypt a message" << endl;
        cout << "C - to exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 'a':
            case 'A':
            {
                string message{};
                string encryptedMessage{};
                cout << "\nEnter the message to encrypt: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, message);

                for (auto letter : message)
                {
                    size_t current_position = alphabet.find(letter);
                    if (current_position != string::npos)
                    {
                        encryptedMessage += key[current_position];
                    }
                    else
                    {
                        encryptedMessage += letter; // If letter not found, keep it unchanged
                    }
                }
                cout << encryptedMessage << endl;
                break;
            }

            case 'b':
            case 'B':
            {
                string encryptedMessage{};
                string decryptedMessage{};
                cout << "\nEnter the message to decrypt: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, encryptedMessage);

                for (auto letter : encryptedMessage)
                {
                    size_t current_position = key.find(letter);
                    if (current_position != string::npos)
                    {
                        decryptedMessage += alphabet[current_position];
                    }
                    else
                    {
                        decryptedMessage += letter; // If letter not found, keep it unchanged
                    }
                }
                cout << decryptedMessage << "\n" << endl;
                break;
            }

            case 'c':
            case 'C':
            {
                cout << "\nExiting the program." << endl;
                run = false;
                break;
            }

            default:
            {
                cout << "Invalid choice, please try again.\n" << endl;
                break;     
            }
        }
    } while (run);

    return 0;
}