#include <iostream>

using namespace std;

// https://codeforces.com/problemset/problem/272/A
int main()
{
    // Number of friends: 1..=100
    int n_friends;
    cin >> n_friends;

    // n_friends positive integers, not exceeding 5, representing how many fingers each friend will show
    // friend_fingers can range from 1..=500
    int friend_fingers = 0;
    for (int i = 0; i < n_friends; i++)
    {
        // Each friend holds up 1..=5 fingers.
        int friend_i_fingers;
        cin >> friend_i_fingers;
        friend_fingers += friend_i_fingers;
    }

    // Calculate how many ways to show some number of fingers on one hand (1 to 5) so Dima doesn't have to clean the place.
    // Find every x (1 <= x <= 5) such that
    // (x + friend_fingers) % (n_friends + 1) != 1
    int n_ways = 0;
    for (int x = 1; x <= 5; x++)
    {
        if ((x + friend_fingers) % (n_friends + 1) != 1)
        {
            n_ways++;
        }
    }

    cout << n_ways << endl;
}