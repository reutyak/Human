#ifndef HUMAN_H
#define HUMAN_H

#include <stdlib.h>
#include <string>
#include <stdint.h>

#include "Consts.h"
#include "Error.h"

using namespace std;

enum class Gender
{
    male = 0,
    female
};

class Human
{
    public:
        Human();

        ~Human() = default;

        Error Init(string first_name, string last_name, Gender gender, char (&identitiy)[Consts::IDENTITY_SIZE], uint8_t age);

        Error Display();

    private:

        bool m_init;
        string m_first_name;
        string m_last_name;
        Gender m_gender;
        char m_identity[Consts::IDENTITY_SIZE];
        uint8_t m_age;        


        

};


#endif //HUMAN_H