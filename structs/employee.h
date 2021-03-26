#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

typedef unsigned int uint;
typedef unsigned short ushort;

struct Address {
    char city[30];
    char street[30];
    uint zip_code;
};

struct Employee {
    uint id;
    char first_name[30];
    char last_name[30];
    char gender;
    ushort age;
    struct Address addr;
};

#endif
