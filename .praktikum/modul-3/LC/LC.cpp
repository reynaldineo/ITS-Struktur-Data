#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<string, int> dataInventory;
    string bahanAutoLooting;

    while (getline(cin, bahanAutoLooting) && bahanAutoLooting != "#"){
        dataInventory[bahanAutoLooting]++; // nambah jumlah
    }

    int nJumlahBenda;
    cin >> nJumlahBenda;

    while(nJumlahBenda--){
        int xBanyakBenda_diBuat, mBahanDiPerlukan;
        cin >> xBanyakBenda_diBuat >> mBahanDiPerlukan;
        cin.ignore();

        map<string, int> dataResep;
        while(mBahanDiPerlukan--){
            string namaBahan;
            int yJumlahBahan;
            getline(cin, namaBahan);
            cin >> yJumlahBahan;
            cin.ignore();
            dataResep[namaBahan] = yJumlahBahan;
        }

        int jumlahBendaDiBuat = xBanyakBenda_diBuat;
        for (auto pointer = dataResep.begin(); pointer != dataResep.end(); pointer++){
            jumlahBendaDiBuat = min(jumlahBendaDiBuat, dataInventory[pointer->first] / pointer->second); 
        }

        if (jumlahBendaDiBuat == xBanyakBenda_diBuat){ // kalau bisa ke buat semua
            for (auto pointer = dataResep.begin(); pointer != dataResep.end(); pointer++){
                dataInventory[pointer->first] -= jumlahBendaDiBuat * pointer->second; // ngurangin bahan yg di inventory
            }
            cout << "Material Fulfilled, Crafting " << jumlahBendaDiBuat << "!" << endl;
        } else { // kalau cuman kebuat sebagian
            cout << "Insufficient Material, Can only craft " << jumlahBendaDiBuat << "." << endl;
        }
    }

    return 0;
}
