Add:
pos[clone]=pos[q]; //in extend
pos[last]=i; //in the for loop in create() function after calling extend
int firstpostn(string p,int root)
{  int s_t = 0 ;
   int vtx = root;
   int u =s_t;
    while(s_t<p.length()){
        vtx = Ax[vtx].e[p[s_t] - 'a'];
        s_t++;
   }
   return pos[vtx] - p.length() + 1 ;
}
