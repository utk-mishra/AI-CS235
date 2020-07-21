#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
vector<int> memoization(100,0);
vector<int> compute(int n,int play,int al,int gamma);

int main()
{
    cout<<"number of sticks = \n";
    int n;
    cin>>n;
    cout<<"type 'AIvsAI' or 'HumanVsAI'\n";
    string string1;
    cin>>string1;

    if(string1=="HumanVsAI")
    {
    
    cout<<"enter heads or tails\n";
    string s;
    cin>>s;
    int toss;
    toss=rand()%2;
    string winner;
    if(toss==1)
    {
        winner="heads";
    }
    else
    {
        winner="tails";
    }
    vector<int> computer;
    int humanbeing;
    int loss;
    if(winner==s)
    {
        while(n>0)
        {
             cout<<"total sticks left = "<<n<<"\n";
            cout<<"\n";
            cout<<"your turn\n";
            cout<<"\n";
           
            if(n==1 || n-1==0)
            {
                loss=0;
                break;
            }
            cout<<"enter the number of sticks from 1 to 3 you want to pick up\n";
            cin>>humanbeing;
            cout<<"number of sticks you have picked up = "<<humanbeing<<"\n";
            n=n-humanbeing;
            cout<<"computer's turn\n";
            cout<<"\n";
            cout<<"total sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }
    
            computer=compute(n,1,INT_MIN,INT_MAX);
     
            cout<<"total number of sticks computer has picked up ="<<computer[0]<<"\n";
            n=n-computer[0];

        }

    }
    else
    {
        while(n>0)
        {
            cout<<"computer's turn\n";
            cout<<"\n";
            cout<<"total number of sticks left  ="<<n;
            cout<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=1;
                break;
            }
 
            computer=compute(n,1,INT_MIN,INT_MAX);

            cout<<"total number of sticks computer has picked up ="<<computer[0]<<"\n";
            n=n-computer[0];
            cout<<"it's your turn pick something\n";
            cout<<"\n";
            cout<<"total number of sticks left  ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=0;
                break;
            }
            cout<<"pick number of sticks from 1 to 3 \n";
            cin>>humanbeing;
            n=n-humanbeing;
        }
    }
        if(loss==1)
        {
            cout<<"you won\n";
        }
        else if(loss==0)
        {
            cout<<"you loose\n";
        }
    }
    else if(string1=="AIvsAI")
    {
       
        cout<<"toss time....\n";
        int toss;
        toss=rand()%2;
        int winner;
        if(toss==1)
        {
            winner=1;
            cout<<"play 1 won the toss \n";
        }
        else{
            winner=2;
            cout<<"play 2 won the toss\n";
        }
        vector<int> comp1;
        vector<int> comp2;
        int loss=0;
        if(winner==1)
        {
            while(n>0)
            {
                cout<<"Player 1's turn\n";
            cout<<"\n";
            cout<<"total sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=0;
                break;
            }
            comp1=compute(n,1,INT_MIN,INT_MAX);
            cout<<"number of sticks picked = "<<comp1[0]<<"\n";
            n=n-comp1[0];
            cout<<"Player 2's turn\n";
            cout<<"\n";
            cout<<"total sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }

            comp2=compute(n,1,INT_MIN,INT_MAX);

            cout<<"number of sticks picked by computer ="<<comp2[0]<<"\n";
            n=n-comp2[0];

            }

        }
         else
        {
        while(n>0)
        {
            cout<<"Player's 2 turn\n";
            cout<<"\n";
            cout<<"total sticks left ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=1;
                break;
            }
   
            comp2=compute(n,1,INT_MIN,INT_MAX);
      
            cout<<"number of sticks picked by computer = "<<comp2[0]<<"\n";
            n=n-comp2[0];
            cout<<"Player's 1 turn\n";
            cout<<"\n";
            cout<<"total sticks left ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=0;
                break;
            }
            comp1=compute(n,1,INT_MIN,INT_MAX);
            n=n-comp1[0];
             cout<<"number of sticks picked by computer ="<<comp1[0]<<"\n";
        }
    }
    if(loss==0)
    {
        cout<<"Player 2 win\n";
    }
    else{
        cout<<"play 1 win\n";
    }

    }
    return 0;
}


vector<int> compute(int n,int play,int al,int gamma)
{
    if(n==1 && play==1)
    {
        
        vector<int> appending1;
        appending1.pb(1);
        appending1.pb(1);
        appending1.pb(-1);
        appending1.pb(gamma);
        return appending1;
    }
    else if(n==1 && play==2)
    {
       
        vector<int> appending2;
        appending2.pb(1);
        appending2.pb(2);
        appending2.pb(al);
        appending2.pb(1);
        return appending2;
    }
    else
    {int i;
        if(memoization[n]==0){
        for(int j=1;j<4;j++)
        { i=4-j;
          if(n>i)
          {
            if(play == 1)
            {
              
                vector<int> arrayno;
                arrayno=compute(n-i,2,al,gamma);
                
                if(arrayno[2]<arrayno[3])
                {
                    al=arrayno[3];
                }
                if(al==1 || al>gamma)
                {
                    break;
                }
            }
            else
            {
                vector<int> arrayno1;
                arrayno1=compute(n-i,1,al,gamma);
                if(arrayno1[2]<arrayno1[3])
                {
                    gamma=arrayno1[2];
                }
                if(gamma == -1 || al>gamma)
                {
                    break;
                }
            }

          }
        }
        memoization[n]=i;
        }
        else
        {
            i=memoization[n];
        }
         vector<int> man;
        man.pb(i);
        man.pb(play);
        man.pb(al);
        man.pb(gamma);
        return man;

    }

}
