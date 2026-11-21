#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

struct Product
{
    string name;
    int quantity;
    double price;
};

int main()
{
    vector<Product> inventory;
    list<string> restockList;

    int n;

    cout << "Enter number of products: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        Product p;

        cout << "\nEnter product name: ";
        getline(cin, p.name);

        cout << "Enter quantity: ";
        cin >> p.quantity;

        cout << "Enter price: ";
        cin >> p.price;
        cin.ignore();

        inventory.push_back(p);

        if (p.quantity <= 5)
        {
            restockList.push_back(p.name);
        }
    }

    cout << "\n--- Complete Inventory ---\n";

    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "Product: " << inventory[i].name << endl;
        cout << "Quantity: " << inventory[i].quantity << endl;
        cout << "Price: Rs. " << inventory[i].price << endl;
        cout << endl;
    }

    cout << "--- Products Requiring Restocking ---\n";

    if (restockList.empty())
    {
        cout << "No products require restocking.\n";
    }
    else
    {
        list<string>::iterator it;

        for (it = restockList.begin();
             it != restockList.end(); ++it)
        {
            cout << *it << endl;
        }
    }

    return 0;
}
