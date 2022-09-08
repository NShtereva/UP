#include <iostream>
#include <cstring>

struct BookRec
{
    int year;
    int pages;
    char title[50];
    char author[50];
    char subject[100];

    BookRec();
    BookRec(const char *_title, const char *_author, const char *_subject, const int &_year, const int &_pages);
};

BookRec::BookRec() : year(0), pages(0), title(""), author(""), subject("")
{}

BookRec::BookRec(const char *_title, const char *_author, const char *_subject, const int &_year, const int &_pages)
    : year(0), pages(0), title(""), author(""), subject("")
{
    if (_title && strlen(_title) < 50)
    {
        strcpy(title, _title);
    }

    if (_author && strlen(_author) < 50)
    {
        strcpy(author, _author);
    }

    if (_subject && strlen(_subject) < 100)
    {
        strcpy(subject, _subject);
    }

    if (_year > 0)
    {
        year = _year;
    }

    if (_pages > 0)
    {
        pages = _pages;
    }
}

//task 0:
void readBookData(BookRec &book)
{
    std::cout << "Enter a title: ";
    std::cin.getline(book.title, 50);

    std::cout << "Enter author: ";
    std::cin.getline(book.author, 50);

    std::cout << "Enter a subject: ";
    std::cin.getline(book.subject, 100);

    do
    {
        std::cout << "Enter year: ";
        std::cin >> book.year;

        if (!std::cin)
        {
            std::cout << "Invalid data!\n";
            std::cin.clear();
            std::cin.ignore();
            book.year = -1;
        }
    } while (book.year < 0);

    do
    {
        std::cout << "Enter the number of pages: ";
        std::cin >> book.pages;

        if (!std::cin)
        {
            std::cout << "Invalid data!\n";
            std::cin.clear();
            std::cin.ignore();
            book.pages = 0;
        }
    } while (book.pages < 0);
}

void printBookData(const BookRec &book)
{
    std::cout << "\ntitle: \"" << book.title << "\"\n"
              << "author: " << book.author << "\n"
              << "subject: " << book.subject << "\n"
              << "year: " << book.year << "\n"
              << "pages: " << book.pages << "\n";
}

void readArray(BookRec *books, const int &booksSize)
{
    for (int i = 0; i < booksSize; i++)
    {
        readBookData(books[i]);
        std::cout << "\n";
        std::cin.get();
    }
}

void printArray(BookRec *books, const int &booksSize)
{
    for (int i = 0; i < booksSize; i++)
    {
        printBookData(books[i]);
        std::cout << "\n";
    }
}

//task 1:
void swapBooks(BookRec &b1, BookRec &b2)
{
    BookRec temp(b1.title, b1.author, b1.subject, b1.year, b1.pages);

    strcpy(b1.title, b2.title);
    strcpy(b1.author, b2.author);
    strcpy(b1.subject, b2.subject);
    b1.year = b2.year;
    b1.pages = b2.pages;

    strcpy(b2.title, temp.title);
    strcpy(b2.author, temp.author);
    strcpy(b2.subject, temp.subject);
    b2.year = temp.year;
    b2.pages = temp.pages;
}

void sortByYear(BookRec *books, const int &booksSize)
{
    for (int i = 0; i < booksSize; i++)
    {
        for (int j = i + 1; j < booksSize; j++)
        {
            if (books[i].year > books[j].year)
            {
                swapBooks(books[i], books[j]);
            }
        }
    }
}

//task 2:
void sortByYearAndAuthor(BookRec *books, const int &booksSize)
{
    for (int i = 0; i < booksSize; i++)
    {
        for (int j = i + 1; j < booksSize; j++)
        {
            if (books[i].year > books[j].year)
            {
                swapBooks(books[i], books[j]);
            }

            else if (books[i].year == books[j].year && strcmp(books[i].author, books[j].author) > 0)
            {
                swapBooks(books[i], books[j]);
            }
        }
    }
}

//task 3:
char** getAuthors(BookRec *books, const int &booksSize, const int &year, int &size)
{
    char** tempArr = new(std::nothrow) char*[booksSize];
    if(tempArr == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";
        return nullptr;
    }

    for (int i = 0; i < booksSize; i++)
    {
        tempArr[i] = new(std::nothrow) char[50];

        if(tempArr[i] == nullptr)
        {
            std::cout << "\nMemory not allocated successfully!\n";
            return nullptr;
        }
    }

    int k = 0;
    for (int i = 0; i < booksSize; i++)
    {
        if(books[i].year == year)
        {
            strcpy(tempArr[k], books[i].author);
            k++;
        }
    }

    size = k;

    char** arr = new(std::nothrow) char*[size];
    if(arr == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";
        return nullptr;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = new(std::nothrow) char[50];

        if(arr[i] == nullptr)
        {
            std::cout << "\nMemory not allocated successfully!\n";
            return nullptr;
        }
    }

    k = 0;
    for (int i = 0; i < size; i++)
    {
        strcpy(arr[k], tempArr[i]);
        k++;
    }

    for (int i = 0; i < booksSize; i++)
    {
        delete[] tempArr[i];
    } delete[] tempArr;

    return arr;
}

char* mostPopularSubject(BookRec *books, const int &booksSize, const int &year)
{
    char** arr = new(std::nothrow) char*[booksSize];
    if(arr == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";
        return nullptr;
    }

    for (int i = 0; i < booksSize; i++)
    {
        arr[i] = new(std::nothrow) char[100];

        if(arr[i] == nullptr)
        {
            std::cout << "\nMemory not allocated successfully!\n";
            return nullptr;
        }
    }

    int k = 0;
    for (int i = 0; i < booksSize; i++)
    {
        if(books[i].year == year)
        {
            strcpy(arr[k], books[i].subject);
            k++;
        }
    }

    int maxCount = 0, index = 0;;
    for (int i = 0; i < k; i++)
    {
        int tempCount = 1;
        for (int j = i + 1; j < k; j++)
        {
            if(books[i].subject == books[j].subject)
            {
                tempCount++;
            }
        }

        if(tempCount > maxCount)
        {
            maxCount = tempCount;
            index = i;
        }
    }

    char* subject = new(std::nothrow) char[100];
    if(subject == nullptr)
    {
        std::cout << "\nMemory not allocated successfully!\n";

        for (int i = 0; i < booksSize; i++)
        {
            delete[] arr[i];
        } delete[] arr;

        return nullptr;
    }

    strcpy(subject, books[index].subject);

    for (int i = 0; i < booksSize; i++)
    {
        delete[] arr[i];
    } delete[] arr;

    return subject;
}

//task 5:
void check(BookRec *books, const int &booksSize, const char* author)
{
    int counter = 0, year = 0, maxNumberOfPages = 0, index = 0;

    for(int i = 0; i < booksSize; i++)
    {
        int tempCounter = 0;
        if(strcmp(books[i].author, author) == 0)
        {
            for(int j = 0; j < booksSize; j++)
            {
                if(strcmp(books[i].author, books[j].author) == 0 && books[i].year == books[j].year)
                {
                    tempCounter++;
                }
            }

            if(tempCounter > counter)
            {
                counter = tempCounter;
                year = books[i].year;
            }
            if(books[i].pages > maxNumberOfPages)
            {
                maxNumberOfPages = books[i].pages;
                index = i;
            }
        }
    }

    if(year != 0)
    {
        std::cout << "\nYear with most published books: " << year << "\n";
    }

    if(maxNumberOfPages != 0)
    {
        std::cout << "\nBook with the most pages: " << books[index].title << "\n";
    }
}

//task 6:
void previousBook(BookRec *books, const int &booksSize, const char* author, const int &year)
{
    BookRec tempArr[booksSize];

    int k = 0;
    for(int i = 0; i < booksSize; i++)
    {
        if(strcmp(books[i].author, author) == 0 && books[i].year < year)
        {
            strcpy(tempArr[k].title, books[i].title);
            strcpy(tempArr[k].author, books[i].author);
            strcpy(tempArr[k].subject, books[i].subject);
            tempArr[k].year = books[i].year;
            tempArr[k].pages = books[i].pages;

            k++;
        }
    }

    if(k == 0)
    {
        std::cout << "\nThere are no such books!\n";
        return;
    }

    BookRec arr[k];
    for(int i = 0; i < k; i++)
    {
        strcpy(arr[i].title, tempArr[i].title);
        strcpy(arr[i].author, tempArr[i].author);
        strcpy(arr[i].subject, tempArr[i].subject);
        arr[i].year = tempArr[i].year;
        arr[i].pages = tempArr[i].pages;
    }

    sortByYear(arr, k);
    printArray(arr, k);
}

int main()
{
    BookRec books[3];

    readArray(books, 3);

    //task 1:
    //sortByYear(books, 3);

    //task 2:
    //sortByYearAndAuthor(books, 3);

    //std::cout << "\n";
    //printArray(books, 3);

    //task 3:
    /*
    int size = 0;
    char **authors = getAuthors(books, 3, 2020, size);
    if(authors == nullptr)
    {
        return 1;
    }
    else
    {
        std::cout << "authors: ";
        for (int i = 0; i < size; i++)
        {
            std::cout << authors[i];
            if(i < size - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }

    for (int i = 0; i < size; i++)
    {
        delete[] authors[i];
    } delete[] authors;
    */

    //task 4:
    //char *subject = mostPopularSubject(books, 3, 2020);
    //std::cout << "\nThe most popular subject: " << subject << "\n";
    //delete[] subject;

    //task 5:
    //check(books, 3, "name");

    //tash 6:
    //previousBook(books, 3, "name", 2020);
    return 0;
}
