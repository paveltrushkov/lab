#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    queue<char> q;
    stack<char> s;
    char letter;
    int mismatches = 0;


    cout << "Enter a word:" << endl;
    cin >> letter;
    q.push(letter);
    s.push(letter);

    int i = 0;
    while (cin.peek() != '\n')
    {
        cin >> letter;
        if (isalpha(letter))
        {
            q.push(letter);
            s.push(letter);
        }
        i++;
    }

    while ((!q.empty()) && (!s.empty()))
    {
        if (q.front() != s.top())
            ++mismatches;

        q.pop();
        s.pop();
    }

    if (mismatches == 0)
    {
        cout << "This is a palindrome" << endl;
    }
    else
    {
        cout << "This is not a palindrome" << endl;
    }
    system("pause");
    return 0;
}
