#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> myPair;

void olahData (priority_queue<myPair> &pqueue, int id, int n, int m){
    priority_queue<myPair> temp;
    int skor = n*500 + m*(-200);
    bool flag = false;

    while (!pqueue.empty()) { // selama blm kosong
        myPair dataPair = pqueue.top(); // salin data pqueue ke data
        pqueue.pop();

        if (dataPair.first != id) { // kalau id sama
            // dataPair.second += skor; //totalin skor
            // temp.push(dataPair);
            // flag = true;
            // break;
            temp.push(dataPair);
            flag = false;
        } else { // kalau idnya ga sama
            // temp.push(dataPair);
            // flag = false;
            dataPair.second += skor; //totalin skor
            temp.push(dataPair);
            flag = true;
            break;
        }

        // if (dataPair.second != id) { // kalau id sama
        //     temp.push(dataPair);
        //     flag = false;
        // } else {
        //     dataPair.first += skor; //totalin skor
        //     temp.push(dataPair);
        //     flag = true;
        //     break;
        // }
    }
    
    if (!flag) pqueue.push({id, skor});

    while (!temp.empty()) { // selama tmp ga kosong
        pqueue.push(temp.top()); // push top tmp ke pqueu
        temp.pop(); // // terus di hapus atasnya
    }
}

int main () {
    priority_queue<myPair> pqueue;
    int q;
    cin >> q;

    while (q--) {
        int id, n, m, skor;
        cin >> id >> n >> m;
        olahData(pqueue, id, n, m);
        cout << pqueue.top().first << " " << pqueue.top().second << endl;
    }
    return 0;
}