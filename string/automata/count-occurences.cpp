Add bool notClone; in node structure
Ax[cur].notClone=1; after line 20
Ax[clone].notClone=0; after line 26
Precall with this function (once)
long long d[_Z<<1];
inline void countAll(int root,int last){///last means max_id node in graph
    set< pair<int,int> > tmp;
    for(int i=root;i<=last;i++){//last means maximum node id  number. not ‘last’ varialble
        tmp.emplace(Ax[i].len,i);
        d[i]=Ax[i].notClone;
    }
    for(set<pair<int,int>>::reverse_iterator it=tmp.rbegin();it!=tmp.rend();it++)
        d[ Ax[it->second].link ]+=d[it->second];
    d[0]=0;      
}
d[search(root,b)]) will be the number of occurrences of string b;
