#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class LinkList{
	private:
		node *head, *tail;
	
	public:
		
	LinkList()
	{
		head=NULL;
		tail=NULL;	
	}		
	
	void inset_start(int element)
	{
		node *temp = new node();
		temp->data = element;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		
		else
		{
			temp->next = head;
			head = temp;
		}
		
	}
	
	void insert_end(int element)
	{
		node *temp = new node();
		temp->data = element;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	
	void insert_pos(int position, int element)
	{
		node *temp = new node();
		temp->data = element;
		node *current = head;
		node *prev = head;
		
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		
		else
		{
			for(int i=0; i<position; i++)
			{
				prev = current;
				current = current->next;
			}
			prev->next = temp;
			temp->next = current;
		}
	}
	
	void display()
	{
		node *temp = head;
		
		
		 while(temp!=NULL)
        {
            if(temp->next!=NULL)
            cout<<temp->data<<" -> ";
            else
            cout<<temp->data;
            
            temp=temp->next; 
        }
        cout<<endl;
	}
	
	void delete_from_front()
	{
		node *temp = head;
		
		if(head != NULL)
		{
			head = temp->next;
			temp = NULL;
		}
	}
	
	void delete_end()
	{
		node *temp = head;
		
		while(temp != NULL)
		{
			node* prev = head;
			
			while(temp->next != NULL)
			{
				prev = temp;
				temp = temp->next;
			}
			
			prev->next = NULL;
			tail = prev;
			temp =NULL;
		}	
	}
	
	void delete_pos(int position)
	{
		node *temp = head;
		node *prev;
		
		for(int i=0; i<position; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = temp->next;
		temp= NULL;
	}
	
	int count()
	{
		int check=0;
		node *temp=head;
		while(temp!=NULL)
		{
			check++;
			temp=temp->next;
		}
		return check;
	}
	
	
	
	
};

	int hash_value(int key, int size, int load)
	{
		if(load<1)
		return key%size;
		if (load>3)
		return key%size;
		
	}


	void HashTable(int data, int load, int size, LinkList *l)
	{
		if(load<1)
		{
			int hash=hash_value(data, size, load);
			l[hash].insert_end(data);	
		}
		if(load<3)
		{
			int hash=hash_value(data, size, load*2);
			l[hash].insert_end(data);	
		}
	
	}


int main()
{
	int n=18;
	LinkList l[n];
	int arr[n]={10, 15, 20, 25, 30, 35, 43, 45, 90, 87, 65, 98, 76, 70, 32, 43, 56, 97};
	int load=18/32; 
	
	for(int i=0; i<n*2 ;i++)
	{
		HashTable(arr[i], load, 18, l);
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<i<<"->";
		l[i].display();
	}
	
}
