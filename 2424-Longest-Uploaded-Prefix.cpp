class LUPrefix {
public:
    set<int> st;
    int size;
    LUPrefix(int n) {
        size = n;
        for(int i=1;i<=n;i++){
            st.insert(i);   
        }
    }
    
    void upload(int video) {
        if(st.find(video) != st.end())
            st.erase(video);
    }
    
    int longest() {
        if(st.size() == 0)
            return size;
        auto first (st. begin());
        int val = *first;
        return val-1;
    }
};
