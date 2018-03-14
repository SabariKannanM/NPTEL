/*
Given a pair of positive numbers, a and b, the task is to repeatedly subtract the smaller of the two number from the greater one until one of the numbers becomes zero.
Write a C++ program to count the number of steps before one of the numbers becomes zero.

Input:
Integer a and b separated by space

Output:
Output the answer

Example:
Input:
5 8

Output:
5

Explanation:
(5,8)->(5,3)->(2,3)->(2,1)->(1,1)->(0,1)

Constraints:
1 <= a, b <= 1000
*/
// C++ program to count of steps until one
// of the two numbers become 0.
#include<bits/stdc++.h>
using namespace std;
 
// Returns count of steps before one
// of the numbers become 0 after repeated
// subtractions.
int countSteps(int x, int y)
{
    // If y divides x, then simply return
    // x/y.
    if (x%y == 0)
        return x/y;
 
    // Else recur. Note that this function
    // works even if x is smaller than y because
    // in that case first recursive call exchanges
    // roles of x and y.
    return x/y + countSteps(y, x%y);
}
 
// Driver code
int main()
{
   int x,y;
  cin >> x >> y;
   cout << countSteps(x, y);
   return 0;
}
