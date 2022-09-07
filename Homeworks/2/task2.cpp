#include <iostream>
#include <cmath>
#include <thread>

char intToChar(char a)
{
    return a + '0';
}

char* initializeProgressBar(const int size, bool flag, const char& leftSymbol, const char& rightSymbol, const char& emptySymbol)
{
    char* progressBar = new char[size + 1];

    for(int i = 0; i < size; i++)
    {
        progressBar[i] = emptySymbol;
    }

    progressBar[0] = leftSymbol;

    if(flag)
    {
        int middle = (size % 2 == 0)? size / 2 : (size / 2 + 1);
        progressBar[middle - 1] = '0';
        progressBar[middle] = '%';
    }

    progressBar[size - 2] = rightSymbol;
    progressBar[size - 1] = '\0';

    return progressBar;
}

char* visualizeProgressBar(double& currentProgress, bool flag = true, const int numberOfDivisions = 50, const char& leftSymbol = '[', 
                                                const char& rightSymbol = ']', const char& fillSymbol = '=', const char& emptySymbol = ' ')
{
    int size = numberOfDivisions + 2;
    char* progressBar = new char[size + 1];

    progressBar = initializeProgressBar(size, flag, leftSymbol, rightSymbol, emptySymbol);

    int middle = (size % 2 == 0)? size / 2 : (size / 2 + 1);
    int p = ceil(currentProgress * 100);

    int temp = p / (100 / numberOfDivisions);
    for(int i = 1; i < temp; i++)
    {
         progressBar[i] = fillSymbol;
    }
    
    if(flag)
    {
        if(p >= 10)
        {
             progressBar[middle - 2] = intToChar((p / 10) % 10);
        }

        progressBar[middle - 1] = intToChar(p % 10);

        if(p == 100)
        {
             progressBar[middle - 3] = intToChar((p / 100) % 10);
        }

        progressBar[middle] = '%';
    }

    return progressBar;
}

int main()
{
    int sec;
    do
    {
        std::cout << "Enter the number of seconds: ";
        std::cin >> sec;
        if(!std::cin)
        {
            std::cout << "Invalid data!\n";
            std::cin.clear();
            std::cin.ignore();
        }
    } while (sec <= 0 && sec >= 60);

    std::cout << "\n";

    int T = sec * 9;
    for (double i = 0; i <= 1; i += 0.01) 
    {
        if(i != 1) 
        {
            system("cls");
        }
        char* progressBar = visualizeProgressBar(i);
        std::cout << progressBar << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(T));
        delete[] progressBar;
    }
    return 0;
}
