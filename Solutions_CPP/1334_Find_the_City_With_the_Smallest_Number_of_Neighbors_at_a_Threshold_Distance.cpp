// 1334 : Find the City With the Smallest Number of Neighbors at a Threshold Distance

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
 

*/

/*
Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

 

*/

/*
Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.


*/

/*
This is just a simple problem of finding distance of noe node to all the other nodes in the graph.

- The addition is that after finding the distances, we need to filter out the ones less than or
equal to the threshold distance.
- For each node, we need to count the number of such distances.
- And return the one with the minimum number of such distances.
- In case of a tie, return the bigger city number.

- So, the problem is an all-pair shortest path problem, which can be solved using any of the
following:
    - Dijkstra's Algorithm
    - Bellman-Ford Algorithm
    - Floyd-Warshall Algorithm

Irrespective of the algorithm used, we have to perform the following steps:
    - Convert the given edges into adjacency matrix. (Read more about it after this comment)
    - Construct some sort of distance matrix to store distance from each node to every other node.
    - For each node, find the number of nodes that are reachable within the threshold distance.
    - Return the node with the minimum number of reachable nodes.
    - In case of a tie, return the node with the maximum number.

- Let's take example 1 to understand the adjacency matrix:
    - The given edges are [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
    - The adjacency matrix will look like:
        0    1    2    3
    0   -    3    -    -
    1   3    -    1    4
    2   -    1    -    1
    3   -    4    1    -

    - The distance matrix (Made using any algorithm) will look like:
        0    1    2    3
    0   -    3    4    5
    1   3    -    1    2
    2   4    1    -    1
    3   5    2    1    -

    - Now the fltered nodes within the threshold distance of 4 will be:
        0    1    2    3
    0   -    3    4    x
    1   3    -    1    2
    2   4    1    -    1
    3   x    2    1    -

    - For each city:
        - City 0 = City 1, City 2
        - City 1 = City 0, City 2, City 3
        - City 2 = City 0, City 1, City 3
        - City 3 = City 1, City 2

    - Solution = City 0 or City 3
    - Since, there is a tie, return the bigger city number, i.e. City 3
*/

// Let's use Dijkstra's Algorithm to solve this problem.
class Solution {
   public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        /*
        - Create an adjacency matrix with 'n' rows.
        - We don't know the number of columns (as there can be any number of cities from a node).
        - For example, City has 1 but City 1 has 3 cities connected to it.
        - We can have 'n' columns too but that will be a waste of space.
        - vectors are dynamic arrays, so instead of initializing the columns,
          we can just push elements and it will grow as needed.
        */
        vector<vector<pair<int, int>>> adjacencyMatrix(n);

        /*
        - Create a distance matrix with 'n' rows and 'n' columns.
        - Each element will be initialized to INT_MAX.

        - How to initialize a 2D matrix? :
            vector<vector<int>> matrix_name(num_of_rows, vector<int>(num_of_columns));
        - How to initialize a matrix with all elements to a specific value? :
            vector<int> matrix_name(num_of_elements, specific_value);
        - Combining both, we can initialize a 2D matrix with all elements to a specific value:
            vector<vector<int>> matrix_name(num_of_rows, vector<int>(num_of_columns,
        specific_value));

        - Note: * 2D matrix is noting but a vector of vectors.
                * i.e. Each element of the matrix is a vector.
                * So, we can doo all vector operations on each row of the matrix.
        */
        vector<vector<int>> distanceMatrix(n, vector<int>(n, INT_MAX));

        /*
        - All diagonal elements will be 0.
        - As the distance from a node to itself is 0.
        */
        for (int i = 0; i < n; i++) {
            distanceMatrix[i][i] = 0;
        }

        /*
        - Now we have to fill the adjacency matrix.
        - We are given with a matrix which contains [from, to, distance].
        - Adjacency matrix is of the form:
            * Each row represents 'from' city.
            * Each column represents 'to' city.
            * The value at [i][j] will be the distance between city i and city j.
        - So, for each element in the edges matrix, we retrieve the 'from', 'to' and 'distance'.
        - And fill the adjacency matrix accordingly.

        - Note: * We are given a bidirectional graph.
                * So, we have to fill the adjacency matrix for both 'from' and 'to' cities.
                * i.e. If there is edge b/w 0 & 1, we have 0->1 & also 1->0.
                * So, one entry is from=0, to=1, dist=3 and the other is from=1, to=0, dist=3.
                * Instead of chaning the variable to and from, we can swap the entires when adding
                  to the adjacency matrix.
        */
        for (auto &edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int dist = edge[2];

            adjacencyMatrix[from].emplace_back(to, dist);
            adjacencyMatrix[to].emplace_back(from, dist);
        }

        /*
        - Dijkstra Algorithm find distance from one node to all other nodes.
        - So, we have to run this algorithm for each node.

        - dijkstra() function will take the following arguments:
            * n = number of cities
            * adjacencyMatrix = adjacency matrix
            * distanceMatrix = distance matrix of the current city (Remember, each element of the 2D
        distanceMatrix is a vector, so we can pass it as a reference)
            * src = source city

        - Note: * We can also pass the entire distanceMatrix to the dijkstra() function.
                * But that is unnecessary as we are using only the src city at a time.
                * The other rows are not sed at all.
                * Passing a 1D array at the beginning also helps simplify the code inside the
                  dijkstra() function.

                * If you want to pass the entire distanceMatrix, you can do so by changing the
                  function signature to:
                    void dijkstra(int n, vector<vector<pair<int, int>>> &adjMatrix,
                                  vector<vector<int>> &distMatrix, int src)
                * Also inside the funstion, you have to change distMatrix[_] to distMatrix[src][_]
        */
        for (int i = 0; i < n; i++) {
            dijkstra(n, adjacencyMatrix, distanceMatrix[i], i);
        }

        /*
        - Now we have to find the city with the minimum number of cities reachable within the
          threshold distance.
        - Let's address it as 'filtered cities' from now on.
        - Initialize the result to -1 (It has to be any number less than the least city number).
        - Initialize the leastCount to n (As the maximum number of cities reachable can be n).
        - We can also initialize leastCount to INT_MAX (It's your choice).
        */
        int result = -1;     // This will be the final city number.
        int leastCount = n;  // This will be the minimum number of filtered cities.

        // For each from city
        for (int i = 0; i < n; i++) {
            // Initialize the current count of filtered cities to 0.
            int currCount = 0;

            // Iterate over the fistance matrix to find the number of filtered cities.
            for (int j = 0; j < n; j++) {
                // Skip the same city (as the distance will be 0 anyways).
                if (i == j) continue;

                // If the distance is less than or equal to the threshold distance, increase count
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    currCount++;
                }
            }

            // If number of filtered cities of current element is less than or equal to the least
            // count, update the result and least count.
            if (currCount <= leastCount) {
                leastCount = currCount;
                result = i;
            }
        }

        return result;
    }

    void dijkstra(int n, vector<vector<pair<int, int>>> &adjMatrix, vector<int> &distMatrix,
                  int src) {
        /*
        - template<
            class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
          > class priority_queue;

        - We need a priority queue to store the cities in the order of their distances.
        - The priority queue should be a min-heap i.e. the city with the minimum distance should be
          at the top.

        - To do that we have to follow the template of the priority queue:
            * First we need to specify the type of the elements in the queue.
            * In our case, the elements are pairs of integers (distance, to_city).

            * Then we have to specify the container in which the elements are stored.
            * In our case, we need a vector which will store the pairs.

            * Then we have to specify the comparison function.
            * By default, the priority queue is a max-heap i.e. it uses the less operator.
            * But that would make the city with the maximum distance at the top.
            * So, we have to use the greater operator to make it a min-heap.
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Push the source city to the priority queue.
        // Source city has a distance of 0 from itself.
        pq.emplace(0, src);

        // Set the distance (from source city) to source city as 0.
        distMatrix[src] = 0;

        while (!pq.empty()) {
            /*
            - Get the city with the minimum distance from the priority queue.
            - That city will be at the top of the priority queue.
            - Use top() to get the top element.
            - Use pop() to remove the top element.

            - As each element is a pair, to retrieve dist & city:
                * Use top().first to get the distance.
                * Use top().second to get the city.
            - Alternatively store pq.top() in a variable and use that variable to access the
            elements.
            */
            auto pqPair = pq.top();
            pq.pop();
            int currDist = pqPair.first;
            int currCity = pqPair.second;

            // If the distance of the current city is greater than the distance in the distance
            // matrix, skip the current city as we already have a shorter path.
            if (currDist > distMatrix[currCity]) continue;

            // If not, then we have to update the distances of the neighbours of the current city.
            for (auto &a : adjMatrix[currCity]) {
                // For each neighbour of the current city, get the neighbour and the distance.
                int neighbour = a.first;
                int dist = a.second;

                // Update the distance of the neighbour if the current distance + distance to the
                // neighbour is less than the distance in the distance matrix.

                // Also, push the neighbour to the priority queue.
                if (distMatrix[neighbour] > currDist + dist) {
                    distMatrix[neighbour] = currDist + dist;
                    pq.emplace(distMatrix[neighbour], neighbour);
                }
            }
        }
    }
};