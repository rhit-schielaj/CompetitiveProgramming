#include <bits/stdc++.h>
using namespace std;

void check_length(const string& str, int& min, int& max)
{
    string start;
    const int str_size = str.size();
    start.reserve(str_size);
    char current, next, next2, next3;
    for (int i = 0; i < str_size; i++)
    {
        current = str[i];
        if (i != str_size - 1)
        {
            next = str[i + 1];
            if (current == ':' && next == ')')
            {
                start += 'Z';
                ++i;
                continue;
            }
            else if (current == 'x' && next == 'D')
            {
                start += 'Z';
                ++i;
                continue;
            }
            if (i != str_size - 2)
            {
                next2 = str[i + 2];
                if (current == ':' && next == '-' && (next2 == ')' || next2 == '('))
                {
                    start += 'Z';
                    i += 2;
                    continue;
                }
                else if (current == ';' && next == '-' && next2 == ')')
                {
                    start += 'Z';
                    i += 2;
                    continue;
                }
                else if (current == '^' && (next == '_' || next == 'o') && next2 == '^')
                {
                    start += 'Z';
                    i += 2;
                    continue;
                }
                else if (current == '-' && next == '_' && next2 == '-')
                {
                    start += 'Z';
                    i += 2;
                    continue;
                }
                else if (current == '^' && next == '^' && next2 == ';')
                {
                    start += 'Z';
                    i += 2;
                    continue;
                }
            }
            if (i != str_size - 3)
            {
                next2 = str[i + 2];
                next3 = str[i + 3];
                if (current == '(' && next == '.' && next2 == '.' && next3 == ')')
                {
                    start += 'Z';
                    i += 3;
                    continue;
                }
            }
        }
        start += current;
    }
    int actual_size = start.size();
    if (min > actual_size) min = actual_size;
    if (max < actual_size) max = actual_size;
}

int main()
{
    const vector<char> potential = {':', ')', '-', '(', ';', 'x', 'D', '_', 'o', '.', '^', 'X'};
    std::string line;
    getline(cin, line);
    const std::string original = line;
    const int str_size = original.size();
    int min = 101, max = -1;
    unordered_set<char> visited; visited.reserve(100);
    for (int i = 0; i < str_size; ++i)
    {
        char current = original[i];
        if (visited.find(current) != visited.end())
        {
            continue;
        }
        else
        {
            visited.emplace(current);
            for (char rep : potential)
            {
                for (int j = 0; j < str_size; ++j)
                {
                    if (line[j] == current)
                    {
                        line[j] = rep;
                    }
                }
                check_length(line, min, max);
                line = original;
            }
        }
    }
    printf("%d %d\n", min, max);
    return 0;
}