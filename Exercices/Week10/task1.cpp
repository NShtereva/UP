#include <iostream>

int main()
{
    const unsigned MAX_SIZE = 20;
    int arr[MAX_SIZE][MAX_SIZE];

    size_t N, M;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0 || N > MAX_SIZE);
    
    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M <= 0 || M > MAX_SIZE);

    for (size_t j = 0; j < M; j++)
    {
        for (size_t i = 0; i < N; i++)
        {
            std::cin >> arr[i][j];
        }
    }

    std::cout << std::endl;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
