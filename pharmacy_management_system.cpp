#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    string name;
    int quantity;
    int threshold;

    Product(string n, int temp, int t) {
        name = n;
        quantity = temp;
        threshold = t;
    }

    void restock(int q) {
        quantity += q;
    }

    bool needsRestock() {
        return (quantity < threshold);
    }
};

class Customer {
public:
    string name;
    string address;
    string prescription;

    Customer(string n, string a, string p) {
        name = n;
        address = a;
        prescription = p;
    }
};

class Prescription {
public:
    string drugname;
    string dosage;
    int quantity;

    Prescription(string n, string d, int q) {
        drugname = n;
        dosage = d;
        quantity = q;
    }
};

class Sales {
public:
    string productname;
    int quantity;
    float price;
    string paymentmethod;

    Sales(string n, int q, float p, string m) {
        productname = n;
        quantity = q;
        price = p;
        paymentmethod = m;
    }

    float gettotal() {
        return quantity * price;
    }
};

int main() {
    string prodn;
    int pt;
    int ptt;

    cout << "Enter the product name to check availability of stock: ";
    cin >> prodn;
    cout << "Enter the quantity of the product: ";
    cin >> pt;
    cout << "Enter the threshold value: ";
    cin >> ptt;

    Product product(prodn, pt, ptt);

    if (product.needsRestock()) {
        cout << product.name << " needs restocking." << endl;
        product.restock(10);
        cout << "Restocked. New quantity: " << product.quantity << endl;
    } else {
        cout << product.name << " does not need restocking." << endl;
    }

    string cname, cadd, cpres;
    cout << "Enter the following customer details:" << endl;
    cout << "Enter the customer name: ";
    cin >> cname;
    cout << "Enter the customer address: ";
    cin >> cadd;
    cout << "Enter the customer prescription: ";
    cin >> cpres;

    string dname, dosage;
    int quan;
    cout << "Enter the drug name: ";
    cin >> dname;
    cout << "Enter the dosage needed (mg): ";
    cin >> dosage;
    cout << "Enter the quantity of the drug (number): ";
    cin >> quan;

    string pname, paymethod;
    int salequan;
    float saleprice;

    cout << "Enter the details for the bill" << endl;
    cout << "Enter the sale product name: ";
    cin >> pname;
    cout << "Enter the quantity (number): ";
    cin >> salequan;
    cout << "Enter the sale price of one tablet (float): ";
    cin >> saleprice;
    cout << "Enter the payment method (Credit Card, UPI etc): ";
    cin >> paymethod;

    Sales sale(pname, salequan, saleprice, paymethod);

    cout << "Total cost of sale: $" << sale.gettotal() << endl;

    return 0;
}
