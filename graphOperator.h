#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include "graphGenerator.h"

//pass graph by reference
//pass component as parameter instead?

class GraphOperator{
    public:

        Graph g;

        GraphOperator(Graph gr);

        //Find the average degree
        double FindAverageDegree();
        //Find the vertex with the highest degree
        std::vector<int> FindHighestDegree();
        //Find the number of connected components
        int FindConnectedNumber();
        //Find the diameter, radius, and centers of each component.
        void FindConnectedParameter();
        //Find the ratio between the number of open and closed triangles
        double FindTrianglesRatio();
        //Find the closest node from x with an interest level of 
        //at least t on hobby h.
        int FindClosestNode(int x, double t, int h);
        //Find a person with the highest interest in h.
        int FindHighestInterest(int h);
        //Find a pair of nodes x and y whose ratio between hobby 
        //distance and graph distance is smallest.
        void FindDistanceRatio();
        
        //helpers
        double hobbyDistance(int x, int y);
};

#endif