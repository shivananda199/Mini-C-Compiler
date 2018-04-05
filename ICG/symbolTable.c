#include<stdio.h>
#include<string.h>
struct sym
{
	int sno;
	char token[100];
	int type[100];
	int paratype[100];
	int tn;
	int pn;
	float fvalue;
	int index;
	int scope;
}st[100];
int n=0,arr[10];
float t[100];
int iter=0;
int returntype_func(int ct)
{
	return arr[ct-1];
}
void storereturn( int ct, int returntype )
{
	arr[ct] = returntype;
	return;
}
void insertscope(char *a,int s)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(a,st[i].token))
		{
			st[i].scope=s;
			break;
		}
	}
}
int returnscope(char *a,int cs)
{
	int i;
	int max = 0;
	for(i=0;i<=n;i++)
	{
		if(!(strcmp(a,st[i].token)) && cs>=st[i].scope)
		{
			if(st[i].scope>=max)
				max = st[i].scope;
		}
	}
	return max;
}
int lookup(char *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if( !strcmp( a, st[i].token) )
			return 0;
	}
	return 1;
}
int returntype(char *a,int sct)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && st[i].scope==sct)
		{
			return st[i].type[0];
		}
	}
}

int returntypef(char *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(a,st[i].token))
			{ return st[i].type[1];}
	}
}

int returntype2(char *a,int sct)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(a,st[i].token) && st[i].scope==sct)
			{ return st[i].type[1];}
	}
}

void check_scope_update(char *a,char *b,int sc)
{
	int i,j,k;
	int max=0;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token)   && sc>=st[i].scope)
		{
			if(st[i].scope>=max)
				max=st[i].scope;
		}
	}
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token)   && max==st[i].scope)
		{
			float temp=atof(b);
			for(k=0;k<st[i].tn;k++)
			{
				if(st[i].type[k]==258)
					st[i].fvalue=(int)temp;
				else
					st[i].fvalue=temp;
			}
		}
	}
}
void storevalue(char *a,char *b,int s_c)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && s_c==st[i].scope)
		{
			st[i].fvalue=atof(b);
		}
	}
}

void insert(char *name, int type)
{
	int i;
	if(lookup(name))
	{
		strcpy(st[n].token,name);
		st[n].tn=1;
		st[n].type[st[n].tn-1]=type;
		//st[n].addr=addr;
		st[n].sno=n+1;
		n++;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(!strcmp(name,st[i].token))
			{
				st[i].tn++;
				st[i].type[st[i].tn-1]=type;
				break;
			}
		}
	}
	return;
}

void insertp(char *name,int type)
{
 	int i;
 	for(i=0;i<n;i++)
 	{
  		if(!strcmp(name,st[i].token))
  		{
   			st[i].pn++;
   			st[i].paratype[st[i].pn-1]=type;
   			break;
  		}
 	}
}

void insert_index(char *name,int ind)
{
 	int i;
 	for(i=0;i<n;i++)
 	{
  		if(!strcmp(name,st[i].token) && st[i].type[0]==273)
  		{
   			st[i].index = atoi(ind);
  		}
	}
}

void insert_by_scope(char *name, int type, int s_c)
{
 	int i;
	for(i=0;i<n;i++)
 	{
  		if(!strcmp(name,st[i].token) && st[i].scope==s_c)
  		{
   			st[i].tn++;
   			st[i].type[st[i].tn-1]=type;
  		}
 	}
}

int checkp(char *name,int flist,int c)
{
 	int i,j;
 	for(i=0;i<n;i++)
 	{
  		if(!strcmp(name,st[i].token))
  		{
    			if(st[i].paratype[c]!=flist)
    			return 1;
  		}
 	}
 	return 0;
}

void insert_dup(char *name, int type, int s_c)
{
	strcpy(st[n].token,name);
	st[n].tn=1;
	st[n].type[st[n].tn-1]=type;
	//st[n].addr=addr;
	st[n].sno=n+1;
	st[n].scope=s_c;
	n++;
	return;
}

void print()
{
	int i,j;
	printf("\n------------------------------Symbol Table-----------------------------\n");
	printf("-----------------------------------------------------------------------\n");
	printf("\nSNo.\tToken\t\tValue\t\tScope\t\tType\n");
	printf("-----------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		if(st[i].type[0]==258)
			printf("%d\t%s\t\t%d\t\t%d\t",st[i].sno,st[i].token,(int)st[i].fvalue,st[i].scope);
		else
			printf("%d\t%s\t\t%.1f\t\t%d\t",st[i].sno,st[i].token,st[i].fvalue,st[i].scope);
			printf("\t");
		for(j=0;j<st[i].tn;j++)
		{
			if(st[i].type[j]==258)
				printf("INT");
			else if(st[i].type[j]==259)
				printf("FLOAT");
			else if(st[i].type[j]==271)
				printf("FUNCTION");
			else if(st[i].type[j]==269)
				printf("ARRAY");
			else if(st[i].type[j]==260)
				printf("VOID");
			if(st[i].tn>1 && j<(st[i].tn-1))printf(" - ");
		}
		printf("\n");
	}
	printf("-----------------------------------------------------------------------\n\n");
	return;
}
