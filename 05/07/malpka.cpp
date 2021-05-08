#include <iostream>

using namespace std;

int nwd(int k,int n )
{   
  if(min(n,k) == 0)
  {
    return max(n,k);
  }
  else{
    return nwd(max(n,k)%min(n,k),min(n,k)); 
  }
}

int main() {
  long long n, k,w;
  cin>> n >> k;
  w = (n)/nwd(k,n);
  cout << w;
 
  return 0;
}