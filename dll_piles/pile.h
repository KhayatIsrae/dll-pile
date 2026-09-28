#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED
#define MAX_ELEM 10
#include <windows.h>
#include <iostream>
#include "main.h"

using namespace std;

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif

template <typename T>
class Pile {
private:
    T tab[MAX_ELEM];
    int sommet;
public:
    Pile(): sommet(-1){}
    void empiler(T elem);
    T depiler();
    int est_vide();
    int est_saturee();
};


template <typename T>
void Pile<T>::empiler(T elem) {
    if(this->est_saturee()){
        cout<< "Pile est saturee";
        exit(0);
    }
    sommet++;
    tab[sommet] = elem;
}
template <typename T>
T Pile<T>::depiler(){
    if(est_vide()){
        cout<< "Pile est vide";
        exit(0);
    }
    T temp=tab[sommet];
    sommet--;
    return temp;
    }

template <typename T>
int  Pile<T>::est_vide(){
    if (sommet==-1) return 1;
    return 0;
}
template <typename T>
int  Pile<T>::est_saturee(){
    if (sommet==MAX_ELEM-1) return 1;
    return 0;
}

int est_correcte(char *expr){
    Pile<char>* ouverture=new Pile<char>;
    char tmp;
    for (int i=0; i<strlen(expr); i++){
            if(expr[i]=='[' || expr[i]=='{' || expr[i]=='('){
                    ouverture->empiler(expr[i]);
            }else if(expr[i]==']' || expr[i]=='}' || expr[i]==')'){
                if(ouverture->est_vide()){
                    return 0;
                }
                tmp=ouverture->depiler();
                if(!comparer(tmp,expr[i])){
                    return 0;
                }
            }
    }
    if(!ouverture->est_vide())
        return 0;

    return 1;
}


#endif // PILE_H_INCLUDED
