#include<iostream>
using namespace std;
class emp
{
int id;
string name,add;
emp *lc,*rc;
public:
void create();
void insert(emp *root, emp *next);
void display(emp *root);
}*root;
void emp :: create()
{
int ch;
emp *next;
root=new emp;
cout<<"Enter the emp info"<<endl;
cout<<"Enter the  emp id"<<endl;
cin>>root->id;
cout<<"Enter the  emp name"<<endl;
cin>>root->name;
cout<<"Enter the  emp address"<<endl;
cin>>root->add;
root->lc=NULL;
root->rc=NULL;
do
{
cout<<"do you want to add more emp(0 or1)"<<endl;
cin>>ch;
if(ch==1)
{
next=new emp;
cout<<"Enter new info"<<endl;
cout<<"Enter new id"<<endl;
cin>>next->id;
cout<<"Enter the new emp name"<<endl;
cin>>next->name;
cout<<"Enter the  emp address"<<endl;
cin>>next->add;
next->lc=NULL;
next->rc=NULL;
insert(root, next);
}
}while(ch==1);
}
void emp::insert(emp *root,emp *next)
{
char chr;
cout<<"Where want to insert employee information id of Left(L) or Right(R)"<<root->id;
cin>>chr;
if(chr=='L' || chr=='l')
{
if(root->lc==NULL)
{
root->lc=next;
}
else
{
insert(root->lc,next);
}
}
else if(chr=='R' || chr=='r')
{
if(root->rc==NULL)
{
root->rc=next;
}
else
{
insert(root->rc,next);
}
}
}
void emp:: display(emp *root)
{

if(root==NULL)
{
return;
}
else
{
display(root->lc);

display(root->rc);
cout<<"\n"<<root->id<<"\t"<<root->name<<"\t\t"<<root->add;
}
}
int main()
{
emp e;
e.create();
e.display(root);
return 0;
}

