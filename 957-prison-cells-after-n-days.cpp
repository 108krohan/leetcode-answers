


class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& c, int N) {
        vector<int> f_c, next_c(c.size(), 0);
            for (int cycle = 0; N-- > 0; c = next_c, ++cycle) {
                for (auto i = 1; i < c.size() - 1; ++i) 
                    next_c[i] = (c[i - 1] == c[i + 1]);
                if (cycle == 0) 
                    f_c = next_c;
                else if (next_c == f_c) 
                    N %= cycle;
        }
        return c;
        // below solution times out... for n at 1 million
        // int count = 1;
        // vector<int> cells_copy(8);
        // while(count <= N) {
        //     // cells.size() = 8
        //     for (int i = 1; i < 7; i++) {
        //         if (cells.at(i - 1) == cells.at(i + 1)) {
        //             cells_copy.at(i) = 1;
        //         }
        //         else {
        //             cells_copy.at(i) = 0;
        //         }
        //     }
        //     // cout << "Day " << count << ": ";
        //     // for(int cell : cells_copy) {
        //     //     cout << cell << " ";
        //     // }
        //     count += 1;
        //     cout << endl;
        //     cells_copy.at(0) = 0;
        //     cells_copy.at(7) = 0;
        //     cells = cells_copy;
        // }
        // return cells;
    }
};

/**
Note for future reader:

The idea here is that there are finite steps are which the movements repeat. 
We say so because there's only a constant number of prison cells. 
And that's 8, all the time. 
The first and the last if they are 1 initially, become 0 in next go. 
So after 1st iteration we assign whatever has happened as the cycle's first state.
We increment count from then on to track the length of this cycle.
And so it happens that when the ongoing vector matches the initial result
there's a cycle
and so we take so and take a mod with N
to save some time
**/
