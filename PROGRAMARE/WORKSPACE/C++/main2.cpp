#include <iostream>
using namespace std;

struct Nod
{
    int info;
    Nod *leg;
};

// Function to create a linked list from an array
Nod *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;

    Nod *head = new Nod;
    head->info = arr[0];
    head->leg = nullptr;

    Nod *current = head;
    for (int i = 1; i < n; i++)
    {
        Nod *newNod = new Nod;
        newNod->info = arr[i];
        newNod->leg = nullptr;
        current->leg = newNod;
        current = newNod;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(Nod *head)
{
    Nod *current = head;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->leg;
    }
    cout << endl;
}

// Function to generate descending list
void FLsiDesc(Nod *head)
{
    if (!head)
        return;

    int n = head->info;
    Nod *current = head;

    while (n > 0)
    {
        n -= 1;

        if (current->leg == nullptr)
        {
            Nod *newNod = new Nod;
            newNod->info = n;
            newNod->leg = nullptr;
            current->leg = newNod;
            current = newNod;
        }
        else if (current->leg->info != n)
        {
            Nod *newNod = new Nod;
            newNod->info = n;
            newNod->leg = current->leg;
            current->leg = newNod;
            current = newNod;
        }
        else
        {
            current = current->leg;
        }
    }
}

// Main function to test FLsiDesc
int main()
{
    int arr[] = {5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    Nod *head = createLinkedList(arr, n);
    cout << "Original List: ";
    printLinkedList(head);

    FLsiDesc(head);
    cout << "Modified List: ";
    printLinkedList(head);

    return 0;
}
