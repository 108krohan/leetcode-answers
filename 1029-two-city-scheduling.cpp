/**
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

 

Note:

    1 <= costs.length <= 100
    It is guaranteed that costs.length is even.
    1 <= costs[i][0], costs[i][1] <= 1000

**/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] - lhs[1] < rhs[0] - rhs[1];
        };
        sort(costs.begin(), costs.end(), cmp);

        int n = costs.size();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n / 2) {
                total += costs[i][0];
            } else {
                total += costs[i][1];
            }
        }
        return total;
    }
};

/**
Notes for future readers:
For every person we have to select either city A or City B for sure.
But the case is we can only send half of the people to A and remaining to B. 
Example we have 100 people we have to send 50 to A and 50 to B. 
Once we sent 50 people to A we have no other option but to send remaining to B, 
and pay the price of B. 
So the 50 A we selected should be such that the price of B 
corresponding to those A should be as higher than A as possible
(ie, B-A should be as high as possible) so 
(Avoiding that B is most beneficial for us ). 
Hence we are taking difference.
**/
