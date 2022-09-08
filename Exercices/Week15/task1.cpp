#include <iostream>

bool hasPath(char** lab, const int& N, const int& M, const int& x0, const int& y0, const int& x1, const int& y1)
{
    if(lab[x0 - 1][y0 - 1] == '#')
    {
        return false;
    }

    if(x0 == x1 && y0 == y1)
    {
        return true;
    }

    lab[x0 - 1][y0 - 1] = '#';

    bool found = false;

    if(y0 - 2 >= 0 && lab[x0 - 1][y0 - 2] == '.')
    {
        if(!found)
        {
            found = hasPath(lab, N, M, x0, y0 - 1, x1, y1);
        }
    }
    
    if(y0 < M && lab[x0 - 1][y0] == '.')
    {
        if(!found)
        {
            found = hasPath(lab, N, M, x0, y0 + 1, x1, y1);
        }
    }

    if(x0 - 2 >= 0 && lab[x0 - 2][y0 - 1] == '.')
    {
        if(!found)
        {
            found = hasPath(lab, N, M, x0 - 1, y0, x1, y1);
        }
    }

    if(x0 < N && lab[x0][y0 - 1] == '.')
    {
        if(!found)
        {
            found = hasPath(lab, N, M, x0 + 1, y0, x1, y1);
        }
    }

    lab[x0 - 1][y0 - 1] = '.';

    return found;
}

int main()
{
    int N, M;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0);

    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M <= 0);
    
    char** lab = new(std::nothrow) char*[N];
    if(lab == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";
        return 1;
    }
    for(int i = 0; i < N; i++)
    {
        lab[i] = new (std::nothrow) char[M];
        if(lab[i] == nullptr)
        {
            std::cout << "\nMemory not allocated successfully!\n";
            return 1;
        }
    }

    std::cout << "\n";
    for(int i = 0; i < N; i++)
    {
        std::cin >> lab[i];
    }

    std::cout << "\n";
    int x0, y0, x1, y1;
    do
    {
        std::cin >> x0 >> y0;
    } while ((x0 < 1 || x0 > N) || (y0 < 1 || y0 > M));

    do
    {
        std::cin >> x1 >> y1;
    } while ((x1 < 1 || x1 > N) || (y1 < 1 || y1 > M));

    std::cout << "\n" << hasPath(lab, N, M, x0, y0, x1, y1) << "\n";

    for(int i = 0; i < N; i++)
    {
        delete[] lab[i];
    } delete[] lab;
    
    lab = nullptr;
    return 0;
}
