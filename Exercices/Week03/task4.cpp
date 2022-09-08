#include<iostream>

int main()
{
    int x1, y1, x2, y2;
    std::cout << "x1 = "; std::cin >> x1;
    std::cout << "y1 = "; std::cin >> y1;
    std::cout << "x2 = "; std::cin >> x2;
    std::cout << "y2 = "; std::cin >> y2;
    
    if (x1 * x2 > 0 && y1 * y2 > 0) 
    {
        std::cout << "\nThe two points are in the same quadrant!\n";
    }
    else
    {
        std::cout << "\nThe two points are not in the same quadrant!\n";
    }

    return 0;
}
