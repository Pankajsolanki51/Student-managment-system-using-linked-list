#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class Node
{
public:
  int roll;
  string name = "";
  float marks, per;
  Node *next_add;
};
class Linked_list
{
public:
  Node *head = NULL;
  void Insert()
  {
    int r;
    string n = "";
    float m;
    cout << "\n\nEnter Roll Number\n";
    cin >> r;
    cout << "\n\nEnter Name \n";
    cin.ignore();
    getline(cin, n);
    cout << "\n\nEnter Marks\n";
    cin >> m;
    Node *new_node = new Node;
    new_node->roll = r;
    new_node->name = n;
    new_node->marks = m;
    new_node->per = (m / 100) * 100;
    new_node->next_add = NULL;
    if (head == NULL)
    {
      head = new_node;
    }
    else
    {
      Node *ptr = head;
      while (ptr->next_add != NULL)
      {
        ptr = ptr->next_add;
      }
      ptr->next_add = new_node;
    }
    cout << "\n\n\nNew Node Created Successfully!!!\n";
  }
  void Search()
  {
    if (head == NULL)
    {
      cout << "\n\nList is Empty !!!\n";
    }
    else
    {
      int r, found = 0;
      cout << "\n\n Enter Roll Number for Seraching\n";
      cin >> r;
      Node *ptr = head;
      while (ptr != NULL)
      {
        if (r == ptr->roll)
        {
          cout << "\n\nRoll No. : " << ptr->roll;
          cout << "\n\nName : " << ptr->name;
          cout << "\n\nMarks : " << ptr->marks;
          cout << "\n\nPercentage % : " << ptr->per;
          found++;
        }
        ptr = ptr->next_add;
      }
      if (found == 0)
      {
        cout << "\n\n****Record not Found****\n";
      }
    }
  }
  void count()
  {
    if (head == NULL)
    {
      cout << "\n\n list is empty\n";
    }
    else
    {
      int c = 0;
      Node *ptr = head;
      while (ptr != NULL)
      {
        c++;
        ptr = ptr->next_add;
      }
      cout << "\n\nTotal Nodes : " << c;
    }
  }
  void Update()
  {
    if (head == NULL)
    {
      cout << "\n\nList is Empty !!!\n";
    }
    else
    {
      int r, found = 0;
      cout << "\n\n Enter Roll Number for Updation\n";
      cin >> r;
      Node *ptr = head;
      while (ptr != NULL)
      {
        if (r == ptr->roll)
        {
          cout << "\n\nEnter New Roll Number\n";
          cin >> ptr->roll;
          cout << "\n\nEnter New Name \n";
          cin.ignore();
          getline(cin, ptr->name);
          cout << "\n\nEnter New Marks\n";
          cin >> ptr->marks;
          ptr->per = ptr->marks / 100 * 100;
          cout << "\n\nUPDATION  SUCESSFULL !!";
           found++;
        }
        ptr = ptr->next_add;
      }
      if (found == 0)
      {
        cout << "\n\n****Record not Found****\n";
      }
    }
  }
  void Del()
  {
    if (head == NULL)
    {
      cout << "\n\nList is Empty !!!\n";
    }
    else
    {
      int r, found = 0;
      cout << "\n\n Enter Roll Number for Deletion\n";
      cin >> r;

      if (r == head->roll)
      {
        Node *ptr = head;
        head = head->next_add;
        cout << "\n\n DELETION SUCESSFULL !!!";
        found++;
        delete ptr;
      }
      else
      {
        Node *pre = head;
        Node *ptr = head->next_add;
        while (ptr != NULL)
        {
          if (r = ptr->roll)
          {
            pre->next_add = ptr->next_add;
            cout << "\n\n DELETION SUCESSFULL !!!";
            found++;

            delete ptr;
            break;
          }
          pre = ptr;
          ptr = ptr->next_add;
        }
      }
      if (found == 0)
      {
        cout << "\n\n Delete Roll No. " << r << "not found...";
      }
    }
  }
  void Show()
  {
    if (head == NULL)
    {
      cout << "\n\nList is Empty !!!\n";
    }
    else
    {
      
      Node *ptr = head;
      while (ptr != NULL)
      {

        cout << "\n\nRoll No. : " << ptr->roll;
        cout << "\n\nName : " << ptr->name;
        cout << "\n\nMarks : " << ptr->marks;
        cout << "\n\nPercentage % : " << ptr->per;

        ptr = ptr->next_add;
      }
    }
  }
};
int main()
{
  Linked_list obj;
  int choice;
p:
  system("cls");
  cout << "\n\n 1. Insert Record ";
  cout << "\n\n 2. Search Record ";
  cout << "\n\n 3. cout Node";
  cout << "\n\n 4. Update Record";
  cout << "\n\n 5. Delete Record";
  cout << "\n\n 6. Show All Record";
  cout << "\n\n 7. EXIT";
  cout << "\n\n******* enter what you wanted to do*******\n";
  cin >> choice;
  switch (choice)
  {
  case 1:
    system("cls");
    obj.Insert();
    break;
  case 2:
    system("cls");
    obj.Search();
    break;
  case 3:
    system("cls");
    obj.count();
    break;
  case 4:
    system("cls");
    obj.Update();
    break;
  case 5:
    system("cls");
    obj.Del();
    break;
  case 6:
    system("cls");
    obj.Show();
    break;

  case 7:
    exit(0);

  default:
    cout << "\n\n Invalid choice.... please try with valid choice";
  }
  getch();
  goto p;
}