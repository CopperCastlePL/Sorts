#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <chrono>

using namespace std;

void print_array(int* Array, int size)
{
    for (int i = 0; i < size; i++)
        cout << *Array + i << " ";
}

void print_vector(vector<int> Vector) {
    
    for (int i = 0; i < Vector.size(); i++)
        cout << Vector[i] << " ";
    cout << endl;
}


int main()
{
    vector<int> myVector { 0,1,2,3,4,5,6,7,8,9 };
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(myVector.begin(), myVector.end(), default_random_engine(seed));
    print_vector(myVector);


    for (int i = 0; i < myVector.size(); i++)
    {
        for (int j = i+1; j < myVector.size(); j++)
        {
            if (myVector[i] > myVector[j])
                swap(myVector[i], myVector[j]);
        }
    }

    print_vector(myVector);
}