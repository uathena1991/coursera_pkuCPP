#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    // define copy function (which double the value of v)
    Sample(const Sample &c){
        v = 2*c.v;
        //        cout <<"copy constructor called"<< endl;
    }
    
    
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}
