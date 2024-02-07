gcd(a,b)=gcd(a,b−a)

```c++
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
```

