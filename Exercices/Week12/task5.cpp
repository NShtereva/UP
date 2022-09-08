#include <iostream>

void print(const int& size, const int* arr)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void solve(const int& N, const int& M, int* arr, int currentPosition)
{
    int sum = 0;
    for(int i = 0; i < currentPosition; i++)
    {
        sum = sum + arr[i];
    }

    if(sum == M && currentPosition == N)
    {
        print(N, arr);
        std::cout << std::endl;
        return;
    }

    if(currentPosition > N)
    {
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        arr[currentPosition] = i;
        solve(N, M, arr, currentPosition + 1);
    }
}

int main()
{
    int N, M;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N < 0);

    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M < 0);

    std::cout << std::endl;

    int* arr = new(std::nothrow) int[N];
    if(!arr)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    solve(N, M, arr, 0);

    delete[] arr;
    arr = nullptr;

    return 0;
}
