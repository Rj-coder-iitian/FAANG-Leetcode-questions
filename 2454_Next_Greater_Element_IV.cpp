vector<int> secondGreaterElement(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, -1), s1, s2, tmp;
        for (int i = 0 ;i < n; ++i) {
            while (!s2.empty() && A[s2.back()] < A[i])
                res[s2.back()] = A[i], s2.pop_back();
            while (!s1.empty() && A[s1.back()] < A[i])
                tmp.push_back(s1.back()), s1.pop_back();
            while (!tmp.empty())
                s2.push_back(tmp.back()), tmp.pop_back();
            s1.push_back(i);
        }
        return res;
    }
