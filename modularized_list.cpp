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