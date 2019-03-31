//斐波那契数列循环，自下而上
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)return 0;
        if(n<=2)return 1;
        int f1=1;
        int f2=1;
        int f3;
        for(int i=3;i<=n;i++){
            f3=f2+f1;
            f1=f2;
            f2=f3;
        }
        return f3;
    }
};