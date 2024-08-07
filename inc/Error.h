#ifndef ERROR_H
#define ERROR_H

#include <stddef.h>

enum class Error
{
    OK = 0,
    FirstNameNotValid,
    LastNameNotValid,
    IdentitiyNotValid,
    AgeNotValid,
    NotInitialize
};

#endif // ERROR_H