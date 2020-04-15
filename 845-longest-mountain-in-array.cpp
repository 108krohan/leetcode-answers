Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

    B.length >= 3
    There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]

(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.

Note:

    0 <= A.length <= 10000
    0 <= A[i] <= 10000

Follow up:

    Can you solve it using only one pass?
    Can you solve it in O(1) space?


class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) {
            return 0;
        }
        int result = 0;
        for(int i = 1; i < A.size(); i++) {
            int current_elem = A.at(i);
            int prev_elem = A.at(i - 1);
            int min_elem_index = i - 1;
            if(current_elem > prev_elem) {
                // prev_elem is starting point, 
                // and min
                while(i < A.size() &&
                     A.at(i) > A.at(i - 1)) {
                    i += 1; 
                }
                bool isPlateau = false;
                if(A.at(i - 1) == A.at(i - 2)) {
                    isPlateau = true;
                    i -= 1;
                    continue;
                }
                bool goesDown = false;
                while(i < A.size() &&
                     A.at(i) < A.at(i - 1)) {
                    i += 1; 
                    goesDown = true;
                }
                int zeroes = 0;
                // [0,0,1,0,0,1,1,1,1,1]
                if(A.at(i - 1) == A.at(i - 2)) {
                    int c = i - 1;
                    while(A.at(c) == A.at(c - 1)) {
                        c -= 1;
                        zeroes += 1;
                    }
                }
                if(goesDown && !isPlateau) {
                    for(int j = min_elem_index;
                       j < i - zeroes; j++) {
                        cout << " " << A.at(j);
                    }
                    cout << endl;
                    result = max(result, 
                                i - min_elem_index
                                - zeroes);                    
                }
                i -= 1;
            }
        }
        return result;
    }
};
