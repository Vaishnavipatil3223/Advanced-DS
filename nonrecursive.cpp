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
			int height(emp *root);
			}*root, *st[100];
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
			cout<<"do you want to add more emp(yes=1or no=0)"<<endl;
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
			cout<<"Where want to insert employee information Left(L) or Right(R) of id="<<root->id;
			cin>>chr;
			if(chr=='L' || chr=='l')
			{
				if(root-> lc==NULL)
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
			int top=-1;
			emp *temp;
			temp=root;

			if(root!=NULL)
			{
				do
				{
					while(temp!=NULL)
					{
						top++;
						st[top]=temp;
						temp=temp->lc;
					}
					if(top!=-1)
					{
						temp=st[top];
						top--;

						cout<<"\n"<<temp->id<<"\t"<<temp->name<<"\t\t"<<temp->add;
						temp=temp->rc;
					}
				}while(top!=-1 || temp!=NULL);
			}
		}
		int emp:: height(emp * root)
		{
			 int lht, rht,fht;
				if(root== NULL)
				{
				    return 0;
			     }
				else
				{
					lht= height(root->lc);
					 rht= height(root->rc);
					  if(lht>rht)
					  {
					  
						  fht=lht+1;
					  }
					  else
					  {
						  fht= rht+1;
					  }
		            }
			 return fht;
		    
		 }
				      
int main()
{
   
			int  choice;
			emp e;
			do
			{
				cout<<"\n 1.Accept data"<<endl;
				cout<<"2.Display data"<<endl;
				cout<<"3.height of the tree"<<endl;
				cout<<"4.Exit"<<endl;
				cout<<"enter ur choice"<<endl;
				cin>>choice;
				switch(choice)
				{
				case  1: 
				e.create();
				break;
				case 2:
				e.display(root);
				break;
				case 3:
				cout<<"Heigth of the tree"<<e.height(root);
				break;
				case  4: 
				cout<<"exit";
			}
			}while(choice !=4);
		
}

