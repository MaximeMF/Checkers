#ifndef WRONGCASE_H
#define WRONGCASE_H
#include <exception>

using namespace std;

/**
 * @brief La classe WrongCase représente une exception lancée lorsque le programme essaye d'atteindre une case non-existante lors
 *          de l'initialisation du damier dans Game (Réalisée pour l'exigence "d'utilisation d'exception")
 */
class WrongCase : public exception
{
    public :

        /**
         * @brief WrongCase Construit l'exception.
         */
        WrongCase();

        /**
         * @brief what méthode de l'exception.
         * @return un char*
         */
        const char* what() const throw();
};

#endif // WRONGCASE_H

