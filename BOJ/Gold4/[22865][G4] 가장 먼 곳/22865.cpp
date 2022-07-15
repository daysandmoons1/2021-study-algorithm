#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

int table[100001];
vector<vector<pair<int, int>>> graph;

void dijkstra(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    while(!q.empty())
    {
        int curDDang = q.front().first;
        int curDist = q.front().second; q.pop();

        for(int i=0; i<graph[curDDang].size(); i++)
        {
            int nextDDang = graph[curDDang][i].first;
            int nextDist = graph[curDDang][i].second;

            if(table[nextDDang] == 0 || table[nextDDang] > curDist + nextDist)
            {
                table[nextDDang] = curDist + nextDist;
                q.push({nextDDang, table[nextDDang]});
            }
        }
    }
}

int main()
{
    int N, M, A, B, C;
    cin >> N;

    memset(table, 0, sizeof(table));

    for(int i=0; i<=N; i++)
        graph.push_back(vector<pair<int, int>>());
    
    cin >> A >> B >> C;

    cin >> M;
    for(int i=0; i<M; i++)
    {
        int D, E, Len;
        cin >> D >> E >> Len;
        graph[D].push_back({E, Len});
        graph[E].push_back({D, Len});
    }

    dijkstra(A);
    dijkstra(B);
    dijkstra(C);

    int maxVal = 0;
    int maxIdx = 0;
    for(int i=1; i<=N; i++)
    {
        if(table[i] != 0 && maxVal < table[i] && i != A && i != B && i != C)
        {
            maxVal = table[i];
            maxIdx = i;
        }
    }

    cout << maxIdx;
}