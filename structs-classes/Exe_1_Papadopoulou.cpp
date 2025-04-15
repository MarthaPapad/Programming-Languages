#include <stdio.h>
#include "ComplexNumber.h"

int main(){
	ComplexNumber c1(1.5, 2.3);
	c1.disComplex();
	ComplexNumber c2(0.5, 1.3);
	c2.disComplex();
	
	ComplexNumber c3 = c1.addComplex(&c2);
	c3.disComplex();
	ComplexNumber c4 = c1.subComplex(&c2);
	c4.disComplex();
	
	return 0;
}
