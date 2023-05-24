#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount; // vertex = panjang node, edge = panjang jalan
    vector<vector<long>> adjList; // V2dimensi, nampung 
    
    void init(long v){
        vertexCount = v; // inputan panjang
        edgeCount = 0; 

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }
    // fungsi add, dipanggil di main
    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex])
                    st.push(vertex);
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
    g.init(5); // inisialisai jumlah vertex
    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(0, 3);
    // g.add_edge(1, 3);
    // g.add_edge(1, 4);

    g.add_edge(7, 4);
    g.add_edge(4, 0);
    g.add_edge(6, 3);
    g.add_edge(2, 1);
    g.add_edge(2, 5);

    vector<long> dfs_result, bfs_result; // nampung jawaban alias ngebuat Graphnya
    g.dfs(dfs_result, 0); // param (graph, startvertex)

    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl;

    g.bfs(bfs_result, 0); // param (graph, startvertex)

    for(auto it:bfs_result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}