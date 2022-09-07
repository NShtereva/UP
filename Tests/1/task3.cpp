#include <iostream>

int main()
{
    const unsigned MAX_SIZE = 99999;
    double array[MAX_SIZE];

    int n;
    do
    {
        std::cin >> n;
    } while (n <= 0 || n > MAX_SIZE);

    for(int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    const double epsilon = 0.000001;

    int K = 0;
    double M = 0;

    int limit = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);

    for(int k = 1; k <= limit; k++)
    {
        bool flag = true, correctK = false;
        double m = std::abs(array[0] - array[k]);

        for(int i = k; i < n - k; i += k)
        {
            correctK = true;
            double currM = std::abs(array[i] - array[i + k]);

            if(!(std::abs(m - currM) < epsilon))
            {
                flag = false;
                break;
            }
        }

        if(flag && correctK && K < k)
        {
            K = k;
            M = m;
        }
    }

    if(K == 0)
        std::cout << "\nNo solution!" << std::endl;
    else
        std::cout << std::endl << K << " " << M << std::endl;
        
    return 0;
}
