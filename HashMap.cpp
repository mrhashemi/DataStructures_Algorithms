#include <cstdio>

template <class T> const T& max (const T& a, const T& b) {
  return (a<b)?b:a;
}

template <class TValue>
class MyHashMap {
public:
    int* keys;
    TValue* values;
    int size;
    //int* collisions;
    int last_filled;
    
    MyHashMap() {
        size = 1000000;
        keys = new int[size]();
        values = new TValue[size]();
        last_filled = 0;
        for (int i=0; i<size; i++){
            values[i] = -1.0;
        }
    }

    ~MyHashMap() {
        delete[] keys;
        delete[] values;
    }
    
    void add(int key, TValue value) {
        int index = key % size;
        keys[index] = key;
        values[index] = value;
      	if (last_filled < index){
        	last_filled = index;
        }
    }
    
    void remove(int key) {
        int index = key % size;
        if (keys[index] > 0){
            values[index] = -1.0;
        }
        else{
            printf("wrong key! \n");
        }
    }
    
    double get(int key) {
        int index = key % size;
        return values[index];
    }
};

int main()
{
    MyHashMap<double>* myobj = new MyHashMap<double>();
    myobj->add(1,6);
    myobj->add(2,7);
    myobj->add(4,3);
    myobj->add(1,2);
    myobj->add(1,16.5);
    myobj->add(5,123);
    myobj->add(3,0.1);
    myobj->remove(4);
    myobj->remove(100);

    for (int i=1; i <= myobj->last_filled; i++){ //
        printf("%f\n", myobj->get(i));
    }

    delete myobj;
    
    return 1;
}
