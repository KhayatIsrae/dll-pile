#ifndef __MAIN_H__
#define __MAIN_H__

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


int comparer(char ouv,char ferm){
    if(ouv=='[' && ferm==']')
        return 1;
    if(ouv=='{' && ferm=='}')
        return 1;
    if(ouv=='(' && ferm==')')
        return 1;
    return 0;
}


#endif // __MAIN_H__
