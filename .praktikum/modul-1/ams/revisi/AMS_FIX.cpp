#include <bits/stdc++.h>
using namespace std;

typedef struct isiData{
  int _id, _skor;
} dataStruk;

struct priorityCompare{
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
    if(nilai1._skor == nilai2._skor) // kalau skor sama
      return nilai1._id < nilai2._id; // ngambil id yg lebih besar
    else
      return nilai1._skor < nilai2._skor; // ngambil skor yg besar
  }
};

int main(){
  vector<dataStruk> vec;

  int q; // jumlah data
  cin >> q ;

  priority_queue<dataStruk, vector<dataStruk>, priorityCompare> pqueue; // gara2 pqueue di sini jadi datanya ke reset lagi
  while (q--) {
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200); // ngitung skor
    int flag = 0;

    for (int i = 0; i < vec.size(); i++) {
      if(vec[i]._id == id) { // ngecek apakah udh ada id yg udh pernah di input
        vec[i]._skor+=skor;
        flag = 1;
        break;
      }
    }

    if(!flag) // kalau blm masuk flag
      vec.push_back(dataStruk{id, skor}); // push ke vec dulu

    for(int i = 0; i < vec.size(); i++) {
      pqueue.push(vec[i]); // nginput ulang isi pquque
    }

    cout << pqueue.top()._id <<" "<< pqueue.top()._skor << endl; // ngebersihin isi si pquue
  }
  return 0;
}

/**
 * jadi vec untuk data perm
 * pqueue cuman untuk sementara, nnti di top habis jg
*/