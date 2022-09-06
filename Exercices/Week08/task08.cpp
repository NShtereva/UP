#include <iostream>
#include <cmath>

int main()
{
    const unsigned MAX_SIZE = 50;
    int n, arr[MAX_SIZE];
    do
    {
        std::cout << "n = ";
        std::cin >> n;
    } while (n < 2 || n > MAX_SIZE);

    std::cout << "\nEnter an array:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int minPositiveSum = INT_MAX, tempPosI, tempPosJ, maxNegativeSum = INT_MIN, tempNegI, tempNegJ;
        
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] >= 0 && arr[i] + arr[j] < minPositiveSum)
            {
                minPositiveSum = arr[i] + arr[j];
                tempPosI = i;
                tempPosJ = j;
            }

            if (arr[i] + arr[j] < 0 && arr[i] + arr[j] > maxNegativeSum)
            {
                maxNegativeSum = arr[i] + arr[j];
                tempNegI = i;
                tempNegJ = j;
            }
        }
    }

    if (fabs(maxNegativeSum) <= minPositiveSum)
    {
        std::cout << "\n" << arr[tempNegI] << " " << arr[tempNegJ] << "\n";
    }
    else
    {
        std::cout << "\n" << arr[tempPosI] << " " << arr[tempPosJ] << "\n";
    }    
    return 0;
}
