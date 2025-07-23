class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // now we need to create a unordered map for storing the frequecies of the chararcters
        unordered_map<char, int> freq;
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i]]++;
        }
        priority_queue<int> pq;
        for (auto ele : freq)
        {
            pq.push(ele.second);
        }

        // after this we need to create a operations on it
        int time = 0;

        while (not pq.empty())
        {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++)
            {
                if (not pq.empty())
                {
                    int frequency = pq.top();
                    pq.pop();
                    if (frequency > 1)
                    {
                        temp.push_back(frequency - 1);
                    }
                }
                    time++;
                    if (pq.empty() and temp.empty())
                    {
                        return time;
                    }
                
            }
            for (int t : temp)
            {
                pq.push(t);
            }
        }
        return time;
    }
};