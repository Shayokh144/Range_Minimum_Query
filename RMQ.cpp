#include<bits/stdc++.h>
using namespace std;
int main()
{


    int n,m;
    int sparse[100][100];
    int arr[100];//={2,5,3,7,99,8,13,11,10,15};
    cin>>m;
    for(int y=1; y<=m; y++)
        cin>>arr[y];


    //// Creating Sparse table  ////////////////////////////////////////////////////

    for(int i=1; i<=m; i++ )
        sparse[i][0]=arr[i];

    for(n=1; (1<<n)<=m; n++)
    {
        for(int i=1; i<=m&&(i+(1<<n)-1)<=m; i++)
        {
            sparse[i][n]=min(sparse[i][n-1],sparse[i+(1<<(n-1))][n-1]);
        }
    }


    /////////////////////End of Sparse table ////////////////////////////////


  /*
  ///print Sparse  Table

   for(int i=0; i<=10; i++)
    {
        for(int j=0; j<=10; j++)
        {
            cout<<sparse[i][j]<<"  ";
        }
        cout<<"\n";
    }

*/
/////......... MRQ  ....................

    int q1,q2,dif,aa,ans,x,y;
    while(cin>>q1>>q2)
    {
        dif=q2-q1+1;
        aa=31-__builtin_clz(dif);
        x=sparse[q1][aa];
        y=sparse[q2-(1<<aa)+1][aa];
        ans=min(x,y);
        cout<<"ans="<<ans<<"\n";
    }



    return 0;
}


/*

8
4 6 5 2 3 4 9 1

*/

/*int num = 16;
    clz = __builtin_clz(num);
    printf("Number of leading zero's in %d is %d\n", num, clz);*/
