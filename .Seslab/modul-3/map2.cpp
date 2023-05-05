#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;
    
    m.insert({1, 2});
    // secara langsung

    m.insert(make_pair(2, 3));
    // menggunakan fungsi make_pair

    m.insert(pair<int, int>(3, 4));
    // membuat object pair, sama seperti contoh sebelumnya

    m[4] = 5;
    // menggunakan indexing

    m[5]++;
    // increment

    for(auto i = m.begin(); i != m.end(); i++){
        cout << i->first << " " << i->second << endl;
    }

    return 0;
}