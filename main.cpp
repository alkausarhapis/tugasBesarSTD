#include "graf.h"

int main() {
    int menuChoice, loginChoice;
    Graph G;
    CreateGraph(G);

    // Alokasi data gedung dan koneksi manual
    AddNewNode(G, AlokasiNode("TULT"));
    AddNewNode(G, AlokasiNode("TUCH"));
    AddNewNode(G, AlokasiNode("PAR"));
    AddNewNode(G, AlokasiNode("GKU"));
    AddNewNode(G, AlokasiNode("REK"));
    AddNewNode(G, AlokasiNode("CAC"));
    AddNewNode(G, AlokasiNode("DMR"));
    AddNewNode(G, AlokasiNode("TMED"));

    Connecting(G, "TULT", "TUCH", 7);
    Connecting(G, "TULT", "TMED", 10);
    Connecting(G, "TULT", "PAR", 6);
    Connecting(G, "TUCH", "GKU", 5);
    Connecting(G, "TUCH", "PAR", 3);
    Connecting(G, "GKU", "PAR", 2);
    Connecting(G, "GKU", "REK", 4);
    Connecting(G, "REK", "CAC", 1);
    Connecting(G, "CAC", "DMR", 2);
    Connecting(G, "DMR", "PAR", 5);
    Connecting(G, "DMR", "TMED", 4);
    Connecting(G, "TMED", "PAR", 8);

    do {
      cout << "===============================================================" << endl;
      cout << "                    Sistem Navigasi Kampus                     " << endl;
      cout << "===============================================================" << endl;
      cout << "Login Untuk melanjutkan" << endl;
      cout << "1. Admin" << endl;
      cout << "2. Pengguna" << endl;
      cout << "3. Keluar sistem" << endl;
      cout << "===============================================================" << endl;
      cout << "> ";

      while (!(cin >> loginChoice) || loginChoice < 1 || loginChoice > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Pilihan tidak valid! Masukkan angka antara 1 sampai 3.\n> ";
      }

      if(loginChoice == 1) {
        do {
            DisplayMenuAdmin();
            while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 5) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Pilihan tidak valid! Masukkan angka antara 1 sampai 5.\n> ";
            }

            switch (menuChoice) {
                case 1:
                    int ruteChoice;
                    DisplayBuildings(G);
                    FindShortestPathMenu(G);
                    cout << endl;
                    break;
                case 2:
                    cout << endl;
                    displayMapMenu(G);
                    cout << endl;
                    break;
                case 3:
                    BlockRoadMenu(G);
                    break;
                case 4:
                    AddBuildingAndRoadMenu(G);
                    break;
                case 5:
                    cout << "Berhasil Logout!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (menuChoice != 5);
      } else if (loginChoice == 2) {
        do {
            DisplayMenuPengguna();
            while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 5) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 3.\n> ";
            }

            switch (menuChoice) {
                case 1:
                    int ruteChoice;
                    DisplayBuildings(G);
                    FindShortestPathMenu(G);
                    cout << endl;
                    break;
                case 2:
                    cout << endl;
                    displayMapMenu(G);
                    cout << endl;
                    break;
                case 3:
                    cout << "Berhasil Logout!" << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (menuChoice != 3);
      }

    } while(loginChoice != 3);

    cout << "Keluar dari sistem";
    return 0;
}