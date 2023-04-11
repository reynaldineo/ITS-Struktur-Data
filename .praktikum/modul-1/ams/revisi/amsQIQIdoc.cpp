#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Player;

// Fungsi untuk menambahkan skor pemain ke dalam priority queue
void tambah_skor(priority_queue<Player>& pqueue, ll id, ll n, ll m) {
    priority_queue<Player> tmp;

    bool kosong = true; //flag

    ll score = n * 500LL - 200LL * m; // ngitung skor

    while (!pqueue.empty()) { // selama blm kosong
        Player playerData = pqueue.top(); // salin data pqueue ke playerData
        pqueue.pop(); // hapus data yg udh disalin, biar nnti bisa salin lagi (semua data)
        
        if (playerData.second != id) { // kalau idnya ga sama
            tmp.push(playerData); //push 
            kosong = true; // tetap biar di push ke stack utama lagi pqueue
        } 
        // kalau id sama
        else { 
            playerData.first += score; // totalin score
            tmp.push(playerData);
            kosong = false; // biar ga ngepush ke data utama pqueue 
            break;
        }
    }

    // jalanin sekali doang
    if (kosong) { // kalau kosong (alias ga pernah id sama)
        pqueue.push({score, id}); // push semua data ke pqueue
    }

    // ngehabisin tmp
    while (!tmp.empty()) { // selama tmp ga kosong
        pqueue.push(tmp.top()); // push top tmp ke pqueu
        tmp.pop(); // terus di hapus atasnya
    }
}

int main() {
    priority_queue<Player> pqueue;
    ll q, id, n, m;
    cin >> q;

    // for (int i = 0; i < q; i++) {
    while (q--) {
        cin >> id >> n >> m;
        tambah_skor(pqueue, id, n, m);
        cout << pqueue.top().second << " " << pqueue.top().first << "\n";
    }

    return 0;
}