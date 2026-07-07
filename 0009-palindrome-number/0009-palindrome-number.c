bool isPalindrome(int x) {
    if (x < 0) return false;
    int num = x;
    long long revnum = 0;

    while (x != 0){
       revnum = (10 * revnum) + (x % 10);
       x /= 10;
    }

    if (revnum == num) return true;
    return false;
}