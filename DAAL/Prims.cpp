#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> vis(V,0);

    // wt, node
    pq.push({0,0});
    int sum = 0;

    while (!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        //get all adjacent nodes
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(!vis[adjNode]){
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    return sum;
}


int main(){
    int V = 5;

    //node1, node2, wt
    vector<vector<int>> edges = {
        {0,1,2}, {0,2,1}, {1,2,1}, {2,3,2}, {2,4,2}, {3,4,1}
    };

    vector<vector<int>> adj[V];

    for(auto it : edges){
        vector<int> temp(2);

        temp[0] = it[1]; //node2
        temp[1] = it[2]; // wt
        adj[it[0]].push_back({temp});

        temp[0] = it[0]; //node1
        temp[1] = it[2]; // wt
        adj[it[1]].push_back({temp});
    }

    int sum = spanningTree(V, adj);
    cout<<sum;
    return 0;
}