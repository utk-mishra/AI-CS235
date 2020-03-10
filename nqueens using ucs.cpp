#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli cost=0,cnt=0;

struct chessboard
{
lli cb[8][8],pc,queens;
    lli col[20],diag1[20],diag2[20];
};

vector<chessboard>V1;

void ucstraversal(vector<chessboard>&V1)
{
    chessboard temp=V1[0];          //vector first element
   
     
    lli queens=temp.queens;         
    V1.erase(V1.begin());               
   
     
   
    if(queens==8)
    {
    cnt++;
    cout<<cnt<<")Solution\n";
    cout<<"Cost= "<<cost<<"\n";
       
       
        for(lli i=0;i<8;i++)
        { for(lli j=0;j<8;j++)
          cout<<temp.cb[i][j]<<" ";
          cout<<"\n";
        }
        cout<<"\n";    

}
   
     
    for(lli i=0;i<8;i++)
    {
        lli cond1=temp.col[i];
        lli cond2=temp.diag1[queens-i+7];
        lli cond3=temp.diag2[queens+i];

       
temp.cb[queens][i]=1;
     temp.queens++;
temp.pc++;
       
if(queens==0 || (cond1==0 && cond2==0 && cond3==0) )
        {        
           
           
            temp.col[i]=temp.diag1[queens-i+7]=temp.diag2[queens+i]=1;
                 
V1.push_back(temp);
cost++;
            temp.col[i]=temp.diag1[queens-i+7]=temp.diag2[queens+i]=0;
}
       
        temp.cb[queens][i]=0;
   temp.queens--;
temp.pc--;

}
}    


int main()
{ lli i,j;
  chessboard c1;
 
  for(i=0;i<8;i++)
  { for(j=0;j<8;j++)
    c1.cb[i][j]=0;
  }
  c1.pc=0;  //path cost
  c1.queens=0;
 
  for(i=0;i<20;i++)
  c1.col[i]=c1.diag1[i]=c1.diag2[i]=0;    
 
  V1.push_back(c1);
 
  while(V1.size()!=0)      
  ucstraversal(V1);
 
 
  return 0;
}
