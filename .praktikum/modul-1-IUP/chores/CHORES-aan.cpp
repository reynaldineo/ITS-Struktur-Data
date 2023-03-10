#include <bits/stdc++.h>
using namespace std;

typedef struct mboh
{
    int dibutuhkan;
    string gawean;
} strukkk;

struct CompareHeight
{
    bool operator()(strukkk const &p1, strukkk const &p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.dibutuhkan > p2.dibutuhkan;
    }
};

// 1 2 3 || 3 2 1

int main()
{
    int e, n;
    cin >> e >> n;
    priority_queue <strukkk, vector<strukkk>, CompareHeight> pq_masbro;
    for (int i = 0; i < n; i++)
    {
        int butuh;
        string kerjaan;
        cin >> butuh >> kerjaan;
        pq_masbro.push(strukkk{butuh, kerjaan});
    }
    int flag = 0;
    while (1)
    {
        if (e - pq_masbro.top().dibutuhkan < 0)
        {
            break;
        }
        else
        {
            e -= pq_masbro.top().dibutuhkan;
            flag = 1;
            cout << pq_masbro.top().gawean << endl;
            pq_masbro.pop();
        }
    }
    if (flag == 0)
    {
        cout << "Pak Aya will do the rest" << endl;
    }
}