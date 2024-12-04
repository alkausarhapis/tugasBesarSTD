#include "graf.h"

int main() {
    Graph G;
	CreateGraph(G);

	AddNewNode(G, AlokasiNode("GKU"));
	AddNewNode(G, AlokasiNode("TULT"));
	AddNewNode(G, AlokasiNode("DMR"));
	AddNewNode(G, AlokasiNode("CAC"));
	AddNewNode(G, AlokasiNode("REK"));
	AddNewNode(G, AlokasiNode("TUCH"));
	AddNewNode(G, AlokasiNode("TMED"));

	Connecting(G, "TULT", "TUCH", 7);
	Connecting(G, "TUCH", "GKU", 5);
	Connecting(G, "GKU", "REK", 4);
	Connecting(G, "REK", "CAC", 7);
	Connecting(G, "CAC", "DMR", 2);
	Connecting(G, "DMR", "TMED", 4);
	Connecting(G, "TMED", "TULT", 10);

	Show(G);


	return 0;
}
