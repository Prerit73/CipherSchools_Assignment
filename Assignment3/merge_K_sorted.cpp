#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        Node(0);
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *mergeK(Node *arr[], int k)
{

    for (int i = 1; i <= k; i++)
    {
        while (true)
        {
            Node *head_0 = arr[0];
            Node *head_i = arr[i];

            if (head_i == NULL)
                break;

            if (head_0->data >= head_i->data)
            {
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
            }
            else
            {
                while (head_0->next != NULL)
                {
                    if (head_0->next->data >= head_i->data)
                    {
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }

                    head_0 = head_0->next;

                    if (head_0->next == NULL)
                    {
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_0->next = head_i;
                        head_0->next->next = NULL;
                        break;
                    }
                }
            }
        }
    }
    return arr[0];
}
int main()
{
    int k = 3;

    int n = 4;

    Node *arr[k];

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    Node *newhead = mergeK(arr, k - 1);
    print(newhead);
}
