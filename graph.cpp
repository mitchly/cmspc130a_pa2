#include "graph.h"

Graph::Graph() {
    adjList.resize(NUM_VERTEX);
}

void Graph::checkComponent() {
    bool visited[adjList.size()] = {false};
    for (size_t i = 1; i < adjList.size(); i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        Component c;
        c.c.emplace(i, adjList.at(i));
        dfs(c, visited, i);
        cp.push_back(c);
    }
}

int Graph::degree(int v) {
    return adjList.at(v).size();
}

//this would be super helpful for some functions
//checks if two nodes are connected
bool Graph::checkConnected(int x, int y) {
    for (auto edge : adjList.at(x)) {
        if (edge.first == y) return true;
    }
    return false;
}

//counts number of triangles knowing that the graph is in the form of an adjList
//divide by 3? to avoid duplicates
int Graph::totalClosedTriangles() {
    int count = 0;
    for (size_t i = 0; i < cp.size(); i++) {
        count += cp.at(i).closedTriangles();
    }
    
    return count;
}

//there is a way to avoid counting duplicates, but it is possible to accidentally count some
int Graph::totalOpenTriangles() {
    int count = 0;
    for (size_t i = 0; i < cp.size(); i++) {
        count += cp.at(i).openTriangles();
    }

    return count;
}

void Graph::dfs(Component &comp, bool visited[], int v) {
    visited[v] = true;
    for (size_t a = 0; a < adjList.at(v).size(); a++) {
        int w = adjList.at(v).at(a).first;
        if (visited[w]) continue;
        
        visited[w] = true;
        comp.c.emplace(w, adjList.at(w));
        dfs(comp, visited, w);
    }
}