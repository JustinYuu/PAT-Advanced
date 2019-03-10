#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int p[10010]={0};
    int n;
    int tmp,i;
    vector<int> seq;

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        p[tmp]++;
        seq.push_back(tmp);
    }
    for(i=0;i<seq.size();++i)
    {
        if(p[seq[i]]==1)
        {
            cout<<seq[i];
            break;
        }
    }
    if(i==seq.size())
        cout<<"None";
    return 0;
}
