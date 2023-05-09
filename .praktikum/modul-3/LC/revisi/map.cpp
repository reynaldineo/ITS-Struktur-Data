#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> m;

    m.insert({2, 4});
    m.insert(make_pair(2, 3));
    m.insert(pair<int, int>(3, 4));
    m[9] = 5;
    m[5]++;
    m[5] += 10;

    auto pointer = m.find(2);
    /* 
    menggunakan fungsi find
    mengembalikan iterator yang menunjuk pada elemen map
    dengan nilai key = 1
    */
    if(pointer != m.end()){
        cout << pointer->first << " " << pointer->second << endl;
    }

    cout << m[9] << endl;
    /* 
    indexing, hanya menampilkan value pada elemen map
    dengan nilai key = 5
    */

    return 0;
}