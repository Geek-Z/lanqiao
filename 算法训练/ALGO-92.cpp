/**
1 + 2 * 2 + 4;
+ + 1 2 * 2 2 4
+ + 1 2 4 4
**/
#include <bits/stdc++.h>
using namespace std;
int a, b;
stack<int> ints;
int cnt = 0;
char buf = ' ';
int calc(char ope) 
{
    switch (ope)
    {
        case '+':
            a = ints.top(); ints.pop();
            b = ints.top(); ints.pop();
            ints.push(a + b);
            break;
        case '-':
            a = ints.top(); ints.pop();
            b = ints.top(); ints.pop();
            ints.push(a - b);
            break;
        case '*':
            a = ints.top(); ints.pop();
            b = ints.top(); ints.pop();
            ints.push(a * b);
            break;
        case '/':
            a = ints.top(); ints.pop();
            b = ints.top(); ints.pop();
            ints.push(a / b);
            break;    
        default:
            break;
    }
}

char readChar(istringstream &is)
{
    char c;
    if(cnt > 0) c = buf, cnt = 0;
    else {
    	is >> c;
		if(is.eof()) c = EOF;
    };
    return c; 
}

int main()
{
#ifdef LOCAL
    freopen("ALGO-92.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    istringstream is(s), eof;
    char c;
    c = readChar(is);
    while(c != EOF) {
        //cout << c << endl;
        if(c == ' ') continue;
        if(isdigit(c) && c != '0')
            ints.push(c - '0');
        else if(c == '0') {
            char next = readChar(is);
            if(next == '1')
                ints.push(10);
            else 
                cnt = 1, buf = next, ints.push(0);
        } else calc(c);
    	c = readChar(is);
	}
    int ans = ints.top();
    cout << ans << endl;
    return 0;
}
