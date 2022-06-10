//
// Created by Ariq Heritsa on 10/06/22.
//

#ifndef STD_1305213031_MOD12_JURNAL_APB_GRAPH_H
#define STD_1305213031_MOD12_JURNAL_APB_GRAPH_H

#include <iostream>

using namespace std;

// define
#define nil NULL

#define idVertex(v) v->idVertex
#define nextVertex(v) v->nextVertex
#define firstEdge(v) v->firstEdge

#define destVertexID(e) e->destVertexID
#define weight(e) e->weight
#define nextEdge(e) e->nextEdge

#define firstVertex(g) g.firstVertex

// ADT
typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
  char idVertex;
  adrVertex nextVertex;
  adrEdge firstEdge;
};

struct edge {
  char destVertexID;
  int weight;
  adrEdge nextEdge;
};

struct graph {
  adrVertex firstVertex;
};

// procedure createVertex (input newVertexID: char, output v:adrVertex)
void createVertex(char newVertexID, adrVertex &v);

// procedure initGraph (output G: graph)
void initGraph(graph &G);

// procedure addVertex (input/output G: graph, input newVertexID: char)
void addVertex(graph &G, char newVertexID);

// procedure buildGraph (output G: graph)
void buildGraph(graph &G);

// function searchVertex (G:graph, IDsimpul:char) adrVertex
adrVertex searchVertex(graph G, char IDsimpul);

// procedure printGraph (In G: Graph)
void printGraph(graph G);

// procedure createEdge (input IDsimpulTujuan: char, input bobot:integer, output e:adrEdge)
void createEdge(char IDsimpulTujuan, int bobot, adrEdge &e);

// procedure addEdge (input/output G: graph, input IDsimpulAsal, IDsimpulTujuan: char, bobot:integer)
void addEdge(graph &G, char IDsimpulAsal, char IDsimpulTujuan, int bobot);

// function outDegree (G:graph, IDsimpul:char) integer
int outDegree(graph G, char IDsimpul);

#endif //STD_1305213031_MOD12_JURNAL_APB_GRAPH_H
