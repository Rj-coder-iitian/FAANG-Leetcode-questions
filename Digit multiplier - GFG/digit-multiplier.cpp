//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long N) {
        string ans;
        for(int i=9;i>=2  && N>1;i--) {
            while(N%i == 0) {
                ans.push_back(i+48);
                N/=i;
            }
        }
        if(N != 1)
            return "-1";
        else if(ans.length() == 0)
            return "1";
            
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}
// } Driver Code Ends