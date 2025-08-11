// Section 11
// Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
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

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!*/

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

// Function prototypes
void display_menu(char &choice);
void print_numbers(const vector<int> &numbers);
void add_number(vector<int> &numbers);
void calculate_mean(const vector<int> &numbers);
void find_smallest(const vector<int> &numbers);
void find_largest(const vector<int> &numbers);
void clear_list(vector<int> &numbers);
void odd_even(const vector<int> &numbers);
void quit_program(bool &running);

int main()
{
    vector<int> numbers{};
    char choice{};
    bool running = true;

    while (running)
    {
        display_menu(choice);

        if (choice == 'P')
            print_numbers(numbers);
        else if (choice == 'A')
            add_number(numbers);
        else if (choice == 'M')
            calculate_mean(numbers);
        else if (choice == 'S')
            find_smallest(numbers);
        else if (choice == 'L')
            find_largest(numbers);
        else if (choice == 'C')
            clear_list(numbers);
        else if (choice == 'O')
            odd_even(numbers);
        else if (choice == 'Q')
            quit_program(running);
        else
            cout << "error: Invalid choice. Please try again." << endl;
    }

    return 0;
}

void display_menu(char &choice)
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
    choice = toupper(static_cast<unsigned char>(choice));
}

void print_numbers(vector<int> const &numbers)
{
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
}

void add_number(vector<int> &numbers)
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
}

void calculate_mean(const vector<int> &numbers)
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
}

void find_smallest(const vector<int> &numbers)
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
}

void find_largest(const vector<int> &numbers)
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
}

void clear_list(vector<int> &numbers)
{
    numbers.clear();
    cout << "The list has been cleared\n"
         << endl;
}

void odd_even(const vector<int> &numbers)
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
}

void quit_program(bool &running)
{
    cout << "Quitting the program. Goodbye!" << endl;
    running = false;
}