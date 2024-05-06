#include<bits/stdc++.h>
using namespace std;

struct rec{
    int roll;
    string name;
    int chain;
};

class hashing{
    rec hashtable[10];
    string name;
    int roll;
    
    public:

    hashing(){
        for(int i=0;i<10;i++)
        {
            hashtable[i].roll=-1;
            hashtable[i].chain=-1;
        }
    }

    void insert(int roll1 ,string name1){
        int x=roll1%10;
        int u=0;
        int y=x;
        while(1){
            if(u>0){
                break;
            }
            if(hashtable[x].roll==-1){
                hashtable[x].roll=roll1;
                hashtable[x].name=name1;
                u++;
                break;
            }
            else if((hashtable[x].roll)%10==y){
                int w=x;
                while(hashtable[w].chain!=-1){
                    w=hashtable[w].chain;
                }
                for(int j=w;j<=w+10;j++){
                    if(hashtable[j%10].roll==-1){
                        hashtable[j%10].roll=roll1;
                        hashtable[j%10].name=name1;
                        hashtable[w%10].chain=j%10;
                        u++;
                        break;
                    }
                }
            }
            else if(hashtable[x].roll%10!=y){
                if(u>0){
                    break;
                }
                int w=-1;
                int rolltemp=hashtable[x].roll;
                string nametemp=hashtable[x].name;
                int chaintemp=hashtable[x].chain;
                hashtable[x].roll=roll1;
                hashtable[x].name=name1;
                hashtable[x].chain=-1;
                for(int i=x+1;i<=x+10;i++){
                    if(hashtable[i%10].roll==-1){
                        hashtable[i%10].roll=rolltemp;
                        hashtable[i%10].name=name1;
                        hashtable[i%10].chain=chaintemp;
                        w=i%10;
                        break;
                    }
                }
                for(int i=0;i<=9;i++){
                    if(hashtable[i].chain==x){
                        hashtable[i].chain=w;
                        break;
                    }
                }
                u++;
                break;
            }
        }
    }

    int search(int roll1){
        int u=0;
        int i=roll1%10;
        while(1){
            if(hashtable[i].roll==roll1){
                cout<<"found : "<<hashtable[i].name<<endl;
                u++;
                break;
            }
            i=hashtable[i].chain;
            if(u>0){
                break;
            }
        }
        if(u==0){
            cout<<"Not found\n";
        }
    }

    void display(){
        cout<<"hashtable-:\n";
        for(int i=0;i<10;i++){
            cout<<hashtable[i].roll<<" "<<hashtable[i].name<<" "<<hashtable[i].chain<<endl;
        }
    }
    
    void dlt(int roll1){
        int i=roll1%10;
        for(int j=0;j<10;j++){
            if(hashtable[i%10].roll==-1){
                cout<<"empty\n";
                break;
            }
            else if(hashtable[i%10].roll==-2){
                i++;
            }
            else if(hashtable[i%10].roll==roll1){
                hashtable[i%10].roll=-2;
                hashtable[i%10].name="";
                break;
            }
        }
    } 
};
int main()
{
    hashing obj;
    int a;
    string b;
    for(int i=0;i<10;i++){
        cin>>a>>b;
        obj.insert(a,b);
    }
    obj.display();
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cout<<"enter roll no to be searched\n";
        cin>>x;
        obj.search(x);
    }
    int k;
    cin>>k;
    while(k--)
    {
        cout<<"enter roll no to be deleted\n";
        int y;
        cin>>y;
        obj.dlt(y);
    }
    obj.display();
}