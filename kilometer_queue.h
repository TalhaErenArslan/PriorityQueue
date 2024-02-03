#ifndef KILOMETER_QUEUE_H
#define KILOMETER_QUEUE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer 
{
public:
    int kilometer; 
    string address; 
};

class Node
{
public:
    Customer customer;
    Node *next;
};

class KilometerQueue
{
private:
    Node *head;
    string filename;

public:
    KilometerQueue()  : head(nullptr), filename("queue.txt") {} 

    void setFilename(const string &filename)
    {
        this->filename = filename;
    }

   void push_back(int kilometer, const string &address) 
     {
        Node *newNode = new Node;
        newNode->customer.kilometer = kilometer; 
        newNode->customer.address = address; 
        newNode->next = nullptr;

        if (head == nullptr || kilometer < head->customer.kilometer) 
     {
        newNode->next = head;
        head = newNode;
     }
    else
    {
        Node *current = head;
        while (current->next != nullptr && current->next->customer.kilometer <= kilometer) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    }


    Customer front()
    {
        if (head != nullptr)
        {
            return head->customer;
        }
        Customer c;
        c.kilometer = -1; 
        c.address = ""; 
        return c;
    }

    void pop_front()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

   void saveToFile()
    {
    ofstream file(filename);

    if (!file)
    {
        cout << "Dosya Olusmadi." << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        file << current->customer.kilometer << " " << current->customer.address << endl; 
        current = current->next;
    }

    file.close();
   
    }


   void loadFromFile()
    {
    ifstream file(filename);

    if (!file)
    {
        cout << "Dosya bulunamadi." << endl;
        return;
    }

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int kilometer; 
    string address; 
    while (file >> kilometer) 
    {
        file.ignore();
        getline(file, address); 
        push_back(kilometer, address); 
    }

    file.close();
    }

};

#endif
