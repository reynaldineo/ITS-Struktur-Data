#include <bits/stdc++.h>
using namespace std;

struct dataStruk{
  int id, skor;
};

struct priorityCompare{
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
    return nilai1.skor < nilai2.skor;
  }
};

struct Compare {
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
    if (nilai1.id == nilai2.id) {
      return nilai1.skor < nilai2.skor;
    }
    return nilai1.id > nilai2.id;
  }
};

int main(){
  priority_queue<dataStruk, vector<dataStruk>, priorityCompare> pqueue;

  int q; // jumlah data
  cin >> q ;

  vector<dataStruk> data(q);

  for (int i = 0; i < q; i++) {
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200);

    data[i] = {id, skor};

    sort(data.begin(), data.end(), Compare());

     if (i > 0 && data[i].id == data[i-1].id) {
      data[i].skor += data[i-1].skor;
    }
    pqueue.push(data[i]);

    cout << pqueue.top().id << " " << pqueue.top().skor << endl;
  }
//   }

//   sort(data.begin(), data.end(), Compare());

//   for (int i = 0; i < q; i++) {
//     if (i > 0 && data[i].id == data[i-1].id) {
//       data[i].skor += data[i-1].skor;
//     }
//     pqueue.push(data[i]);

//     cout << pqueue.top().id << " " << pqueue.top().skor << endl;
//   }

  return 0;
}
