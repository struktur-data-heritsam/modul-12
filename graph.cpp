//
// Created by Ariq Heritsa on 10/06/22.
//

#include "graph.h"

void createVertex(char newVertexID, adrVertex &v) {
  v = new vertex;

  idVertex(v) = newVertexID;
  nextVertex(v) = nil;
  firstEdge(v) = nil;
}

void initGraph(graph &G) {
  firstVertex(G) = nil;
}

void addVertex(graph &G, char newVertexID) {
  adrVertex newVertex, currentVertex;

  createVertex(newVertexID, newVertex);

  if (firstVertex(G) == nil) {
    // graph kosong
    firstVertex(G) = newVertex;
  } else {
    // graph tidak kosong
    currentVertex = firstVertex(G);

    while (nextVertex(currentVertex) != nil) {
      currentVertex = nextVertex(currentVertex);
    }

    nextVertex(currentVertex) = newVertex;
  }

}

void buildGraph(graph &G) {
  char inputIDsimpul;

  cout << "Masukkan simpul baru: ";
  cin >> inputIDsimpul;

  while (inputIDsimpul >= 65 && inputIDsimpul <= 90 || inputIDsimpul >= 97 && inputIDsimpul <= 122) {
    addVertex(G, inputIDsimpul);

    cout << "Masukkan simpul baru: ";
    cin >> inputIDsimpul;
  }
}

adrVertex searchVertex(graph G, char IDsimpul) {
  adrVertex current = firstVertex(G);

  while (current != nil) {
    if (idVertex(current) == IDsimpul) {
      return current;
    }

    current = nextVertex(current);
  }

  return nil;
}

void printGraph(graph G) {
  if (firstVertex(G) == nil) {
    cout << "Graph kosong" << endl;
  } else {
    cout << "Isi graph: " << endl;
    adrVertex current = firstVertex(G);

    while (current != nil) {
      cout << "Vertex " << idVertex(current) << " -> ";

      adrEdge edge = firstEdge(current);

      while (edge != nil) {
        cout << destVertexID(edge) << "(" << weight(edge) << ")" << " -> ";
        edge = nextEdge(edge);
      }

      cout << "NULL" << endl;

      current = nextVertex(current);
    }
  }

  cout << endl;
}

void createEdge(char IDsimpulTujuan, int bobot, adrEdge &e) {
  e = new edge;

  destVertexID(e) = IDsimpulTujuan;
  weight(e) = bobot;
  nextEdge(e) = nil;
}

void addEdge(graph &G, char IDsimpulAsal, char IDsimpulTujuan, int bobot) {
  // cari simpul
  adrVertex currentVertex = searchVertex(G, IDsimpulAsal);

  // buat edge baru
  adrEdge newEdge;
  createEdge(IDsimpulTujuan, bobot, newEdge);

  if (currentVertex != nil) {
    if (firstEdge(currentVertex) == nil) {
      // edge masih kosong
      firstEdge(currentVertex) = newEdge;
    } else {
      // edge tidak kosong
      adrEdge currentEdge = firstEdge(currentVertex);

      while (nextEdge(currentEdge) != nil) {
        currentEdge = nextEdge(currentEdge);
      }

      nextEdge(currentEdge) = newEdge;
    }
  }
}

int outDegree(graph G, char IDsimpul) {
  adrVertex currentVertex = searchVertex(G, IDsimpul);
  int count = 0;

  if (currentVertex != nil) {
    adrEdge currentEdge = firstEdge(currentVertex);

    while (currentEdge != nil) {
      count++;
      currentEdge = nextEdge(currentEdge);
    }
  }

  return count;
}
