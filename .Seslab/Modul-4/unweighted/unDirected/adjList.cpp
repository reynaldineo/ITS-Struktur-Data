#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount; // vertex = panjang node, edge = panjang jalan
    vector<vector<long>> adjList; // V2dimensi, nampung graph Node polosan
    
    void init(long v){
        vertexCount = v; // inputan panjang
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }
    // fungsi add, dipanggil di main
    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2); // masukin data[a] ke b
        adjList[vertex2].push_back(vertex1); // masukin data[b] ke a
        edgeCount++; // ngitung jalannya
    }

    void dfs(vector<long> &result, long start){ // param(graph, startVertex)
        vector<bool> visited(vertexCount, false); // V.ngecek udh pernah di visit, param (panjangAwal, isiVector)
        stack<long> st; // bantuan untuk metode DFS

        st.push(start); // masukin startVertex ke stack agar bisa di proses 
        visited[start] = true; // startVertex sudah di visit
        result.push_back(start); // masukin ke result karena sudah di visited

        while(!st.empty()){ // selama stack belum kosong, isi awalnya = startVertex
            long temp = st.top(); // masukin top stack ke temp, agar nnti bisa di cari yg terhubung sama dia
            st.pop();  // hapus karena nnti mau di print, udh di salin di temp juga Jadi aman

            if(!visited[temp]){ // kalau belum pernah di visit
                result.push_back(temp); // print
                visited[temp] = true; // ubah jadi ush pernah di visit
            }
            // untuk setiap vertex dari graphAwal ADJ
            for(auto vertex:adjList[temp]){ // cnth: temp = 0, temennya 0 siapa? yg terhubung sama 0
                if (!visited[vertex]) // kalau belum pernah di kunjungi
                    st.push(vertex); // masukin ke stack
            }
        }
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                }
            }
        }
    }
};

int main(){
    graph g;
    g.init(5); // inisialisasi jumlah vertex / node
    g.add_edge(0, 1); // memasukan isi 
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(1, 4);

    vector<long> dfs_result, bfs_result; // nampung hasil jawaban, alias ngebuat graph
    g.dfs(dfs_result, 0); // param(graph, startVertex)

    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs_result, 0); // param(graph, startVertex)

    for(auto it:bfs_result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}