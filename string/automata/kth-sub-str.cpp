This code bellow runs in O(k), we can do better with precals with distsub(root)
int k,path=0;
void   klex(int ver,vector<int>&ans)
{
    for(int i=0;i<_Y;i++)
    if( Ax[ver].e[i]){
        path++;
        if (path==k){   
            ans.push_back(i);
            return;
        }
        klex(Ax[ver].e[i],ans);
        if (path==k){
            ans.push_back(i);
            return;
        }
    }
}
