//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long cnt= 0; 
        int i = 0; 
        int j = 0; 
        int wind=0;     
        while(j<n){
            if(a[j]>R){
                wind = 0; 
                i = j+1; 
            }
            else if(a[j]>=L && a[j]<=R){
                wind = j- i+1;
            }
            cnt+=wind ;
            j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends