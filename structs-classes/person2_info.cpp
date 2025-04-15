#include <iostream>

using namespace std;
#include "person2.h"

int main(int argc, char** argv){
	person2 m;
	m.setAge(26);
	m.setName("Martha Papadopoulou");
	m.printPerson();
	
	person2 john(23,"John");
	john.printPerson();
	return 0;
}
