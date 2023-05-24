#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
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
            cout << "top: " << st.top() << endl;
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true; // 3
            }

            cout << "ini result: ";
            for(int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;

            cout << "cek adj: ";
            for(auto vertex:adjList[temp]){
                cout << vertex << " ";
                if (!visited[vertex])
                    st.push(vertex);
            }
            cout << endl;
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
            cout << "front: " << temp << endl;

            cout << ":cek adj:" << endl;
            for(auto vertex:adjList[temp]){
                cout << "vertexnya: " << vertex << endl;
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                    
                    cout << "ini result: ";
                    for(int i = 0; i < result.size(); i++) {
                        cout << result[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
};

int main(){
    graph g;
    g.init(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(1, 4);

    vector<long> dfs_result, bfs_result;
    g.dfs(dfs_result, 0);

    cout << "Hasil DFS: " << endl;
    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl << endl;

    g.bfs(bfs_result, 0);
    
    cout << "Hasil BFS: " << endl;
    for(auto it:bfs_result){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}