#include <iostream>

typedef unsigned char pixel[3];

double mediumColorIntensity(const pixel& p)
{
    double intensity = 0;
    for (int i = 0; i < 3; i++)
    {
        intensity = intensity + (int)p[i];
    }
    return intensity / 3;
}

void fillWithBlack(pixel& p)
{
    for (int i = 0; i < 3; i++)
    {
        p[i] = 0;
    }
}

bool isEqual(const pixel& p1, const pixel& p2)
{
    for (int i = 0; i < 3; i++)
    {
        if (p1[i] != p2[i])
            return false;
    }
    return true;
}

pixel** fillArea(const pixel *const *const image, size_t width, size_t height, size_t row, size_t column)
{
    pixel** newIimage = new(std::nothrow) pixel*[height];
    if (!newIimage)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < height; i++)
    {
        newIimage[i] = new (std::nothrow) pixel[width];
        if (!newIimage[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return nullptr;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                newIimage[i][j][k] = image[i][j][k];
            }
        }
    }

    fillWithBlack(newIimage[row][column]);

    pixel black = {0, 0, 0};

    for (int i = row; i < height; i++)
    {
        for (int j = column; j < width; j++)
        {
            if (!isEqual(newIimage[i][j], black))
            {
                continue;
            }

            double currIntensity = mediumColorIntensity(image[i][j]);

            if (i > 0 && std::abs(currIntensity - mediumColorIntensity(image[i - 1][j])) <= 1.0)
            {
                fillWithBlack(newIimage[i - 1][j]);
            }
            if (i < height - 1 && std::abs(currIntensity - mediumColorIntensity(image[i + 1][j])) <= 1.0)
            {
                fillWithBlack(newIimage[i + 1][j]);
            }
            if (j > 0 && std::abs(currIntensity - mediumColorIntensity(image[i][j - 1])) <= 1.0)
            {
                fillWithBlack(newIimage[i][j - 1]);
            }
            if (j < width - 1 && std::abs(currIntensity - mediumColorIntensity(image[i][j + 1])) <= 1.0)
            {
                fillWithBlack(newIimage[i][j + 1]);
            }
        }
    }

    return newIimage;
}

void streamRecovery()
{
    if (!std::cin)
    {
        std::cout << "Invalid data!" << std::endl;
        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

void printPixel(const pixel& p)
{
    std::cout << "{ ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << (int)p[i];

        if (i < 2)
            std::cout << ", ";
    }
    std::cout << " }";
}

void printImage(const pixel *const *const image, size_t width, size_t height)
{
    std::cout << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printPixel(image[i][j]);
            std::cout << "   ";
        }
        std::cout << std::endl;
    }
}

void deleteImage(pixel** image, const int& height)
{
    for (int i = 0; i < height; i++)
    {
        delete[] image[i];
    }
    delete[] image;
    image = nullptr; 
}

int main()
{
    int height, width;

    do
    {
        std::cout << "Enter the number of rows: ";
        std::cin >> height;
        streamRecovery();
    } while (height <= 0);

    do
    {
        std::cout << "Enter the number of columns: ";
        std::cin >> width;
        streamRecovery();
    } while (width <= 0);

    pixel** image = new(std::nothrow) pixel*[height];
    if (!image)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < height; i++)
    {
        image[i] = new(std::nothrow) pixel[width];
        if (!image[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    std::cout << "\nEnter the image:" << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int curr;
                do
                {
                    std::cin >> curr;
                    streamRecovery();
                } while (curr < 0 || curr > 255);
                image[i][j][k] = curr;
            }
        }
    }

    int row, column;

    do
    {
        std::cout << "\nEnter the starting row of the area: ";
        std::cin >> row;
        streamRecovery();
    } while (row < 0 && row > height - 1);

    do
    {
        std::cout << "Enter the starting column of the area: ";
        std::cin >> column;
        streamRecovery();
    } while (column < 0 && column > width - 1);

    pixel** newImage = fillArea(image, width, height, row, column);
    if (newImage == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        deleteImage(image, height);
        return 1;
    }

    printImage(newImage, width, height);

    deleteImage(newImage, height);
    deleteImage(image, height);

    return 0;
}

/*
Enter the number of rows: 3
Enter the number of columns: 3

Enter the image:
125 48  3  1 5 9   0   0  6
123 33 19  9 4 1   3   8  9
15  14 13  0 3 9  128 150 3

Enter the starting column of the area: 0
Enter the starting column of the area: 0

==>     { 0, 0, 0 }     { 1, 5, 9 }  { 0, 0, 6 }
        { 0, 0, 0 }     { 9, 4, 1 }  { 3, 8, 9 }
        { 15, 14, 13 }  { 0, 3, 9 }  { 128, 150, 3 }
*/
