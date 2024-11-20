#include <cstdio>

template <class T> const T& max (const T& a, const T& b) {
  return (a<b)?b:a;     // or: return comp(a,b)?b:a; for version (2)
}

class MyHashSet {
public:
    int* set;
    int size;
    int* collisions;
    int last_filled;
    
    MyHashSet() {
        size = 1000000;
        set = new int[size];
        collisions = new int[size];
        last_filled = 0;
        for (int i=0; i<size; i++){
            collisions[i] = 0;
        }
    }
    
    void add(int key) {
        int index = key % size;
        //int index_max = set[last_filled] % size;
        int index_set = index;
        for (int i=0; i<=index; i++){
            index_set += max(0, collisions[i] -1);
        }
        if (collisions[index] > 0){
            for (int i=last_filled; i>= index_set; i--){
                set[i+1] = set[i];
            }
            last_filled += 1;
        }
        else{
            set[index_set] = key;
            if (index_set > last_filled){
                last_filled = index_set;
            }
        }
        collisions[index] += 1;
    }
    
    void remove(int key) {
        int index = key % size;
        if (collisions[index] > 0){
            int index_set = index;
            for (int i=0; i<=index; i++){
                index_set += max(0, collisions[i] -1);
            }
            for (int i=index_set; i < last_filled; i++){
                set[i] = set[i+1];
            }
            last_filled -= 1;
            collisions[index] -= 1;
        }
        else{
            printf("wrong key! \n");
        }
    }
    
    bool contains(int key) {
        bool contain = false;
        int index = key % size;
        if (collisions[index] > 0){contain = true;}
        return contain;
    }
};

int main()
{
    MyHashSet* myobj = new MyHashSet();
    myobj->add(6);
    myobj->add(2);
    myobj->add(4);
    myobj->add(1);
    myobj->add(1);
    myobj->add(5);
    myobj->add(3);
    myobj->add(1);
    //myobj->add(4);
    //myobj->add(3);
    //myobj->add(12);
    //myobj->add(12);
    //myobj->add(18);
    //bool param_1 = myobj->contains(1);
    //bool param_3 = myobj->contains(3);
    //myobj->add(2);
    //bool param_2 = myobj->contains(2);
    myobj->remove(1);
    //myobj->remove(100);
    //bool param_10 = myobj->contains(2);
    //myobj->add(18);
    //myobj->add(20);
    //myobj->add(1);
    //myobj->add(4);
    
    for (int i=0; i <= myobj->last_filled; i++){ //
        printf("%d\n", myobj->set[i]);
        //printf("%d\n", myobj->collisions[i]);
    }
    
    for (int i=0; i <= (myobj->set[myobj->last_filled] % myobj->size); i++){
        //printf("%d\n", myobj->set[i]);
        printf("%d\n", myobj->collisions[i]);
    }
    
    return 1;
}