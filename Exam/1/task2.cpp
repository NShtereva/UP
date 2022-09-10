#include <iostream>
#include <cstring>

const int MAX_TEXT_SIZE = 10000001;;
const int MAX_SENTENCE_SIZE = 1000;

void readText(char* text, int& size)
{
    char c;
    bool endOfText = false;
    
    do
    {
        std::cin.get(c);
        text[size] = c;

        size++;

        if(size > 2 && (text[size - 3] == '!' && text[size - 2] == '!' && text[size - 1] == '!'))
        {
            endOfText = true;
        }

    } while (size < MAX_TEXT_SIZE && !endOfText);
    
    text[size] = '\0';
}

bool isWhitespace(char symbol)
{
    return symbol == ' ' || symbol == '\t' || symbol == '\n';
}

bool isEndOfSentence(char curr, char next)
{
    return (curr == '!' || curr == '?' || curr == '.') && isWhitespace(next);
}

int getNumberOfSentences(const char* text, const int& size)
{
    int counter = 0;
    bool isInBrackets = false, isInQuotes = false;

    for(int i = 0; i < size; i++)
    {
        if(text[i] == '(')
        {
            isInBrackets = true;
        }
        else if(text[i] == ')')
        {
            isInBrackets = false;
        }
        else if(text[i] == '\"' && !isInQuotes)
        {
            isInQuotes = true;
        }
        else if(text[i] == '\"' && isInQuotes)
        {
            isInQuotes = false;
        }
        else if(i < size - 1 && isEndOfSentence(text[i], text[i + 1]) && !isInBrackets && !isInQuotes)
        {
            counter++;
        }
        else if(i < size - 2 && (text[i] == '!' && text[i + 1] == '!' && text[i + 2] == '!'))
        {
            counter++;
            i = i + 2;
        }
    }

    return counter;
}

void separateTheSentances(const char* text, const int& size, char** array, const int& arraySize)
{
    bool isInBrackets = false, isInQuotes = false;
    int index = 0, j = 0;

    for(int i = 0; i < size && index < arraySize && j < MAX_SENTENCE_SIZE; i++)
    {
        if(text[i] == '(')
        {
            isInBrackets = true;
        }
        else if(text[i] == ')')
        {
            isInBrackets = false;
        }
        else if(text[i] == '\"' && !isInQuotes)
        {
            isInQuotes = true;
        }
        else if(text[i] == '\"' && isInQuotes)
        {
            isInQuotes = false;
        }
        else if(i < size - 1 && isEndOfSentence(text[i], text[i + 1]) && !isInBrackets && !isInQuotes)
        {
            array[index][j] = text[i];
            array[index][j + 1] = '\0';

            index++; j = 0;
            i++;

            continue;
        }
        else if(i < size - 2 && (text[i] == '!' && text[i + 1] == '!' && text[i + 2] == '!'))
        {
            array[index][j] = '!'; j++;
            array[index][j] = '!'; j++;
            array[index][j] = '!'; j++;
            array[index][j] = '\0';

            index++; j = 0;
            i = i + 2;

            continue;
        }

        if(j == 0 && isWhitespace(array[index][j]))
            continue;

        array[index][j] = text[i];
        j++;
    }
}

void processTheSentances(char** array, const int& arraySize)
{
    char* temp = new(std::nothrow) char[MAX_SENTENCE_SIZE];
    if(!temp)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    for(int i = 0; i < arraySize; i++)
    {
        bool isInQuotes = false;
        int currLen = strlen(array[i]), index = 0;

        for(int j = 0; j < currLen; j++)
        {
            if(array[i][j] == '\"' && !isInQuotes)
            {
                isInQuotes = true;
            }
            else if(array[i][j] == '\"' && isInQuotes)
            {
                isInQuotes = false;
            }
            else if(isWhitespace(array[i][j]))
            {
                temp[index] = ' ';
                index++;

                while(j < currLen - 1 && isWhitespace(array[i][j + 1]) && !isInQuotes)
                {
                    j++;
                }

                continue;
            }

            temp[index] = array[i][j];
            index++;
        }

        temp[index] = '\0';
        strcpy(array[i], temp);
    }

    delete[] temp;
    temp = nullptr;
}

void sort(char** array, const int& arraySize)
{
    char* temp = new(std::nothrow) char[MAX_SENTENCE_SIZE];
    if(!temp)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    for(int i = 0; i < arraySize; i++)
    {
        for(int j = i + 1; j < arraySize; j++)
        {
            if(strcmp(array[i], array[j]) > 0)
            {
                strcpy(temp, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp);
            }
        }
    }

    delete[] temp;
    temp = nullptr;
}

int main()
{
    char* text = new(std::nothrow) char[MAX_TEXT_SIZE];
    if(!text)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    int size = 0;
    readText(text, size);

    std::cout << std::endl;

    int counter = getNumberOfSentences(text, size);

    char** array = new(std::nothrow) char*[counter];
    if(!array)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;

        delete[] text;
        text = nullptr;

        return 1;
    }

    for(int i = 0; i < counter; i++)
    {
        array[i] = new(std::nothrow) char[MAX_SENTENCE_SIZE];
        if(!array[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;

            delete[] text;
            text = nullptr;

            return 1;
        }
    }

    separateTheSentances(text, size, array, counter);
    processTheSentances(array, counter);
    sort(array, counter);

    for(int i = 0; i < counter; i++)
    {
        std::cout << array[i] << std::endl;
    }

    for(int i = 0; i < counter; i++)
    {
        delete[] array[i];
    } delete[] array;
    array = nullptr;

    delete[] text;
    text = nullptr;
    return 0;
}
