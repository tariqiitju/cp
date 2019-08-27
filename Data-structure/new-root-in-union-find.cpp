make-root(u,p) // make new root in union find DS
	If u!=parent[u]
		make-root(parent[u],p)
	parent[u]=p
