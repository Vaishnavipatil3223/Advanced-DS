#include<iostream>
using namespace std;
class emp
{
				int id,salary;
				string name,add;
				emp *lc,*rc;
				public:
				void create();
				void insert(emp *root, emp *next);
				void search(emp *root,int key);
				void display(emp *root);
				void min(emp*root);
				void max(emp*max);
				int height(emp *root);
			
}*root=NULL;
	void emp :: create()
	{
				int ch;
				emp *next;
				if(root==NULL)
				{
				root=new emp;
				cout<<"Enter the emp info"<<endl;
				cout<<"Enter the  emp id"<<endl;
				cin>>root->id;
				cout<<"Enter the  emp name"<<endl;
				cin>>root->name;
				cout<<"Enter the  emp address"<<endl;
				cin>>root->add;
				cout<<"Enter the  emp Salary"<<endl;
				cin>>root->salary;
				root->lc=NULL;
				root->rc=NULL;
				}
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
				cout<<"Enter the  emp salary"<<endl;
				cin>>next->salary;
				next->lc=NULL;
				next->rc=NULL;
				insert(root, next);
		     }
	      }while(ch==1);
	}
	void emp::insert(emp *root,emp *next)
	{
			if(next->salary < root->salary)
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
			else if(next->salary > root->salary)
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
		cout<<"\n"<<root->id<<"\t"<<root->name<<"\t"<<root->add<<"\t"<<root->salary<<"\n";
		display(root->rc);
		}

	}
	void emp:: search(emp* root,int key)
	{
	    
		if(root==NULL)
		{
			cout<<"Employee not found"<<endl;
			return;
		}
     	
			if(root->salary==key)
			{
				cout << "Employee found: " << root->id << " - " << root->name << " - " << root->salary << "\n";
				return;
            }
		    else if(root->salary > key)
			{
				search(root->lc,key);
			}
			else
			{
				search(root->rc,key);
			}	
			
	}
	void emp::min(emp *root)
	{
		emp *current = root;
		if (current == NULL) {
			cout << "No records available.\n";
			return;
		}
		
		while (current->lc != NULL) {
			current = current->lc;
		}
		cout << "Minimum salary record is: ID=" << current->id << " Name=" << current->name << " Salary=" << current->salary << "\n";
	}
	void emp::max(emp *root)
	{
		emp *current = root;
		if (current == NULL) {
			cout << "No records available.\n";
			return;
		}
		
		while (current->rc != NULL) {
			current = current->rc;
		}
		cout << "Maximum salary record is: ID=" << current->id << " Name=" << current->name << " Salary=" << current->salary << "\n";
	}
	

	 
		

int main()
{ 
			
			int  choice;
			emp e;
			do
			{
				cout<<"1.Accept data"<<endl;
				cout<<"2.Display data"<<endl;
				cout<<"3.Search"<<endl;
				cout<<"4.Minimum Salary"<<endl;
				cout<<"5.Maximum Salary"<<endl;
				cout<<"6.Exit"<<endl;
				cout<<"enter ur choice"<<endl;
				cin>>choice;
				switch(choice)
				{
					case  1: 
					e.create();
					break;
					case 2:
					cout<<"\nEmp_id\tEmp_Name\tEmp_address\tEmp_Salary\n";
					e.display(root);
					break;
				     case  3:
					 int key;
				     cout<<"Enter key value"<<endl;
				     cin>>key;
				     e.search(root,key);
				     break;
				     case 4:
				     e.min(root);
					 break;
					 case 5:
					 e.max(root);
					 break;
					 case 6:
					 cout<<"Exit";
					 

			     }
			}while(choice !=6);
return 0;
}

