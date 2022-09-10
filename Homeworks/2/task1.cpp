#include <iostream>

const size_t MAX_WIDTH_SIZE = 81;

int readNumber(int min, int max)
{
    int number;
    
    do 
    {
        std::cin >> number;

        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();

            std::cin >> number;
        }
    } while (number < min || number > max);

    return number;
}

void printPlayground(const int& height, const int& width, const char playground[][MAX_WIDTH_SIZE])
{
    std::cout << "\n";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= 2 * width; j++)
        {
            std::cout << playground[i][j];
        }
        std::cout << "\n";
    }
}

int correctMove(int& colNumber, const int& height, const int& width, const char playground[][MAX_WIDTH_SIZE])
{
    bool valid = false;
    int row;

    while (!valid)
    {
        row = 0;

        std::cout << "\nEnter a column number: ";
        colNumber = readNumber(1, width);

        for (row = height - 1; row >= 0; row--)
        {
            if (playground[row][2 * colNumber - 1] == ' ')
            {
                valid = true;
                break;
            }
        }
    }
    
    return row;
}

bool fourInARow(const char playground[][MAX_WIDTH_SIZE], const int& width, const int& rowNumber, const int& colNumber, const char& symbol)
{
    if (colNumber + 3 < width)
    {
        return playground[rowNumber][2 * colNumber + 1] == symbol && playground[rowNumber][2 * colNumber + 3] == symbol &&
               playground[rowNumber][2 * colNumber + 5] == symbol && playground[rowNumber][2 * colNumber + 7] == symbol;
    }
    return false;
}

bool fourOnOneColumn(const char playground[][MAX_WIDTH_SIZE], const int& rowNumber, const int& colNumber, const char& symbol)
{
    if (rowNumber - 3 >= 0)
    {
        return playground[rowNumber][2 * colNumber + 1] == symbol && playground[rowNumber - 1][2 * colNumber + 1] == symbol &&
               playground[rowNumber - 2][2 * colNumber + 1] == symbol && playground[rowNumber - 3][2 * colNumber + 1] == symbol;
    }
    return false;
}

bool fourOnTheMainDiag(const char playground[][MAX_WIDTH_SIZE], const int& min, const char& symbol)
{
    if (min - 4 >= 0)
    {
        return playground[min - 1][2*(min - 1) + 1] == symbol && playground[min - 2][2 * (min - 2) + 1] == symbol && 
               playground[min - 3][2 * (min - 3) + 1] == symbol && playground[min - 4][2 * (min - 4) + 1] == symbol;
    }
    return false;
}

bool fourOnTheSecondaryDiag(const char playground[][MAX_WIDTH_SIZE], const int& width, const int& rowNumber, const int& colNumber, 
                                                                                                                    const char& symbol)
{
    if (rowNumber + colNumber == width - 1 && rowNumber - 3 >= 0 && colNumber + 3 < width)
    {
        return playground[rowNumber][2 * colNumber + 1] == symbol && playground[rowNumber - 1][2 * colNumber + 3] == symbol &&
               playground[rowNumber - 2][2 * colNumber + 5] == symbol && playground[rowNumber - 3][2 * colNumber + 7] == symbol;
    }
    return false;
}

bool isWinningMove(const char& symbol, const int& height, const int& width, const char playground[][MAX_WIDTH_SIZE])
{
    bool flag = false;
    int min = std::min(height, width);

    for (int i = height - 1; i >= 0 && !flag; i--)
    {
        for (int j = 0; j < width && !flag; j++)
        {
            if (fourInARow(playground, width, i, j, symbol) || fourOnOneColumn(playground, i, j, symbol) ||
                fourOnTheMainDiag(playground, min, symbol) || fourOnTheSecondaryDiag(playground, width, i, j, symbol))
            {
                flag = true;
            }
        }
    }

    return flag;
}

int main()
{
    const size_t MAX_HEIGHT_SIZE = 20;

    int height, width;

    std::cout << "height = ";
    height = readNumber(4, 20);

    std::cout << "width = ";
    width = readNumber(4, 40);

    char playground[MAX_HEIGHT_SIZE][MAX_WIDTH_SIZE];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= 2 * width; j++)
        {
            if (j % 2 == 0)
            {
                playground[i][j] = '|';
            }
            else
            {
                playground[i][j] = ' ';
            }
        }
    }

    printPlayground(height, width, playground);

    int counter = 0;
    bool player1Wins = false, player2Wins = false;
    while (counter < height * width && !player1Wins && !player2Wins)
    {
        int choicePlayer1, choicePlayer2, rowNumber;

        rowNumber = correctMove(choicePlayer1, height, width, playground);
        playground[rowNumber][2 * choicePlayer1 - 1] = 'O';
        printPlayground(height, width, playground);
        player1Wins = isWinningMove('O', height, width, playground);

        counter++;

        if (player1Wins || counter == height * width)
        {
            continue;
        }

        rowNumber = correctMove(choicePlayer2, height, width, playground);
        playground[rowNumber][2 * choicePlayer2 - 1] = 'X';
        printPlayground(height, width, playground);
        player2Wins = isWinningMove('X', height, width, playground);

        counter++;
    }

    if (player1Wins)
    {
        std::cout << "\nPlayer 1 wins!\n";
    }
    else if (player2Wins)
    {
        std::cout << "\nPlayer 2 wins!\n";
    }
    else
    {
        std::cout << "\nStandoff!\n";
    }

    return 0;
}
