#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <stdio.h>
#include <fenv.h>
#include <math.h>
#include <errno.h>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    printf("MATH_ERRNO is %s\n", math_errhandling & MATH_ERRNO ? "set" : "not set");
    printf("MATH_ERREXCEPT is %s\n", math_errhandling & MATH_ERREXCEPT ? "set" : "not set");
    
    feclearexcept(FE_ALL_EXCEPT);
    
    errno = 0;
    printf("log(0) = %f\n", log(0));

    if (errno == ERANGE) {
        perror("errno == ERANGE");
    }
        
    if (fetestexcept(FE_DIVBYZERO)) {
        puts("FE_DIVBYZERO (pole error) reported");
    }
        
    _getch();
    return 0;
}