class Solution {
public:
    double pow(double x, long long n) {
        if(!n) return 1;
        long long m = abs(n);
        double a = pow(x,m/2);
        if(m % 2 == 0)
            return a*a;
        else return a*a*x;
    }
    double myPow(double x, long long n){
        if (n > 0) return pow(x,n);
        else return 1/pow(x,n);
    }
};