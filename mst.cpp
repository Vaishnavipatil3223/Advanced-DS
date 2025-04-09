#include<iostream>
using namespace std;
class interview
{
	int vertex;
	string city[10];
	int fuel;
	int adj[100] [100];
	public:
	void create();
	void mst();
	void display();
};
	void interview::create()
	{
	cout<<"how many cities you want to enter"<<endl;
	cin>>vertex;
	cout<<"Enter city Name"<<endl;
	for(int i=0;i<vertex;i++)
	{
		cin>>city[i];
	}
	cout<<"Enter fuel"<<endl;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
			if(i==j)
			{
				adj[i][j]=0;
			}
			else
			{
				cout << "Fuel from " << city[i] << " to " << city[j] << ": ";
				cin>>adj[i][j];
			}
		}
	}
}
	void interview::mst()
	{
			
		int u,i,j,min,e;
		int key[10];
		int parent[10];
		bool visited[10];
		for(i=0;i<vertex;i++)
		{
			key[i]=999;
			visited[i]=false;
		}
		key[0]=0;
		parent[0]=-1;
		for(int e=0;e<vertex-1;e++)
		{
			min=999;
			for(int i=0;i<vertex;i++)
			{
					if(!visited[i] && min>key[i])
					{
					min=key[i];
					u=i;
			}
		}
		visited[u]=true;
			for(j=0;j<vertex;j++)
			{
				if(adj[u][j] && !visited[j] && adj[u][j]< key[j])
				{
					key[j]=adj[u][j];
					parent[j]=u;
				}
			}
	}
	}
	void interview::display()
	{
		int key[10],parent[10];
		int sum=0;
		for(int i=0;i<vertex;i++)
		{
			sum=sum + key[i];
		}
		cout<<"sum"<<sum<<endl;
		for(int i=1;i<vertex;i++)
		{
			cout<<city[parent[i]]<<"To"<<city[i]<<"->"<<key[i];
		}
	}
			
	int main()
	{
		interview i;
		int ch;
		do
		{
			cout<<"-----Menu-----"<<endl;
			cout<<"1.Accept the  data"<<endl;
			cout<<"2.minimum spanning tree"<<endl;
			cout<<"3.Exit"<<endl;
			cout<<"Enter ur choice"<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1:
				i.create();
				break;
				case 2:
		          i.mst();
		          i.display();
		          break;
		          case 3:
		          cout<<"exit"<<endl;
		       }
		 }while(ch!=3);
		return 0;

	}

