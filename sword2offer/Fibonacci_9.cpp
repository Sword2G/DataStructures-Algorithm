//递归可能导致栈溢出，这里用迭代
int Fibonacci(int n) {
    if(n < 2)
        return n;
        
    int first = 0;
    int second = 1;
        
    while(n-- > 0){
        second = first + second;
        first = second - first;
    }

    return first;
}