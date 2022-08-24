class Solution {
public:
    // vector<int> parent;
    // int find(int x) {
    //     return x == parent[x] ? x : find(parent[x]);
    // }
    // void uni(int x, int y) {
    //     x = find(x);
    //     y = find(y);
    //     if(x != y) {
    //         parent[x] = y;
    //     }
    // }
    unordered_map<int, int> f;
    int find(int x) {
        if(!f.count(x)) f[x] = x;
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        f[x]  = y;
    }
    bool equationsPossible(vector<string>& equations) {
        // parent.resize(200,0);
        // for(int i=0;i<200;i++)
        //     parent[i] = i;
        int n = equations.size();
        for(int i=0;i<n;i++) {
            if(equations[i][1] == '=') {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                uni(x, y);
            }
        }
        for(int i=0;i<n;i++) {
            if(equations[i][1] == '!'){
                int x = find(equations[i][0] - 'a');
                int y = find(equations[i][3] - 'a');
                if(x == y)
                    return false;
            }
        }
        return true;
    }
};

// int uf[26];
//     bool equationsPossible(vector<string>& equations) {
//         for (int i = 0; i < 26; ++i) uf[i] = i;
//         for (string e : equations)
//             if (e[1] == '=')
//                 uf[find(e[0] - 'a')] = find(e[3] - 'a');
//         for (string e : equations)
//             if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
//                 return false;
//         return true;
//     }

//     int find(int x) {
//         if (x != uf[x]) uf[x] = find(uf[x]);
//         return uf[x];
//     }