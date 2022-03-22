#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include "component.h"

class Graph {
    public:
        // an 100-element vector of vectors of pairs
        // rows represent vertices
        // columns represent the edges of a vertex
        // pair.first is the vertex's neighbor, pair.second is the weight
        std::vector<edges> adjList;

        // a vector of components, i.e. connected subgraphs
        std::vector<Component> cp;

        // a 20-element array for hobbies
        double hobbies[NUM_VERTEX][20] = {{0}};


        Graph();

        // forms the components vector for this graph
        void checkComponent();

        // checks if two nodes are connected
        bool checkConnected(int x, int y);

        // returns the degree of a given vertex
        int degree(int v);

        // returns the number of closed triangles present in the graph
        int totalClosedTriangles();

        // returns the number of open triangles present in the graph
        int totalOpenTriangles();

        // performs depth first search; helper for checkComponent()
        void dfs(Component &c, bool visited[], int v);
};

#endif