Add:
pos[clone]=pos[q]; //in extend
pos[last]=i; //in the for loop in create() function after calling extend
int tp,t;
int minshift(int ver)
{
   for(int i=0;i<_Y;i++)
     if( Ax[ver].e[i] ){
        tp++;
        if(tp==t){
            return pos[ver];
        }
        return minshift(Ax[ver].e[i]);
    }
}
int minshift(string s){
    int root = create(s+s);
    t=s.length();
    tp=0;
    return minshift(root) - t + 2;
}
