void primes_till_N(int N, vector<int> &arr)
    {
        // Declare the variables
        int i, j, flag;

        // Traverse each number from 1 to N
        // with the help of for loop
        for (i = 1; i <= N; i++) {

            // Skip 0 and 1 as they are
            // neither prime nor composite
            if (i == 1 || i == 0)
                continue;

            // flag variable to tell
            // if i is prime or not
            flag = 1;

            for (j = 2; j <= i / 2; ++j) {
                if (i % j == 0) {
                    flag = 0;
                    break;
                }
            }

            // flag = 1 means i is prime
            // and flag = 0 means i is not prime
            if (flag == 1)
                arr.push_back(i);
        }
    }
    
    bool isThree(int n) {
        vector<int> arr;
        primes_till_N(100,arr);
        bool flag = false;
        for(auto it : arr){
            if(n == it*it){
                flag = true;
                break;
            }
        }
        return flag;
    }
