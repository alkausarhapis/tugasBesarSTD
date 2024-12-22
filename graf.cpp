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

void Connecting(Graph &G, Infotype_Node node1, Infotype_Node node2, int weight) {
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);
    if (P1 != Null && P2 != Null) {
        Infotype_Edge edge1 = {node2, weight};
        Infotype_Edge edge2 = {node1, weight};
        InsertLast_Edge(G, P1, AlokasiEdge(edge1));
        InsertLast_Edge(G, P2, AlokasiEdge(edge2));
    }
}

void Disconnect(Graph &G, Infotype_Node node1, Infotype_Node node2) {
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);

    if (P1 != Null && P2 != Null) {
        Addr_Edge *prevEdge = &FirstEdge(P1);
        while (*prevEdge != Null && Info(*prevEdge).destination != node2) {
            prevEdge = &NextEdge(*prevEdge);
        }
        if (*prevEdge != Null) {
            Addr_Edge temp = *prevEdge;
            *prevEdge = NextEdge(temp);
            delete temp;
        }

        prevEdge = &FirstEdge(P2);
        while (*prevEdge != Null && Info(*prevEdge).destination != node1) {
            prevEdge = &NextEdge(*prevEdge);
        }
        if (*prevEdge != Null) {
            Addr_Edge temp = *prevEdge;
            *prevEdge = NextEdge(temp);
            delete temp;
        }
    }
}

void Show(Graph G) {
    Addr_Node P = Start(G);
    while (P != Null) {
        cout << "Gedung " << Info(P) << " terhubung ke:\n";
        Addr_Edge E = FirstEdge(P);
        while (E != Null) {
            cout << "  - " << Info(E).destination << " (Jarak: " << Info(E).weight << ")\n";
            E = NextEdge(E);
        }
        P = NextNode(P);
    }
}

void FindShortestPath(Graph G, Infotype_Node nodes[], int nodeCount) {
    const int INF = 1000000;
    Infotype_Node graphNodes[100];
    int distances[100];
    int predecessors[100];
    bool visited[100];
    int totalNodes = 0;

    Addr_Node P = Start(G);
    while (P != Null) {
        graphNodes[totalNodes] = Info(P);
        totalNodes++;
        P = NextNode(P);
    }

    int totalDistance = 0;
    for (int i = 0; i < nodeCount - 1; i++) {
        for (int j = 0; j < totalNodes; j++) {
            distances[j] = INF;
            visited[j] = false;
            predecessors[j] = -1;
        }

        int startIndex = -1, endIndex = -1;
        for (int j = 0; j < totalNodes; j++) {
            if (graphNodes[j] == nodes[i]) startIndex = j;
            if (graphNodes[j] == nodes[i + 1]) endIndex = j;
        }

        if (startIndex == -1 || endIndex == -1) {
            cout << "Node tidak ditemukan!" << endl;
            return;
        }

        distances[startIndex] = 0;

        for (int j = 0; j < totalNodes; j++) {
            int minDistance = INF, currentIndex = -1;
            for (int k = 0; k < totalNodes; k++) {
                if (!visited[k] && distances[k] < minDistance) {
                    minDistance = distances[k];
                    currentIndex = k;
                }
            }

            if (currentIndex == -1) break;
            visited[currentIndex] = true;

            Addr_Node currentNode = FindNode(G, graphNodes[currentIndex]);
            Addr_Edge edge = FirstEdge(currentNode);

            while (edge != Null) {
                Infotype_Node neighbor = Info(edge).destination;
                int weight = Info(edge).weight;

                int neighborIndex = -1;
                for (int k = 0; k < totalNodes; k++) {
                    if (graphNodes[k] == neighbor) {
                        neighborIndex = k;
                        break;
                    }
                }

                if (!visited[neighborIndex] && distances[currentIndex] + weight < distances[neighborIndex]) {
                    distances[neighborIndex] = distances[currentIndex] + weight;
                    predecessors[neighborIndex] = currentIndex;
                }

                edge = NextEdge(edge);
            }
        }

        if (distances[endIndex] == INF) {
            cout << "Tidak ada jalur dari " << nodes[i] << " ke " << nodes[i + 1] << ".\n";
            return;
        }

        totalDistance += distances[endIndex];
        cout << "Jalur dari " << nodes[i] << " ke " << nodes[i + 1] << ": ";
        int current = endIndex;
        while (current != -1) {
            cout << graphNodes[current];
            current = predecessors[current];
            if (current != -1) cout << " <- ";
        }
        cout << " (Jarak: " << distances[endIndex] << ")\n";
    }

    cout << "Jarak total: " << totalDistance << endl;
}


// Menu menuan
void DisplayMenuAdmin() {
    cout << "================[MENU ADMIN]================" << endl;
    cout << "1. Mencari rute terpendek" << endl;
    cout << "2. Tampilkan peta" << endl;
    cout << "3. Pemblokiran jalan" << endl;
    cout << "4. Menambahkan gedung & jalan" << endl;
    cout << "5. Log out" << endl;
    cout << "============================================" << endl;
    cout << "> ";
}

void DisplayMenuPengguna() {
    cout << "===============[MENU PENGGUNA]==============" << endl;
    cout << "1. Mencari rute terpendek" << endl;
    cout << "2. Tampilkan peta" << endl;
    cout << "3. Log out" << endl;
    cout << "============================================" << endl;
    cout << "> ";
}

void DisplayBuildings(Graph G) {
    cout << "====================[LIST GEDUNG]====================" << endl;
    Addr_Node P = Start(G);
    while (P != Null) {
        cout << "Gedung " << Info(P) << endl;
        P = NextNode(P);
    }
    cout << "=====================================================" << endl;
}

void displayMapMenu(Graph G){
    cout << "=====================[Peta]=====================" << endl;
    Show(G);
    cout << "================================================" << endl;
}

 void FindShortestPathMenu(Graph G) {
    int totalNodes = 0;
    Addr_Node P = Start(G);
    while (P != Null) {
        totalNodes++;
        P = NextNode(P);
    }

    cout << "Jumlah gedung yang tersedia: " << totalNodes << endl;

    int nodeCount;
    do {
        cout << "> Masukkan jumlah titik yang dilalui: ";
        cin >> nodeCount;

        if (cin.fail() || nodeCount <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Harap masukkan ulang.\n";
        }
    } while (cin.fail() || nodeCount <= 0);

    Infotype_Node nodes[100];
    for (int i = 0; i < nodeCount; i++) {
        do {
            cout << "> Titik " << i + 1 << " (tulis kode gedungnya): ";
            cin >> nodes[i];

            if (FindNode(G, nodes[i]) == Null) {
                cout << "Kode gedung " << nodes[i] << " tidak ditemukan! Harap masukkan ulang.\n";
            }
        } while (FindNode(G, nodes[i]) == Null);
    }

    FindShortestPath(G, nodes, nodeCount);
}

void BlockRoadMenu(Graph G) {
    Infotype_Node node1, node2;
    displayMapMenu(G);

    bool validInput = false;
    do {
        cout << "> Jalan yang ingin diblokir (tulis kode gedung, contoh: TULT CAC): ";
        cin >> node1 >> node2;

        if (FindNode(G, node1) == Null || FindNode(G, node2) == Null) {
            cout << "Salah satu atau kedua kode gedung tidak ditemukan! Harap masukkan ulang.\n";
        } else {
            validInput = true;
        }
    } while (!validInput);

    Disconnect(G, node1, node2);

    cout << "=====================[Peta Setelah Pemblokiran]=====================" << endl;
    Show(G);
    cout << "===================================================================" << endl;
}

void AddBuildingAndRoadMenu(Graph &G) {
    string newBuilding;
    cout << "Masukkan nama gedung baru: ";
    cin >> newBuilding;

    Addr_Node newBuildingNode = AlokasiNode(newBuilding);
    AddNewNode(G, newBuildingNode);
    cout << "Gedung " << newBuilding << " berhasil ditambahkan.\n";

    char addRoadChoice;
    do {
        string connectedBuilding;
        int weight;

        cout << "\nDaftar gedung yang tersedia:\n";
        DisplayBuildings(G);

        do {
            cout << "Masukkan nama gedung yang akan dihubungkan dengan " << newBuilding << ": ";
            cin >> connectedBuilding;

            if (FindNode(G, connectedBuilding) == Null) {
                cout << "Gedung " << connectedBuilding << " tidak ditemukan! Harap masukkan ulang.\n";
            }
        } while (FindNode(G, connectedBuilding) == Null);

        cout << "Masukkan jarak antara " << newBuilding << " dan " << connectedBuilding << ": ";
        while (!(cin >> weight) || weight <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Masukkan jarak yang benar: ";
        }

        Connecting(G, newBuilding, connectedBuilding, weight);
        cout << "Gedung " << newBuilding << " berhasil dihubungkan dengan " << connectedBuilding << " dengan jarak " << weight << ".\n";

        cout << "Apakah Anda ingin menambahkan jalan lain untuk " << newBuilding << "? (y/n): ";
        cin >> addRoadChoice;
    } while (addRoadChoice == 'y' || addRoadChoice == 'Y');
}
