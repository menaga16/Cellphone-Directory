#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct list add;
struct list
{
  char name[40];
  char num[20];
  char gmail[40];
  char cn[40];
  add* next;
};

int i=1,size=0;

void Insert(add** head)
{
	char name;
	add* temp=(add*)malloc(sizeof(add));
	printf("\n\tContact Name : ");
	scanf("%s",temp->name);
	printf("\n\tMobile Number : ");
	scanf("%s",temp->num);
	printf("\n\tGmail id : ");
	scanf("%s",temp->gmail);
	printf("\n\tcity name : ");
	scanf("%s",temp->cn);
	temp->next = NULL;
	size++;
	if(*head == NULL)
	{
		*head = temp;
		printf("\n\n\t\tDone!!! contact successfully added to your directory\n\n");
		return;
	}
	else
	{
		add* p = *head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
		system("cls");
		printf("\n\t\tDone!!! contact successfully added to your directory \n\n");
	}
	return;
}

void Searchbyname(add*head)
{
	char ch[40];
	system("cls");
	printf("\n\n\n\t\tContact name to search : ");
	scanf("%s",ch);
	if(head == NULL)
	{
		system("cls");
		printf("\n\n\n\t\t No Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
		if(strcmp((p->name),ch) == 0)
			{
				printf("\n\t\t\t contact %s is founded!!!",p->name);
				printf("\n\t\t-------------------------");
				printf("\n\t\tName : %s",p->name);
				printf("\n\t\tNumber : %s",p->num);
				printf("\n\t\tGmail ID : %s",p->gmail);
				printf("\n\t\tcity name : %s\n\n",p->cn);
				return;
			}
			p = p->next;
		}
		printf("\n\n\n\t\tThis Contact is not exists in the list! ");
	}
}

void Searchbynumber(add*head)
{
	char ch[40];
	system("cls");
	printf("\n\n\n\t\tContact number to search : ");
	scanf("%s",ch);
	if(head == NULL)
	{
		system("cls");
		printf("\n\n\n\t\tNo Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
			if(strcmp((p->num),ch) == 0)
			{
				printf("\n\t\t\t contact %s is founded!!!",p->num);
				printf("\n\t\t-------------------------");
				printf("\n\t\tName : %s",p->name);
				printf("\n\t\t number : %s",p->num);
				printf("\n\t\tGmail ID : %s",p->gmail);
				printf("\n\t\tcity name : %s\n\n",p->cn);
				return;
			}
			p = p->next;
		}
	printf("\n\n\n\t\tThis Contact is not exists in the list! ");
	}
}


void Delete(add** head)
{
	char ch[40];
	system("cls");
	printf("\n\t\tContact name to delete: ");
	scanf("%s",ch);
	if(*head == NULL)
	{
		printf("\n\t\t\t\t\tNo Contact exists in this Phone Book List!\n\n");
		return;
	}
	else
	{
		if(strcmp(((*head)->name),ch) == 0)
		{
			add*p=*head;
			*head = (*head)->next;
			free(p);
			printf("\n\t\t\tDone!!! the contact %s is successfully deleted from the directory\n\n\n\n");
			return;
		}
		else
		{
			add*p = *head;
			while(p->next != NULL)
			{
				if(strcmp((p->next->name),ch) == 0)
				{
					p->next = p->next->next;
					size--;
					return;
				}
				p = p->next;
			}
			printf("\n\t\t\tInvalid Contact!!!\n\n");
		}
	}
}

void Searchbycity(add*head)
{
	char ch[40];
	int find=0;
	printf("\n\n\n\t\tEnter City Name to search : ");
	scanf("%s",ch);
	if(head == NULL)
	{
		printf("\n\n\n\t\tNo Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
			if(strcmp((p->cn),ch) == 0)
			{
			printf("\n\t\t\t Contacts in City : %s are founded!!!",p->cn);
			printf("\n\t\t-------------------------");
			printf("\n\t\tName : %s",p->name);
			printf("\n\t\t number : %s",p->num);
			printf("\n\t\tGmail ID : %s",p->gmail);
			printf("\n\t\tcity name : %s\n\n",p->cn);
			find++;
			}
			p = p->next;
		}
		if(find==0)
		{
			printf("\n\n\n\t\tThis Contact is not exists in the list! ");
		}
	}
}


void Display(add* head)
{
	printf("\n\t\tTotal Number of Contacts in the Phone Book: %d",size);
	if(head == NULL)
	{
		printf("\n\n\n\t\tNo Contact exists in this Phone Book List!");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
			printf("\n\t\t\t\t%d.%c%s",i,32,p->name);
			printf("\n\t\t\t-------------------------");
			printf("\n\t\t\tNumber : %s",p->num);
			printf("\n\t\t\tGmail ID : %s",p->gmail);
			printf("\n\t\t\tcity name : %s\n\n",p->cn);
			p = p->next;
			i++;
		}
		i=1;
		return;
	}
}


void updatename(add*head)
{
	char ch[40];
	char chn[40];
	system("cls");
	printf("\n\n\n\t\tContact name : ");
	scanf("%s",ch);
	printf("\n\n\n\t\tenter the name to update :");
	scanf("%s",chn);

	if(head == NULL)
	{
		system("cls");
		printf("\n\n\n\t\t No Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
			if(strcmp((p->name),ch) == 0)
			{
				strcpy((p->name),chn);
				printf("\n\t\t----------UPDATED CONTACT---------------");
				printf("\n\t\tName : %s",p->name);
				printf("\n\t\tNumber : %s",p->num);
				printf("\n\t\tGmail ID : %s",p->gmail);
				printf("\n\t\tcity name : %s\n\n",p->cn);
				return;
			}
			p = p->next;
		}
		printf("\n\n\n\t\tThis Contact is not exists in the list! ");
	}
}


void updatemail(add*head)
{
	char ch[40];
	char chn[40];
	system("cls");
	printf("\n\n\n\t\tContact name : ");
	scanf("%s",ch);
	printf("\n\n\n\t\tenter the Email address to update :");
	scanf("%s",chn);
	
	if(head == NULL)
	{
		system("cls");
		printf("\n\n\n\t\t No Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	else
	{
		add*p = head;
		while(p != NULL)
		{
			if(strcmp((p->name),ch) == 0)
			{
				strcpy((p->gmail),chn);
				printf("\n\t\t----------UPDATED CONTACT---------------");
				printf("\n\t\tName : %s",p->name);
				printf("\n\t\tNumber : %s",p->num);
				printf("\n\t\tGmail ID : %s",p->gmail);
				printf("\n\t\tcity name : %s\n\n",p->cn);
				return;
			}
			p = p->next;
		}
		system("cls");
		printf("\n\n\n\t\tThis Contact is not exists in the list! ");
	}
}


void updatecity(add*head)
{
	char ch[40];
	char chn[40];
	system("cls");
	printf("\n\n\n\t\tContact name : ");
	scanf("%s",ch);
	printf("\n\n\n\t\tenter the City name to update :");
	scanf("%s",chn);

	if(head == NULL)
	{
		system("cls");
		printf("\n\n\n\t\t No Contact exists in this Phone Book List!!!\n\n");
		return;
	}
	
	else
	{
		add*p = head;
		while(p != NULL)
		{
			if(strcmp((p->name),ch) == 0)
			{
				strcpy((p->cn),chn);
				printf("\n\t\t----------UPDATED CONTACT---------------");
				printf("\n\t\tName : %s",p->name);
				printf("\n\t\tNumber : %s",p->num);
				printf("\n\t\tGmail ID : %s",p->gmail);
				printf("\n\t\tcity name : %s\n\n",p->cn);
				return;
			}
			p = p->next;
		}
		system("cls");
		printf("\n\n\n\t\tThis Contact is not exists in the list! ");
	}
}


int main()
{
	add* head=NULL;
	char c[40];
	mainhome:
	system("cls");
	printf("\n\t\t_________________________________________________________________\n");
	
	printf("\n\t\t\t\t\t WELCOME TO OUR PHONE BOOK ");
	
	printf("\n\t\t_________________________________________________________________\n\n\n");
	while(1)
	{
		system("COLOR 75");
		printf("\n\n\t\t\t\t\t\tMenu");
		printf("\n\t\t\t-------------------------------------------------");
		printf("\n\t\t\t1)Create A Contact\t\t\t2)Remove A Contact");
		printf("\n\t\t\t3)Find a contact by number\t\t4)Find A Contact by name");
		printf("\n\t\t\t5)Find A contact by City\t\t6)Update Name");
		printf("\n\t\t\t7)Update Mail\t\t\t\t8)Update City");
		printf("\n\t\t\t9)Show contact list\t\t\t-1)Quit");
		int ch;
		printf("\n\n\t\t\t enter your choice:");
		scanf("%d",&ch);
		if(ch == -1)
		{
			break;
		}
		else
		{
			switch(ch)
			{
				case 1:system("cls");
					Insert(&head);
					break;
				case 2:system("cls");
					Delete(&head);
					break;
				case 3:system("cls");
					Searchbynumber(head);
					break;
				case 4:system("cls");
					Searchbyname(head);
					break;
				case 5:system("cls");
					Searchbycity(head);
					break;
				case 6:system("cls");
					updatename(head);
					break;
				case 7:system("cls");
					updatemail(head);
					break;
				case 8:system("cls");
					updatecity(head);
					break;
				case 9:system("cls");
					Display(head);
					break;
				default :printf("\n\t\tInvalid Choice!Try again!!!");
					break;
			}
		}
	}
}
