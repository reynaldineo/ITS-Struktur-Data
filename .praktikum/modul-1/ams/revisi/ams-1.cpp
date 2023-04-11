#include <bits/stdc++.h>
using namespace std;

typedef struct isiData{
  int _id, _skor;
} dataStruk;

struct priorityCompare{
  bool operator() (dataStruk const &nilai1, dataStruk const &nilai2) {
    if(nilai1._skor == nilai2._skor)
      return nilai1._id < nilai2._id;
    else
      return nilai1._skor < nilai2._skor;
  }
};

int main(){
  vector<dataStruk> vec;

  int q; // jumlah data
  cin >> q ;

  while (q--) {
    priority_queue<dataStruk, vector<dataStruk>, priorityCompare> pqueue;
    int id, n, m, skor;
    cin >> id >> n >> m;
    skor = (n*500) + (m*-200);

    int flag = 0;
    for (int i = 0; i < vec.size(); i++)
    {
      if(vec[i]._id == id){
        vec[i]._skor+=skor;
        flag = 1;
        break;
      }
    }
    if(!flag)
      vec.push_back({id, skor});
    for(int i = 0; i < vec.size(); i++){
      pqueue.push(vec[i]);
    }


    cout << pqueue.top()._id <<" "<< pqueue.top()._skor << endl;
  }
  return 0;
}


// GIMANA NOTALIN KALAU IDNYA SAMA
// 