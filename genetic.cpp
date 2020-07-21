#include<bits/stdc++.h>
using namespace std;

#define pback push_back
#define collection 8
#define lli long long int
#define integer int

vector<vector<int>> form_collection;
vector<lli> student_marks;
set<lli> leader;
vector<vector<int>> groups;
void printinggroups();
void  RANDOM(int key,int n,int i);

int fit(int key,int n,int i);

int fit2(int key,int mar);

int crossmaking(int ease_1,int ease_2,int key,int g1);


int main()
{
        int m, k, marksobtained;
        
        cout<<"Enter Number of groups:";
        cin>>k;
        cout<<" "<<k<<endl;

        cout<<"Enter value of n:";
        cin>>m;
        cout<<" "<<m<<endl;
        
        cout<<"Please Enter the marks obtained by students:";
      //  for(int i=0;i<m;i++)
    int j=0;
    while(j<m)
    {
                cin>>marksobtained;
                student_marks.pback(marksobtained);
        j++;
        }
    cout<<endl;
    cout<<"                               marks"<<"    gr representative"<<"\n";
        vector<pair<int,int>> foo;
        //for(int i=0;i<collection;i++)
     j=0;
        while(j<m)
        {
                mt19937 mt_rand ( time (NULL));
                 RANDOM(k,m,j);
                leader.clear();
            j++;
        }
    
    //for(int count1=0;count1<50;count1++)
      int count1=0;
      while(count1<50)  
        {
        for(int i=0;i<collection;i++)
        {
            int ze=fit(k,m,i);
            foo.pback(make_pair(ze,i));
        }
        sort(foo.rbegin(),foo.rend());
        int i=0;
        mt19937 mt_rand (time(0));
        for(i=0;i<collection;i++)
        {
            marksobtained=rand()%360;
            if(marksobtained>=0 && marksobtained<=10)
            {
                int indexNumber=foo[0].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=11 && marksobtained<=30)
            {
                int indexNumber=foo[1].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=31 && marksobtained<=60)
            {
                int indexNumber=foo[2].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=61 && marksobtained<=100)
            {
                int indexNumber=foo[3].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=101 && marksobtained<=150)
            {
                int indexNumber=foo[2].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=151 && marksobtained<=210)
            {
                int indexNumber=foo[2].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=211 && marksobtained<=280)
            {
                int indexNumber=foo[2].second;
                form_collection.pback(groups[indexNumber]);
            }
            else if(marksobtained>=281 && marksobtained<=360)
            {
                int indexNumber=foo[2].second;
                form_collection.pback(groups[indexNumber]);
            }
        }
        auto ite=form_collection.begin();
            int current_pop=0;
            //for(i=0;i<4;i++)
            j=0;
            while(j<4)
            {
                groups[j].clear();
                j++;
            }
            groups.clear();
            int indexNumber1=0,indexNumber2=1;
            for(;current_pop<collection;)
            //while(current_pop<collection)
            {
                mt19937 mt_rand(time(NULL));
                integer ease_1=rand()%4;
                integer ease_2=rand()%4;
                integer indexNumber=k-1;
                indexNumber=rand()%indexNumber;
                integer call1=crossmaking(ease_1,ease_2,k,indexNumber);
                integer call2=crossmaking(ease_2,ease_1,k,indexNumber);
                if( (call1==0) || (call2==0))
                {
                    groups.erase(groups.begin()+indexNumber1);
                    continue;
                }
                else if((call1==1) && (call2==1))
                {
                        indexNumber1=indexNumber+2;
                        indexNumber2=3;
                        leader.clear();        
                        current_pop=current_pop+2;
                }
            }
        count1++;
        }
    printinggroups();
}



void  RANDOM(int key,int n,int i)
{
        int ee,m;
        mt19937 mt_rand (time(0));
        //while(leader.size()!=k)
        for(;leader.size()!=key;)
        {
                ee=rand()%n;
                leader.insert(student_marks[ee]);
        }
        m=0;
        vector<integer> temp;
        for(auto j=leader.begin();j!=leader.end();j++)
        {
                temp.pback(*j);
                m++;
        }
        groups.pback(temp);
}
int fit(int key,int n,int i)
{
    integer dis[key],fitnes=0,easy;
    integer j=0;
    //for(in=0;in<n;in++)
        integer jn=0;
    while(jn<n)
    {
        auto gr=groups[i].begin();
        for(j=0;j<key;j++)
        {
            dis[j]=student_marks[jn]-(*gr);
            dis[j]=dis[j]*dis[j];
            gr++;
        }
        easy=1000020;
       // for(j=0;j<key;j++)
        while(j<key)
        {
            if(dis[j]<easy)
            {
                easy=dis[j];
            }
            j++;
        }
        fitnes=fitnes+easy;
        jn++;
    }
    return fitnes;
}
  
  int crossmaking(int ease_1,int ease_2,int key,int g1)
{
    leader.clear();
    int in=key-1, i;
   // for(i=0;i<=g1;i++)
    i=0;
    while(i<=g1)
    {
        leader.insert(form_collection[ease_1][i]);
        i++;
    }
    //for(int j=i;j<key;j++)
    integer j=i;
    while(j<key)
    {
        leader.insert(form_collection[ease_2][j]);
        j++;
    }
    if(leader.size()!=key)
    {
        return 0;
    }
    else if(leader.size()==key)
    {
    vector<integer> temporary1;
    for(auto itc1=leader.begin();itc1!=leader.end();itc1++)
    {
         temporary1.pback(*itc1);
    }
    groups.pback(temporary1);
    return 1;
}
} 

int fit2(int key,int mar)
{
int kkk=groups.size(),it_val,com=100000,dis,val;
kkk--;
auto ite=groups[kkk].begin();
for(int i=0;i<key;i++)
{
it_val=*ite;
dis=it_val-mar;
dis=dis*dis;
if(dis<com)
{
val=it_val;
com=dis;
}
ite++;
}
return val;
}
void printinggroups()
{
integer nu=student_marks.size();
integer ka=groups[0].size();
integer student;
auto student1=student_marks.begin();
       // stu=*(stu1);
int i=0;
while(i<nu)
//for(integer i=0;i<nu;i++)
{
//auto stu1=student_marks.begin();
       student=*(student1);
int gro=fit2(ka,student);
cout<<"    marks obtained by student -- "<<student<<" -----> "<<gro<<endl;
student1++;
i++;
}
}
