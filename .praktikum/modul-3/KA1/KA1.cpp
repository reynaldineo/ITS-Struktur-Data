#include <bits/stdc++.h>
using namespace std;

int main(){
    set<string> data1;
    set<string> data2;

    int jumlahTestcase; cin >> jumlahTestcase;
    int kataKamus1 = 0, katakamus2 = 0;

    // while(jumlahTestcase--){
    for (int i = 0; i < jumlahTestcase; i++){
        string kata; 
        cin >> kata;

        auto pointer = data1.find(kata);

        if(pointer == data1.end()){ // kalau ga ketemu
            // cout << "data tidak ditemukan" << endl;
            // printf("%s masuk Kamus 1!\n", kata);
            cout << kata << " masuk Kamus 1!" << endl;
            data1.insert(kata);
            kataKamus1++;
        }
        else{ // kalau ketemu
            //  cek lagi di kamus 2 ada apa engga
            auto pointer2 = data2.find(kata);
            
            if(pointer2 == data2.end()){ // kalau ga ada
                // printf("%s masuk Kamus 2!\n", kata);
                cout << kata << " masuk Kamus 2!" << endl;
                data2.insert(kata);
                katakamus2++;
            } else { // kalau ada
                // printf("%s tidak bisa masuk Kamus!\n", kata);
                cout << kata << " tidak bisa masuk Kamus!" << endl;
            }
        }
    }
    printf("Kamus 1 berisi %d kata\n", kataKamus1);
    printf("Kamus 2 berisi %d kata\n", katakamus2);


}
