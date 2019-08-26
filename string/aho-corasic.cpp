#include <bits/stdc++.h>
using namespace std;
///aho corasic
#define VAL(c)  ((c)-'a')  //character mapping scheem
const int _Z=3e5+5;//maximum number of node
const int _Y=26;//size of character set
struct node
{
    int link,edge[_Y];
    node(){link=0;memset(edge,0,sizeof edge);}
    void clear(){link=0;memset(edge,0,sizeof edge);}

};
node _[_Z];int AVL=1;//start avl from 1;
inline int insert(int u, char *s)
{
    for(int i=0;s[i];i++)
    {
        if(!_[u].edge[VAL(s[i])])
        {
            _[AVL].clear();
            _[u].edge[VAL(s[i])]=AVL++;
        }
        u=_[u].edge[VAL(s[i])];
    }
    return u;
}
inline void constructSuffixLink(int root)
{
    //process root
    queue<int>q;
    for(int c=0;c<_Y;c++)
    {
        if(!_[root].edge[c])_[root].edge[c]=root;
        else 
        {
            _[_[root].edge[c]].link=root;
            q.push(_[root].edge[c]);
        }
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int c=0;c<_Y;c++)
        {
            int v=_[u].edge[c];
            if(v)
            {
                int t=_[u].link;
                while(!_[t].edge[c])t=_[t].link;
                _[v].link=_[t].edge[c];
                q.push(v);
            }
        }
    }
}
