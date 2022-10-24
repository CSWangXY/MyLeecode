class Solution {
public:
    unordered_map<string, vector<int>> m;
    vector<int> diffWaysToCompute(string expression) 
    {
        if(m.find(expression) != m.end())
        return m[expression];

        if(expression.find_first_of("+*-")==expression.npos)
        return {stoi(expression)};
        vector<int> ans;
        int pos = 0;
        while((pos = expression.find_first_of("+-*", pos+1))!= expression.npos)
        {
            //cout<<pos;
            vector<int> left = diffWaysToCompute(expression.substr(0,pos));
            vector<int> right = diffWaysToCompute(expression.substr(pos+1));

            for(auto l:left)
            {
                for(auto r:right)
                {
                    if(expression[pos] == '+')
                    ans.push_back(l+r);
                    else if(expression[pos] == '-')
                    ans.push_back(l-r);
                    else
                    ans.push_back(l*r);
                }
            }
        }
        m[expression] = ans;
        return m[expression];
    }
};