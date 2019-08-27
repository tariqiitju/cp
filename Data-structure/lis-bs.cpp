const int inf = 1e9;
template<class T> inline void lis(vector<T> &a, vector<int> &par , vector<int> &len){
	vector<T> last ={-inf};//tested [len array] with lightoj 1421
	vector<int> index_of_last = {-1};
	int n = (int)a.size();
	par.resize(n);len.resize(n);
	for(int i = 0;i < n;i++){
		int j = lower_bound(last.begin(), last.end(),a[i]) - last.begin();//use upper_bound for non-decreasing
		len[i] = j;
		if(j == last.size()){
			last.push_back(a[i]);
			par[i] = index_of_last.back();
			index_of_last.push_back(i);
		}else if(a[i] < last[j]){
			last[j] = a[i];
			par[i] = index_of_last[ j - 1];
			index_of_last[j] = i;
		}
	}
}

int MP[MX],RMP[MX],A[MX];
int Lcs(int *a,int *b ,int n){
    for(int i=0;i<n;i++)MP[a[i]]=i+1,RMP[i+1]=a[i];
    for(int i=0;i<n;i++)A[i]=MP[b[i]];;
     return lis(A,n);
}
