#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include "component.h"

Component::Component(const Component &comp) {
    for (auto m : comp.c) {
        c.emplace(m.first, m.second);
    }
}

//set of nodes w eccentricity equal to the radius of the graph (could be more than one)
std::vector<int> Component::center() {    
    std::vector<std::pair<int, double>> minEccen;
    for(auto p : c) {
        double eccen = eccentricity(p.first);
        minEccen.push_back(std::make_pair(p.first, eccen));
    }

	double radius = std::numeric_limits<double>::infinity();
    for (auto d : minEccen) {
        if ((d.second != 0) && d.second < radius) radius = d.second;
    }
    
    std::vector<int> out;
    for (auto p : minEccen) {
        if (std::abs(p.second - radius) < 0.001) out.push_back(p.first);
    }
    std::sort(out.begin(), out.end());
	return out;
}

//max eccentricity
double Component::diameter() {
    std::vector<double> maxEccen;
    for (auto p : c) {
        double eccen = eccentricity(p.first);
        maxEccen.push_back(eccen);
    }
    
    double out = 0.0;
    for (auto d : maxEccen) {
        if ((d != std::numeric_limits<double>::infinity()) && d > out) out = d;
    }    return out;
}

// initializes an array of all vertices, set all distances to inf
// loop through all adjacent vertices, find eccentricity of them using DFS
double Component::eccentricity(int v) {
    double distance[NUM_VERTEX];
    std::fill_n(distance, NUM_VERTEX, std::numeric_limits<double>::infinity());
    distance[v] = 0;
    // Dijkstra
    std::vector<int> visited;
    std::vector<int> vertices;
    for (auto p : c) {vertices.push_back(p.first);}
    int u;
    while (!vertices.empty()) {
        double min = std::numeric_limits<double>::infinity();
        std::vector<int>::iterator index;
        for (auto i = vertices.begin(); i != vertices.end(); i++) {
            if (distance[*i] < min) {
                u = *i;
                min = distance[*i];
                index = i;
            }
        }
        visited.push_back(u);
        vertices.erase(index);
        for (auto e : c.at(u)) {
            if (distance[e.first] > (distance[u] + e.second)) distance[e.first] = (distance[u] + e.second);
        }
    }

    double out = 0.0;
    for (auto d : distance) {
        if ((d != std::numeric_limits<double>::infinity()) && d > out) out = d;
    }
    return out;
}

//min eccentricity
double Component::radius() {
    std::vector<double> minEccen;
    for(auto p : c) {
        double eccen = eccentricity(p.first);
        minEccen.push_back(eccen);
    }

    double out = std::numeric_limits<double>::infinity();
    for (auto d : minEccen) {
        if ((d != 0) && d < out) out = d;
    }
    return out;
}

//calculate combinations for total number of possible triangles
int Component::combination(int n) {
    int combo = 1;
    for (int i = n; i > (n-2); i--) {
        combo *= i;
    }
    return combo / 2;
}

int Component::closedTriangles() {
    int count = 0;

    for (auto v = c.begin(); v != c.end(); v++) {
        // run through neighbors of v
        for (auto i = (*v).second.begin(); i != (*v).second.end(); i++) {
            // run through the neighbors of v that are listed in the vector after i
            for (auto j = i; j != (*v).second.end(); j++) {
                // run through the neighbors of i to check if j is connected to i
                for (auto k = c.at((*i).first).begin(); k != c.at((*i).first).end(); k++) {
                    if ((*k).first == (*j).first) count++;
                }
            }
        }
    }
    return count / 3;
}

int Component::openTriangles() {
    int ttlTriangle = 0;
    for (auto v = c.begin(); v != c.end(); v++) {
        ttlTriangle += combination((*v).second.size());
    }
    return ttlTriangle - 3*closedTriangles();
}