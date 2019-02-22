#include<iostream>
#include<cstring>
using namespace std;
char str[]="my name is himanshu my name is hetesh my name is himanshu my name is hetesh hi hi hi hello ";

class word
{
public:
char s[50];
int count;
word *next;

};
class hash
{
	public:
		word *head;
		word *tail;
		hash()
		{
			word *a=new word();
			head=a;
			a->next=NULL;
		}
	void addElement(char *x)
	{
		int flag=0;
		word *a;
		for(a=head;a->next!=NULL;a=a->next)
		{
			if(strcmp(a->s,x)==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
		word *b=new word();
		a->next=b;
		//cout<<x;
		strcpy(a->s,x);
		a->count=1;
		//cout<<a->s;
		b->next=NULL;
		}
		else
		{
			a->count++;
		}
	}
	void print()
	{
		word *a;
		for(a=head;a->next!=NULL;a=a->next)
		{
			cout<<a->s<<"  "<<a->count;
			cout<<endl;
		}
	}
};
hash h[256];
void wordSearch()
{
	char word[50];
	int index,i,j,k,flag=0,count=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' '&&flag==0)
		{
			index=i;
			count++;
			flag=1;
		}
		else if(str[i]==' ')
		{
			if(flag==1)
			{
				k=0;
				for(j=index;j<i;j++)
				{
					word[k]=str[j];
					k++;
				}
				word[k]='\0';
	//			cout<<word<<endl;
				h[word[0]].addElement(word);
			}
			flag=0;
		}
	}
	//for(j=0;j<9;j++)
	//{
		//h[97].print();
	//}
	for(j=97;j<124;j++)
	{
	h[j].print();
	cout<<endl;
 	}
}
int main()
{
	wordSearch();
	return 0;
}
