#include "graf.h"

void CreateGraph(Graph &G) {
	Start(G) = Null;
}

Addr_Node AlokasiNode(Infotype_Node infoNode) {
	Addr_Node P = new Elmt_Node;
	Info(P) = infoNode;
	FirstEdge(P) = Null;
	NextNode(P) = Null;
	return P;
}

Addr_Edge AlokasiEdge(Infotype_Edge infoEdge) {
	Addr_Edge P = new Elmt_Edge;
	Info(P) = infoEdge;
	NextEdge(P) = Null;
	return P;
}

void AddNewNode(Graph &G, Addr_Node P) {
	if (Start(G) == Null) {
		Start(G) = P;
	} else {
		Addr_Node Q = Start(G);
		while (NextNode(Q) != Null) {
			Q = NextNode(Q);
		}
		NextNode(Q) = P;
	}
}
