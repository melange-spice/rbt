#pragma once
#include <iostream>
#include "rbt.h"
using namespace std;

class menu
{
    void menu_options();
    int raw_input(const char *prompt);
    int menu_input(const char *prompt);

public:
    menu(rbt *rbt_tree);
    ~menu();
};

// take menu input choice from the user
int menu::menu_input(const char *prompt)
{

    int raw_inp = raw_input(prompt);

    while (raw_inp < 1 || raw_inp > 7)
    {
        cout << "Invalid menu choice\n";
        raw_inp = raw_input(prompt);
    }

    return raw_inp;
}

// take a valid integer from the user
int menu::raw_input(const char *prompt)
{

    int x = 0;

inp:
    cout << prompt;
    cin >> x;

    if (!cin)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invaild input\n";

        goto inp;
    }

    return x;
}

void menu::menu_options()
{

    cout << "1) Insert value into RBT\n";
    cout << "2) Display preorder\n";
    cout << "3) Display inorder\n";
    cout << "4) Display postorder\n";
    cout << "5) Search value\n";
    cout << "6) Delete value\n";
    cout << "7) Quit\n";
}

menu::menu(rbt *rbt_tree)
{
    int choice = 0;

    while (true)
    {
        menu_options();
        choice = menu_input("\n>");

        if (choice == 1)
        {
            int to_insert = raw_input("Enter value to insert: ");
            rbt_tree->insert(to_insert);
        }
        else if (choice == 2)
        {
            rbt_tree->preorder();
        }
        else if (choice == 3)
        {
            rbt_tree->inorder();
        }
        else if (choice == 4)
        {
            rbt_tree->postorder();
        }
        else if (choice == 5)
        {
            int to_search = raw_input("Enter value to search: ");
            Node *ptr = rbt_tree->search(to_search);

            if (ptr == nullptr)
            {
                cout << "value not found in the RBT\n";
            }
            else
            {
                cout << "value found: " << ptr->data << "\t" << ptr->color << "\t" << ptr->counter<<"\n";
            }
        }
        else if (choice == 6)
        {
            int to_delete = raw_input("Enter value to delete: ");
            bool status = rbt_tree->deletenode(to_delete);

            if (status == true)
            {
                cout << "Value successfully deleted from the RBT\n";
            }
            else
            {
                cout << "Value not found in the RBT\n";
            }
        }
        else if (choice == 7)
        {
            break;
        }

        //clear the screen
        system("pause");
        system("cls");
    }
}

menu::~menu()
{
}
