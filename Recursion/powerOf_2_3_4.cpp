// power of 2 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1 ) return 1;
        if(n%2!=0) return false;
        return isPowerOfTwo(n/2);
    }
};
// power of 3
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true ;
        if(n%3!=0) return false;
        return isPowerOfThree(n/3); 
    }
};
// power of 4
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        if(n==1) return true ;
        if(n%4!=0) return false;
        return isPowerOfFour(n/4); 
    }
};
