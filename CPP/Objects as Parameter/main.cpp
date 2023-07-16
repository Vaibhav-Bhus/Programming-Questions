#include <iostream>

using namespace std;

class Weight{
    int kg,gm;
public :
    void getWeight(int x, int y){
        kg = x;
        gm = y;
    }
    void putWeight(){
        cout<<kg<<" Kilo And "<<gm<<" Grams\n";

    }
    void sum(Weight, Weight);
};
void Weight::sum(Weight w1, Weight w2)
{
    gm = w1.gm + w2.gm;
    kg = gm / 1000;
    gm = gm % 1000;
    kg = kg + w1.kg + w2.kg;
}
int main()
{
    Weight W1, W2, W3;
    W1.getWeight(45, 600);
    W2.getWeight(58, 900);
    W3.sum(W1, W2);
    cout<<"W1's Weight = ";
    W1.putWeight();
    cout<<"W2's Weight = ";
    W2.putWeight();
    cout<<"W3's Weight(Sum Of W1 and W2) = ";
    W3.putWeight();
}
