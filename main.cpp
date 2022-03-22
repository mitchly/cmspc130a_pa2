#include <iostream>
#include <bits/stdc++.h>

#include "graphGenerator.h"
#include "graphOperator.h"

using namespace std;

int main(int argc, char* argv[]) {
    Graph g;
    
    ifstream eifs(argv[1]);
    ifstream hifs(argv[2]);
    
    GraphGenerator ggen(eifs, hifs, g);
    auto al = g.adjList;
    auto cp = g.cp;

    /*for (size_t i = 0; i < al.size(); i++) {
        cout << "adjList[" << i << "]: ";
        for (auto edge : al.at(i)) {
            cout << "<" << edge.first << "," << edge.second << "> " << endl;
        }
    }
    cout << "------------" << endl;*/
    
    /*int count, ttl(0);
    for (size_t i = 0; i < cp.size(); i++) {
        count = 0;
        cout << "cp[" << i << "]:" << endl;
        for (auto map : cp.at(i).c) {
            cout << map.first << ":<";
            for (auto edge : map.second) {
                cout << edge.first << ":" << edge.second << ",";
            }
            cout << ">" << endl;
            count++;
        }
        cout << "--------------count:" << count << endl;
        ttl += count;
    }
    cout << "--------------ttl:" << ttl << endl;*/
    
    /*for (int i = 0; i < NUM_VERTEX; i++) {
        cout << i << ":";
        for (int j = 0; j < 20; j++) {
            cout << g.hobbies[i][j] << ", ";
        }
        cout << endl;
    }*/

    /*
    go.FindAverageDegree();
    //cout << "a" << endl;
    go.FindHighestDegree();
    //cout << "a" << endl;
    go.FindConnectedNumber();
    //cout << "a" << endl;
    go.FindConnectedParameter(g.cp.at(0));
    //cout << "a" << endl;
    go.FindTrianglesRatio();
    //cout << "a" << endl;
    go.FindClosestNode(3, 0.5, 7);
    //cout << "a:" << endl;
    go.FindHighestInterest(7);
    //cout << "a" << endl;
    go.FindDistanceRatio();
    //cout << "a" << endl;*/

    GraphOperator go(g);
    cout << "The average degree:" << endl;
    cout << fixed << showpoint;
    cout << setprecision(2) << go.FindAverageDegree() << endl;
    cout << "The vertex with the highest degree:" << endl;
    auto v = go.FindHighestDegree();
    for (size_t i = 0; i < v.size(); i++) {
        if (i != 0) cout << ", ";
        cout << v.at(i);
    }
    cout << endl;
    cout << "The number of connected components:" << endl;
    cout << go.FindConnectedNumber() << endl;
    cout << "The diameter, radius, and center(s) of each components" << endl;
    go.FindConnectedParameter();
    cout << "The ratio between the number of open and closed triangles:" << endl;
    cout << fixed << showpoint;
    cout << setprecision(4) << go.FindTrianglesRatio() << endl;
    cout << "The closest node:" << endl;
    cout << go.FindClosestNode(39, 0.5, 7) << endl;
    cout << "A closest with highest interest:" << endl; //fix
    cout << go.FindHighestInterest(7) << endl;
    cout << "The pair of nodes x and y:" << endl;
    go.FindDistanceRatio();
    
    eifs.close();
    hifs.close();
	return 0;
}