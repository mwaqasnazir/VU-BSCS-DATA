/*
Assignment 1
VUID: Bc190404195
Name: Muhammad Waqas Nazir

*/


#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
	public :
		string st_id;
		string f_name;
		string l_name;
		int marks;
		Node *nextNode;
		
		Node()
		{
			st_id="";
			f_name="";
			l_name="";
			marks=0;
		}
		
		Node(string id, string f_nm, string l_nm, int mrk)
		{
			st_id=id;
			f_name=f_nm;
			l_name=l_nm;
			marks=mrk;
		}
		
		void setVUID(string id)
		{
			st_id=id;
		}
		void setMarks(int m)
		{
			marks=m;
		}
		void setFName(string f_n)
		{
			f_name=f_n;
		}
		void set_LName(string l_n)
		{
			l_name=l_n;
		}
		
		int getMarks() 
		{ 
			return marks; 
		}
		string getSTID()
		{
			return st_id;
		}
		string getFName()
		{
			return f_name;
		}
		string getLName()
		{
			return l_name;
		}
};

class Student_List
{
	private :
		Node * headNode;		
	public :
		Student_List()
		{
			headNode = NULL;
		}
		
		void add_student(Node **head, Node* newNode)
		{
			Node* currentNode;
			if(*head == NULL || (*head)->marks <= newNode->marks)
			{
				newNode->nextNode = *head;
				*head=newNode;
			}
			else
			{
				currentNode = *head;
				while(currentNode->nextNode != NULL && currentNode->nextNode->marks > newNode->marks)
				{
					currentNode=currentNode->nextNode;
				}
				newNode->nextNode=currentNode->nextNode;
				currentNode->nextNode=newNode;
			}
		}
		
		void new_Node()
		{
			string id;
			string f_nm;
			string l_nm;
			int mrk;
			cout<<"Enter VU ID : ";
			cin>>id;
			cout<<"Enter Marks: ";
			cin>>mrk;
			cout<<"Enter First Name : ";
			cin>>f_nm;
			cout<<"Enter Last Name : ";
			cin>>l_nm;
			
			Node* newNode= new Node(id,f_nm,l_nm,mrk);
		
			newNode->nextNode=NULL;
			add_student(&headNode, newNode);
		}
		
		void display_Student()
		{
			Node* node1 = headNode;
			if(node1==NULL)
			{
				cout<<"No Student Entered Yet "<<endl;	
			}
			else
			{
				while(node1!=NULL)
				{
					cout<<"\n\nVU ID : "<<node1->getSTID();
					cout<<"\nMarks: "<<node1->getMarks();
					cout<<"\nFirst Name : "<<node1->getFName();
					cout<<"\nLast Name : "<<node1->getLName()<<endl;
					node1=node1->nextNode;
				}
			}
		}
};


main()
{
	Student_List * list = new Student_List();
	bool close=1;
	int check=0;
	do
	{
		cout<<"\n1. To Add New Student in Ranking";
		cout<<"\n2. To Display Ranking";
		cout<<"\n3. To Close";
		cout<<"\n\nEnter Your Choice (1, 2 or 3) : ";
		cin>>check;
		
		if(check==1)
		{
			list->new_Node();
		}
		else if(check==2)
		{
			cout<<"\nRanking Chart\n";
			list->display_Student();
		}
		if(check==3)
		{
			close=0;
		
		}
		
	}while(close);
}

