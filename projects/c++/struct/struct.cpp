#include <iostream>

using namespace std;

enum {initials_length = 20, birth_length = 20};

struct tag_fio{
    char name[initials_length];
    char surname[initials_length];
};

struct tag_person {
    tag_fio fio;
    char sex;
    int old;
    char date_of_birth[birth_length];
};

int main()
{
    tag_person person = {
        {"Artem", "Gorev"},
        'M',
        18,
        "11.11.2005",
    };

    person.old = 19;
    strcpy(person.fio.name, "Artiom");

    return 0;
}