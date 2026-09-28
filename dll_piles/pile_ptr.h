#ifndef PILE_PTR_H_INCLUDED
#define PILE_PTR_H_INCLUDED
#include "main.h"
#include <windows.h>

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

template<typename T>
class noeud{
public:
    T val;
    noeud<T>*suiv;
    noeud(): suiv(nullptr){}
};

template <typename T>
class pile {
private:
    noeud<T>* sommet;

public:
    pile() : sommet(nullptr) {}

    void empiler(T elem);
    T depiler();
    int est_vide();
    ~pile() {
        while (!est_vide()) {
            depiler();
        }
    }
};


template <typename T>
void pile<T>::empiler(T elem){
    noeud<T>* nv = new noeud<T>;
    nv->val=elem;
    nv->suiv=sommet;
    this->sommet=nv;
}
template <typename T>
T pile<T>::depiler(){
    if(this->est_vide()){
        exit(-1);
    }
  noeud<T>*tmp;
  tmp= this->sommet;
  this->sommet=this->sommet->suiv;
  T res=tmp->val;
  delete tmp;
  return res;
}

template <typename T>
int pile<T>::est_vide(){
    return !this->sommet;
}


int est_correcte_ptr(char *expr) {

    pile<char> ouverture;
    char tmp;

    for (size_t i = 0; i < strlen(expr); i++) {

        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            ouverture.empiler(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {

            if (ouverture.est_vide())
                return 0;

            tmp = ouverture.depiler();

            if (!comparer(tmp, expr[i]))
                return 0;
        }
    }

    if (!ouverture.est_vide())
        return 0;

    return 1;
}


#endif // PILE_PTR_H_INCLUDED
