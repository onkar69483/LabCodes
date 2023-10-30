#include <iostream>
using namespace std;

int gcd(int num1,int num2){
    int min;
    if(num1<=num2) min=num1;
    else min=num2;
    while(min>0){
        if(num1%min==0 && num2%min==0){
            return min;
        }
        min--;
    }
}

int lcm(int num1,int num2){
    int max;
    if(num1>=num2) max=num1;
    else max=num2;
    while(1!=0){
        if(max%num1==0 && max%num2==0) return max;
        max++;
    }
}

int main(){
    cout<<gcd(16,15)<<endl;
    cout<<lcm(2,14)<<endl;
    return 0;
}