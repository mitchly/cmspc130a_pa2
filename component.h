#ifndef COMPONENT_H
#define COMPONENT_H

#include <unordered_map>
#include <vector>

#define NUM_VERTEX 101
using edges = std::vector< std::pair<int, double> >;

class Component {
    public:
        // an unordered_map of vectors of pairs
        // each key 0represents a vertex
        // each value is a vector of edges of a vertex
        // pair.first is the vertex's neighbor, pair.second is the weight
        std::unordered_map<int, edges> c;


        Component() = default;

        // copy constructor
        Component(const Component &comp);

        // returns a vector with all the centers in a component
        std::vector<int> center();

        // returns the diameter of the component
        double diameter();

        // returns the eccentricity of a vertex
        double eccentricity(int v);

        // returns the radius of the component
        double radius();

        int combination(int n);

        int openTriangles();
        
        int closedTriangles();
};

#endif