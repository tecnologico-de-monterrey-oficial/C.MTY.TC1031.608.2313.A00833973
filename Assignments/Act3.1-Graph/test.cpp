#include <iostream>
using namespace std;
#include "GraphM.h"
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "Graph.h"
int main()
{
    vector<string> vertices = {"A", "B", "C", "D", "E"};
    vector< Edge<string> > edges;
    edges.emplace_back("A","B",5);
    edges.emplace_back("B","A",4);
    edges.emplace_back("A","C",5);
    edges.emplace_back("C","A",7);
    edges.emplace_back("A","E",9);
    edges.emplace_back("E","A",7);
    edges.emplace_back("B","D",1);
    edges.emplace_back("D","B",2);
    edges.emplace_back("C","D",5);
    edges.emplace_back("D","C",3);
    edges.emplace_back("E","D",3);
    edges.emplace_back("D","E",2);

    Graph<string> graph(vertices, edges);
    graph.print();
    
    graph.addVertex("T");
    graph.print();
    
    Edge<string> edgi("T","A",3);
    graph.addEdge(edgi);
    graph.print();
    graph.bfs("A");
    return 0;
}
