class Solution {
public:
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string Am1 = arriveAlice.substr(0,2);
        string Ad1 = arriveAlice.substr(3,2);
        string Am2 = leaveAlice.substr(0,2);
        string Ad2 = leaveAlice.substr(3,2);
        string Bm1 = arriveBob.substr(0,2);
        string Bd1 = arriveBob.substr(3,2);
        string Bm2 = leaveBob.substr(0,2);
        string Bd2 = leaveBob.substr(3,2);
        int iam1 = stoi(Am1);
        int iad1 = stoi(Ad1);
        int iam2 = stoi(Am2);
        int iad2 = stoi(Ad2);
        int ibm1 = stoi(Bm1);
        int ibd1 = stoi(Bd1);
        int ibm2 = stoi(Bm2);
        int ibd2 = stoi(Bd2);
        int days = 0, i;
        int mxAM = max(iam1, ibm1);
        int mnLM = min(iam2, ibm2);
        if(mxAM > mnLM)
            return 0;
        int sa = 0, sb = 0, la = 0, lb = 0;
        for(i=1;i<iam1;i++){
            sa += months[i-1];
        }
        sa += iad1;
        for(i=1;i<ibm1;i++){
            sb += months[i-1];
        }
        sb += ibd1;
        for(i=1;i<iam2;i++){
            la += months[i-1];
        }
        la += iad2;
        for(i=1;i<ibm2;i++){
            lb += months[i-1];
        }
        lb += ibd2;
        int start = max(sa, sb);
        int end = min(la, lb);
        if(start > end)
            return 0;
        return end - start + 1;
    }
};
