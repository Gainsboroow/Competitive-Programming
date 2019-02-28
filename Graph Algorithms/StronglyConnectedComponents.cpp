#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_NODE = 1000;

vector<int> graph[MAX_NODE];
vector<int> rgraph[MAX_NODE]; // Reverse graph where every edge is flipped

stack<int> processOrder;

bool alreadySeen[MAX_NODE];

void dfs(int node){
    if (alreadySeen[node]) return;
    alreadySeen[node] = true;

    for (int neighbour : graph[node]){
        dfs(neighbour);
    }

    processOrder.push(node);
}

int nbSCC;
int component[MAX_NODE]; //component[i] is the component node i belongs to

void SCC(int node){
    if (component[node]) return;
    component[node] = nbSCC;

    for (int neighbour : rgraph[node]){
        SCC(neighbour);
    }
}

int main(){
    int nbNodes, nbEdges;
    cin >> nbNodes >> nbEdges;

    for (int i = 0; i < nbEdges; i++){
        int source, dest;
        cin >> source >> dest; 
        graph[source].push_back(dest);
        rgraph[dest].push_back(source);
    }
    
    for (int node = 0; node < nbNodes; node++){
        dfs(node);
    }

    while (!processOrder.empty()){
        int node = processOrder.top();
        processOrder.pop();
        if (!component[node]){
            nbSCC ++;
            SCC(node);
        }
    }

    cout << nbSCC << '\n';

    for (int node = 0; node < nbNodes; node++){
        cout << component[node] << ' ';
    }
}