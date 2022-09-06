#include <iostream>
#include <cmath>

bool isDigitsUnique(const unsigned int& a)
{
    const unsigned MAX_SIZE = 10;
    int arr[MAX_SIZE], count = 0, temp = -1;

    while (temp != 0)
    {
        int p = pow(10, count);
        temp = (a / p) % 10;
        for (int i = 0; i < count; i++)
        {
            if (temp == arr[i])
                return false;
        }
        arr[count] = temp;
        count++;
    }

    return true;
}

int main()
{
    unsigned int a;
    do
    {
        std::cout << "a = ";
        std::cin >> a;
    } while (a < 10);
    
    std::cout << std::boolalpha << isDigitsUnique(a) << std::endl;
    return 0;
}
