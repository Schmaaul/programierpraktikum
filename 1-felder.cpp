#include <iostream>

int *copyArr(int *array, int size)
{
    int *copy = new int[size];
    for (int i = 0; i < size; i++)
    {
        copy[i] = array[i];
    }
    return copy;
}

void swap(int &int1, int &int2)
{
    int helper = int1;
    int1 = int2;
    int2 = helper;
}

void sortArr(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int b = 0; b < size - 1; b++)
        {
            if (array[b] > array[b + 1])
            {
                swap(array[b], array[b + 1]);
                swapped = true;
            }
        }
        if (!swapped) return;       
    }
}

int coutMissing(int *array, int size)
{
    if (size < 2) throw std::invalid_argument("Array size must be 2 or more.");
    array = copyArr(array, size);
    sortArr(array, size);

    int missing = 0;

    int b = array[0];
    for (int i = 0; i < size;) {
        if (b > array[size-1]) throw std::logic_error("Da ist was falsch gelaufen b ist zu groß geworden");
        if (b > array[i]) throw std::logic_error("S O S Endlosschleifen alarm");

        if (array[i] != b) {std::cout << b << ","; missing++;}
        else i++;
        b++;
    }
    std::cout << std::endl;
    return missing;
}

int main()
{

    int arr[] = {8, 10, 11, 7, 3, 15,500};
    coutMissing(arr, 7);
}