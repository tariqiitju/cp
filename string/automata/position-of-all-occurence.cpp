Add bool notClone; in node structure
Ax[cur].notClone=1; after line 20
Ax[clone].notClone=0; after line 26
pos[clone]=pos[q]; //in extend
pos[last]=i; //in the for loop in create() function after calling extend
vector<int> adj[_Z<<1];
for (int v = root; v <= last; v++) {///run the loop after construction
    adj[st[v].link].push_back(v);
}
vector<int> allOccur;
void output_all_occurrences(int v, int P_length) {
    if (Ax[v].notClone)
        allOccur.push_back( pos[v] - P_length + 1);
    for (int u : adj[v])
        output_all_occurrences(u, P_length);
}
