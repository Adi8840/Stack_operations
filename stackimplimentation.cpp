//Stack implimentation;
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void displaystack(struct stack *s);
void createstack(struct stack *s);
void topelement(struct stack *s);
void bottomelement(struct stack *s);
void peakelement(struct stack *s,int i);
int popelement(struct stack *s);
void pushelement(struct stack *s,int value);
struct stack
{
	int *arr;
	int top;
	int size;
};
/*void createstack(struct stack *s)
{
	s->top=-1;
}*/

void topelement(struct stack *s)
{
	int ele;
    if(s->top==-1)
	{
	printf(" :Stack is empty nothing to display\n\n");
	}
		else
	{
		ele=s->arr[s->top];
	printf(" :The topmost element is %d\n\n",ele);	
}
}

void bottomelement(struct stack *s)
{
	int ele;
	if(s->top==-1)
	{
	printf(" :Stack is empty nothing to display\n\n");
	}
	else
	{
    ele=s->arr[0];
    printf(" :The bottommost element is %d\n\n",ele);
}
}
void peakelement(struct stack *s,int i)
{
	int n;
	if(s->top-i+1<0)
	{
	printf(" :Invalid positon\n\n");
	}
	else
	{
   	n=s->arr[s->top-i+1];
   	printf(" :Element at position %d is %d\n\n",i,n);
}
}
void pushelement(struct stack *s,int value)
{
	if(s->top==s->size-1)
	{
		printf(" :Stack is full overflow occurs\n\n");
	}
	else
	{
	s->top=s->top+1;
	s->arr[s->top]=value;
    }
}

int popelement(struct stack *s)
{
	int n;
	if(s->top==-1)
	{
		printf(" :Stack is empty underflow condition occurs\n\n");
		return -1;
	}
	else
	{
	n=s->arr[s->top];
	s->top=s->top-1;
	printf(" :Popped element is %d\n\n",n);
	return(n);
    }
}

void displaystack(struct stack *s)
{
	struct stack *t;
	int i;
	if(s->top==-1)
	{
		printf(" :Stack is empty\n\n");
	}
	else
	{
	printf(" :Elements of array is: ");
    for(i=0;i<=s->top;i++)
	{
	printf("%d ",s->arr[i]);	
	}
	printf("\n\n");
    }
}

int main()
{
	struct stack *s=(struct stack *)malloc(sizeof(struct stack ));
	int choice,n,i,ele;
	printf("Enter the size of stack\n");
    scanf("%d",&n);
	s->size=n;
	s->top=-1;
    //createstack(&s);
	s->arr=(int *)malloc(s->size*sizeof(int));
	while(1)
	{
	printf("Press 1 to push the element in stack\n");
	printf("Press 2 to pop element from the stack\n");
	printf("Press 3 to display the stack elements\n");
	printf("Press 4 to display topmost element\n");
	printf("Press 5 to display bottommost element\n");
	printf("Press 6 to display element at a particular position\n");
	printf("Press 7 to quit from the program\n\n");
	printf(" ::Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
		printf("Enter the value to push element\n");
		scanf("%d",&ele);
		pushelement(s,ele);	
		break;
		}
		case 2:
		{
		popelement(s);	
		break;
		}
		case 3:
		{
		displaystack(s);
		break;
		}
		case 4:
		{
		topelement(s);	
		break;
		}
		case 5:
		{
		bottomelement(s);	
		break;
		}
		case 6:
		{ 
		printf("Enter the position to display the element\n");
		scanf("%d",&i);
    	peakelement(s,i);		
		break;
		}
		case 7:
		{
		exit(0);
		}
		default:
		{
		printf("Invalid input\n");
		}
	}
}
}