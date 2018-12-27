#include <iostream>

using namespace std;
//
struct Node{
    int data;
    Node *next;
};
//
ostream &operator<<(ostream &o, const Node &node){
    o<<node.data;
    return o;
}
//
template<typename T>
void Print(T _begin, T _end){
    // * ++ != need to be overloaded
    for(T p=_begin; p!=_end; ++p){
        cout<<*p<<"  ";      //<< need to be overloaded
    }
    cout<<endl;
}
//
class LinkListIterator{
public:
    LinkListIterator(Node *_p);
    LinkListIterator &operator++();
    bool operator!=(const LinkListIterator &it);
    Node &operator*();

private:
    Node *m_p;
};
//
LinkListIterator::LinkListIterator(Node *p):m_p(p){
    ;
}
//
LinkListIterator &LinkListIterator::operator++(){
    m_p = m_p->next;
    return *this;
}
//
bool LinkListIterator::operator!=(const LinkListIterator &it){
    return m_p != it.m_p;
}
//
Node& LinkListIterator::operator*(){
    return *m_p;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Node n1;
    n1.data = arr[0];
    Node n2;
    n2.data = arr[1];
    Node n3;
    n3.data = arr[2];
    Node n4;
    n4.data = arr[3];
    Node n5;
    n5.data = arr[4];

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    {
        LinkListIterator begin_(&n1);
        LinkListIterator end_(n5.next);
        Print(begin_, end_);
    }

    getchar();
    return 0;
}
