#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> dijktas(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(V, 1e9);

    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main(){
    int V=6, S=0;
    vector<vector<int>> adj[V];
    
    adj[0].push_back({1,4});
    adj[0].push_back({2,4});

    adj[1].push_back({0,4});
    adj[1].push_back({2,2});

    adj[2].push_back({0,4});
    adj[2].push_back({1,2});
    adj[2].push_back({3,3});
    adj[2].push_back({4,1});
    adj[2].push_back({5,6});

    adj[3].push_back({2,3});
    adj[3].push_back({5,2});

    adj[4].push_back({2,1});
    adj[4].push_back({5,3});

    adj[5].push_back({3,2});
    adj[5].push_back({4,3});


    vector<int> result = dijktas(V, adj, S);
    for(int i = 0; i<V; i++){
        cout<<result[i]<<" ";
    }

    cout<<endl;
    return 0;
}