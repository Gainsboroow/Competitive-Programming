#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODE = 1000;

vector<pair<int,int>> graph[MAX_NODE];

int dist[MAX_NODE]; // dist[i] corresponds to the mininmum distance between the source node and node i

priority_queue<pair<int,int>> nodeQueue;


int main(){
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;

    for (int node = 1; node < nbNodes; node ++){
        dist[node] = 1e9; 
    }

    dist[0] = 0; // Setting the distance between a node and itself to 0

    for (int edge = 0; edge < nbEdges; edge++){
        int node1, node2, _dist;
        cin >> node1 >> node2 >> _dist;
        graph[node1].push_back({node2, _dist});
        graph[node2].push_back({node1, _dist});
    }

    nodeQueue.push({0, 0});

    while (!nodeQueue.empty()){
        int node = nodeQueue.top().second;
        nodeQueue.pop();

        for (auto neighbour : graph[node]){
            if (dist[neighbour.first] > dist[node] + neighbour.second){
                dist[neighbour.first] = dist[node] + neighbour.second;
                nodeQueue.push({-dist[neighbour.first], neighbour.first}); 
            }
        }
    }

    for (int node = 0; node < nbNodes; node++){
        cout << dist[node] << ' ';
    }
    
}