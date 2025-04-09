#include<iostream>
using namespace std;
class graph
{
	int v,fuel;
	string city;
	graph *next;
	public:
	void create();
	void addedge();
	void display();
}*Head[10];
	void graph::create()
	{
		cout<<"how many no of citites you want to enter"<<endl;
		cin>>v;
		cout<<"Enter city"<<endl;
		
		for(int i=0;i<v;i++)
		{
			Head[i]=new graph;
	
			cin>>Head[i]->city;
			Head[i]->next=NULL;
		}
		
	}
	void graph::addedge()
	{
		int e,j;
		string src,dest;
		graph *n1,*temp;
		cout<<"Enter edges"<<endl;
		cin>>e;
		for(int i=0;i<e;i++)
		{
			cout<<"Enter the  source and destination of city"<<endl;
			cin>>src>>dest;
			for(j=0;j<v;j++)
			{
				if(Head[j]->city==src)
				{
					break;
				}
			}
			n1=new graph;
			n1->city=dest;
			cout<<"Enter fuel"<<endl;
			cin>>n1->fuel;
			n1->next=NULL;
			temp=Head[j];
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}	
			
			temp->next=n1;
			
			
		}
	}
	void graph::display()
	{
			graph *temp;
			for(int i=0;i<v;i++)
			{
				temp=Head[i];
				while(temp!=NULL)
				{
					cout<<" "<<temp->city<<" -> "<<temp->fuel<<"->";
					temp=temp->next;
				}
				cout<<"null \n";
			}
	}
	
	
	int main()
	{
		graph g;
		int ch;
		do
		{
			cout<<"-----Menu-----"<<endl;
			cout<<"1.Accept the  data"<<endl;
			cout<<"2.Add edges"<<endl;
			cout<<"3.Display the data"<<endl;
			cout<<"4.Exit"<<endl;
			cout<<"Enter ur choice"<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1:
				g.create();
				break;
				case 2:
				g.addedge();
				break;
				case 3:
		          g.display();
		          break;
		          case 4:
		          cout<<"exit"<<endl;
		       }
		 }while(ch!=4);
		return 0;

	}
	
	
	
