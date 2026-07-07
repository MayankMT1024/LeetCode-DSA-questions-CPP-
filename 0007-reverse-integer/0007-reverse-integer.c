int reverse(int x){
    int n = x;
    if (n == INT_MIN) return 0;
    else if(n < 0){
        n = -n;
    } else if (n == 0){
        return 0;
    }
    int revnum = 0;
    while (n != 0){
        int pop = n % 10;
        
        if (revnum > INT_MAX / 10 || (revnum == INT_MAX / 10 && pop > 7)) return 0;
        if (revnum < INT_MIN / 10 || (revnum == INT_MIN / 10 && pop < -8)) return 0;
        
        revnum = (revnum * 10) + pop;
        n /= 10; 
    }

    if (revnum < INT_MIN || revnum > INT_MAX) return 0;

    if (x < 0) return -revnum;
    else return revnum;
}