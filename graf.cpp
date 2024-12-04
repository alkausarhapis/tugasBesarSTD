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

Addr_Node FindNode(Graph G, Infotype_Node data) {
	Addr_Node P = Start(G);
	while (P != Null && Info(P) != data) {
		P = NextNode(P);
	}
	return P;
}

void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge) {
	if (FirstEdge(PNode) == Null) {
		FirstEdge(PNode) = PEdge;
	} else {
		Addr_Edge Q = FirstEdge(PNode);
		while (NextEdge(Q) != Null) {
			Q = NextEdge(Q);
		}
		NextEdge(Q) = PEdge;
	}
}

void Connecting(Graph &G, Infotype_Node node1, Infotype_Node node2, Infotype_Edge distance) {
	Addr_Node P1 = FindNode(G, node1);
	Addr_Node P2 = FindNode(G, node2);
	if (P1 != Null && P2 != Null) {
		Addr_Edge E1 = AlokasiEdge(distance);
		InsertLast_Edge(G, P1, E1);
	}
}

void Show(Graph G) {
	Addr_Node P = Start(G);
	while (P != Null) {
		cout << "Gedung " << Info(P) << " terhubung ke:\n";
		Addr_Edge E = FirstEdge(P);
		while (E != Null) {
			cout << "  Jarak: " << Info(E) << endl;
			E = NextEdge(E);
		}
		P = NextNode(P);
	}
}


