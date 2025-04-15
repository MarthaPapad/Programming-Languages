class person2{
	
	private:
		string name;
		int age;
	public:
		person2(){		//default constructor
		}
		person2(int y, string n){		//constructor
			name = n;
			age = y;
		}
		
		void setAge(int y);
		int getAge();
		void setName(string n);
		string getName();
		void printPerson();
	
};

void person2::setAge(int y){
	age = y;
} 
int person2::getAge(){
	return age;
}
void person2::setName(string n){
	name = n;
}
string person2::getName(){
	return name;
}
void person2::printPerson(){
	cout << "Age " << getAge() << endl;
	cout << "Name " << getName() << endl;
}
