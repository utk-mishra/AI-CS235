#include<bits/stdc++.h>
using namespace std;
vector<int> memoization(100,0);
vector<int> compute(int n,int player,int alpha,int beta)
{
    if(n==1 && player==1)
    {
        
        vector<int> ap1;
        ap1.push_back(1);
        ap1.push_back(1);
        ap1.push_back(-1);
        ap1.push_back(beta);
        return ap1;
    }
    else if(n==1 && player==2)
    {
       
        vector<int> ap2;
        ap2.push_back(1);
        ap2.push_back(2);
        ap2.push_back(alpha);
        ap2.push_back(1);
        return ap2;
    }
    else
    {int i;
        if(memoization[n]==0){
        for(int j=1;j<4;j++)
        { i=4-j;
          if(n>i)
          {
            if(player == 1)
            {
              
                vector<int> arr;
                arr=compute(n-i,2,alpha,beta);
                
                if(arr[2]<arr[3])
                {
                    alpha=arr[3];
                }
                if(alpha==1 || alpha>beta)
                {
                    break;
                }
            }
            else
            {
                vector<int> arr1;
                arr1=compute(n-i,1,alpha,beta);
                if(arr1[2]<arr1[3])
                {
                    beta=arr1[2];
                }
                if(beta == -1 || alpha>beta)
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
        man.push_back(i);
        man.push_back(player);
        man.push_back(alpha);
        man.push_back(beta);
        return man;

    }

}
int main()
{
    cout<<"enter the number of sticks = \n";
    int n;
    cin>>n;
    cout<<"please enter what do you want ? type 'AIvsAI' or 'HumanVsAI'\n";
    string string1;
    cin>>string1;

    if(string1=="HumanVsAI")
    {
    cout<<"lets have toss for who would play the first chance\n";
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
            cout<<"your turn\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
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
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }
    
            computer=compute(n,1,INT_MIN,INT_MAX);
     
            cout<<"number of sticks computer has picked up ="<<computer[0]<<"\n";
            n=n-computer[0];

        }

    }
    else
    {
        while(n>0)
        {
            cout<<"computer's turn\n";
            cout<<"\n";
            cout<<"number of sticks left  ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=1;
                break;
            }
 
            computer=compute(n,1,INT_MIN,INT_MAX);

            cout<<"number of sticks computer has picked up ="<<computer[0]<<"\n";
            n=n-computer[0];
            cout<<"your turn\n";
            cout<<"\n";
            cout<<"number of sticks left  ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=0;
                break;
            }
            cout<<"enter the number of sticks from 1 to 3 you want to pick up\n";
            cin>>humanbeing;
            n=n-humanbeing;
        }
    }
        if(loss==1)
        {
            cout<<"you have won the game\n";
        }
        else if(loss==0)
        {
            cout<<"you have lost the game\n";
        }
    }
    else if(string1=="AIvsAI")
    {
        cout<<"there are two AI players,player1 and player2....\n";
        cout<<"tossing a coin to see who wins....\n";
        int toss;
        toss=rand()%2;
        int winner;
        if(toss==1)
        {
            winner=1;
            cout<<"player 1 won the toss so he plays first....\n";
        }
        else{
            winner=2;
            cout<<"player 2 won the toss so he plays first...\n";
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
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=0;
                break;
            }
            comp1=compute(n,1,INT_MIN,INT_MAX);
            cout<<"number of sticks you have picked up = "<<comp1[0]<<"\n";
            n=n-comp1[0];
            cout<<"Player 2's turn\n";
            cout<<"\n";
            cout<<"number of sticks left = "<<n<<"\n";
            cout<<"\n";
            if(n==1 || n-1==0)
            {
                loss=1;
                break;
            }

            comp2=compute(n,1,INT_MIN,INT_MAX);

            cout<<"number of sticks computer has picked up ="<<comp2[0]<<"\n";
            n=n-comp2[0];

            }

        }
         else
        {
        while(n>0)
        {
            cout<<"Player's 2 turn\n";
            cout<<"\n";
            cout<<"number of sticks left ="<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=1;
                break;
            }
   
            comp2=compute(n,1,INT_MIN,INT_MAX);
      
            cout<<"number of sticks computer has picked up="<<comp2[0]<<"\n";
            n=n-comp2[0];
            cout<<"Player's 1 turn\n";
            cout<<"\n";
            cout<<"number of sticks left -"<<n<<"\n";
            cout<<"\n";
            if(n==1||n-1==0)
            {
                loss=0;
                break;
            }
            comp1=compute(n,1,INT_MIN,INT_MAX);
            n=n-comp1[0];
             cout<<"number of sticks computer has picked up="<<comp1[0]<<"\n";
        }
    }
    if(loss==0)
    {
        cout<<"Player 2 won the game\n";
    }
    else{
        cout<<"player 1 won the game\n";ute
    }

    }
    return 0;
}
