// 2582 : Pass the Pillow

/*
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.

Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.
 

*/

/*
Example 1:

Input: n = 4, time = 5
Output: 2
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
After five seconds, the 2nd person is holding the pillow.

Example 2:

Input: n = 3, time = 2
Output: 3
Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
After two seconds, the 3rd person is holding the pillow.

 

*/

/*
Constraints:

2 <= n <= 1000
1 <= time <= 1000


*/

/*
=> This is a simple maths question
=> We just have to figure out whether we are in the forward part of the backward part of the passing

=> We have Total Time = (n-1) * Complete Time + Extra Time
=> If we are in the forward part of the passing, then our position will be (Extra Time + 1)
=> Else, it would be that much from the end of the line 
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int complete = time / (n-1);
        int extra = time % (n-1);

        return (complete % 2 == 0) ? (extra + 1) : (n - extra);
    }
};