#include "BigInt.h"
#include <iostream>

BigInt::BigInt(int n) 
{
    if (n == 0)
    {
        digits.push_back(0);
    }
    while (n > 0) 
    {
        digits.push_back(n % 10);
        n /= 10;
    }
}

BigInt& BigInt::operator*=(int num) 
{
    if (num == 0) 
    {
        digits = { 0 };
        return *this;
    }

    uint32_t a = 0;
    for (int i = 0; i < digits.size(); i++) 
    {
        uint32_t b = digits[i] * num + a;
        digits[i] = b % 10;
        a = b / 10;
    }

    while (a > 0) 
    {
        digits.push_back(a % 10);
        a /= 10;
    }

    return *this;
}

std::string BigInt::convert_to_string() const 
{
    if (digits.empty())
    {
        return "0";
    }
    std::string result;
    result.reserve(digits.size());
    for (int i = digits.size() - 1; i > -1; i--) 
    {
        result += '0' + digits[i];
    }
    return result;
}