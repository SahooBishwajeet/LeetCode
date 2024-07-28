// 2045 : Second Minimum Time to Reach Destination

/*
A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.

Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.
Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.

 

*/

/*
Example 1:
        

Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
Explanation:
The figure on the left shows the given graph.
The blue path in the figure on the right is the minimum time path.
The time taken is:
- Start at 1, time elapsed=0
- 1 -> 4: 3 minutes, time elapsed=3
- 4 -> 5: 3 minutes, time elapsed=6
Hence the minimum time needed is 6 minutes.

The red path shows the path to get the second minimum time.
- Start at 1, time elapsed=0
- 1 -> 3: 3 minutes, time elapsed=3
- 3 -> 4: 3 minutes, time elapsed=6
- Wait at 4 for 4 minutes, time elapsed=10
- 4 -> 5: 3 minutes, time elapsed=13
Hence the second minimum time is 13 minutes.      

Example 2:


Input: n = 2, edges = [[1,2]], time = 3, change = 2
Output: 11
Explanation:
The minimum time path is 1 -> 2 with time = 3 minutes.
The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.
 

*/

/*
Constraints:

2 <= n <= 104
n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
There are no duplicate edges.
Each vertex can be reached directly or indirectly from every other vertex.
1 <= time, change <= 103


*/

/*
- Let's first understand what are they asking for.

- We have been given a bi-directional connected graph.
- Bidirectional => We can go from vertex u to vertex v and vice versa.
- Connected => Every vertex is connected to at least one other vertex.

# 1st Aspect:
- We have to move from 1st vertex to the nth vertex.
- Each edge has a time associated with it. But the time is same for all the edges.
- This fact will help us in future.

# 2nd Aspect:
- The main problem is the traffic signal.
- Let's say we have been given signal = 5, that means:
    - From 0 to 5 minutes, signal will be green and we can move.
    - From 5 to 10 minutes, signal will be red and we have to wait till 10th minute.
    - From 10 to 15 minutes, signal will be green and we can move.
    - From 15 to 20 minutes, signal will be red and we have to wait till 20th minute.
    - And so on.

# 3rd Aspect:
- We have to find the 2nd minimum time to reach the destination.
- That means, in cases we have to traverse the same path again and again.

- Let's take example 2 of the problem statement:
    - There are only 2 vertices and 1 edge.
    - If we don't allow to traverse the same path again, then there is only one paths
    - And we won't have any 2nd minimum time.

- But if we try to traverse the same path again, won't there be a problem in implementation?
- For example, let's say we want to use Breadth First Search (BFS) to find the minimum time.
- BFS stores the visited nodes in a queue.
- If we just keep on adding nodes in queue (as we allow multiple traversals),
  then the queue will keep on increasing and we might get stuck in an loop.
- To prevent this we use a technique called "Relaxation".
- In relaxation we set a limit while considering the condition in place
i.e. we will allow multiple traversals but upto a maximum limit. (Let's say 2 times)


- So the prblem boils down to doing the following:
    - Construct the adjacency matrix for the graph.
    - Check if green signal or red signal. (How to do that is explained below)
    - If green signal, then apply BFS (along with required relaxation)
    - If red signal, then wait till green signal comes.
    - And add the time we waited to the total time.
    - For every traversal made, add the time taken to the total time.

# How to find signal?
    - We have a variable which keeps count of total time
    - Let's say time taken for each edge is 3 minutes and signal is 5 minutes.

    $----------$__________$----------$__________$----------$__________$----------$
    0          5          10         15         20         25         30         35
    ...green........red.......green.......red.......green.......red.......green...

    - What pattern do we see?
    - Let's take the current time = 12 minutes.
    - How can we say it is in green signal or red signal?
    - If we divide current time by signal time, then we get the number of cycles completed, right?
    - In our case, 12/5 = 2.4 = 2 cycles completed.

    - Green ; 0th cycle, 2nd cycle, 4th cycle, 6th cycle, 8th cycle, ...
    - Red ; 1st cycle, 3rd cycle, 5th cycle, 7th cycle, 9th cycle, ...

    - If the cycle number is even, then it is green signal.
    - If the cycle number is odd, then it is red signal.

    - So, we can find the signal by checking if the cycle number is even or odd.
    - i.e. (current_time / signal_time) % 2 == 0 => Green Signal
      &    (current_time / signal_time) % 2 == 1 => Red Signal

# How to find the waiting time?
    - Let's say we are at 6th minute and we have to wait till the next signal.
    - We don't know when the next signal will come.

    - One way is to find the current cycle number and then find the next cycle number.
    - Then multiplying signal_time with next cycle number will give us the time when the next signal
will come.
    - Here, current cycle number = 6/5 = 1.2 = 1
    - => Next cycle number = 1 + 1 = 2
    - => Next signal time = next_cycle_number * signal_time = 2 * 5 = 10
    - => Waiting time = next_signal_time - current_time = 10 - 6 = 4 minutes

    - Another way is to use remainder.
    - If we find the remainder of current_time with signal_time, then we know by how much minutes we
are ahead of the previous signal.
    - In our case current_time % signal_time = 6 % 5 = 1 minute ahead of the previous signal.
    - so, waiting time would be signal time - how much ahead
    - i.e. waiting time = signal_time - (current_time % signal_time) = 5 - 1 = 4 minutes

    - We are free to use any of the above methods.
    - But the 2nd one is better as it doesn't involve division & multiplication.
*/

class Solution {
   public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
        // Initialize adjacency matrix of size n + 1
        // As we have discussed this many times, we don't care about columns
        vector<vector<int>> adjMat(n + 1);

        // Traverse the edges & add the edges to adjacency matrix
        // Bidirectional edges => a->b and b->a both are to be added
        for (auto &edge : edges) {
            adjMat[edge[0]].push_back(edge[1]);
            adjMat[edge[1]].push_back(edge[0]);
        }

        /*
        - Initialize queue for BFS
        - The queue will store pair of 2 integers:
            - 1st integer => node number
            - 2nd integer => frequency (1 or 2) i.e. how many times we visited the node
        */
        queue<pair<int, int>> q;

        /*
        - Two vectors to store minimum & 2nd minimum time to reach the node
        - d1 => minimum time
        - d2 => 2nd minimum time

        - We initialize both the vectors with a default value (let's say -1)
        - We can even use INT_MAX, but we have to handle the logic appropriately

        - This default value will be used to check wheter if the node is visited or not
        - If a node is not visited, then both minimum & 2nd minimum time will be -1
        - If a node is visited once, then minimum time will be some value & 2nd minimum will be -1
        - If a node is visited twice, then both minimum & 2nd minimum time will be some value
        */
        vector<int> d1(n + 1, -1), d2(n + 1, -1);

        /*
        - We start from node 1
        - So, we add node 1 to the queue along with frequency 1
        - i.e. we have visited node 1 once
        - Also we set the minimum time to reach node 1 as 0

        - Note: We have not visited the node 2nd time, so 2nd minimum time will not be touched
        */
        q.push({1, 1});
        d1[1] = 0;

        // Typical BFS loop, until the queue is empty
        while (!q.empty()) {
            // Extract the top/front element from the queue
            // And since we had a pair, extract those 2 values too
            // i.e. Node & Frequency (how many times we visited the node)
            auto qTop = q.front();
            q.pop();
            int node = qTop.first;
            int freq = qTop.second;

            // We now have to calculate the time taken to reach the node
            int timeTaken = 0;

            // If we have visited the node once, then time taken is stored in d1[node]
            // Else, it is stored in d2[node]
            if (freq == 1) {
                timeTaken = d1[node];
            } else {
                timeTaken = d2[node];
            }

            /*
            Note:
            The above can be optimized in a one-liner as follows:
                int timeTaken = (freq == 1) ? d1[node] : d2[node];
            */

            /*
            - We have to check if the signal is green or red
            - As discussed above, we can find that by checking if the cycle number is even or odd
            - If it is odd i.e. remainder = 1, then it is red signal
            - So, we to find the waiting time in that case

            - If it is even i.e. remainder = 0, then it is green signal
            - So, we have waiting time = 0 in that case

            - In both the cases we add the time taken to go to the next node
            */
            if ((timeTaken / change) % 2 == 1) {
                int waitingTime = change - (timeTaken % change);
                timeTaken += waitingTime + time;
            } else {
                timeTaken += time;
            }

            /*
            - Now, we have to traverse the neighbours of the current node

            - If we have not visited the neighbour even once, then d1[neighbour] will be -1
            - In that case, we set the minimum time to reach the neighbour as timeTaken
            - And add the neighbour to the queue with frequency 1

            - If we have visited the neighbour once, then d1[neighbour] will be some value
            - And d2[neighbour] will be -1
            - In that case, we set the 2nd minimum time to reach the neighbour as timeTaken
            - And add the neighbour to the queue with frequency 2

            - In this case, if we have reached the destination node, then we return the time taken
            - As this is the 2nd visit to the destination node, this must be the 2nd minimum time
            */
            for (auto &neighbour : adjMat[node]) {
                if (d1[neighbour] == -1) {
                    d1[neighbour] = timeTaken;
                    q.push({neighbour, 1});
                } else if (d2[neighbour] == -1 && d1[neighbour] != timeTaken) {
                    if (neighbour == n) return timeTaken;

                    d2[neighbour] = timeTaken;
                    q.push({neighbour, 2});
                }
            }
        }

        return 0;  // Nothing mentioned as such in the problem statement
                   // It is said that there is guaranteed to be a solution
                   // So default return is arbitrary (we can even return -1)
    }
};