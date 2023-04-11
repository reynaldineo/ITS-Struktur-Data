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

// struct Compare {
//   bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
//     return nilai1._id > nilai2._id;
//   }
// };

int main(){

  priority_queue<dataStruk, vector<dataStruk>, priorityCompare> pqueue;
  map<int, int> skorById;

  int q; // jumlah data
  cin >> q ;

  while (q--) {
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200);

    if (skorById.find(id) != skorById.end()) {
      skor += skorById[id];
    }

    pqueue.push(dataStruk{id, skor});
    skorById[id] = skor;
    // Kode skorById[id] = skor; digunakan untuk menyimpan nilai skor yang baru dihitung ke dalam map skorById. id digunakan sebagai kunci untuk mengakses nilai skor. Dalam hal ini, setiap kali input baru masuk, nilai skor akan diperbaharui pada kunci id yang sesuai, sehingga map skorById akan selalu menyimpan skor terbaru untuk setiap id.

    cout << pqueue.top()._id <<" "<< pqueue.top()._skor << endl;
  }
  return 0;
}

// Cara kerjanya adalah dengan menyimpan skor untuk setiap id yang pernah diinput menggunakan map skorById. Kemudian, ketika inputan selanjutnya memiliki id yang sama dengan yang sebelumnya, maka skor yang baru dihitung akan ditambahkan dengan skor yang sudah ada di map. Setelah itu, pasangan id dan skor yang baru akan dimasukkan ke dalam priority queue.