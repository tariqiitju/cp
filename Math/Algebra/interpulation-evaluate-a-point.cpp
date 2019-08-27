double interpolate(vector<pair<int,int>> f, int xi){//F(f[i].first)=f[i].second
    int n=f.size();
    double result = 0; // Initialize result
    for (int i=0; i<n; i++) { 
        // Compute individual terms of above formula 
        double term = f[i].second;
        for (int j=0;j<n;j++){
            if (j!=i)
                term = term*(xi - f[j].first)/double(f[i].first - f[j].first);
        } 
        result += term; 
    }
    return result;
}
