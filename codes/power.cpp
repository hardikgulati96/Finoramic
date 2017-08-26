int powmod(int x, int n, int z) {
  
   
    if(x==0)
    return 0;
    if(n==0)
    return 1;
    long long int temp=powmod(x,n/2,z);
    long long int res;
    if(n%2==0)
    res=((temp%z)*(temp%z))%z;
    else
    {
        
    if(n>0)
    {
    res=((((temp%z)*(temp%z))%z)*x)%z;
    }
    else
    res=((temp*temp)%z/x)%n;
    }
    if(res>0)
    return res%z;
    else
    return (res+z)%z;
    
    
}
