#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <string>

class BigInt 
{
private:
    std::vector<int> digits;
public:
    BigInt() = default;
    explicit BigInt(int n);

    BigInt(const BigInt&) = default;
    BigInt& operator=(const BigInt&) = default;

    BigInt& operator*=(int num);
    std::string convert_to_string() const;

};

#endif