#include <iostream>
#include <string>
#include <vector>

using namespace std;


void DFS(vector<string> &A, int i, int j, bool visited[][1000], int n, int m)
{
    visited[i][j] = true;
    // cout<<"Intial  = "<<i<<" "<<j<<endl;
    //Eight possible neighbours
    // if ((i+1) < n && (j+1) < m && A[i+1][j+1] == 'X' && !visited[i+1][j+1])
    // {
    //         // cout<<"1"<<endl;
    //         DFS(A,i+1,j+1,visited,n,m); 
    // }
    if ( (j+1) < m && A[i][j+1] == 'X' && !visited[i][j+1])
    {
            // cout<<i<<" "<<j+1<<endl;
            // cout<<"2"<<endl;
            DFS(A,i,j+1,visited,n,m);
    }
    // if ((i-1) >= 0 && (j+1) < m && A[i-1][j+1] == 'X' && !visited[i-1][j+1])
    // {
    //         cout<<"3"<<endl;
    //         DFS(A,i-1,j+1,visited,n,m);
    // }
    if ((i-1) >= 0 && A[i-1][j] == 'X' && !visited[i-1][j])
    {
            // cout<<"4"<<endl;
            DFS(A,i-1,j,visited,n,m);
    }
    // if ((i-1) >= 0 && (j-1) >= 0 && A[i-1][j-1] == 'X' && !visited[i-1][j-1])
    // {
    //         // cout<<"5"<<endl;
    //         DFS(A,i-1,j-1,visited,n,m);
    // }
    if ( (j-1) >= 0 && A[i][j-1] == 'X' && !visited[i][j-1])
    {
            // cout<<"6"<<endl;
            DFS(A,i,j-1,visited,n,m);
    }
    // if ((i+1) < n && (j-1) >= 0 && A[i+1][j-1] == 'X' && !visited[i+1][j-1])
    // {
    //         // cout<<i+1<<" "<<j-1<<endl;
    //         //cout<<"7"<<endl;
    //         DFS(A,i+1,j-1,visited,n,m);
    // }
    if ((i+1) < n && A[i+1][j] == 'X' && !visited[i+1][j])
    {
            // cout<<"8"<<endl;
            DFS(A,i+1,j,visited,n,m);
    }
}

int black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int m = A[0].size();
    //cout<<n<<" "<<m<<endl;     
    bool visited[1000][1000];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            visited[i][j] = false;
    }
    
    int shapes  = 0;
    //cout<<"Start"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(A[i][j] == 'X' && !visited[i][j])
            {
                // cout<<i<<" "<<j<<endl;
                DFS(A,i,j,visited,n,m);
                shapes++;
                // cout<<"shapes = "<<shapes<<endl;    
            }
            
        }
    }
    return shapes;
}


int main()
{
    std::vector<string> v;
    v.push_back("OOOXOOO");
    v.push_back("OOXXOXO");
    v.push_back("OXOOOXO");
    black(v);
    return 0;
}