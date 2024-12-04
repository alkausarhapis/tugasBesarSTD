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

	return 0;
}
