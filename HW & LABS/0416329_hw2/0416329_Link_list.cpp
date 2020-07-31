#include "0416329_Link_List.h"

Link_List::Link_List()
{
    size=0;
}

Link_List::~Link_List()
{

}

Link_List::Link_List(const Link_List &in_link_list) : Link_List()
{
    if (in_link_list.getSize() == 0)
    {
        return;
    }

    Int_Node* iterator;

    for(iterator = in_link_list.head; ; iterator = iterator->next)
    {
        this->insert_node(iterator->value);

        if (iterator == in_link_list.tail)
        {
            break;
        }
    }
}

int Link_List::getSize() const
{
    return this->size;
}


bool Link_List::insert_node(int value)
{
    Int_Node* temp = new Int_Node;
    temp->value = value;

    if (this->size == 0)
    {
        this->head = temp;
        this->tail = temp;
        this->size++;
        return true;
    }
    else
    {
        this->tail->next = temp;
        temp->pre = tail;
        tail = temp;
        this->size++;
        return true;
    }
}

bool Link_List::delete_node()
{
    Int_Node* iterator = tail;

    if (size == 0)
    {
        return false;
    }

    if (size == 1)
    {
        delete iterator;
        size--;
        return true;
    }
    else
    {
        tail = iterator->pre;
        delete iterator;
        size--;
        return true;
    }
}

bool Link_List::insert_node(int index, int value)
{
    Int_Node* temp = new Int_Node;
    temp->value = value;
    Int_Node* iterator = head;

    int i=0;

    for (iterator = head; ; iterator = iterator->next)
    {

        if (index == i)
        {
            temp->next = iterator;

            if (size != 1)
            {
                iterator->pre->next = temp;
                temp->pre = iterator->pre;
            }

            iterator->pre = temp;
            size++;
            return true;
        }
        i++;
    }

    if (index >= size)
    {
        return false;
    }

}

bool Link_List::delete_node(int index)
{
    Int_Node* iterator = head;

    int i=0;

    if (size == 0)
    {
        return false;
    }

    for (iterator = head; ;iterator = iterator->next)
    {

        if (index == i)
        {
            Int_Node* next1 = iterator->next;
            Int_Node* prev1 = iterator->pre;

            if (size == 1)
            {
                delete iterator;
                size--;
                return true;
            }

            if (iterator == head)
            {
                head = iterator->next;
                delete iterator;
                size--;
                return true;
            }

            if (iterator == tail)
            {
                tail = iterator->pre;
                delete iterator;
                size--;
                return true;
            }

            if (iterator != head && iterator != tail && size > 1)
            {

                prev1->next = next1;
                next1->pre = prev1;
                delete iterator;
                size--;
                return true;
            }
        }
        i++;
    }

    if (index >= size)
    {
        return false;
    }
}


ostream &operator<<(ostream & o_stream, const Link_List &link_list1)
{
    Int_Node* iterator = link_list1.head;

    for (iterator = link_list1.head; ; iterator = iterator->next)
    {

        o_stream << iterator->value << "->";
        if (iterator == link_list1.tail)
        {
            break;
        }

    }

    return o_stream;
}

istream &operator>>(istream & i_stream, Link_List &link_list)
{
    int x;
    i_stream >> x;

    link_list.insert_node(x);

    return i_stream;
}

bool Link_List::operator==(const Link_List &link_list) const
{
    Int_Node* iterator1;
    Int_Node* iterator2;

    if (size != link_list.getSize())
    {
        return false;
    }

    for (iterator1 = head, iterator2 = link_list.head; ; iterator1 = iterator1->next, iterator2 = iterator2->next)
    {
        if(iterator1->value != iterator2->value)
        {
            return false;
        }

        if (iterator1 == tail && iterator2 == link_list.tail)
        {
            return true;
        }
    }
}

int& Link_List::operator[](int index)
{
    int i = 0;
    Int_Node* iterator;

    for (iterator = head; ; iterator = iterator->next)
    {
        if (index == i)
        {
            return iterator->value;
        }
        i++;
    }
}

int Link_List::operator[](int index) const
{
    int i = 0;
    Int_Node* iterator;

    for (iterator = head; ; iterator = iterator->next)
    {
        if (index == i)
        {
            return iterator->value;
        }
        i++;
    }
}
