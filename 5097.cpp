#include <iostream>
#include <list>
#include <map>
using namespace std;

class Leaderboard {
private:
    list<pair<int, int>> score_list;
    static bool comp(const list<pair<int, int>>::iterator &first, const list<pair<int, int>>::iterator &second)
    {
        return first->first == second->first;
    }
public:
    Leaderboard() {
        
    }

    void addScore(int playerId, int score) {
        list<pair<int, int>>::iterator iter;
        iter = find(score_list.begin(), score_list.end(), comp);
        if (iter == score_list.end())
        {
            for (iter = score_list.begin(); iter != score_list.end(); iter++)
            {
                if (iter->second > score)
                {
                    --iter;
                    score_list.insert(iter,pair<int, int>(playerId, score));
                    break;
                }
            }
        }
        else
        {
            iter->second += score;
            list<pair<int, int>>::iterator iter2;
            for (iter2 = score_list.begin(); iter2 != score_list.end(); iter2++)
            {
                if (iter2->second > iter->second)
                {
                    --iter2;
                    score_list.insert(iter2, *iter);
                    score_list.erase(iter);
                    break;
                }
            }
        }
    }
    
    int top(int K) {
        int result = 0;
        int i;
        list<pair<int, int>>::iterator iter;
        for (i = 0, iter = score_list.begin(); i < K && iter != score_list.end(); i++, iter++)
        {
            result += iter->second;
        }

        return result;
    }
    
    void reset(int playerId) {
        list<pair<int, int>>::iterator iter;
        for (iter = score_list.begin(); iter != score_list.end(); iter++)
        {
            score_list.erase(iter);
        }
    }
};

int main()
{

    return 0;
}