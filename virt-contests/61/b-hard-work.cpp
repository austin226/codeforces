// https://codeforces.com/contest/61/problem/B

#include <cctype>
#include <iostream>
#include <memory>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

const char sign0 = '-';
const char sign1 = ';';
const char sign2 = '_';

string normalize(string str)
{
    stringstream ss;
    for (char c : str)
    {
        if (!(c == sign0 || c == sign1 || c == sign2))
        {
            ss << char(tolower(c));
        }
    }
    return ss.str();
}

int main()
{
    // each str is len <= 100
    // each answer is len <= 600
    // case insensitive
    // order doesn't matter
    // ignore any sign characters
    // output WA for wrong, ACC for correct
    // no string input or answer is empty

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // TODO correct answer
    set<string> correct_answers;
    correct_answers.insert(normalize(s1) + normalize(s2) + normalize(s3));
    correct_answers.insert(normalize(s1) + normalize(s3) + normalize(s2));
    correct_answers.insert(normalize(s2) + normalize(s1) + normalize(s3));
    correct_answers.insert(normalize(s2) + normalize(s3) + normalize(s1));
    correct_answers.insert(normalize(s3) + normalize(s2) + normalize(s1));
    correct_answers.insert(normalize(s3) + normalize(s1) + normalize(s2));

    // n students 0..=1000
    int n_students;
    cin >> n_students;

    vector<string> output;

    // each student submits an answer. check if it's correct.
    for (int i = 0; i < n_students; i++)
    {
        string answer;
        cin >> answer;

        bool is_correct = correct_answers.find(normalize(answer)) != correct_answers.end();
        if (is_correct)
        {
            output.push_back("ACC");
        }
        else
        {
            output.push_back("WA");
        }
    }

    for (string s : output)
    {
        cout << s << endl;
    }
}
