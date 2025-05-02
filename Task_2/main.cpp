#include <iostream>
#include "BigInt.h"
#include "FactorialsTable.h"

int main() 
{
    int num = 0;
    std::cout << "Enter a number [0; 255]: ";
    std::cin >> num;

    if (num < 0 || num > 255) 
    {
        std::cout << "Invalid value for calculating factorial!" << std::endl;
        return 1;
    }

    std::cout << num << "! = " << FactorialsTable::factorial(num).convert_to_string() << std::endl;
    return 0;
}
