#include <bits/stdc++.h>
using namespace std;

/*global section*/

#define ll long long 
#define pb push_back
#define V vector<ll>
#define set vector<pair<ll,ll>>
#define mp map<float,ll>

V vector1;
vector<float>V1[10000];
vector<float>final;

int main()
{

  ll i,j,n,d,m,k,l;

  
  cout<<"please enter the number of groups: ";
  cin>>k;
  cout<<"please enter the number of students: ";
  cin>>n;
  cout<<"please enter the number of subjects: ";
  cin>>m;
 
    i=0;
    while(i<n)

      { ll s=0;
        cout<<"Marks of student "<<i+1<<": ";
        j=0;
        while(j<m)
       
        {
           cin>>d;
           s+=d;
           j++;
        }
        s=s/m;
        vector1.pb(s);
        i++;
      }
 

      mt19937 mt_rand(time(NULL));

      ll ps=80;

      i=0;
      while(i<ps)

          {  
            
            ll A[10000]={0};
            j=1;
                     while(j<=k)
              
                    { 
                        d = (mt_rand() % n);
                        if(A[d]==0)
                        { 
                          A[d]+=1;
                          V1[i].pb(vector1[d]);
                        }
                      else
                      { 
                        while(A[d]>=1)
                        d = (mt_rand() % n);
                       
                        A[d]+=1;
                        V1[i].pb(vector1[d]);
                      }
                   
                        j++;
                    }
              
            i++;
          }
 
      i=1;
      while(i<=100)
  
          { 
              set vec3;
               V vec4,vec5,vec6;
              V vec2[10000];
              vector<float>V7[10000]; 
              ll h=0;
              while(h<ps)
            
            {  
              j=0;
              while(j<n)

            { 
              ll min = abs(V1[h][0]-vector1[j]);
              ll min1 = 0;
              l=1;while(l<k)
              
              {
                if(abs(V1[h][l]-vector1[j])<min)
                {
                    min = abs(V1[h][l]-vector1[j]);
                    min1 = l;
                }
                l++; 
           }
                vec2[h].pb(min1);
            j++;
          }
          h++; 
        } 
            

             ll s2=0;  

             j=0;while(j<ps)
            
           { 
              ll s=0;
               for(l=0;l<n;l++)
               s=s+(V1[j][vec2[j][l]]-vector1[l])*(V1[j][vec2[j][l]]-vector1[l]); 
               s2=s2+s;  
               vec3.pb({s,j}); 
             j++;
           }
           //sorting of vec3
           sort(vec3.begin(),vec3.end());  
              
           for(j=0;j<V1[vec3[0].second].size();j++)
           {if(i==100)
            final.pb(V1[vec3[0].second][j]);
           }
           reverse(vec3.begin(),vec3.end());

              
              
           float s1=0;   
           

            j=1;while(j<=ps)
          {
           s1+=j;
           j++;
         }   
            j=1;while(j<=ps)
         
           { float d=(j/s1)*100;
             ll d1=ceil(d);
             
             if((d1-d)>0.5)
             vec4.pb(floor(d));
             else
             vec4.pb(ceil(d)); 
             j++;  
           }
           

           vec5.pb(1);
           ll z=vec4[0];   
               j=1;while(j<vec4.size())
         
           {vec5.pb(z+1);
            z=z+vec4[j];
            j++;
           }
              
          j=1;while(j<=ps)

           { d = (rand() % 100)+1;
             
             ll pos=lower_bound(vec5.begin(), vec5.end(), d)-vec5.begin();
             if(pos!=0)
             pos=pos-1;    
             vec6.pb(vec3[pos].second);
          j++; }

         
           ll z1=0;   
            j=1;while(j<=(ps/2)) 
           
           { d = (rand() % ps);
             
             ll d1 =(rand() % ps);
             
             ll cnt=0;
             
            
              for(;d1==d && cnt<=60;)
             {d1 = (rand() % ps);
              cnt++;
             }
            
            
             ll d2 = (rand() % k);

             ll d3 = (rand() % 2);

              mp B,C;
            
            if(d3==0)
            { l=0;while(l<=d2)
          
              { V7[z1].pb(V1[vec6[d1]][l]);
                V7[z1+1].pb(V1[vec6[d]][l]);
              l++;}
             l=d2+1;
             while(l<k)

             {V7[z1].pb(V1[vec6[d]][l]);
              V7[z1+1].pb(V1[vec6[d1]][l]);
             l++;}
            }
            else
            { 
              l=d2+1;
             while(l<k)

              { V7[z1].pb(V1[vec6[d1]][l]);
                V7[z1+1].pb(V1[vec6[d]][l]);
             l++;
              }
             l=0;while(l<=d2)
         
             {V7[z1].pb(V1[vec6[d]][l]);
              V7[z1+1].pb(V1[vec6[d1]][l]);
             l++;}
            }     
            

            z1+=2;
          j++; }
           h=0;
           while(h<ps)

          {
            V1[h].clear();
            V1[h]=V7[h];
           h++;
          }
              
        i++; 
        }
            
   V groups[k]; 

   
   for(ll j=0; j<vector1.size();j++)
   { ll min,min1;
     for(ll i=0; i<final.size(); i++)
    { ll res = abs(final[i]-vector1[j])*abs(final[i]-vector1[j]);
       if(i==0)
     {min = res;
      min1 = i;
     }
      if(res < min)
      { min = res;
        min1 = i;
      }
    }
    groups[min1].pb(j+1);
   }
    
    i=0;
    while(i<final.size())

   { cout<<"Group "<<i+1<<": ";
    j=0;while(j<groups[i].size())
    
     {cout<<groups[i][j]<<" ";
    j++;}
     cout<<"\n";
  i++; }
     
       

  return 0;
    
}
