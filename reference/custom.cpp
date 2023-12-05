#include <string>

using namespace std;

void remove_leading(string input, const char char_to_remove)
{
    input.erase(0, min(input.find_first_not_of(char_to_remove), input.size() - 1));
}

void remove_trailing(string input, const char char_to_remove)
{
    input.erase(input.find_last_not_of(char_to_remove) + 1, string::npos);
}