#include<iostream>
using namespace std;


class Score{
    public:
        Score(int s)
        {
            score = s;
        }

        char evaluate()
        {
            if(score>=90 && score <= 100)
            return 'A';
            else return 'B';
        }
    private:
        int score;
};


int main()
{
    int s;
    cin>>s;
    Score score(s);
    cout<< score.evaluate();
    cout<<1;
}