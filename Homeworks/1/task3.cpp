#include <iostream>

void readDate(int& d, int& m, int& y, int& h, int& min, int& s)
{
    std::cin >> d; std::cin.get();
    std::cin >> m; std::cin.get();
    std::cin >> y; 
    std::cin >> h; std::cin.get();
    std::cin >> min; std::cin.get();
    std::cin >> s;
}

bool isValidDate(const int& d, const int& m, const int& y)
{
    if((y < 0 || y > 9999) || (m < 1 || m > 12) || d <= 0)
        return false; 

    bool isLeapYear = ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0));

    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return d <= 31;
    }
    else if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        return d <= 30;
    }
    else
    {
        if(isLeapYear)
            return d <= 29;
        return d <= 28;
    }

    return false;
}

bool isValidTime(const int& h, const int& min, const int& s)
{
    return (h >= 0 && h < 24) && (min >= 0 && min < 60) && (s >= 0 && s < 60);
}

int diffTime(int& h1, int& min1, int& s1, 
             int& h2, int& min2, int& s2,
             int& resultH, int& resultMin, int& resultS)
{
    int minusOneDay = 0;

    if(s1 < s2)
    {
        resultS = resultS + (s1 + 60 - s2);
        min1--;
    }
    else
        resultS = resultS + (s1 - s2);

    if(min1 < min2)
    {
        resultMin = resultMin + (min1 + 60 - min2);
        h1--;
    }
    else
        resultMin = resultMin + (min1 - min2);

    if(h1 < h2)
    {
        resultH = resultH + (h1 + 24 - h2);
        minusOneDay = -1;
    }
    else
        resultH = resultH + (h1 - h2);

    return minusOneDay;
}

// date1 > date2
void diffDate(int& d1, int& m1, int& y1, int& h1, int& min1, int& s1,
              int& d2, int& m2, int& y2, int& h2, int& min2, int& s2)
{
    int resultH = 0, resultMin = 0, resultS = 0;

    if(diffTime(h1, min1, s1, h2, min2, s2, resultH, resultMin, resultS) == -1)
        d1--;
    
    int days = 0;

    if(d1 < d2)
    {
        days = days + (d1 + 30 - d2);
        m1--;
    }
    else
        days = days + (d1 - d2);

    if(m1 < m2)
    {
        days = days + (m1 + 12 - m2) * 30;
        y1--;
        days = days + ((y1 - y2 > 0) ? (y1 - y2) * 365 : 0);
    }
    else
        days = days + (m1 - m2) * 30 + (y1 - y2) * 365;

    if(days > 0)
        std::cout << days << "-";
    
    std::cout << ((resultH < 10) ? "0" : "")    << resultH   << ":"
              << ((resultMin < 10) ? "0" : "")  << resultMin << ":"
              << ((resultS < 10) ? "0" : "")    << resultS   << std::endl;
}

int main()
{
    int d1, m1, y1, h1, min1, s1,
        d2, m2, y2, h2, min2, s2;
    
    readDate(d1, m1, y1, h1, min1, s1);
    readDate(d2, m2, y2, h2, min2, s2);

    if(!isValidDate(d1, m1, y1) || !isValidTime(h1, min1, s1) || 
       !isValidDate(d2, m2, y2) || !isValidTime(h2, min2, s2))
    {
        std::cout << "\nInvalid date/time!" << std::endl;
        return 1;
    }

    std::cout << std::endl;

    if(y1 > y2)
        diffDate(d1, m1, y1, h1, min1, s1, d2, m2, y2, h2, min2, s2);
    
    else if(y1 < y2)
        diffDate(d2, m2, y2, h2, min2, s2, d1, m1, y1, h1, min1, s1);
    
    else
    {
        if(m1 > m2)
            diffDate(d1, m1, y1, h1, min1, s1, d2, m2, y2, h2, min2, s2);
        
        else if(m1 < m2)
            diffDate(d2, m2, y2, h2, min2, s2, d1, m1, y1, h1, min1, s1);
        
        else
        {
            if(d1 < d2)
                diffDate(d2, m2, y2, h2, min2, s2, d1, m1, y1, h1, min1, s1);
            else
                diffDate(d1, m1, y1, h1, min1, s1, d2, m2, y2, h2, min2, s2);
        }
    }
    return 0;
}
