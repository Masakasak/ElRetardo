#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
struct MobilePhone {
    double weight;
    bool is_broken;
    double price;
};
 
string bool_cast(const bool b) {
    ostringstream ss;
    ss << boolalpha << b;
    return ss.str();
}
 
int main() {
    int count;
    cin >> count;
 
    struct MobilePhone data[count];
 
    for(int i = 0; i < count; i++) {
        double weight;
        bool is_broken;
        double price;
 
        cin >> weight;
        cin >> is_broken;
        cin >> price;
 
        MobilePhone phone;
        phone.weight = weight;
        phone.is_broken = is_broken;
        phone.price = price;
        data[i] = phone;
    }
 
    cout << "<MobilePhones>" << endl;
    for(int i = 0; i < count; i++) {
        MobilePhone element = data[i];
        string output = "\t<MobilePhone id='" + to_string(i) + "' weight='" + to_string(element.weight) + "' is_broken='" + bool_cast(element.is_broken) + "' price='" + to_string(element.price) + "'/>";
        cout << output << endl;
    }
    cout << "</MobilePhones>" << endl;
 
 
    return 0;
}