#include <stack>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

char convert_bracket(char s)
{
    switch (s)
    {
    case '(': s = ')';
        break;
    case '{': s = '}';
        break;
    }
    return s;
}

bool is_balanced(string expression) {
    stack<char> bracketStack;
    for (char s : expression) {
        if (s == '(' || s == '{') {
            bracketStack.push(s);
        }
        else {
            if (bracketStack.size() > 0 && s == convert_bracket(bracketStack.top())) {
                bracketStack.pop();
            }
            else {
                return false;
            }
        }
    }
    if (bracketStack.size() == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    std::string line;
    std::ifstream in("Text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    bool answer = is_balanced(line);
    if (answer)
        cout << "YEP\n";
    else cout << "NOPE\n";
    return 0;
}