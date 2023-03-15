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

  const int MAX_ID = 1000000; // asumsi id tidak melebihi 1 juta
  dataStruk skorById[MAX_ID+1]; // array untuk menyimpan skor berdasarkan id

  int q; // jumlah data
  cin >> q ;

  while (q--) {
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200);

    // cek apakah id sudah pernah diinput sebelumnya
    if (skorById[id]._id == id) {
      skor += skorById[id]._skor;
    }

    skorById[id] = dataStruk{id, skor}; // simpan skor berdasarkan id ke dalam array of struct

    pqueue.push(skorById[id]);

    cout << pqueue.top()._id <<" "<< pqueue.top()._skor << endl;
  }
  return 0;
}
