#include <iostream>
#include <map>
using namespace std;
#define ull unsigned long long int

ull catalan(ull angka){
    map<ull, ull> data;
    data[0] = data[1] = 1;

    for(ull i = 2; i <= angka; i++){
        data[i] = 0;
        for(int j = 0; j < i; j++){
            data[i] += data[j] * data[i - j -1];
        }
    }
    return data[angka];
}

int main(){
    int tJumlahTestCase;
    cin >> tJumlahTestCase;

    while(tJumlahTestCase--){
        ull nJumlahGunung;
        cin >> nJumlahGunung;
        ull hasil = catalan(nJumlahGunung);
        cout << hasil << endl;
    }
    return 0;
}