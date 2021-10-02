class Solution {
public:
int reverse(int x) {
   
 int sign;
 long long int res=0;
    
    sign=x>0?1:-1;
    
  string s=to_string(x);
    
    
    
    std::reverse(s.begin(),s.end());
    
    for(auto ell:s)
    {
        if(ell=='-') continue;
        
        res=res*10+(int)(ell-'0');
        
        if(res>INT32_MAX) return 0;
        
        if(sign*res<INT32_MIN) return 0; 
        

    }
    
    
    return res*sign ;
    
}
};
