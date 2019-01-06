#include "wrongcase.h"

WrongCase::WrongCase() : exception()
{

}

const char * WrongCase::what() const throw(){
    return "Buy a mouse";
}
