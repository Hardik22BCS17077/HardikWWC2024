class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> visited(n, 0); unordered_map<int, vector<int>> map;

        for (int i = 0; i < trust.size(); i++) {
            map[trust[i][1]].push_back(trust[i][0]);
            if (visited[trust[i][0] - 1] == 0) {
                visited[trust[i][0] - 1] = 1;
            }
        }

        int judge = -1; int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {
                judge = i + 1;
                count++;
            }
        }

        if (judge == -1 || count > 1) return -1;
        else {
            for (auto itr : map) {
                if (itr.first == judge) {
                    if (itr.second.size() == n - 1) return judge;
                    else return -1;
                }
            }
       }
        
        return n;
    }
};
