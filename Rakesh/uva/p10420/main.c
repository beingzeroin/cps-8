#include <stdio.h>
#include <stdlib.h>
typedef struct list List;
List* createNode(char [],List*);
typedef struct output Output;
struct list
{
    char name[75];
    List* next;
};
struct output
{
    char countryname[75];
    int count;
    Output* next;
};
int main()
{
    int n=0,i=0,j=0;
    char a[75];
    List* head=NULL;
    scanf("%d",&n);
    fflush(stdin);
    gets(a);
    head=malloc(sizeof(List));
    for(i=0; a[i]!='\0'; i++)
    {
        head->name[i]=a[i];
    }
    head->next=NULL;
    for(i=1; i<n; i++)
    {
        head=createNode(gets(a),head);
    }
    Output* olist=NULL,*olist_;
    olist=malloc(sizeof(Output));
    olist_=olist;
    while(head!=NULL)
    {
        if(olist==NULL)
        {
            olist=malloc(sizeof(Output));
        }
            j=0;i=0;
            while(head->name[i]==' ') i++;
            for(; head->name[i]!=' '; i++,j++)
            {
                olist->countryname[j]=head->name[i];
            }
            olist->next=NULL;
            olist=olist->next;
            head=head->next;
    }
    for(; olist_!=NULL; olist_=olist_->next)
    {
        puts(olist_->countryname);
    }
    return 0;
}
List* createNode(char a[],List* head)
{
    int i=0;
    List* node=malloc(sizeof(List));
    for(i=0; a[i]!='\0'; i++)
    {
        node->name[i]=a[i];
    }
    node->next=head;
    return node;
}

