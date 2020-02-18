#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define V1 11

lli start;
priority_queue< pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>, vector<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>>, greater<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>> > p1;


lli heuristic(lli node,lli vis[],lli gr[][V1])
{
       
   vis[node]=1;
   
     
   lli m1=100000,m2=100000;
   lli i,z=0,heuristic=0;
   

i=1;
   
    while(i<=V1)
   {
      if(vis[i]==0)
    {    
     
       
      if(gr[node-1][i-1]<m1)
      m1=gr[node-1][i-1];
     
      if(gr[i-1][start-1]<m2)
      m2=gr[i-1][start-1];
   
      z=z+1;    
    }
       
  i++; }    
   
   if(z>=1)  
   heuristic+=m1+m2;
   
   
   
   return heuristic;
}


void traversal(lli node,lli total,lli vis[],lli gr[][V1])
{
   lli mx=-1,i;
   i=1;
   
      while(i<=V1)
   { if(vis[i]>=mx)
     mx=vis[i];
     i++;
   }
       
       

   vis[node]=mx+1;

   
   
   lli z=0;  
   lli vis1[V1+1][V1+1]={0};
   lli vis2[V1+1][V1+1]={0};
   vector<lli>path1[V1+1];
   
   for(lli i=1;i<=V1;i++)
   {
      if(vis[i]==0)
    {
      for(lli j=1;j<=V1;j++)
      {
          vis1[i][j]=vis[j];
       
          if(vis[j]>=1)
          vis2[i][j]=1;
          else
          vis2[i][j]=0;    
      }
         
      lli heur=heuristic(i,vis2[i],gr);
      lli obj=heur+gr[node-1][i-1]+total;    
      p1.push({obj,{i,{node,{total,vis1[i]}}}});          
 
      z=z+1;
    }
       
   }
   

   
   if(z>=1)
   {pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>> p2=p1.top();
    p1.pop();
   
    total=p2.second.second.second.first + gr[p2.second.second.first-1][p2.second.first-1];
 
   
    traversal(p2.second.first,total,p2.second.second.second.second,gr);
   }
   
   else
   {
     vector<pair<lli,lli>>finalpath;
       
     cout<<"Path: ";  
     
     for(lli i=1;i<=V1;i++)
     finalpath.push_back({vis[i],i});
       
     sort(finalpath.begin(),finalpath.end());
     
     for(lli i=0;i<finalpath.size();i++)
     cout<<finalpath[i].second<<" ";
       

       
     cout<<"1 ";  
     cout<<"\n";
 
     cout<<"total: "<<total+gr[node-1][start-1];
     return;
   }
       
   
}    

int main()
{
  start=1;
  //cout<<start<<" 000"<<"    ";;  
  lli vis[V1+1]={0};
 
 
  lli gr[][V1] =
  {
{0 , 8 ,50 ,31 ,12 ,48 ,36 , 2 , 5 ,39 ,10,},
        {8 , 0 ,38 , 9 ,33 ,37 ,22 , 6 , 4 ,14 ,32,},
        {50, 38,  0, 11, 55,  1, 23, 46, 41, 17, 52 ,},
        {31,  9, 11,  0, 44, 13, 16, 19, 25, 18, 42 ,},
        {12, 33, 55, 44,  0, 54, 53, 30, 28, 45,  7 ,},
        {48, 37,  1, 13, 54,  0, 26, 47, 40, 24, 51 ,},
        {36, 22, 23, 16, 53, 26,  0, 29, 35, 34, 49 ,},
        {2 , 6 ,46 ,19 ,30 ,47 ,29 , 0 , 3 ,27 ,15 ,},
        {5 , 4 ,41 ,25 ,28 ,40 ,35 , 3 , 0 ,20 ,21 ,},
        {39, 14, 17, 18, 45, 24, 34, 27, 20,  0, 43 ,},
        {10, 32, 52, 42,  7, 51, 49, 15, 21, 43,  0 ,}
  };
 
   traversal(start,0,vis,gr);
 
 
  return 0;  
   
}