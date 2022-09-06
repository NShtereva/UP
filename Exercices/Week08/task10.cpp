#include <iostream>

void func(const int& n, int* arr)
{
    int count = 0, pos1 = -1, pos2 = -1;

    for (int i = 0; i < n; i++)
    {
        int tempCount = 0, tempI = i, tempJ;
        for (int j = i; j < n; j++)
        {
            if (arr[j] <= arr[j + 1])
            {
                tempCount++;
                tempJ = j + 1;
            }
            else break;
        }

        if (tempCount > count)
        {
            count = tempCount;
            pos1 = tempI;
            pos2 = tempJ;
        }
    }

    if (pos1 > -1 && pos2 > -1)
    {
        std::cout << pos1 << " " << pos2 << "\n";
    }
    else
    {
        std::cout << "\nNo such sequence!\n";
    }
}

int main()
{
    const unsigned MAX_SIZE = 50;
    int arr[MAX_SIZE], n;
    std::cout << "n = ";
    std::cin >> n;

    std::cout << "\nEnter an array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    func(n, arr);
    return 0;
}
