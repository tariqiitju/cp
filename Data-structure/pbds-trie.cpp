inline string conv(ull r){
	string p="";
	while(r)p+=('0'+r&63),r>>=6;
	return p;
}
trie<string, int> string_to_anything_fast_mapping;
