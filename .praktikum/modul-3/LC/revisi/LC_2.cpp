#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<string, int> dataInventory;
    string bahanAutoLooting;
    while(getline(cin, bahanAutoLooting) && bahanAutoLooting != "#"){
        dataInventory[bahanAutoLooting]++; // ngasih jumlah
    }

    int nJumlahBenda;
    cin >> nJumlahBenda;
    // cin.ignore();

    while(nJumlahBenda--){
        int xBanyakBenda_diBuat, mBahanDiPerlukan;
        cin >> xBanyakBenda_diBuat >> mBahanDiPerlukan;

        map<string, int> dataResep;
        cin.ignore();
        while(mBahanDiPerlukan--){
            string namaBahan;
            int yJumlahBahan;

            // cin.ignore(); // untuk menghapus karakter new line
            getline(cin, namaBahan);
            cin >> yJumlahBahan;
            cin.ignore();
            dataResep[namaBahan] =  yJumlahBahan;
        }

        int jumlahBendaDiBuat = xBanyakBenda_diBuat;
        for(auto i = dataResep.begin(); i != dataResep.end(); i++){
            jumlahBendaDiBuat = min(jumlahBendaDiBuat, dataInventory[i->first] / i->second);
        }

        if(jumlahBendaDiBuat == xBanyakBenda_diBuat){
            for(auto i = dataResep.begin(); i != dataResep.end(); i++){
                dataInventory[i->first] -= jumlahBendaDiBuat * i->second;
            }
            cout << "Material Fulfilled, Crafting " << xBanyakBenda_diBuat << "!" << endl;
        } else {
            cout << "Insufficient Material, Can only craft " << jumlahBendaDiBuat << "." << endl;
        }
    }

    return 0;
}