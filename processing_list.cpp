// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    C - Clear the list
    O - Display odd and even numbers
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

If the user enters 'C' or 'c' then you should clear the list and display "The list has been cleared"

If the user enters 'O' or 'o' then you should display all of the odd and even numbers in the list.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> numbers{}; 
    char choice{};
    bool running = true;

    do
    {
        cout << "P - print numbers in the list" << endl;
        cout << "A - add a number to the list" << endl;
        cout << "M - Display mean of the numbers in the list" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "C - clear the list" << endl;
        cout << "O - display the odd and even numbers in the list" << endl;
        cout << "Q - Quit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'p':
        case 'P':
            if (numbers.size() == 0)
            {
                cout << "[] - the list is empty\n"
                     << endl;
            }
            else
            {
                cout << "[";
                for (auto num : numbers)
                {
                    cout << num << " ";
                }
                cout << "]" << endl;
            }
            break;

        case 'a':
        case 'A':
        {
            int num_to_add;
            cout << "enter an integer to add to the list: ";
            cin >> num_to_add;
            if (num_to_add % 1 != 0)
            {
                cout << "sorry, invalid input, please enter an integer\n"
                     << endl;
            }
            else
            {
                numbers.push_back(num_to_add);
                cout << num_to_add << " added\n"
                     << endl;
            }
            break;
        }

        case 'm':
        case 'M':
        {
            if (numbers.size() == 0)
            {
                cout << "unable to calculate the mean - no data\n"
                     << endl;
            }
            else
            {
                double avg{};
                for (auto num : numbers)
                {
                    avg += num;
                }
                cout << "The average is " << avg / numbers.size() << "\n"
                     << endl;
            }
            break;
        }

        case 's':
        case 'S':
        {
            if (numbers.size() == 0)
            {
                cout << "Unable to determine the smallest number - list is empty\n"
                     << endl;
            }
            else
            {
                int smallest = numbers[0];
                for (auto num : numbers)
                {
                    if (num < smallest)
                    {
                        smallest = num;
                    }
                    else
                        continue;
                }
                cout << "The smallest number is " << smallest << "\n"
                     << endl;
            }
            break;
        }

        case 'l':
        case 'L':
        {
            if (numbers.size() == 0)
            {
                cout << "Unable to determine the largest number - list is empty\n"
                     << endl;
            }
            else
            {
                int largest = numbers[0];
                for (auto num : numbers)
                {
                    if (num > largest)
                    {
                        largest = num;
                    }
                    else
                        continue;
                }
                cout << "The largest number is " << largest << "\n"
                     << endl;
            }
            break;
        }

        case 'c':
        case 'C':
        {
            numbers.clear();
            cout << "The list has been cleared\n"
                 << endl;
            break;
        }

        case 'o':
        case 'O':
        {
            vector<int> odd_numbers{};
            vector<int> even_numbers{};
            for (auto num : numbers)
            {
                if (num % 2 == 0)
                {
                    even_numbers.push_back(num);
                }
                else
                {
                    odd_numbers.push_back(num);
                }
            }
            cout << "odd numbers: ";
            for (auto num : odd_numbers)
            {
                cout << num << " ";
            }
            cout << "\neven numbers: ";
            for (auto num : even_numbers)
            {
                cout << num << " ";
            }
            cout << "\n" << endl;
            break;
        }

        case 'q':
        case 'Q':
            cout << "Goodbye!\n"
                 << endl;
            running = false;
            break;

        default:
            cout << "Unknown selection, please try again\n"
                 << endl;
            break;
        }

    } while (running);

    return 0;
}


