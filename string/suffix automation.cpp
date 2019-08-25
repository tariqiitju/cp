#define VAL(c)   ((c)-'a')//char mapping scheme
const int _Z=1e5+10;///maximum number chars
const int _Y=26;  //char set size
struct node{
    int len;
    int link;
    int e[_Y];
    node(){len=0,link=0;memset(e,0,sizeof e);}
    inline void clear(){len=link=0;memset(e,0,sizeof e);}
};
node Ax[_Z<<1];int AVL=1;///set AVL=1 at for each test case
inline int New(){
	Ax[AVL].clear();
	return AVL++;
}
inline int extend(int root,int last,int c){
    int cur = New();
    Ax[cur].len = Ax[last].len + 1;
    for(;last && !Ax[last].e[c];last = Ax[last].link)
        Ax[last].e[c] = cur;
    if(last){
        int p = last, q = Ax[last].e[c];
        if(Ax[p].len+1==Ax[q].len)Ax[cur].link=q;
        else
        {
            int clone=New();
            Ax[clone].len=Ax[p].len+1;
            Ax[clone].link=Ax[q].link;
            for(int j=0;j<_Y;j++)Ax[clone].e[j]=Ax[q].e[j];
            for(;p&&Ax[p].e[c]==q;p=Ax[p].link)Ax[p].e[c]=clone;
            Ax[cur].link=Ax[q].link=clone;
        }
    }else Ax[cur].link=root;
    return cur;
}
inline int create(char* s){
	int root=New();
	int last=root;
	for(int i=0;s[i];i++){
		last=extend(root,last,VAL(s[i]));
	}
	return root;
}
