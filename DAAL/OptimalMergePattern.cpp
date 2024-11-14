#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int optimalMergePattern(vector<int> files, int n){
    priority_queue<int, vector<int>, greater<int>> minheap;
    int cost = 0;
    for(int i = 0; i<n; i++){
        minheap.push(files[i]);
    }

    while(minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();

        int e2 = minheap.top();
        minheap.pop();

        cost += e1 + e2;
        minheap.push(e1+e2);
    }

    return cost;
}

int main(){
    int n;
    cout<<"Enter number of files: ";
    cin>>n;

    vector<int> files(n);

    cout<<"\nEnter files sizes: ";
    for(int i = 0; i<n; i++){
        cin>>files[i];
    }

    int cost = optimalMergePattern(files, n);
    cout<<"Cost: "<<cost;
    return 0;
}