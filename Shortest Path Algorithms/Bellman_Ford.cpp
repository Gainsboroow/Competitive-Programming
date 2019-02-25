#include <iostream>
#include <vector>
using namespace std;

const int MAX_NODE = 1000;

struct Edge{
    int source, dest, _dist;
};

int dist[MAX_NODE]; // dist[i] corresponds to the mininmum distance between the source node and node i
vector<Edge> edges;


int main(){
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;

    for (int node = 0; node < nbNodes; node ++){
        dist[node] = 1e9; 
    }

    dist[0] = 0; // Setting the distance between a node and itself to 0

    for (int edge = 0; edge < nbEdges; edge++){
        int node1, node2, _dist;
        cin >> node1 >> node2 >> _dist;
        edges.push_back({node1, node2, _dist});
    }

    for (int step = 0; step < nbNodes; step ++){
        for (Edge edge : edges){
            dist[edge.dest] = min(dist[edge.dest], dist[edge.source] + edge._dist);
        }
    }

    for (Edge edge : edges){
        if ( dist[edge.dest] > dist[edge.source] + edge._dist ){
            cout << "Negative cycle detected";
            return 0;
        }
    }

    for (int node = 0; node < nbNodes; node++){
        cout << dist[node] << ' ';
    }
}