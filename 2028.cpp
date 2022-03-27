class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        vector<int> result;
        int rollssum = 0;
        for(int i=0;i<rolls.size();i++)
        {
            rollssum += rolls[i];
        }
        int unknownsum = mean*(n+rolls.size())-rollssum;
        if(unknownsum<n || unknownsum >6*n)
        return {};
        else
        {
        int qq=unknownsum/n;
        int lleft = unknownsum%n;
        for(int i=1;i<=lleft ;i++)
        {
            result.push_back(qq+1);
        }
        for(int i=1;i<=n-lleft;i++)
        {
            result.push_back(qq);
        }
        }
        return result;
    }
};