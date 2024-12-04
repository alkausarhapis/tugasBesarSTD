#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define Null     		NULL
#define Info(P)  		(P)->Info
#define NextNode(P)  	(P)->NextNode
#define NextEdge(P)  	(P)->NextEdge
#define FirstEdge(P) 	(P)->FirstEdge
#define Start(G) 		(G).Start

typedef struct vElmt Elmt_Node;
typedef struct eElmt Elmt_Edge;
typedef Elmt_Node*   Addr_Node;
typedef Elmt_Edge*   Addr_Edge;

typedef string Infotype_Node;
typedef int Infotype_Edge;

typedef struct {
	Addr_Node Start;
} Graph;

struct vElmt {
   Infotype_Node Info;
   Addr_Node     NextNode;
   Addr_Edge     FirstEdge;
};

struct eElmt {
   Infotype_Edge Info;
   Addr_Edge     NextEdge;
};

void CreateGraph(Graph &G);
Addr_Node AlokasiNode(Infotype_Node infoNode);
Addr_Edge AlokasiEdge(Infotype_Edge infoEdge);
void AddNewNode(Graph &G, Addr_Node P);
Addr_Node FindNode(Graph G, Infotype_Node data);
void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge);
void Connecting(Graph &G, Infotype_Node node1, Infotype_Node node2, Infotype_Edge distance);
void Show(Graph G);

#endif // GRAF_H_INCLUDED
