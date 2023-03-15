#include <bits/stdc++.h>

using namespace std;

int main(){
    string rumah, vax, hashtag;

    getline(cin,rumah);
    getline(cin,hashtag);
    getline(cin,vax);

    stringstream pisah1(rumah); //memisahkan setiap kata
    stringstream pisah2(vax);

    vector<string> kata_rumah;
    vector<string> kata_vax;

    string temp1, temp2;

    while(pisah1 >> temp1){
        kata_rumah.push_back(temp1);//memasukkan setiap kata yang sudah dipisah di stringstream
    }

    while(pisah2 >> temp2){
        kata_vax.push_back(temp2);
    }


    vector<bool> stat; //penunjuk kondisi apakah vaksin atau belum, dianalogikan spt [true, false, false, false, true, true] jika menggunakan testcase
    int non_vaksin = 0;

    //cek kesamaan pada rumah yg divaksin dan tidak
    for(int i = 0; i < kata_rumah.size(); i++){
        bool vaksin = false;
        for(int j = 0; j < kata_vax.size(); j++){
            if(kata_vax[j] == kata_rumah[i]){
                vaksin = true;
                stat.push_back(vaksin); //push nilai true ketika ada kesamaan kata
            }
        }
        if(vaksin == false){
            non_vaksin++;
            stat.push_back(vaksin); //push nilai false ketika tidak ada kesamaan
        }

    }

    int ws = 0, ws_max = 0;
    

    for(int i = 0; i < stat.size(); i++){
        if(stat[i] == true){
            ws = 0;
        }
        else{
            ws++;
            ws_max = ws;
        }
    }

    if(ws_max == kata_rumah.size() - kata_vax.size()){
        cout << "Bisa menang ini mah, gas mainin aja masbro" << endl;
    }
    else{
        cout << "Gabisa sumpah, game ini red flag banget sih" << endl;
    }


}