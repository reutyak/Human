#include <regex>
#include <iostream>
#include "../inc/ValidateData.h"

bool ValidateData::IsValidName(const string &name)
{
    if (std::regex_match(name, std::regex("[[:alpha:]]*")))
    {
        return true;
    }
    return false;
};

bool ValidateData::IsValidID(char (&identitiy)[Consts::IDENTITY_SIZE])
{
    uint8_t sum = 0, inc_num = 0;
    for (int i = 0; i < Consts::IDENTITY_SIZE; i++)
    {
        if (identitiy[i] < 48 | identitiy[i] > 57)
        {
            printf("ID must contain only digits\n");
            return false;
        }
        inc_num = (uint8_t)(identitiy[i] - Consts::ASCII_ZERO_VALUE) * ((i % 2) + 1);
        inc_num = inc_num > 9 ? inc_num - 9 : inc_num;
        sum += inc_num;
    }
    return (sum % 10 == 0);
};

bool ValidateData::IsValidAge(uint8_t age)
{
    if (age < 0 | age > 120)
    {
        printf("Age must be greater than 0 and smaller than 120\n");
        return false;
    };
    return true;
};