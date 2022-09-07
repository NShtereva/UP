#include <iostream>

int main()
{
    bool b11, b12, b13, b14,
         b21, b22, b23, b24;

    std::cin >> b11 >> b12 >> b13 >> b14;
    std::cin >> b21 >> b22 >> b23 >> b24;

    bool res0 = 0, res1, res2, res3, res4, temp = 0; 

    if(b14 && b24) temp = 1;
    res4 = b14 ^ b24;

    res3 = (b13 ^ b23) ^ temp;

    if((b13 ^ b23) && temp) temp = 1;
    else temp = 0;

    res2 = (b12 ^ b22) ^ temp;

    if((b12 ^ b22) && temp) temp = 1;
    else temp = 0;

    res1 = (b11 ^ b21) ^ temp;

    if((b11 ^ b21) && temp) temp = 1;
    else temp = 0;

    res0 = res0 ^ temp;

    std::cout << std::endl;
    std::cout << res0 << res1 << res2 << res3 << res4 << std::endl;
    return 0;
}
