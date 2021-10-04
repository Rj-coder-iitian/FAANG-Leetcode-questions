bool isPrefixString(string s, vector<string>& words) {
        bool flag = true;
        int n = s.length();
        int dum = n;
        int i=0;
        for(auto w: words){
            if(dum < w.length()){
                flag = false;
                break;
            }else{
                dum -= w.length();
            }
            for(int j=0;j<w.length();){
                if(i>=n){
                    break;
                }
                if(s[i] != w[j]){
                    flag = false;
                    break;
                }else{
                    i++;
                    j++;
                }
            }
            if(i>=n){
                break;
            }
            if(flag == false)
                break;
        }
        if(dum > 0){
            flag = false;
        }
        return flag;
    }
