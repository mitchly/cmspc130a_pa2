#include <string>
#include "graphGenerator.h"

GraphGenerator::GraphGenerator(std::ifstream &edge, std::ifstream &hobby, Graph &g) {
    int n1, n2, u, v, len;
    double weight;
    std::string s;
    
    while (!edge.eof()) {
        std::getline(edge, s);
        if (s.empty()) continue;
        n1 = s.find(",");
        n2 = s.rfind(",");
        len = s.length();
        u = stoi(s.substr(0, n1));
        v = stoi(s.substr(n1+1, n2-n1-1));
        weight = stod(s.substr(n2+1, len-n2-1));
        addEdge(g, u, v, weight);
    }
    int index = 1;
    while (!hobby.eof()) {
        std::getline(hobby, s);
        if (s.empty()) continue;
        n1 = 0;
        n2 = s.find(",");
        for (int i = 0; i < 20; i++) {
            double d = stod(s.substr(n1, n2-n1));
            n1 = n2 + 1;
            n2 = s.find(",", n1+1);
            g.hobbies[index][i] = d;
        }
        index++;
    }

    g.checkComponent();
}

void GraphGenerator::addEdge(Graph &g, int u, int v, double w) {
    g.adjList.at(u).push_back(std::make_pair(v, w));
    g.adjList.at(v).push_back(std::make_pair(u, w));
}