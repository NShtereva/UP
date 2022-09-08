#include <iostream>
#include <cstring>

bool isEqual(const char* word1, const char* word2)
{
    if (strlen(word1) != strlen(word2))
    {
        return false;
    }

    int i = 0;
    while (word1[i] != '\0')
    {
        char curr1 = word1[i], curr2 = word2[i];

        if (curr1 >= 'A' && curr1 <= 'Z')
        {
            curr1 = curr1 - 'A' + 'a';
        }

        if (curr2 >= 'A' && curr2 <= 'Z')
        {
            curr2 = curr2 - 'A' + 'a';
        }

        if (curr1 != curr2)
        {
            return false;
        }

        i++;
    }

    return true;
}

int getLength(const char* text, char*** dict, const int& N)
{
    int len = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char tempWord[101];
        int k = 0;

        while (text[i] != ' ' && text[i] != '\0')
        {
            tempWord[k] = text[i];
            k++;
            i++;
        }
        tempWord[k] = '\0';

        bool isEq = false;

        for (int j = 0; j < N; j++)
        {
            if (isEqual(tempWord, dict[j][0]))
            {
                len = len + strlen(dict[j][1]) + 1; // + 1 -> ' ' || '\0'
                isEq = true;
                break;
            }
        }

        if (isEq)
            continue;

        len = len + k + 1; // + 1 -> ' ' || '\0'
    }

    return len;
}

void copy(char* dest, const char* source, int& index)
{
    for (int p = 0; p < strlen(source); p++)
    {
        dest[index] = source[p];
        index++;
    }
}

int main()
{
    int N;
    do
    {
        std::cout << "N = ";
        std::cin >> N;
    } while (N <= 0);

    char*** dict = new(std::nothrow) char**[N];
    if (!dict)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        dict[i] = new(std::nothrow) char*[2];
        if (!dict[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dict[i][j] = new(std::nothrow) char[101];
            if (!dict[i][j])
            {
                std::cout << "\nMemory not allocated successfully!" << std::endl;
                return 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> dict[i][j];
        }
    }

    int M;
    do
    {
        std::cout << "M = ";
        std::cin >> M;
    } while (M <= 0);

    char* text = new(std::nothrow) char[M + 1];
    if (!text)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        for (int i = 0; i < N; i++)
        {
            delete[] dict[i];
        } delete[] dict;
        dict = nullptr;

        return 1;
    }

    std::cin.get();
    std::cin.getline(text, M + 1);

    char* newText = new (std::nothrow) char[getLength(text, dict, N)];
    if (!newText)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        delete[] text;
        text = nullptr;

        for (int i = 0; i < N; i++)
        {
            delete[] dict[i];
        } delete[] dict;
        dict = nullptr;

        return 1;
    }

    int index = 0;
    for (int i = 0; i < M + 1; i++)
    {
        char tempWord[101];
        int k = 0;

        while (text[i] != ' ' && text[i] != '\0')
        {
            tempWord[k] = text[i];
            k++;
            i++;
        }
        tempWord[k] = '\0';

        bool isEq = false;

        for (int j = 0; j < N; j++)
        {
            if (isEqual(tempWord, dict[j][0]))
            {
                copy(newText, dict[j][1], index);

                newText[index] = ' ';
                index++;

                isEq = true;
                
                break;
            }
        }

        if (isEq)
            continue;

        copy(newText, tempWord, index);

        if (i != M)
        {
            newText[index] = ' ';
            index++;
        }
        else
            newText[index] = '\0';
    }

    std::cout << "\nNew Text:\n";
    std::cout << newText << "\n";

    delete[] newText;
    newText = nullptr;

    delete[] text;
    text = nullptr;

    for (int i = 0; i < N; i++)
    {
        delete[] dict[i];
    } delete[] dict;
    dict = nullptr;
    return 0;
}
