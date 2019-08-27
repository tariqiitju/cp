//Largest x such that p^x divides n! (given p,n) :
int largestPower(int n, int p){
    int x = 0;
    while (n){ 
        n /= p;
        x += n;
    }
    return x;
}
