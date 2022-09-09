#include <iostream>
#include <cmath>

const unsigned secretNumber = 2471;

const unsigned SIZE = 4;
const unsigned MAX_MOVES = 7;

static unsigned move = 0;
static bool victory = false;

int* getDigits(int number)
{
    int* digits = new(std::nothrow) int[SIZE];
    if(!digits)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return digits;
    }

    int i = SIZE - 1;
    while(number != 0)
    {
        digits[i] = number % 10;
        number = number / 10;
        i--;
    }

    return digits;
}

bool isCorrectNumber(const int& number)
{
    if(number < 1234 || number > 9876)
        return false;

    int* digits = getDigits(number);

    for(unsigned i = 0; i < SIZE; i++)
    {
        for(unsigned j = i + 1; j < SIZE; j++)
        {
            if(digits[i] == digits[j] || digits[i] == 0)
            {
                delete[] digits;
                digits = nullptr;

                return false;
            }
        }
    }

    delete[] digits;
    digits = nullptr;

    return true;
}

const int* tryGuess(const int& number)
{
    move++;
    if(move == MAX_MOVES + 1 || !isCorrectNumber(number) || victory)
    {
        std::cout << "Invalid move!" << std::endl;
        return nullptr;
    }

    int* answer = new(std::nothrow) int[2];
    if(!answer)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return answer;
    }

    int bulls = 0, cows = 0;
    int* digits = getDigits(number);

    for(int i = 0; i < SIZE; i++)
    {
        int currSecretNumberDigit = (int)(secretNumber / pow(10, SIZE - 1 - i)) % 10;

        if(digits[i] == currSecretNumberDigit)
        {
            bulls++;
            continue;
        }

        for(int j = 0; j < SIZE; j++)
        {
            if(digits[j] == currSecretNumberDigit)
                cows++;
        }
    }

    delete[] digits;
    digits = nullptr;

    answer[0] = bulls;
    answer[1] = cows;

    if(answer[0] == 4 && answer[1] == 0)
        victory = true;

    return answer;
}

void play()
{
    int counter = 0;

    while(counter < MAX_MOVES)
    {
        int number;

        std::cout << "Enter number: ";
        std::cin >> number;

        const int* answer = tryGuess(number);
        if(!answer)
        {
            std::cout << "Game over" << std::endl;
            return;
        }
        else if(answer[0] == 4 && answer[1] == 0)
        {
            std::cout << "\n(" << answer[0] << "," << answer[1] << ")\n" << std::endl; 
            std::cout << "Game over. You win!" << std::endl;

            delete[] answer;
            answer = nullptr;

            return;
        }

        std::cout << "\n(" << answer[0] << "," << answer[1] << ")\n" << std::endl; 

        delete[] answer;
        answer = nullptr;

        counter++;
    }
}

int main()
{
    play();    
    return 0;
}
