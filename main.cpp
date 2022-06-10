#include <iostream>
#include "graph.h"

using namespace std;

int main() {
  graph G;

  initGraph(G);

  buildGraph(G);

  printGraph(G);

  addEdge(G, 'A', 'C', 12);
  addEdge(G, 'A', 'D', 60);

  addEdge(G, 'B', 'A', 10);

  addEdge(G, 'C', 'B', 20);
  addEdge(G, 'C', 'D', 32);

  addEdge(G, 'E', 'A', 7);

  printGraph(G);

  // out degree
  adrVertex currentVertex = firstVertex(G);

  while (currentVertex != nil) {
    cout << "degout(" << idVertex(currentVertex) << ") = " << outDegree(G, idVertex(currentVertex)) << endl;
    currentVertex = nextVertex(currentVertex);
  }

  return 0;
}
