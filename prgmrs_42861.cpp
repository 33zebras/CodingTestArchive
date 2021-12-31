#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int elemInChunk(vector<set<int>> &chnk, int a)
{
    for(int i = 0; i < chnk.size(); i++)
    {
        auto it = chnk[i].find(a);
        if(it != chnk[i].end())
            return i;
    }
    return -1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, edgCnt = 0;
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){return a[2] < b[2];});
    vector<set<int>> chunks;
    
    for(int idx = 0; edgCnt < n-1; idx++)
    {
        int aInChunk = elemInChunk(chunks, costs[idx][0]);
        int bInChunk = elemInChunk(chunks, costs[idx][1]);
        if(aInChunk == bInChunk)
        {
            if(aInChunk == -1)
                chunks.push_back(set<int>{costs[idx][0], costs[idx][1]});
            else continue;
        }
        else if(aInChunk != -1 && bInChunk != -1)
        {
            chunks[aInChunk].merge(chunks[bInChunk]);
            chunks.erase(chunks.begin() + bInChunk);
        }
        else
        {
            if(aInChunk == -1)
                chunks[bInChunk].insert(costs[idx][0]);
            else
                chunks[aInChunk].insert(costs[idx][1]);
        }
        if(idx != -1)
            answer += costs[idx][2];
        edgCnt++;
    }
    
    return answer;
}
