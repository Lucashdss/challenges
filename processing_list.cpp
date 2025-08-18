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
            cout << "\n"
                 << endl;
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
