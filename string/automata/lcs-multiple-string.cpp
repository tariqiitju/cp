//To find the actual substring just keep track which l is optimal (last line in the loop).
int lcs(vector<string> t){
    int n=t.size();
    vector<int> roots(n-1),b(n-1);
    for(int i=0;i<n-1;i++)
        b[i]=roots[i]=create(t[i]);
    int l=0,mx=0;
    for(int i=0;t[n-1][i];i++){
        int c=VAL(t[n-1][i]);
        bool cond=1;
        for(int d=0;cond && d<n-1; cond=cond&&(Ax[b[d]].e[c]),d++);
        if(cond){
            for(int d=0;d<n-1;d++)b[d]=Ax[b[d]].e[c];
            l++;
        }else{
            for(int d=0;d<n-1;d++){
                for(;b[d] && !Ax[b[d]].e[c];b[d]=Ax[b[d]].link)l=min(l,Ax[b[d]].len);
                if(!b[d])b[d]=roots[d];
                l=min(l,Ax[b[d]].len);
            }
            cond=1;
            for(int d=0;cond && d<n-1; cond=cond&&(Ax[b[d]].e[c]),d++);
            if(cond)
            {
                for(int d=0;d<n-1;d++)b[d]=Ax[b[d]].e[c];
                l++;
            }
        }
        mx=max(mx,l);
    }
    return mx;
}
