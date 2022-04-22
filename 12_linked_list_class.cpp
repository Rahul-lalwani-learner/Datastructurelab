#include <iostream>
using namespace std;

class linklist
{

    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head = NULL;

public:
    void insert(int newdata);
    void insertBeg(int newdata);
    void insertEnd(int newdata);
    void insertPos(int num, int newdata);
    void insertInd(int index, int newdata);
    void replace(int index, int newdata);
    void reverse();
    void deleteEnd();
    void deleteStart();
    void del(int num);
    void display();
};
void linklist::deleteStart()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "linkedlist is Empty" << endl;
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}
void linklist::deleteEnd()
{
    struct node *ptr, *prev;
    if (head == NULL)
    {
        cout << "The linked List is Empty" << endl;
    }
    else if (head->next == NULL)
    {
        ptr = head;
        head = NULL;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
}
void linklist::insert(int newdata)
{
    if (head == NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = newdata;
        new_node->next = head;
        head = new_node;
    }
    else
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = newdata;
        new_node->next = NULL;
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void linklist::insertBeg(int newdata)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = newdata;
    new_node->next = head;
    head = new_node;
}
void linklist::insertEnd(int newdata)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = newdata;
    new_node->next = NULL;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void linklist::insertInd(int index, int newdata)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    struct node *prev = ptr;

    new_node->data = newdata;
    int count = 1;
    while ((count < index) && (ptr != NULL))
    {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }
    if (ptr == NULL)
    {
        cout << "index is overflowing " << endl;
    }
    else
    {

        new_node->next = ptr;
        prev->next = new_node;
    }
}
void linklist::insertPos(int num, int newdata)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = newdata;
    struct node *ptr = head;
    struct node *prev = ptr;
    while (prev->data != newdata)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new_node;
    new_node->next = ptr;
}
void linklist::replace(int index, int newdata)
{
    struct node *ptr = head;
    int count = 1;
    while (count < index)
    {
        ptr = ptr->next;
        count++;
    }
    ptr->data = newdata;
}
void linklist::reverse()
{
    struct node *current, *prev, *nextnode;
    prev = NULL;
    current = nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;

    cout << "Your array is reversed now" << endl;
}
void linklist::display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    else
    {
        cout << "The elements in linked list are: " << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
void linklist::del(int num)
{
    struct node *ptr = head, *prev;
    if (head == NULL)
    {
        cout << "The linked list is empty" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == num)
            {
                break;
            }
            ptr = ptr->next;
        }
        if (ptr == head)
        {
            struct node *temp;
            temp = ptr;
            head = ptr->next;
            free(temp);
        }
        else if (ptr == NULL)
        {
            cout << "Elements NOT FOUND" << endl;
        }
        else
        {
            prev = head;
            while (prev->next != ptr)
            {
                prev = prev->next;
            }
            prev->next = ptr->next;
            struct node *temp;
            temp = ptr;
            free(temp);
        }
    }
}
int main()
{
    linklist rahul, second;
    rahul.insertBeg(1);
    rahul.insertEnd(2);
    rahul.insertEnd(3);
    rahul.insertEnd(4);
    rahul.insertEnd(5);
    rahul.insertEnd(6);
    // rahul.deleteStart();
    // rahul.deleteEnd();
    // rahul.reverse();
    // rahul.del(1);
    // rahul.del(3);
    // rahul.del(5);
    // rahul.insertInd(5,5);
    // rahul.insertPos(2,3);
    // rahul.replace(1,34);
    rahul.display();

    second.insert(12);
    second.insert(13);
    second.display();
    return 0;
}