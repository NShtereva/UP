#include <iostream>

void print(const bool* vector, const int& N)
{
    for(int i = 0; i < N; i++)
    {
        std::cout << vector[i];
    }
    std::cout << "\n";
}

void generateHelper(bool* vector, const int& N, const int& currIndex)
{
    if(currIndex == 0)
    {
        print(vector, N);
        return;
    }

    vector[currIndex - 1] = 0;
    generateHelper(vector, N, currIndex - 1);

    vector[currIndex - 1] = 1;
    generateHelper(vector, N, currIndex - 1);
}

void generate(bool* vector, const int &N)
{
    generateHelper(vector, N, N);
}

int main()
{
    int N;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0);

    bool *vector = new (std::nothrow) bool[N];
    if(vector == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";
        return 1;
    }
    
    generate(vector, N);

    delete[] vector;
    vector = nullptr;    
    return 0;
}
