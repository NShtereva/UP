#include <iostream>

const size_t MAX_LEN = 20;

int length(const char* a)
{
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    return i;
}

void copy(char* str1, char* str2)
{
    int size = length(str2);
    for (int i = 0; i < size; i++)
    {
        str1[i] = str2[i];
    }
    str1[size] = '\0';
}

void sort(char arr[][MAX_LEN], const size_t size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(length(arr[i]) > length(arr[j]))
            {
                char temp[MAX_LEN];
                copy(temp, arr[i]);
                copy(arr[i], arr[j]);
                copy(arr[j], temp);
            }
        }
    }
}

int main()
{
    const size_t MAX_SIZE = 8;
    char arr[MAX_SIZE][MAX_LEN];

    for(int i = 0; i < MAX_SIZE; i++)
    {
        std::cin >> arr[i];
    }

    sort(arr, MAX_SIZE);

    std::cout << std::endl;
    for(int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
