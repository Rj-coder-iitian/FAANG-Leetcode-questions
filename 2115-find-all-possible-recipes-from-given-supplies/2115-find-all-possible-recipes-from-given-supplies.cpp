class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> sup;
        int n = recipes.size();
        for(auto s : supplies)
            sup.insert(s); // Store all supplies in unordered set.
        
        unordered_map<string, int> indegree;
        for(auto& x: recipes)
            indegree[x] = 0;
        
        for(int i = 0;i < ingredients.size(); i++) {
            for(int j=0;j<ingredients[i].size();j++){
                if(sup.find(ingredients[i][j]) == sup.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        
        // Kahn's algorithm Topological sorting
        queue<string> q;
        for(auto s: indegree){
            if(s.second == 0)
                q.push(s.first);
        }
        
        vector<string> ans;
        while(!q.empty()) {
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto& nbr : graph[tmp]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        return ans;
    }
};