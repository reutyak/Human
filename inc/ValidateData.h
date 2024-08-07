#ifndef VALIDATE_DATA_H
#define VALIDATE_DATA_H

#include <stdlib.h>
#include <string>
#include <stdint.h>

#include "Consts.h"
#include "Error.h"

using namespace std;

namespace ValidateData
{
    bool IsValidName(const string &name);
    bool IsValidID(char (&identitiy)[Consts::IDENTITY_SIZE]);
    bool IsValidAge(uint8_t age);
}

#endif // VALIDATE_DATA_H