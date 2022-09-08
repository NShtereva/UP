#include <iostream>

// 1)
void printHelper(const int* arr, const int& size, const int& currIndex)
{
    if (currIndex == size)
    {
        return;
    }

    std::cout << arr[currIndex] << " ";
    printHelper(arr, size, currIndex + 1);
}

void print(const int* arr, const int& size)
{
    printHelper(arr, size, 0);
    std::cout << std::endl;
}

// 2)
bool isSortedHelper(const int* arr, const int& size, const int& currIndex)
{
    if (currIndex == size - 1)
    {
        return true;
    }

    if (arr[currIndex] > arr[currIndex + 1])
    {
        return false;
    }

    return isSortedHelper(arr, size, currIndex + 1);
}

bool isSorted(const int* arr, const int& size)
{
    return isSortedHelper(arr, size, 0);
}

// 3)
void copy(const int* arr, const int& size, const int& arrIndex, int* newArr)
{
    if (arrIndex == size)
    {
        return;
    }

    newArr[arrIndex + 1] = arr[arrIndex];
    copy(arr, size, arrIndex + 1, newArr);
}

void insertInSortedHelper(const int* arr, const int& size, const int& number, int* newArr, const int& currIndex, const int& arrIndex)
{
    if(size == 0)
    {
        newArr[0] = number;
        return;
    }

    if (currIndex == size + 1)
    {
        return;
    }

    if (arr[arrIndex] < number && arrIndex < size)
    {
        newArr[currIndex] = arr[arrIndex];
        insertInSortedHelper(arr, size, number, newArr, currIndex + 1, arrIndex + 1);
    }
    else
    {
        newArr[currIndex] = number;
        copy(arr, size, arrIndex, newArr);
        insertInSortedHelper(arr, size, number, newArr, size + 1, arrIndex);
    }
}

int* insertInSorted(int*& arr, const int& size, const int& number)
{
    int* newArr = new (std::nothrow) int[size + 1];
    if(!newArr)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        delete[] arr;
        arr = nullptr;

        return newArr;
    }

    insertInSortedHelper(arr, size, number, newArr, 0, 0);

    delete[] arr;
    arr = nullptr;

    return newArr;
}

int main()
{
    int M;
    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M <= 0);

    int *arr = new (std::nothrow) int[M];
    if (!arr)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < M; i++)
    {
        std::cin >> arr[i];
    }

    // 1)
    std::cout << std::endl;
    print(arr, M);

    // 2)
    std::cout << "Sorted: " << std::boolalpha << isSorted(arr, M) << std::endl;

    // 3)
    int* newArr = insertInSorted(arr, M, 0);        // 1 2 4 4 5 -> 0 1 2 4 4 5
    // int* newArr = insertInSorted(arr, M, 6);     // 1 2 4 4 5 -> 1 2 4 4 5 6
    // int* newArr = insertInSorted(arr, M, 3);     // 1 2 4 4 5 -> 1 2 3 4 4 5
    // int* newArr = insertInSorted(arr, M, 5);     // 1 2 4 4 5 -> 1 2 4 4 5 5
    if(newArr)
    {
        M++;

        std::cout << std::endl;
        print(newArr, M);
        std::cout << "Sorted: " << std::boolalpha << isSorted(newArr, M) << std::endl;

        M--;

        delete[] newArr;
        newArr = nullptr;
    }

    std::cout << std::endl;

    // 4)
    int N;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0 || N >= 1000);

    int number;
    for(int i = 0; i < N; i++)
    {
        std::cin >> number;
        arr = insertInSorted(arr, i, number);
    }

    // 5)
    std::cout << std::endl;
    std::cout << "Sorted: " << std::boolalpha << isSorted(arr, N) << std::endl;
    print(arr, N);

    delete[] arr;
    arr = nullptr;
    return 0;
}
