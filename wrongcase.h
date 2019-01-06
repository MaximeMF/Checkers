#ifndef WRONGCASE_H
#define WRONGCASE_H
#include <exception>

using namespace std;


class WrongCase : public exception
{
    public :
        WrongCase();
        const char* what() const throw();
};

#endif // WRONGCASE_H

