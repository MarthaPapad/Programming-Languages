class ComplexNumber{
	private:
		float real;
		float imaginary;
	public:
		ComplexNumber(float re=0.0, float im=0.0){
			real = re;
			imaginary = im;
		}
		ComplexNumber addComplex(const ComplexNumber* c);
		ComplexNumber subComplex(const ComplexNumber* c);
		void disComplex();		
};

ComplexNumber ComplexNumber::addComplex(const ComplexNumber* c) {
	float re3 = real + c->real;
	float im3 = imaginary + c->imaginary;
	ComplexNumber c3(re3, im3);
	return c3;
}
ComplexNumber ComplexNumber::subComplex(const ComplexNumber* c) {
	float re4 = real - c->real;
	float im4 = imaginary - c->imaginary;
	ComplexNumber c4(re4, im4);
	return c4;
}
void ComplexNumber::disComplex(){
	printf("Complex Number: %f + (%f)*i\n", real, imaginary);
}
