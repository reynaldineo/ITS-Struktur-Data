#include <bits/stdc++.h>

using namespace std;

int main(){
    string rumah, vax, hashtag;

    getline(cin,rumah); // scan satu line
    getline(cin,hashtag);
    getline(cin,vax);

    stringstream pisah1(rumah); //memisahkan setiap kata
    stringstream pisah2(vax);

    vector<string> kata_rumah;
    vector<string> kata_vax;

    string temp1, temp2;

    while(pisah1 >> temp1){ // operasi >> meruapakan operasi stringstream untuk memasukan setiap kata ke temp
        kata_rumah.push_back(temp1);//memasukkan setiap kata yang sudah dipisah di stringstream
    }

    while(pisah2 >> temp2){ // operator >>, yang membaca satu kata dari stream dan menyimpannya di dalam variabel temp2.
        kata_vax.push_back(temp2);
    }


    vector<bool> stat; //penunjuk kondisi apakah vaksin atau belum, dianalogikan spt [true, false, false, false, true, true] jika menggunakan testcase
    int non_vaksin = 0;

    //cek kesamaan pada rumah yg divaksin dan tidak
    for(int i = 0; i < kata_rumah.size(); i++){
        bool vaksin = false; 

        for(int j = 0; j < kata_vax.size(); j++){ // nyocokin setiap vaxin ke rumah 1 per 1
            if(kata_vax[j] == kata_rumah[i]){ // ngecek ada yg sama ga vax sama rumah sesuai index
                vaksin = true;
                stat.push_back(vaksin); //push nilai true ketika ada kesamaan kata
                // break;
            }
        }

        if(vaksin == false){ // kalau ga di vaksin (pas nyocokin ga nemu)
            non_vaksin++; // nambah jumlah rumah yg ga di vaksin
            stat.push_back(vaksin); //push nilai false ketika tidak ada kesamaan
        }

    } // udh dapet pola true falsenya kalau aldi 1 0 0 1 nya

    int ws = 0, ws_max = 0;
    // streakTemp, streakFull

    for(int i = 0; i < stat.size(); i++){ // ngulang sesuai banyaknya
        if(stat[i] == true){ // kalau rumahnya di vaksin 
            ws = 0;
        }
        else{ // kalau rumahnya ga di vaksin
            ws++;
            ws_max = ws;
        }
    }

    // kALAU mau menang streak maxnya harus sebanyak jumlah rumah yg ga di vaksin alias (jmlh rumah - rmh yg udh di vaksin)
    if(ws_max == kata_rumah.size() - kata_vax.size()){
        cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    }
    // kalau ga sama kalah
    else{
        cout << "Gabisa sumpah, game ini red flag banget sih" << endl;
    }


}