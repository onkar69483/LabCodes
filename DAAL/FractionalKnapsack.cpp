#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value;
    int weight;
};


bool comp(Item a, Item b){
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1>r2;
}

int fk(int W, Item arr[], int n){
    sort(arr, arr+n, comp);

    int currWeight = 0;
    double total = 0.0;

    for(int i = 0; i<n; i++){
        if(currWeight + arr[i].weight <= W){
            currWeight += arr[i].weight;
            total += arr[i].value;
        } else {
            int remain = W - currWeight;
            total += (double)arr[i].value * (double)remain / (double)arr[i].weight;
            break;
        }
    }

    return total;
}


int main(){

    int W=50, n=3;
    Item arr[] = {{100,20}, {60,10}, {120,30}};

    double cost = fk(W, arr, n);

    cout<<"Cost: "<<setprecision(2)<<fixed<<cost;

    return 0;
}


