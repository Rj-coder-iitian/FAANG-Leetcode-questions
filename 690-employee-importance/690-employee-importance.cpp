/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void getImportanceHelper(Employee* employee, int id, unordered_map<int, Employee*> mp, unordered_set<int>& vis, int& res) {
        vis.insert(id);
        res += employee->importance;
        for(auto sub: employee->subordinates) {
            if(vis.find(sub) == vis.end()){
                getImportanceHelper(mp[sub], sub, mp, vis, res);
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for(auto employee : employees){
            mp[employee->id] = employee;
        }
        unordered_set<int> vis;
        int res = 0;
        for(int i=0;i<employees.size();i++) {
            if(employees[i]->id == id){
                getImportanceHelper(employees[i], id, mp, vis, res);
            }
        }
        return res;
    }
};