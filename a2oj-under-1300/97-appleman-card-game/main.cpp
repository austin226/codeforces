#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

using namespace std;

// https://codeforces.com/problemset/problem/462/B
int main()
{
    // Speed up iostream since we don't use stdio
    std::ios::sync_with_stdio(false);

    // number of cards
    // 1 <= n <= 10^5
    int n_cards;
    cin >> n_cards;

    // number of selected cards
    // 1 <= k <= n <= 10^5
    int k_selected;
    cin >> k_selected;

    // n-length string of card letters
    // The i-th character of the string is the letter written on the i-th card
    string card_letters;
    cin >> card_letters;

    // Sort the string by letter
    sort(card_letters.begin(), card_letters.end());

    // Collect the frequencies of each letter
    vector<int> letter_frequencies;
    optional<char> prev_letter;
    int prev_letter_freq = 0;
    for (char curr_letter : card_letters)
    {
        if (!prev_letter.has_value() || prev_letter.value() != curr_letter)
        {
            // We've reached a new letter.
            if (prev_letter.has_value())
            {
                // Record the frequency of the previous letter and add it to the set.
                letter_frequencies.push_back(prev_letter_freq);
            }

            prev_letter.emplace(curr_letter);
            prev_letter_freq = 1;
        }
        else
        {
            // We're still on the same letter as before.
            prev_letter_freq++;
        }
    }
    // Count frequency for the last letter.
    letter_frequencies.push_back(prev_letter_freq);
    sort(letter_frequencies.begin(), letter_frequencies.end(), std::greater<>());

    // Calculate the maximum number of coins
    // 1 <= total_coins <= (10^5 * 10^5 = 10^10)
    uint64_t total_coins = 0;
    int cards_remaining = k_selected;
    for (int i = 0; i < k_selected && cards_remaining > 0; i++)
    {
        for (int freq : letter_frequencies)
        {
            // The number of cards of this letter that we can select
            uint64_t this_letter_selected = min(cards_remaining, freq);
            cards_remaining -= this_letter_selected;

            // Each card is worth [this_letter_selected] coins.
            total_coins += this_letter_selected * this_letter_selected;
        }
    }

    cout << total_coins << endl;
}
