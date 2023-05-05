// C++ program to demonstrate the creation of descending
// order set container
#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{

	set<string, greater<string> > s1;
	// s1.insert("anjay");
	// s1.insert("badut");
	// s1.insert("rey");
	// s1.insert("cacing");

	// for (auto i : s1) {
	// 	cout << i << ' ';
	// }

    int nJumlah; cin >> nJumlah;
    printf("\n");
    while(nJumlah--){
        int perintah;
        string namaKartu;
        cin >> perintah >> namaKartu;

        if(perintah == 1){
            s1.insert(namaKartu);
        } else if(perintah == 2){
            s1.erase(namaKartu);
        } else if(perintah == 0){
            int xKartuTeratas = stoi(namaKartu);
            // for (auto i = 0; i < xKartuTeratas; i++){
            for(auto i = s1.begin(); i != s1.end(); i++){
                cout << *i << endl;
            }
            printf("---\n");
        }
    }
    
	return 0;
}
