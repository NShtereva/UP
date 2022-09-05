#include <iostream>

int main()
{
	int h, min;
	std::cin >> h >> min;

	double m = min / 5.0;
    
	if (h >= 12)
		h = h - 12;

	double angel = h > m ? (h - m) * 30 : (m - h) * 30;
	std::cout << "\nAngel: " << angel << std::endl;
    return 0;
}