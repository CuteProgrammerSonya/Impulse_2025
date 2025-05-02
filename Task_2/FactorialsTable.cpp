#include "FactorialsTable.h"

const std::vector<BigInt>& FactorialsTable::get_table()
{
    static const std::vector<BigInt> factorials_table = create_table();
    return factorials_table;
}

std::vector<BigInt> FactorialsTable::create_table()
{
    std::vector<BigInt> factorials_table;
    factorials_table.reserve(MAX_VALUE + 1);
    factorials_table.emplace_back(1); // 0!

    for (int i = 1; i < MAX_VALUE + 1; i++)
    {
        factorials_table.push_back(factorials_table.back());
        factorials_table.back() *= i;
    }
    return factorials_table;
}

const BigInt& FactorialsTable::factorial(int num)
{
    return get_table()[num];
}
