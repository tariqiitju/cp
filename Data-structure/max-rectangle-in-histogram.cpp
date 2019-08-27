int getMaxArea(int hist[], int n) {
    stack<int> s;					//store indicies in increasing order
    int max_area = 0;
    int i = 0; 
    while (i < n) 
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {	//pop all the bigger bar than h[i] , so we can push i in stack
            int tp = s.top();
            s.pop();
            int area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);//maximum possible area with top
            max_area = max(max_area,area_with_top);
        }
    }
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        int tp = s.top(); 
        s.pop(); 
        int area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1);
        max_area = max(max_area,area_with_top);
    }
    return max_area; 
}
