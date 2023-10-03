#include <iostream>

using namespace std;

class Student{
	
    public:

	char name[10];
	float marks[5];	
	Student();
	void sname();
	void inmarks();
	float percentage();
	void display();
};

void Student::sname(){
	cout<<"\nEnter name: ";
	cin>>name;
}

void Student::inmarks(){
    int i;
	cout<<"Enter marks: ";
	for(i=0;i<5;i++){
        cin>>marks[i];
	}
}

float Student::percentage(){
	int i;
	float total=0,per;
	for(i=0;i<5;i++){
	    total=total+marks[i];
	}	
	per=total/5;
	return per;
}

void Student::display(){
    cout<<name<<"\t"<<percentage()<<"%"<<endl; 
}
//Student constructor automatically calls function to get marks, calculate percentage
Student::Student(){
	sname();
	inmarks();
	percentage();
}

int main() {
	Student s1,s2,s3,s4,s5; //created 5 student objects
	cout<<"\nMarks list\nName\tmarks\n";
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
	return 0;
}
