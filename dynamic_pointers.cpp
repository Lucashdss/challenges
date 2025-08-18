#include <iostream>

using namespace std;

void print(const int *arr, const int size);
int *apply_all(int *arr1, const size_t &size1, int *arr2, const size_t &size2);

int main()
{
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{array1_size * array2_size};

    cout << "Result: ";
    print(results, results_size);

    delete[] results;
    cout << endl;

    return 0;
}

void print(const int *arr, const int size)
{
    for (int i{}; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *apply_all(int *arr1, const size_t &size1, int *arr2, const size_t &size2)
{
    int *result = new int[size1 * size2];
    int index{0};

    for (int i{}; i < size2; ++i)
    {
        for (int j{}; j < size1; ++j)
        {
            result[index] = arr2[i] * arr1[j];
            ++index;
        }
    }

    return result;
}
