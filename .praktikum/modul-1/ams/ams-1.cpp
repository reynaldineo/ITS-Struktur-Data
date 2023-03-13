#include <bits/stdc++.h>
using namespace std;

typedef struct isiData{
  int _id, _skor;
} dataStruk;

struct priorityCompare{
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
    return nilai1._skor < nilai2._skor;
  }
};

// int cekID (dataStruk const &nilai1, dataStruk & const nilai2) {
//   if (nilai1._id == nilai2._id) {
//     return nilai1._skor + nilai2._skor
//   }
  
// };

struct Compare {
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {

    if (nilai1._id == nilai2._id) {
            return nilai1._skor < nilai2._skor;
        }
        return nilai1._id > nilai1._id;
  }
};




int main(){

  priority_queue<dataStruk, vector<dataStruk>, priorityCompare> pqueue;

  int q; // jumlah data
  cin >> q ;

  while (q--) {
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200);


    pqueue.push(dataStruk{id, skor});


    cout << pqueue.top()._id <<" "<< pqueue.top()._skor << endl;
  }
  return 0;
}


// GIMANA NOTALIN KALAU IDNYA SAMA
// 