#ifndef FACTORIALS_TABLE_H
#define FACTORIALS_TABLE_H
#include "BigInt.h"
#define MAX_VALUE 255
class FactorialsTable
{
private:
    static const std::vector<BigInt>& get_table();

    static std::vector<BigInt> create_table();

public:
    static const BigInt& factorial(int num);
};
#endif
