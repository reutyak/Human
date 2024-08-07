#include "../inc/Human.h"
#include "../inc/ValidateData.h"
#include <regex>
#include <iostream>

#define MAGENTA(string) "\x1b[35m" string "\x1b[0m"

Human::Human() : m_init(false) {};

Error Human::Init(string first_name, string last_name, Gender gender, char (&identitiy)[Consts::IDENTITY_SIZE], uint8_t age)
{
    if (!ValidateData::IsValidName(first_name))
    {
        printf("First name isn't valid\n");
        return Error::FirstNameNotValid;
    }
    if (!ValidateData::IsValidName(last_name))
    {
        printf("Last name isn't valid\n");
        return Error::LastNameNotValid;
    }
    if (!ValidateData::IsValidID(identitiy))
    {
        printf("ID not valid\n");
        return Error::IdentitiyNotValid;
    }
    if (!ValidateData::IsValidAge(age))
    {
        printf("Age must be greater than 0 and smaller than 120\n");
        return Error::AgeNotValid;
    }
    m_first_name = first_name;
    m_last_name = last_name;
    m_gender = gender;
    memcpy(m_identity, identitiy, Consts::IDENTITY_SIZE);
    m_age = age;
    m_init = true;
    return Error::OK;
};

Error Human::Display()
{
    if (!m_init)
    {
        return Error::NotInitialize;
    }
    printf(MAGENTA("First Name: %s\n"), m_first_name.c_str());
    printf(MAGENTA("Last Name: %s\n"), m_last_name.c_str());
    if (m_gender == Gender::male)
    {
        printf(MAGENTA("Gender: male\n"));
    }
    else
    {
        printf(MAGENTA("Gender: female\n"));
    }
    printf(MAGENTA("Age: %d\n"), m_age);
    printf(MAGENTA("Identity: "));
    for (int i = 0; i < Consts::IDENTITY_SIZE; i++)
    {
        printf(MAGENTA("%c"), m_identity[i]);
    }
    printf("\n");
    return Error::OK;
};
