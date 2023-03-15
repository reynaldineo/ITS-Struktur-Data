#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> myPair;

void olahData (priority_queue<myPair> &pqueue, int id, int n, int m) {
    priority_queue<myPair> temp;
    int skor = n*500 - m*200;
    bool flag = true; // untuk cek apakah idnya udh pernah di input

    while (!pqueue.empty()) { // selama blm kosong
        myPair dataPair = pqueue.top(); // salin data pqueue ke data
        pqueue.pop();

        if (dataPair.second != id) { // kalau id sama
            temp.push(dataPair);
            flag = true;
        } else { // kalau id sama, alias udh pernah input
            dataPair.first += skor; //totalin skor
            temp.push(dataPair);
            flag = false;
            break;
        }
    }
    
    if (flag) pqueue.push({skor, id});

    while (!temp.empty()) { // selama temp ga kosong
        pqueue.push(temp.top()); // push top temp ke pqueu
        temp.pop(); // // terus di hapus atasnya
    }
}

int main () {
    priority_queue<myPair> pqueue;
    int q;
    cin >> q;

    while (q--) {
        int id, n, m;
        cin >> id >> n >> m;
        olahData(pqueue, id, n, m);
        cout << pqueue.top().second << " " << pqueue.top().first << endl;
    }
    return 0;
}