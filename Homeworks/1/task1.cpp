#include <iostream>

int main()
{
    double x1, y1, w1, h1;
    std::cout << "first rectangle:" << std::endl;
    std::cin >> x1 >> y1 >> w1 >> h1;

    double x2, y2, w2, h2;
    std::cout << "second rectangle:" << std::endl;
    std::cin >> x2 >> y2 >> w2 >> h2;

    double S = 0;

    if(x1 == x2 && y1 == y2)
    {
        S = std::min(w1, w2) * std::min(h1, h2);
    }
    else if(x1 >= x2 && y1 >= y2)
    {
        if(x2 + w2 > x1 && y2 + h2 > y1)
        {
            double a = (x2 + w2) - x1,
                   b = (y2 + h2) - y1;
            S = a * b;
        }
    }
    else if(x1 >= x2 && y1 <= y2)
    {
        if(x1 < x2 + w2 && y1 + h1 > y2)
        {
            double a = (x2 + w2) - x1,
                   b = (y1 + h1) - y2;
            S = a * b;
        }
    }
    else if(x1 <= x2 && y1 >= y2)
    {
        if(y1 < y2 + h2)
        {
            double a = (x1 + w1) - x2,
                   b = (y2 + h2) - y1;
            S = a * b;
        }
    }
    else if(x1 <= x2 && y1 <= y2)
    {
        if(x2 < x1 + w1 && y2 < y1 + h1)
        {
            double a = (x1 + w1) - x2,
                   b = (y1 + h1) - y2;
            S = a * b;
        }
    }

    std::cout << "\nS = " << S << std::endl;
    return 0;
}
