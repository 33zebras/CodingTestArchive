#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    for(int i = 0; i < routes.size(); i++)
    {
        int outAt = routes[i][1];
        int offset = 0;
        for(int j = i+1; j < routes.size(); j++)
        {
            outAt = routes[j][1] < outAt ? routes[j][1] : outAt;
            if(routes[j][0] <= outAt)
                offset++;
        }
        i += offset;
        answer++;
    }
    return answer;
}
