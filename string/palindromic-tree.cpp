#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 5;
const int _Y = 26;
#define VAL(c)  ((c)-'a')
struct node{
    int len,link,e[_Y];ll cnt=0;
    node(){cnt=len=link=0;memset(e,0,sizeof(e));}
    inline void clear(){cnt=len=link=0;memset(e,0,sizeof(e));}
}ALL[MX];
int avl = 1;                        //Each test case
inline int New(){
    ALL[avl].clear();
    return avl++;
}
struct palindromicTree{
    int rootEven,rootOdd;
    string s;
    palindromicTree(){rootEven=rootOdd=0;s="";}
    palindromicTree(string _s){
        s = _s;
        rootOdd = New();
        ALL[rootOdd].len = - 1;
        ALL[rootOdd].link = rootOdd;
        rootEven = New();
        ALL[rootEven].len = 0;
        ALL[rootEven].link = rootOdd;
        int last = rootEven;
        for(int i=0;s[i];i++){
            while(s[i - ALL[last].len - 1] != s[i])last = ALL[last].link;
            int x = ALL[last].link ,c = VAL(s[i]);
            while(s[i - ALL[x].len - 1] != s[i])x = ALL[x].link;
            if(!ALL[last].e[c]){
                int cur = New();
                ALL[last].e[c] = cur;
                ALL[cur].len = ALL[last].len + 2;
                ALL[cur].link = ALL[cur].len == 1 ? rootEven : ALL[x].e[c];
            }
            ALL[ALL[last].e[c]].cnt++;
            last = ALL[last].e[c];
        }
    }
};
