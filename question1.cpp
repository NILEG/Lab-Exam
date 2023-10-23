#include<iostream>
using namespace std;
struct info
{
	string name;
	int id;
	info *link=NULL;
} *top=NULL, *temp_search=NULL;
int *ptr;
void push(info *&head, string name, int id);
void add(string name);
void search(int id);
int get_last_id();
void stack_to_array();
void display();
int len();
void peek();
void pop(info *&head);
void push(info *&head, string name, int id)
{
	struct info *temp=new info();
	temp->name=name;
	temp->id=id;
	temp->link=head;
	head=temp;
}
void add(string name)
{
	int id=get_last_id()+1;
	push(top, name, id);
}
void pop(info *&head)
{
	info *temp=head;
	head=head->link;
	delete(temp);
}
void search(int id)
{
	if(id>get_last_id())
	{
		cout<<"Not Exist"<<endl;
	}
	else
	{
		while(id != top->id && top!=NULL)
		{
			push(temp_search, top->name, top->id);
			pop(top);
		}
		if(top !=NULL)
		{
			cout<<"Found"<<endl;
		}
		else
		{
			cout<<"Invalid ID"<<endl;
		}
		while(temp_search != NULL)
		{
			push(top, temp_search->name, temp_search->id);
			pop(temp_search);
		}
	}
}
int get_last_id()
{
	if(top != NULL)
	{
		return top->id;
	}
	else
	{
		return -1;
	}
}
void peek()
{
	if(top != NULL)
	{
		cout<<top->id<<endl;
	}
}
void stack_to_array()
{
	int arr[len()];
	int count=0;
	struct info *q=top;
	while(q != NULL)
	{
		arr[count]=q->id;
		count++;
		q=q->link;
	}
	while(count != 0)
	{
		cout<<arr[count-1]<<endl;
		count--;
	}
}
int len()
{
	int counter=0;
	struct info *q=top;
	while(q != NULL)
	{
		q=q->link;
		counter++;
	}
	return counter;
}
void display()
{
	struct info *q=top;
	while(q != NULL)
	{
		cout<<q->name<<" : "<<q->id<<endl;
		q=q->link;
	}
}
int main()
{
	add("App 1");
	add("App 2");
	add("App 3");
	add("App 4");
	add("App 5");
	peek();
	search(0);
	display();
	cout<<"Array Ids"<<endl;
	stack_to_array();
	return 0;
}