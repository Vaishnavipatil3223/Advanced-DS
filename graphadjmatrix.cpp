#include<iostream>
using namespace std;
class Graph
{
	int vertex;
	string city[10];
	int fuel;
	int adj[100] [100];
	public:
	void accept();
	void display();
};
	void Graph::accept()
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
	void Graph::display()
	{
		cout << "\nMatrix:\n";
		cout << "   ";
    for (int i = 0; i < vertex; i++) {
        cout << city[i] << "  ";
    }
    cout << endl;
		for (int i = 0; i < vertex; i++) {
			cout << city[i] << " "; 
			for (int j = 0; j < vertex; j++)
			{
				
				cout <<" "<< adj[i][j]<<" "; 
			}
			cout << endl;
		}
	}
		
	
	int main()
	{
		Graph g;
		int ch;
		do
		{
			cout<<"-----Menu-----"<<endl;
			cout<<"1.Accept the  data"<<endl;
			cout<<"2.Display the data"<<endl;
			cout<<"3.Exit"<<endl;
			cout<<"Enter ur choice"<<endl;
			cin>>ch;
			switch(ch)
			{
				case 1:
				g.accept();
				break;
				case 2:
		          g.display();
		          break;
		          case 3:
		          cout<<"exit"<<endl;
		       }
		 }while(ch!=3);
		return 0;

	}

