#include "graf.h"

// Implementasi fungsi dasar graf
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

// Fungsi navigasi
void FindShortestPath(Graph G, Infotype_Node start, Infotype_Node end) {
    cout << ">> (Simulasi jalur tercepat belum diimplementasikan)" << endl;
}

void DFS_AllRoutes(Graph G, Infotype_Node start, Infotype_Node end,
                   Infotype_Node path[], int &pathLen,
                   Infotype_Node routes[][100], int &routeCount) {
    cout << ">> (Simulasi semua rute belum diimplementasikan)" << endl;
}

// Fungsi untuk menu
void DisplayMenu() {
    cout << "================[MENU]================" << endl;
    cout << "1. Mencari rute" << endl;
    cout << "2. Pemblokiran jalan" << endl;
    cout << "3. Menambahkan gedung & jalan" << endl;
    cout << "4. Keluar" << endl;
    cout << "======================================" << endl;
    cout << "> ";
}

void DisplayRuteMenu() {
    cout << "==============[RUTE]==============" << endl;
    cout << "1. Rute tercepat" << endl;
    cout << "2. Tampilkan semua rute" << endl;
    cout << "3. Kembali" << endl;
    cout << "==================================" << endl;
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

void FindShortestPathMenu(Graph G) {
    Infotype_Node start, end;
    cout << "> Titik 1 (tulis kode gedungnya): ";
    cin >> start;
    cout << "> Titik 2 (tulis kode gedungnya): ";
    cin >> end;

    FindShortestPath(G, start, end);
}

void FindAllRoutesMenu(Graph G) {
    Infotype_Node start, end;
    cout << "> Titik 1 (tulis kode gedungnya): ";
    cin >> start;
    cout << "> Titik 2 (tulis kode gedungnya): ";
    cin >> end;

    Infotype_Node path[100], routes[100][100];
    int pathLen = 0, routeCount = 0;

    DFS_AllRoutes(G, start, end, path, pathLen, routes, routeCount);
}

void BlockRoadMenu(Graph G) {
    Infotype_Node node1, node2;
    cout << "=====================[Peta]=====================" << endl;
    Show(G);
    cout << "================================================" << endl;

    cout << "> Jalan yang ingin diblokir (tulis kode gedung, contoh: A B): ";
    cin >> node1 >> node2;

    Disconnect(G, node1, node2);

    cout << "=====================[Peta Setelah Pemblokiran]=====================" << endl;
    Show(G);
    cout << "===================================================================" << endl;
}
