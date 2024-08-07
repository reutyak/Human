#include "../inc/Human.h"
#include "../inc/ValidateData.h"
#include <stdlib.h>
#include <string.h>
#include <regex>
#include <iostream>

bool IsDigit(const string &str)
{
    for (char ch : str)
    {
        int value_ascii = ch; // ASCII Val converted
        if (!(ch >= 48 && ch <= 57))
        {
            return false;
        }
    };
    return true;
};

bool ValidAge(const string &age)
{
    if (!IsDigit(age))
    {
        return false;
    }
    uint8_t user_age = (uint8_t)atoi(age.c_str());
    bool ret = ValidateData::IsValidAge(user_age);
    return ret;
};

bool ValidID(const string &id)
{
    if (id.length() != 9)
    {
        printf("ID must contain 9 digits\n");
        return false;
    }
    char temp_identity[Consts::IDENTITY_SIZE];
    int index = 0;
    for (char ch : id)
    {
        temp_identity[index] = ch;
        index++;
    }
    bool ret = ValidateData::IsValidID(temp_identity);
    return ret;
};

int main()
{
    string mystr;
    string first_name;
    string last_name;
    uint8_t age;
    Gender gender;
    char identity[Consts::IDENTITY_SIZE];

    while (true)
    {
        cout << "Enter your first name:\n";
        getline(cin, mystr);
        if (ValidateData::IsValidName(mystr))
        {
            first_name = mystr;
            break;
        }
        printf("Invalid first name\n");
    }

    while (true)
    {
        cout << "Enter your last name:\n";
        getline(cin, mystr);
        if (ValidateData::IsValidName(mystr))
        {
            last_name = mystr;
            break;
        }
        printf("Invalid last name\n");
    }

    while (true)
    {
        cout << "Enter your gender: Male -> press M, Female -> press F\n";
        getline(cin, mystr);
        if (mystr == "M" | mystr == "m")
        {
            gender = Gender::male;
            break;
        }
        else if (mystr == "F" | mystr == "f")
        {
            gender = Gender::female;
            break;
        }

        printf("Invalid type, try again\n");
    }

    while (true)
    {
        cout << "Enter your age:\n";
        getline(cin, mystr);
        if (ValidAge(mystr))
        {
            age = (uint8_t)atoi(mystr.c_str());
            break;
        }
        printf("Invalid age\n");
    }

    while (true)
    {
        cout << "Enter ID:\n";
        getline(cin, mystr);
        if (ValidID(mystr))
        {
            int index = 0;
            for (char ch : mystr)
            {
                identity[index] = ch;
                index++;
            }
            break;
        }
        printf("Invalid ID\n");
    }

    Human new_human;
    Error init_ret = new_human.Init(first_name, last_name, gender, identity, age);
    new_human.Display();

    return 0;
}