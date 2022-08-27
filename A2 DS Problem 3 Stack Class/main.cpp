#include <iostream>
#include<string>
using namespace std;
template<class T>
class Node
{
private:
    T info;
    Node<T>*next;
public:
    Node()
    {
        next=NULL;
    }
    Node(T n,Node<T>*pt=0)
    {
        info=n;
        next=pt;
    }
    Node<T>*getNext()
    {
        return next;
    }
    void setNext(Node<T>*pt)
    {
        next=pt;
    }
    T getInfo()
    {
        return info;
    }
    void setInfo(T n)
    {
        info=n;
    }
};
template<class T>
class myStack
{
private:
    Node<T>*head,*tail;
public:
    myStack()
    {
        head=tail=NULL;
    }
    myStack(T value,int Size)
    {
        head=tail=NULL;
        for(int i=1; i<=Size; i++)
            Push(value);
    }
    void Push(T value)
    {
        Node<T>*myNode;
        myNode=new Node<T>(value,NULL);
        if(head==NULL)
        {
            head=tail=myNode;
        }
        else
        {
            myNode->setNext(tail);
            tail=myNode;
        }
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Error can't pop ,stack is empty"<<endl;
            return -1;
        }
        T deleted;
        if(head==tail)
        {
            deleted=head->getInfo();
            delete tail;
            head=tail=NULL;
        }
        else
        {
            Node<T>*toDelete;
            toDelete=new Node<T>;
            toDelete=tail;
            deleted=toDelete->getInfo();
            tail=toDelete->getNext();
            delete toDelete;
        }
        return deleted;
    }
    T &top(T&var)
    {
        if(head==NULL)
            return var;
        var=tail->getInfo();
        return var;
    }
    void print()
    {
        if(head==NULL)
            cout<<"Stack is empty."<<endl;
        else if(head==tail)
            cout<<head->getInfo()<<endl;
        else
        {
            Node<T>*loop;
            loop=new Node<T>;
            loop=tail;
            while(loop)
            {
                cout<<loop->getInfo()<<" ";
                loop=loop->getNext();
            }
            cout<<endl;
        }
    }
    int mySize()
    {
        if(head==NULL)
            return 0;
        else if(head==tail!=NULL)
            return 1;
        else
        {
            int Size=0;
            Node<T>*loop;
            loop=new Node<T>;
            loop=tail;
            while(loop)
            {
                loop=loop->getNext();
                Size++;
            }
            return Size;
        }

    }
    ~myStack()
    {
        delete(head);
        delete(tail);
    }
};
int main()
{
    myStack<int> s(3,3);
    int t;
    s.Push(100);
    s.Push(200);
    s.Push(300);
    s.Push(400);
    s.print();
    cout<<"Current Size : "<<s.mySize()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.top(t)<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.print();
    cout<<"Current Size : "<<s.mySize()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.top(t)<<endl;
    cout<<endl<<"Now let's try with double "<<endl;
    myStack<double> s2;
    double t2;
    s2.Push(1.1);
    s2.Push(2.2);
    s2.Push(3.3);
    s2.Push(4.44);
    s2.print();
    cout<<"Current Size : "<<s2.mySize()<<endl;
    cout<<s2.isEmpty()<<endl;
    cout<<s2.top(t2)<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    s2.print();
    cout<<"Current Size : "<<s2.mySize()<<endl;
    cout<<s2.isEmpty()<<endl;
    cout<<s2.top(t2)<<endl;
    return 0;
}
