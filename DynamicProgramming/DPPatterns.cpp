/*
    https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns#Minimum-(Maximum)-Path-to-Reach-a-Target
    1.Minimum (Maximum) Path to Reach a Target.
    Problem list: https://leetcode.com/list/55ac4kuc
    Generate problem statement for this pattern

    Statement
    Given a target find minimum (maximum) cost / path / sum to reach the target.

    Approach
    Choose minimum (maximum) path among all possible paths before the current state, then add value for the current state.

    routes[i] = min(routes[i-1], routes[i-2], ... , routes[i-k]) + cost[i]
*/

