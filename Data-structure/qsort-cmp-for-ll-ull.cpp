inline int com (const void * a, const void * b){//for unsinged
	ull f = *(ull*)a , s = *(ull*)b;
	if(f==s) return 0;
	if(f > s) return 1;
	return -1;
}
