#include <iostream>

#include "BullsAndCows.h"

const unsigned MAX_MOVES = 7;

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
