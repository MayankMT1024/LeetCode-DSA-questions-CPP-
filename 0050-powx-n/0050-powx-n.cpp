class Solution {
public:
    double power(double x, long n){
        if(x == 0.0 || x == 1.0) return x;
        if(n == 1) return x;
        if(n == 0) return 1;

        if(n<0) return(1/power(x, -1 * n));

        if(n%2 == 0) return power(x*x, n/2);
        else return x*power(x, n-1);
    }
    double myPow(double x, int n) {
        return power(x, n);
    }
};