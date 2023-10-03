//Complex number code operator overloading

#include <iostream>

using namespace std;

class Complex{
    
    int real;
    int img;
    
    public:
    
    void get_data(){
        cout<<"Enter real part of complex number: ";
        cin>>real;
        cout<<"Enter imaginary part of complex number: ";
        cin>>img;
    }
    
    void display(){
        cout<<real<<"+"<<img<<"i\n";
    }
    
    Complex operator +(Complex obj)
    {
        Complex result;
        result.real = real + obj.real;
        result.img = img + obj.img;
        return result;
    }
    
    void operator --()
		{
			real--;
			img--;
		}
    
    void operator ++(){
        ++real;
        ++img;
    }
    
    bool operator <(Complex obj){
        if(real<obj.real)
            return true;
        if(real==obj.real && img<obj.img)
            return true;
        return false;
    }
    
    Complex operator -(Complex obj)
    {
        Complex result;
        result.real = real - obj.real;
        result.img = img - obj.img;
        return result;
    }
    
    bool operator ==(Complex obj){
        if(real==obj.real && img==obj.img)
            return true;
        else
            return false;
    }
};


int main(){
    
    int choice;
    Complex num1,num2,result;
    
    while(choice!=5){
        
        cout<<"\nMenu"<<endl;
        cout<<"1. Prefix increment on obj"<<endl;
        cout<<"2. Postfix decrement on obj"<<endl;
        cout<<"3. Add two num"<<endl;
        cout<<"4. Compare two num"<<endl;
        cout<<"5. Subtract"<<endl;
        cout<<"6. Exit!"<<endl;
   
        cout<<"Enter your choice: ";
        cin>>choice;
    
         switch(choice){
            case 1:
                cout<<"Enter Num1:"<<endl;
                num1.get_data();
                cout<<"Before: ";
                num1.display();
                ++num1;
                cout<<"After: ";
                num1.display();
                break;
            case 2:
                cout<<"Enter Num1:"<<endl;
                num1.get_data();
                cout<<"Before: ";
                num1.display();
                --num1;
                cout<<"After: ";
                num1.display();
                break;
            case 3:
                cout<<"Enter Num1:"<<endl;
                num1.get_data();
                cout<<"Enter Num2:"<<endl;
                num2.get_data();
                result=num1+num2;
                cout<<"Result: ";
                result.display();
                break;
            case 4:
                cout<<"Enter Num1:"<<endl;
                num1.get_data();
                cout<<"Enter Num2:"<<endl;
                num2.get_data();
                if(num1==num2){
                    cout<<"Equal!"<<endl;
                }
                else if(num2<num1){
                    cout<<"Greater: ";
                    num1.display();
                }
                else{
                    cout<<"Greater: ";
                    num2.display();
                }
                break;
            case 5:
                cout<<"Enter Num1:"<<endl;
                num1.get_data();
                cout<<"Enter Num2:"<<endl;
                num2.get_data();
                result=num1-num2;
                cout<<"Result: ";
                result.display(); 
                break;
            case 6:
                break;
            default:
                cout<<"Invalid Input!"<<endl;
                break;
        }
    }
    
    return 0;
}
