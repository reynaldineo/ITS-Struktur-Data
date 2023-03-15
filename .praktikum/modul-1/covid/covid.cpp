#include <iostream>
#include <vector>
#include <string> // buat getline
#include <sstream> // buat stringstream

using namespace std;

int main () {
    string fullRumah, batasPager, fullVaksin;

    // ngambil data dalam satu line 
    getline(cin, fullRumah);
    getline(cin, batasPager);
    getline(cin, fullVaksin);

    // memisahkan setiap kata
    stringstream misahRumah(fullRumah); 
    stringstream misahVaksin(fullVaksin);

    vector<string> rumah;
    vector<string> vaksin;
    string tempRumah, tempVaksin;

    // melakukan operasi stringstream(>>) untuk memasukan setiap 1 rumah ke temp rumah yg akan di push
    while(misahRumah >> tempRumah) {
        rumah.push_back(tempRumah);
    }
    while(misahVaksin >> tempVaksin) {
        vaksin.push_back(tempVaksin);
    }

    vector<bool> dataSederhana; // dataSederhana

    for(int i = 0; i <rumah.size(); i++) {
        bool cekVaksin = false; // set awal belum vaksin

        for(int j = 0; j <vaksin.size(); j++) {
            // ngecek apakah rumah i sudah di vaksin, dengan ngebandingin tiap data vaksin
            if(rumah[i] == vaksin[j]) { 
                cekVaksin = true;
                dataSederhana.push_back(cekVaksin);
            }
        }

        if (cekVaksin == false) {
            dataSederhana.push_back(cekVaksin);
        }
    } // udh dapat data sederhana

    int streakTemp = 0, streakFull = 0;
    // perulangakan untuk mengecek menang/kalah memlalui streak
    for(int i = 0; i < dataSederhana.size(); i++) {
        // kalau rumahnya sudah di vaksin
        if(dataSederhana[i] == true) {
            streakTemp = 0; // reset streak
        } else { // kalau == false
            streakTemp++;
            streakFull = streakTemp;
        }
    }
    // kALAU mau menang streak maxnya harus sebanyak jumlah rumah yg ga di vaksin 
    // alias (jmlh rumah total - rumah yg udh di vaksin)
    if(streakFull == rumah.size() - vaksin.size()) {
        cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    } else {
        cout << "Gabisa sumpah, game ini red flag banget sih" << endl;
    }
    return 0;
}