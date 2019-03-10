#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void nm_postorder(int pi, int pj, int ii, int ij)
{
    if(pi > pj || ii > ij)
        return;
    int pos;
    for(int i = ii; i <= ij; ++i)
        if(inorder[i] == preorder[pi]){
            pos = i; break;
        }
    for(int i=1; i<=pos-ii; ++i)
        if(preorder[pi+i] >= preorder[pi]){
            return;
        }
    for(int i=pi+pos-ii+1; i<= pj; ++i)
        if(preorder[i] < preorder[pi]){
            return;
        }
    nm_postorder(pi+1, pi+pos-ii, ii, pos-1);
    nm_postorder(pi+pos-ii+1, pj, pos+1, ij);
    postorder.push_back(preorder[pi]);
}

void m_postorder(int pi, int pj, int ii, int ij)
{
    if(pi > pj || ii > ij)
        return;
    int pos;
    for(int i = ij; i >= ii; --i)
        if(inorder[i] == preorder[pi]){
            pos = i; break;
        }
    for(int i=1; i<=pos-ii; ++i)
        if(preorder[pi+i] < preorder[pi]){
            return;
        }
    for(int i=pi+pos-ii+1; i<= pj; ++i)
        if(preorder[i] >= preorder[pi]){
            return;
        }
    m_postorder(pi+1, pi+pos-ii, ii, pos-1);
    m_postorder(pi+pos-ii+1, pj, pos+1, ij);
    postorder.push_back(preorder[pi]);
}

bool comp(int n1, int n2){
    if(n1 > n2)
        return true;
    else
        return false;
}

int main()
{
    int N; cin>>N;
    preorder.resize(N);
    inorder.resize(N);
    for(int i=0; i != N; ++i){
        cin>>preorder[i];
        inorder[i] = preorder[i];
    }
    if(preorder.size() == 1){
        cout<<"YES"<<endl<<preorder[0]<<endl;
        return 0;
    }
    else if(preorder[0] > preorder[1]){
        sort(inorder.begin(), inorder.end());
        nm_postorder(0, N-1, 0,N-1);
    }
    else{
        sort(inorder.begin(), inorder.end(), comp);
        m_postorder(0, N-1, 0, N-1);
    }
    if(postorder.size() != N)
        cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<N; ++i)
            if( i == N-1)
                cout<<postorder[i]<<endl;
            else
                cout<<postorder[i]<<" ";
    }
    return 0;
}
