#include <iostream>

void enterValidData(int& data)
{
    do
    {
        std::cin >> data;

        if(!std::cin)
        {
            std::cout << "Invalid data!" << std::endl;
            while(!std::cin)
            {
                std::cin.clear();
                std::cin.ignore();
            }
        }

    } while(data < 0);
}

bool areIndexesUnique(int** arr, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i][0] == arr[j][0])
                return false;
        }
    }
    return true;
}

bool isValidTimePerDay(const int* arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 1440)
            return false;
    }
    return true;
}

double pointsPerMinutes(const int* arr)
{
    return (double)arr[2] / arr[1];
}

void sortCharacteristics(int** arr, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (pointsPerMinutes(arr[i]) < pointsPerMinutes(arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void printRemainingTime(int& minutes)
{
    if (minutes >= 0 && minutes <= 59)
    {
        std::cout << "0:" << minutes << std::endl;
    }
    else
    {
        int h = 0;

        while (minutes >= 60)
        {
            minutes = minutes - 60;
            h++;
        }

        std::cout << h << ":" << minutes << std::endl;
    }
}

int* getIndexes(int** characteristics, const int& tasksCount, const int& timeToStudy, int& size)
{
    int* indexes = new(std::nothrow) int[tasksCount];
    if (!indexes)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return nullptr;
    }

    int sumOfPoints = 0, tempTimeToStudy;

    for (int i = 0; i < tasksCount; i++)
    {
        int tempSumOfPoints = characteristics[i][2];
        tempTimeToStudy = timeToStudy - characteristics[i][1];

        int *tempIndexes = new (std::nothrow) int[tasksCount];
        if (!tempIndexes)
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return nullptr;
        }

        tempIndexes[0] = characteristics[i][0];

        int k = 1;

        for (int j = i + 1; j < tasksCount; j++)
        {
            if (tempTimeToStudy - characteristics[j][1] >= 0)
            {
                tempSumOfPoints = tempSumOfPoints + characteristics[j][2];
                tempTimeToStudy = tempTimeToStudy - characteristics[j][1];

                tempIndexes[k] = characteristics[j][0];
                k++;
            }
        }

        if (sumOfPoints < tempSumOfPoints)
        {
            sumOfPoints = tempSumOfPoints;

            for (int p = 0; p < k; p++)
            {
                indexes[p] = tempIndexes[p];
            }

            size = k;
        }

        delete[] tempIndexes;
        tempIndexes = nullptr;
    }

    return indexes;
}

void deleteMatrix(int** matrix, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

int main()
{
    int tasksCount;
    enterValidData(tasksCount);

    int** characteristics = new(std::nothrow) int*[tasksCount];
    if (!characteristics)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < tasksCount; i++)
    {
        characteristics[i] = new(std::nothrow) int[3];
        if (!characteristics[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < tasksCount; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            enterValidData(characteristics[i][j]);
        }
    }

    int remainingDays;
    enterValidData(remainingDays);

    int* timePerDay = new(std::nothrow) int[remainingDays];
    if (!timePerDay)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        deleteMatrix(characteristics, tasksCount);

        return 1;
    }

    for (int i = 0; i < remainingDays; i++)
    {
        enterValidData(timePerDay[i]);
    }

    if (!areIndexesUnique(characteristics, tasksCount) || !isValidTimePerDay(timePerDay, remainingDays))
    {
        std::cout << "\nInvalid input data!" << std::endl;

        delete[] timePerDay;
        timePerDay = nullptr;

        deleteMatrix(characteristics, tasksCount);

        return 1;
    }

    sortCharacteristics(characteristics, tasksCount);

    int timeToStudy = 0, timeRequiredForTasks = 0;

    for (int i = 0; i < remainingDays; i++)
    {
        timeToStudy = timeToStudy + timePerDay[i];
    }

    for (int i = 0; i < tasksCount; i++)
    {
        timeRequiredForTasks = timeRequiredForTasks + characteristics[i][1];
    }

    if (timeRequiredForTasks <= timeToStudy)
    {
        std::cout << "\nTasks: ";
        for (int i = 0; i < tasksCount; i++)
        {
            std::cout << characteristics[i][0];
            if (i < tasksCount - 1)
            {
                std::cout << ", ";
            }
        }

        int remainingMinutes = timeToStudy - timeRequiredForTasks;

        std::cout << "\nTime remaining: ";
        printRemainingTime(remainingMinutes);
    }
    else
    {
        int size = 0;

        int* indexes = getIndexes(characteristics, tasksCount, timeToStudy, size);
        if (!indexes)
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;

            delete[] timePerDay;
            timePerDay = nullptr;

            deleteMatrix(characteristics, tasksCount);

            return 1;
        }

        std::cout << "\nTasks: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << indexes[i];
            if (i < size - 1)
            {
                std::cout << ", ";
            }
        }

        int currentTime = 0;

        for (int i = 0; i < tasksCount; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (characteristics[i][0] == indexes[j])
                {
                    currentTime = currentTime + characteristics[i][1];
                }
            }
        }

        int remainingMinutes = timeToStudy - currentTime;

        std::cout << "\nTime remaining: ";
        printRemainingTime(remainingMinutes);

        delete[] indexes;
        indexes = nullptr;
    }

    delete[] timePerDay;
    timePerDay = nullptr;

    deleteMatrix(characteristics, tasksCount);
    return 0;
}
