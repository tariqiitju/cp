inline int search(int t,string s){
	for(int i=0;s[i];i++){
		if(Ax[t].e[VAL(s[i])])
			t=Ax[t].e[VAL(s[i])];
		else return 0;
	}
	return t;
}