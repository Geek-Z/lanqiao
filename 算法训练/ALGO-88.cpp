/**
5
bbaabaaaaabbbbbbbababaabaabaabbabababbbabbabbabbba
baabaa
**/
#include <bits/stdc++.h>
using namespace std;
int maxTime = 0;        /* 计算最多出现的次数, 用于第一次比较*/
string maxStr = "";
int nowCur = -1;
int cur = 0;            /* 指针, 给元素标记个顺序*/
struct Info
{
    int cnt;
    int length;
    int seq;
    Info() : cnt(0), length(0), seq(0) {}
};
map<string, Info> cnter;
int main()
{
    int L;
    string s;
    cin >> L;
    cin >> s;
    
    // 枚举子串的长度
    for(int len = L ; len <= s.size(); ++len)
    {
        // 枚举开始位置
        for(int b = 0; b <= s.size() - len; ++b)
        {
            int e = b + len;
            string t = string(s.begin() + b, s.begin() + e);
            if(cnter.find(t) == cnter.end())
            {
                cnter[t].seq = cur++;
                cnter[t].length = len;
            }
            cnter[t].cnt += 1;
            maxTime = max(maxTime, cnter[t].cnt);
        }
    }

    for(map<string, Info>::iterator b = cnter.begin(); b != cnter.end(); ++b)
    {
        string s = b->first;
        Info inf = b->second;
        if(maxTime == inf.cnt)
        {
            // 找到第一个出现次数最大的
            if(maxStr == "") maxStr = s, nowCur = inf.seq;
            else
            {
                // 出现次数相同, 保留长度最大的那个
                if(s.size() > maxStr.size())
                    maxStr = s, nowCur = inf.seq;
                else if(s.size() == maxStr.size())
                {
                    // 出现次数相同, 长度也相同, 则保留次序比较小的
                    if(inf.seq < nowCur)
                        maxStr = s, nowCur = inf.seq;
                }
            }
        }
    }
    cout << maxStr << endl;
    return 0;
}