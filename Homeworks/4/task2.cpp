#include <iostream>

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

int length(const char* str)
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

void readTable(char*** table, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> table[i][j];
        }

        int len1 = length(table[i][0]);
        int len2 = length(table[i][1]);

        if (len1 != 1 || (len2 < 1 || len2 > 10))
        {
            std::cout << "Invalid data. Please enter this row again!\n";
            i--;
        }
    }
}

int strcmp(const char* text1, const char* text2)
{
    while (*text1 && *text1 == *text2) {
        ++text1;
        ++text2;
    }
    return *text1 - *text2;
}

char getOppositeLetter(const char& letter)
{
    char oppositeLetter = '\0';

    if (letter >= 'A' && letter <= 'Z')
    {
        oppositeLetter = 'a' + (letter - 'A');
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        oppositeLetter = 'A' + (letter - 'a');
    }

    return oppositeLetter;
}

bool isTableCorrect(char*** table, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        char temp = getOppositeLetter(table[i][0][0]);

        for(int j = i + 1; j < size; j++)
        {
            if(table[i][0][0] == table[j][0][0] || temp == table[j][0][0])
            {
                return false;
            }

            if(strcmp(table[i][1], table[j][1]) == 0)
            {
                return false;
            }
        }
    }

    return true; 
}

// Uses the boolean variable flag to check if a match has been found between a letter of the entered string and 
// an element of the encryption table. 
void helper(const char* str, char*** table, const int& size, const int& i, int& j, bool& flag)
{
    for (j = 0; j < size && !flag; j++)
    {
        char temp = getOppositeLetter(str[i]);
        
        if (str[i] == table[j][0][0] || temp == table[j][0][0])
        {
            flag = true;
            j--;
        }            
    }
}

char* encryption(const char* str, char*** table, const int& size, bool& hasChanged)
{
    int lenOfTheEncryptedString = 0, len = length(str);

    for (int i = 0; i < len; i++)
    {
        bool flag = false;
        int j;

        helper(str, table, size, i, j, flag);

        if (flag)
        {
            lenOfTheEncryptedString = lenOfTheEncryptedString + length(table[j][1]);
        }
        else
        {
            lenOfTheEncryptedString++;
        }
    }

    char* result = new(std::nothrow) char[lenOfTheEncryptedString + 1];
    if (!result)
    {
        return nullptr;
    }

    int index = 0;

    for (int i = 0; i < len; i++)
    {
        bool flag = false;
        int j;

        helper(str, table, size, i, j, flag);

        if (flag)
        {
            int tempLength = length(table[j][1]);

            for (int p = 0; p < tempLength; p++)
            {
                result[index] = table[j][1][p];
                index++;
            }

            hasChanged = true;
        }
        else
        {
            result[index] = str[i];
            index++;
        }
    }

    result[index] = '\0';

    return result;
}

// Is str1 a prefix of str2?
bool isPrefix(const char* str1, const char* str2)
{
    if (length(str1) == 0) return true;
    if (length(str2) == 0) return false;
    return str1[0] == str2[0] && isPrefix(str1 + 1, str2 + 1);
}

// Is str1 a substring of str2?
bool isSubstr(const char* str1, const char* str2)
{
    if (length(str2) == 0) return false;
    if (isPrefix(str1, str2)) return true;
    return isSubstr(str1, str2 + 1);
}

// Returns the index of the first encounter of substr in str.
int firstSubstringIndex(const char* substr, const char* str)
{
    if (length(str) == 0) return -1;
    if (isPrefix(substr, str)) return 0;
    if (substr[0] == str[0]) return 1 + firstSubstringIndex(substr, str + 1);
    if (substr[0] != str[0] && isSubstr(substr, str)) return 1 + firstSubstringIndex(substr, str + 1);
    return -1;
}

void strcpy(char* destination, const char* source)
{
    int index = 0;
    while (source[index] != '\0') 
    {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
}

void swap(char* str1, char* str2)
{
    char tempStr[11] = "";
    strcpy(tempStr, str1);
    strcpy(str1, str2);
    strcpy(str2, tempStr);
}

void sort(char*** table, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (length(table[i][1]) < length(table[j][1]))
            {
                swap(table[i][0], table[j][0]);
                swap(table[i][1], table[j][1]);
            }
        }
    }
}

char* decryption(char* str, char*** table, const int& size, bool& hasChanged)
{
    sort(table, size);

    int lenOfTheDecryptedString = length(str), i = 0;

    while (i < size)
    {
        int index = firstSubstringIndex(table[i][1], str);

        if (index == -1)
        {
            i++;
            continue;
        }

        hasChanged = true;

        str[index] = table[i][0][0];

        int len = length(table[i][1]);

        for(int j = index + len; j < lenOfTheDecryptedString; j++)
        {
            str[j - len + 1] = str[j];
        }

        lenOfTheDecryptedString = lenOfTheDecryptedString - len + 1;
        str[lenOfTheDecryptedString] = '\0';
    }

    char* newStr = new (std::nothrow) char[lenOfTheDecryptedString + 1];
    if (newStr == nullptr)
    {
        return nullptr;
    }

    strcpy(newStr, str);

    return newStr;
}

void print(char** array, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

void deleteTable(char*** table, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] table[i];
    }
    delete[] table;
    table = nullptr;
}

void deleteArr(char** array, const int& size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
}

int main()
{
    const size_t MAX_LEN_OF_CODING_WORDS = 11;
    const size_t MAX_LEN_OF_ENTERED_STRINGS = 1001;
    const size_t MAX_LEN_OF_ENCRYPTED_STRINGS = 10001; // when each letter is replaced by 10 others

    int K;
    std::cout << "Enter K:" << std::endl;
    K = readNumber(1, 26);

    char*** table = new(std::nothrow) char**[K];
    if (!table)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        return 1;
    }

    for (int i = 0; i < K; i++)
    {
        table[i] = new(std::nothrow) char*[2];
        if (!table[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            table[i][j] = new(std::nothrow) char[MAX_LEN_OF_CODING_WORDS];
            if (!table[i][j])
            {
                std::cout << "\nMemory not allocated successfully!" << std::endl;
                return 1;
            }
        }
    }

    do
    {
        std::cout << "Enter the table:\n";
        readTable(table, K);
    } while (!isTableCorrect(table, K));

    int N;
    std::cout << "Enter N:" << std::endl;
    N = readNumber(0, 1000);

    char* helperString = new(std::nothrow) char[MAX_LEN_OF_ENTERED_STRINGS];
    if (!helperString)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;
        deleteTable(table, K);
        return 1;
    }

    char** encryptedStrings = new(std::nothrow) char*[N];
    if(!encryptedStrings)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        deleteTable(table, K);

        delete[] helperString;
        helperString = nullptr;

        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        encryptedStrings[i] = new(std::nothrow) char[MAX_LEN_OF_ENCRYPTED_STRINGS];
        if(!encryptedStrings[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;

            deleteTable(table, K);

            delete[] helperString;
            helperString = nullptr;
        
            return 1;
        }
    }

    char* tempString = new(std::nothrow) char[MAX_LEN_OF_ENCRYPTED_STRINGS];
    if (!tempString)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        deleteTable(table, K);

        delete[] helperString;
        helperString = nullptr;

        deleteArr(encryptedStrings, N);

        return 1;
    }

    bool hasChanged = false;

    std::cin.get();

    for (int i = 0; i < N; i++)
    {
        std::cin.getline(helperString, MAX_LEN_OF_ENTERED_STRINGS);

        tempString = encryption(helperString, table, K, hasChanged);

        if(tempString != nullptr)
        {
            if(!hasChanged)
            {
                std::cout << "The string \"" << tempString << "\" cannot be encrypted!" << std::endl;
                N--;
            }
            else
            {
                strcpy(encryptedStrings[i], tempString);
            }
        }
        else
        {
            std::cout << "Memory not allocated successfully, so the string \"" << helperString << "\" cannot be encrypted!" << std::endl;
            N--;
        }     
    }

    int M;
    std::cout << "Enter M:" << std::endl;
    M = readNumber(0, 1000);

    char** decryptedStrings = new(std::nothrow) char*[M];
    if(!decryptedStrings)
    {
        std::cout << "\nMemory not allocated successfully!" << std::endl;

        deleteTable(table, K);

        delete[] helperString;
        helperString = nullptr;

        deleteArr(encryptedStrings, N);

        delete[] tempString;
        tempString = nullptr;

        return 1;
    }

    for (int i = 0; i < M; i++)
    {
        decryptedStrings[i] = new(std::nothrow) char[MAX_LEN_OF_ENTERED_STRINGS];
        if(!decryptedStrings[i])
        {
            std::cout << "\nMemory not allocated successfully!" << std::endl;

            deleteTable(table, K);

            delete[] helperString;
            helperString = nullptr;

            deleteArr(encryptedStrings, N);

            delete[] tempString;
            tempString = nullptr;
        
            return 1;
        }
    }

    hasChanged = false;

    std::cin.get();

    for (int i = 0; i < M; i++)
    {
        std::cin.getline(helperString, MAX_LEN_OF_ENTERED_STRINGS);

        tempString = decryption(helperString, table, K, hasChanged);

        if(tempString != nullptr)
        {
            if(!hasChanged)
            {
                std::cout << "Bad string!" << std::endl;
                M--;
            }
            else
            {
                strcpy(decryptedStrings[i], tempString);
            }
        }
        else
        {
            std::cout << "Memory not allocated successfully, so the string \"" << helperString << "\" cannot be decrypted!" << std::endl;
            M--;
        }
    }

    delete[] tempString;
    tempString = nullptr;

    delete[] helperString;
    helperString = nullptr;

    deleteTable(table, K);

    std::cout << std::endl;

    print(encryptedStrings, N);
    deleteArr(encryptedStrings, N);

    print(decryptedStrings, M);
    deleteArr(decryptedStrings, M);
    return 0;
}
