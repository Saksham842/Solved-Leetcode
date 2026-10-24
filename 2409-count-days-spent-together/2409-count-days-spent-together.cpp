
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> sdays(12);

        sdays[0] = 0;
        for (int i = 1; i < 12; i++) {
            sdays[i] = sdays[i - 1] + days[i - 1];
        }

        int aa = stoi(arriveAlice.substr(0, 2));
        int la = stoi(leaveAlice.substr(0, 2));
        int ab = stoi(arriveBob.substr(0, 2));
        int lb = stoi(leaveBob.substr(0, 2));

        int aadays = sdays[aa - 1] + stoi(arriveAlice.substr(3, 2));
        int ladays = sdays[la - 1] + stoi(leaveAlice.substr(3, 2));
        int abdays = sdays[ab - 1] + stoi(arriveBob.substr(3, 2));
        int lbdays = sdays[lb - 1] + stoi(leaveBob.substr(3, 2));

        int l = max(aadays, abdays);
        int r = min(ladays, lbdays);

        return max(0, r - l + 1);
    }
};
