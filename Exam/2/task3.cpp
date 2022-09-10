#include <iostream>
#include <cmath>

double readNumber()
{
    double number;
    
    do 
    {
        std::cin >> number;

        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();

            std::cin >> number;
        }
    } while (number <= 0);

    return number;
}

double distance(const double& x1, const double& y1, const double& x2, const double& y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Do two circles have points in common?
bool havePointsInCommon(const double* circle1, const double* circle2)
{
    return distance(circle1[0], circle1[1], circle2[0], circle2[1]) <= circle1[2] + circle2[2];
}

void copy(double* circle1, double* circle2)
{
    for(int i = 0; i < 3; i++)
    {
        circle1[i] = circle2[i];
    }
}

void remove(double** circles, int& N)
{
    for(int i = 0; i < N; i++)
    {
        bool isLonelyCircle = true;

        for(int j = 0; j < N && isLonelyCircle; j++)
        {
            if(i != j && havePointsInCommon(circles[i], circles[j]))
                isLonelyCircle = false;
        }

        if(isLonelyCircle)
        {
            for(int j = i; j < N - 1; j++)
                copy(circles[j], circles[j + 1]);

            N--; i--;
        }
    }
}

// length of a circle
double C(const double* circle)
{
    const double pi = 3.14;
    return 2 * pi * circle[2];
}

void sort(double** circles, const int& N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(C(circles[i]) > C(circles[j]))
            {
                double temp[3];
                copy(temp, circles[i]);
                copy(circles[i], circles[j]);
                copy(circles[j], temp);
            }
        }
    }
}

void print(double** circles, const int& N)
{
    std::cout << std::endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << circles[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int N;
    std::cout << "Enter the number of circles:" << std::endl;
    N = readNumber();

    double** circles = new(std::nothrow) double*[N];
    if(!circles)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    for(int i = 0; i < N; i++)
    {
        circles[i] = new(std::nothrow) double[3];
        if(!circles[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    std::cout << "Enter the circles:" << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cin >> circles[i][0];
        std::cin >> circles[i][1];
        circles[i][2] = readNumber();
    }

    int M = N;

    remove(circles, M);
    sort(circles, M);
    print(circles, M);

    for(int i = 0; i < N; i++)
    {
        delete[] circles[i];
    } delete[] circles;
    circles = nullptr;
    return 0;
}
