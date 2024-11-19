#include <iostream>
using namespace std;

int way(int a)
{
    if(a==0 || a==1)
    return 1;
    if(a==2)
    return 2;
    return way(a-1)+way(a-2)+way(a-3);
}

int main(){
    int n;
    cout<<"NO of step : ";
    cin>>n;
    int res = way(n);
    cout<<res;
}
