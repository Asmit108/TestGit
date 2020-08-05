#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
   long int val;
   long int last;
   struct node *next;
};
struct node *START=NULL;
struct node *TAIL=NULL;

void popstart()
{ struct node *n;
  n=(struct node*)malloc(sizeof(struct node));
  n=START;
  if(START==TAIL){START=NULL;TAIL=NULL;}
  else{ START=START->next;
  }
  free(n);
}
long int c=0;
long int push(long int a,long int b,long int s)
{
   while((START!=NULL)&&(START->last)<=a){popstart();c--;}
   if(c>=s){cout<<-1<<endl;return 0;}
   else{ c++;
        struct node *n;
        n=(struct node*)malloc(sizeof(struct node));
        n->next=NULL;
        if(START==NULL){n->val=a;n->last=a+b;START=n;TAIL=n;}
        else{
             if((TAIL->last)>=a){n->val=TAIL->last;n->last=(TAIL->last)+b;}
            else{
                 n->val=a;n->last=a+b;

            }
            TAIL->next=n;
            TAIL=n;
        }
       }

  cout<<TAIL->val<<endl;
  return 0;

}
int main()
{
    long int s,n;
    cin>>s>>n;
    long int **a;
    a=(long int**)malloc(sizeof(long int*)*n);
    for(long int i=0;i<n;i++)
    {
        a[i]=(long int*)malloc(sizeof(long int)*2);
        cin>>a[i][0]>>a[i][1];
    }
    for(long int i=0;i<n;i++)
    {
        push(a[i][0],a[i][1],s);
    }
    return 0;
}
