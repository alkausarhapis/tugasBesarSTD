#include "graf.h"

int main() {
    Graph G;
    CreateGraph(G);

    AddNewNode(G, AlokasiNode("TULT"));
    AddNewNode(G, AlokasiNode("TUCH"));
    AddNewNode(G, AlokasiNode("PAR"));
    AddNewNode(G, AlokasiNode("GKU"));
    AddNewNode(G, AlokasiNode("REK"));
    AddNewNode(G, AlokasiNode("CAC"));
    AddNewNode(G, AlokasiNode("DMR"));
    AddNewNode(G, AlokasiNode("TMED"));

    Connecting(G, "TULT", "TUCH", 7);
    Connecting(G, "TULT", "PAR", 6);
    Connecting(G, "PAR", "GKU", 2);
    Connecting(G, "GKU", "REK", 4);
    Connecting(G, "REK", "CAC", 1);
    Connecting(G, "CAC", "DMR", 2);
    Connecting(G, "DMR", "TMED", 8);

    int menuChoice;
    do {
        DisplayMenu();
        cin >> menuChoice;

        switch (menuChoice) {
            case 1: {
                int ruteChoice;
                do {
                    DisplayRuteMenu();
                    cin >> ruteChoice;

                    if (ruteChoice == 1) {
                        DisplayBuildings(G);
                        FindShortestPathMenu(G);
                    } else if (ruteChoice == 2) {
                        DisplayBuildings(G);
                        FindAllRoutesMenu(G);
                    }
                } while (ruteChoice != 3);
                break;
            }
            case 2:
                BlockRoadMenu(G);
                break;
            case 3:
                cout << "Fitur menambahkan gedung & jalan belum tersedia." << endl;
                break;
            case 4:
                cout << "Keluar dari sistem." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (menuChoice != 4);

    return 0;
}
