#include <iostream>

using namespace std;

class Student{
	public:

	char name[10];
	float marks[5];	
	
	void sname(){	
		cout<<"\n\nEnter name: ";
		cin>>name;
	}
	
	void inmarks(){
	    int i;
	   cout<<endl<<"Enter marks: ";
	    for(i=0;i<5;i++){
            cin>>marks[i];
	    }
	}
	
	float percentage(){
		int i;
		float total=0,per;
	  for(i=0;i<5;i++){
	  	total=total+marks[i];
	  }	
	  per=total/5;
	  return per;
	}
	
	void display(){
	 cout<<name<<"\t"<<percentage()<<"%"<<endl; 
	}
	Student(){
	    sname();
	    inmarks();
	    percentage();
	}
};

int main() {
	Student s1,s2,s3,s4,s5;
	cout<<"Marks list\nName\tmarks\n";
    s1.display();
    s2.display();
    s3.display();
    s4.display();
    s5.display();
	return 0;
}
