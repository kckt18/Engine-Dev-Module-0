#include <bits/stdc++.h>
using namespace std;
//blue print through which we can create objects == classes
class Phone {
    public:
        string name;
        string company;
        int year = 2026;
        int RAM = 8;
        int storage = 256;

        void photoTake() {
            cout << "Photo Captured." << endl;
        }
        void deleted() {
            cout << "Content Deleted." << endl;
        }
};
int main () {
    Phone Phone1;
    Phone1.name = "Samsung A56";
    Phone1.company = "Samsung";
    
    cout << Phone1.name << Phone1.storage << endl;
    Phone1.photoTake();
    Phone1.deleted();

}