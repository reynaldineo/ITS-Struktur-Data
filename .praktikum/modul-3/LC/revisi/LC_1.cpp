#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
    map<string, int> dataAutoLooting;
    string kStringAutoLooting; 
    do{
        getline(cin, kStringAutoLooting);
        // cek di dataAutoLooting ada atau ga ada
        auto pointer = dataAutoLooting.find(kStringAutoLooting);
        int awal = 0;

        // kalau ga ada submit index 0
        if(pointer == dataAutoLooting.end()){
            dataAutoLooting.insert(make_pair(kStringAutoLooting, awal));
        } else {
        // kalau ada tambah index
            dataAutoLooting[kStringAutoLooting]++;
        }

        dataAutoLooting.insert(make_pair(kStringAutoLooting, awal));

    } while (kStringAutoLooting != "#");
    
    int nJumlahTotalBenda; cin >> nJumlahTotalBenda;

    while(nJumlahTotalBenda--){
        int xJumlahBenda_Nsekian;
        cin >> xJumlahBenda_Nsekian;

        int mJumlahBahanDiperlukan;
        cin >> mJumlahBahanDiperlukan;

        map<string, int> dataBahan_rakit;

        
        vector<string> namaBahan_diPerlukan;
        vector<int> jumlahBahan_diPerlukan;
        while(mJumlahBahanDiperlukan--){
            string namaBahan;
            cin >> namaBahan;
            int yJumlahBahan_untukNamaBahan;
            cin >> yJumlahBahan_untukNamaBahan;
            // masukin ke map baru yg nyimpen jumlah bahan sama namanya

            // dataBahan_rakit.insert(make_pair(namaBahan, yJumlahBahan_untukNamaBahan));
            namaBahan_diPerlukan.push_back(namaBahan);
            jumlahBahan_diPerlukan.push_back(yJumlahBahan_untukNamaBahan);

        }

        // Olah bahan sesuai resep, bisa / ga
        int jmlhBendaBerhasil_diBuat = 0;
        while(xJumlahBenda_Nsekian--){
            vector<int> indexAutoLooting_bahan;
            for (int i = 0; i < mJumlahBahanDiperlukan; i++){
                // cek bahan pertama
                auto pointer = dataAutoLooting.find(namaBahan_diPerlukan[i]);

                // kalau ga ada
                if(pointer == dataAutoLooting.end()){
                    break; // keluar dri for 
                } else {
                // kalau ada kurangin index
                    // dataAutoLooting[namaBahan_diPerlukan[i]]-= jumlahBahan_diPerlukan[i];
                    indexAutoLooting_bahan.push_back(i);
                    jmlhBendaBerhasil_diBuat++;
                }
            }
            
            if(xJumlahBenda_Nsekian == jmlhBendaBerhasil_diBuat) 
                cout << "Material Fulfilled, Crafting " << jmlhBendaBerhasil_diBuat << "!" << endl;
            else
                cout << "Insufficient Material, Can only craft " << jmlhBendaBerhasil_diBuat << "." << endl;
        }
    }
}