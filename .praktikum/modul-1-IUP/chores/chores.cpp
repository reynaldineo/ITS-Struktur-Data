#include <bits/stdc++.h>
using namespace std;

typedef struct isiData 
{
  int _prioritas; // init di struct
  string _taskName; // init di struct
} dataStruk;

struct priorityCompare // fungsi untuk membandingkan prioritas
{
  bool operator() (dataStruk const &p1, dataStruk const &p2)
  {
    return p1._prioritas > p2._prioritas;
  }
};

int main ()
{
  int energy, nChorus; // deklarasi
  cin >> energy >> nChorus; // first input
  priority_queue < dataStruk, vector<dataStruk>, priorityCompare> pqueue; // init priority queue-nya

  for (int i = 0; i < nChorus; i++) { // // input dan push semua data
    int prioritas;  // init di main
    string taskName;  // init di main
    cin >> prioritas >> taskName; // secondary input
    pqueue.push(dataStruk{prioritas, taskName}); // push data ke struct, data mengandung 2 jenis
  }
  int flag = 0; // untuk nandain apakah ada task yg di kerjain
  while (1) {
    // kalau energynya mudh ga cukup
    if (energy - pqueue.top()._prioritas < 0) break;
    else {
      flag = 1; // untuk nandain berarti ada task yg di kerjain
      energy -= pqueue.top()._prioritas; // untuk menghitung energnya, (energy - priotitas)
      cout << pqueue.top()._taskName << endl; // print taskNamenya
      pqueue.pop(); // pop/hapus datanya
    }
  }
  if (flag == 0) {// berarti ga ada task yg di kerjain
    cout << "Pak Aya will do the rest" << endl; // print sesuai yg di minta soal, kalau ga ada task yg di kerjakan
  }
}