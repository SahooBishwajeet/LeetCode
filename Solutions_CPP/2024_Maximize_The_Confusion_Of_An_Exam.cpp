// 2024. Maximize the Confusion of an Exam
/* A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. 
He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, 
the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
*/

/*
Example 1:
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:
Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

Example 3:
Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.

Constraints:
1. n == answerKey.length
2. 1 <= n <= 5 * 104
3. answerKey[i] is either 'T' or 'F'
4. 1 <= k <= n

/*
=> We will use Sliding window to solve the problem. In that we are going to maintain 2 pointers to determine the size of the Window
=> We will use a Map to store frequency of 'T' and 'F' in current window. 
=> We also need a variable to store Max Frequency b/w 'T' and 'F'. We will update it in each iteration if necessary.

=> In any case our window length should be less than or equal to Max Frequency + k. If not then we will move left pointer to adjuct the size of window.
=> In the end, our left pointer will be pointing to the beginning of required substring. So, length of required substring = Array Length - Left Pointer Index.
*/
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxFreq = 0;
        int i = 0, j = 0, len = answerKey.length();

        unordered_map<char, int> charCount;

        while(j < len){
            char currentChar = answerKey[j];
            charCount[currentChar]++;
            maxFreq = max(maxFreq, charCount[currentChar]);

            if(j - i + 1 > maxFreq + k){
                charCount[answerKey[i]]--;
                i++;
            }
            j++;
        }

        return len - i;
    }
};
