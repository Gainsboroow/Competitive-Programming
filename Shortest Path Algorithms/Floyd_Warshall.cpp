#include <iostream>
using namespace std;

const int MAX_NODE = 1000;
int dist[MAX_NODE][MAX_NODE]; // dist[i][j] corresponds to the mininmum distance between i and j

int main(){
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;

    for (int node1 = 0; node1 < nbNodes; node1 ++){
        for (int node2 = 0; node2 < nbNodes; node2 ++){
            dist[node1][node2] = 1e9; 
        }
        dist[node1][node1] = 0; // Setting the distance between a node and itself to 0
    }

    for (int edge = 0; edge < nbEdges; edge++){
        int node1, node2, _dist;
        cin >> node1 >> node2 >> _dist;
        dist[node1][node2] = _dist;
        dist[node2][node1] = _dist;
    }

    for (int interNode = 0; interNode < nbNodes; interNode++){
        for (int node1 = 0; node1 < nbNodes; node1 ++){
            for (int node2 = 0; node2 < nbNodes; node2 ++){
                dist[node1][node2] = min(dist[node1][node2], dist[node1][interNode] + dist[interNode][node2] );
            }
        }
    }
    
    for (int node1 = 0; node1 < nbNodes; node1 ++){
        for (int node2 = 0; node2 < nbNodes; node2 ++){
            cout << dist[node1][node2] << ' ';
        }
        cout << '\n';
    }
}
