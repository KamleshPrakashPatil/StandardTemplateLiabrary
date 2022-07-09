#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyCLL
{
    private:                    // Characteristics
        struct node <T> * Head;
        struct node <T> * Tail;
        int iCnt;

    public:                     // Behaviours
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

template<class T>
SinglyCLL <T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

template<class T>
void SinglyCLL <T>::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one node
    {
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
}

template<class T>
void SinglyCLL <T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one node
    {
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
}

template<class T>
void SinglyCLL <T>::InsertAtPos(T no, int ipos)
{
    int iSize = Count();

    if((ipos < 1) || (ipos > iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
            struct node<T> * newn = NULL;

            newn = new node<T>;

            newn->data = no;
            newn->next = NULL;

            struct node <T> * temp = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp -> next;
            temp->next = newn;
    }
}

template<class T>
void SinglyCLL <T>::DeleteFirst()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else    // If LL contains more than 1 node
    {
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
    }
}

template<class T>
void SinglyCLL <T>::DeleteLast()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else    // If LL contains more than 1 node
    {
        struct node<T> * temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;

        Tail->next = Head;
    }
}

template<class T>
void SinglyCLL <T>::DeleteAtPos(int ipos)
{
    int iSize = Count();

    if((ipos < 1) || (ipos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
            struct node<T> * temp1 = Head;
            int iCnt = 0;

            for(iCnt = 1; iCnt < ipos-1; iCnt++)
            {
                temp1 = temp1->next;
            }

            struct node<T> * temp2 = temp1->next;

            temp1->next = temp2->next;
            delete temp2;
    }
}

template<class T>
void SinglyCLL <T>::Display()
{
    struct node<T> * temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
}

template<class T>
int SinglyCLL <T>::Count()
{
    int iCnt = 0;
    struct node<T> * temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Head);

    return iCnt;
}
template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class SinglyLL
{
    public:
        struct node <T> *Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn=NULL;
    newn= new node<T>;

    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T> *newn=NULL;
    newn= new node<T>;

    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct node<T> *temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newn;
    }
    Count++;
}

template<class T>
void SinglyLL <T>::Display()
{
    cout<<"Elements from LinkedList are: "<<endl;
    struct node<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

template<class T>
int SinglyLL <T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL <T>::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct node<T> *temp=Head;

        Head=Head->next;

        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL <T>::DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        struct node<T>*temp=Head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp;
        temp=NULL;
    }
    Count--;
}

template<class T>
void SinglyLL <T>::InsertAtPos(T no,int pos)
{
    int size=0;
    size=CountNode();

    if((pos<1)||(pos>(size+1)))
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn=NULL;
        newn= new node<T>;

        newn->data=no;
        newn->next=NULL;

        struct node<T>*temp=Head;

        for(int i=1;i<(pos-1);i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

template<class T>
void SinglyLL <T>::DeleteAtPos(int pos)
{
    int size=CountNode();

    if((pos<1)||(pos>size))
    {
        return;
    }
    else if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==size)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp=Head;
        struct node <T> *tempdelete=NULL;

        for(int i=1;i<(pos-1);i++)
        {
            temp=temp->next;
        }
        tempdelete=temp->next;
        temp->next=tempdelete->next;
        delete tempdelete;

    }
}
template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCLL
{
private:
    struct node <T> * Head;
    struct node <T> * Tail;
    int CountNode;

public:
    DoublyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Count();
    void Display();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head=NULL;
    Tail=NULL;
    CountNode=0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T iNO)
{
    struct node<T> * newn=NULL;
    newn=new node<T>;

    newn->data=iNO;
    newn->next=NULL;
    newn->prev=NULL;

    if(CountNode==0)    //if((Head==NULL)&&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }

    Head->prev=Tail;
    Tail->next=Head;

    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T iNO)
{
    struct node<T> * newn=NULL;
    newn=new node<T>;

    newn->data=iNO;
    newn->next=NULL;
    newn->prev=NULL;

    if(CountNode==0)    //if((Head==NULL)&&(Tail==NULL))
    {
        Head=newn;
        Tail=newn;
    }
    else
    {
        Tail->prev=newn;
        newn->prev=Tail;

        Tail=newn;
    }

    Head->prev=Tail;
    Tail->next=Head;
    
    CountNode++;
}

template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo,int iPos)
{
    if((iPos<1)||(iPos>CountNode+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==CountNode+1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct node<T> * newn=NULL;
        newn=new node <T>;

        newn->data=iNo;
        newn->next=NULL;
        newn->prev=NULL;

        struct node<T> * temp=Head;

        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }

        newn->prev=temp;
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;

        CountNode++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(CountNode==0)
    {
        return ;
    }
    else if(CountNode==1)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Head=Head->next;
        delete(Tail->next);     //delete(Head->prev);
    }

    Tail->next=Head;
    Head->prev=Tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(CountNode==0)
    {
        return ;
    }
    else if(CountNode==1)
    {
        delete Head;
        Head=NULL;
        Tail=NULL;
    }
    else
    {
        Tail=Tail->prev;
        delete (Tail->next);        //delete(Head->prev)
    }

    Tail->next=Head;
    Head->prev=Tail;
    CountNode--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    if((iPos<1)||(iPos>CountNode))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==CountNode)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp=Head;

         for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }

        temp->next=temp->next->next;
        delete(temp->next->prev);
        temp->next->prev=temp;

        CountNode--;
    }
}

template<class T>
void DoublyCLL<T>::Display()
{
    int i=0;
    struct node<T> * temp=Head;

    for(i=1;i<=CountNode;i++)
    {
        cout<<"<-| "<<Head->data<<" |->";
        temp=temp->next;
    }
    cout<<"\n";
}

template<class T>
int DoublyCLL<T>::Count()
{
    return CountNode;
}