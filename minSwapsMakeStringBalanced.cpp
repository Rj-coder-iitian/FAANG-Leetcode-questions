int minSwaps(string s) {
        int occur = 0, n = s.length();
        int diff = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '[')
                occur++;
            else{
                if(occur == 0){
                    diff++;
                }else{
                    occur--;
                }
            }
        }
        if(diff<2)
            return diff;
        else
            return diff - diff/2;
    }
