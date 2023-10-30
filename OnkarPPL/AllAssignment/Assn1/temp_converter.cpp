#include <iostream>
using namespace std;

double CtoF(double C){
    double F=9*C/5+32;
    return F;
}

double FtoC(double F){
    double C=(F-32)*5/9;
    return C;
}

int main(){
    cout<<CtoF(36);
    return 0;
}