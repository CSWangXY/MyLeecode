class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        vector<int> num;
        int score = 0;
        for(int i = 0;i<ops.size();i++)
        {
            int len = num.size();
            if(ops[i] == "+")
            {
                score = score +num[len-1]+num[len-2];
                num.push_back(num[len-1]+num[len-2]);
            }
            else if(ops[i] == "D")
            {
                score = score + num[len-1]*2;
                num.push_back(num[len-1]*2);
            }
            else if(ops[i] == "C")
            {
                score = score - num[len-1];
                num.pop_back();
            }
            else
            {
                int tt = stoi(ops[i]);
                score += tt;
                num.push_back(tt);
            }
        }
        return score;
    }
};