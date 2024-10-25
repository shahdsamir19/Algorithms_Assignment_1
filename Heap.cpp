//
// Created by Shahd Elnassag on 10/20/2024.
//
#include <bits/stdc++.h>

using namespace std;

class Heap {

public:
    vector<int> vec;

    void Heapify(int position) {
        int left = (2 * position) + 1;
        int right = (2 * position) + 2;
        int max = position;

        if (left < vec.size() && vec[left] > vec[max]) {
            max = left;
        }
        if (right < vec.size() && vec[right] > vec[max]) {
            max = right;
        }
        if (max != position) {
            swap(vec[position], vec[max]);
            Heapify(max);
        }
    }

    void BuildMaxHeap(vector<int> input_vec){
        vec = input_vec;
        for (int p = vec.size()/2 - 1; p >=0; p--) {
            Heapify(p);

        }
    }

    bool isEmpty() {
        return vec.empty();
    }

    void Inserting(int element) {
        vec.push_back(element);

        int new_pos = vec.size() - 1;

        while (new_pos > 0) {
            int parent = (new_pos - 1) / 2;

            if (vec[new_pos] > vec[parent]) {
                swap(vec[new_pos], vec[parent]);
                new_pos = parent;
            } else {
                break;
            }
        }

    }

    int extracMax() {

        if (isEmpty()) {
            cout << "OOPS, Heap Empty!\n";
            return -1;
        }


        int maxElement = vec[0];

        vec[0] = vec.back();
        vec.pop_back();
        Heapify(0);

        return maxElement;

    }

    int extracMin() {

        if (isEmpty()) {
            cout << "OOPS, Heap Empty!\n";
            return -1;
        }


        int minIndex = 0;

        for (int pos = 1; pos < vec.size(); pos++) {
            if(vec[pos] < vec[minIndex]){
                minIndex = pos ;
            }
        }

        int minElement = vec[minIndex];

        vec[minIndex] = vec.back();
        vec.pop_back();
        Heapify(minIndex);

        return minElement;

    }




    void PrintHeap() {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " , ";

        }
        cout << "\n";
    }


};

class HeapSort{
public:
    Heap heap;

    void HeapSortFun(vector<int>& vec){

        heap.BuildMaxHeap(vec);

        for (int i = vec.size() - 1; i >= 0; i--) {
            vec[i] = heap.extracMax();
        }
    }
};





class PriorityQueue{
public:
    Heap heap;

    void push(int val){
        heap.Inserting(val);
    }

    int pop(){
        return heap.extracMax();
    }

    void PrintPriorityQueue(){
        heap.PrintHeap();
    }

};




void Menu(){
    cout<<"Welcome to Task 3\n"
          "1.Heap \n"
          "2.Priority Queue\n"
          "3.Heap Sort\n"
          "4.Terminate Program\n";
}

int TestFunction() {
    bool status = true;
    while (status) {
        int choice;
        Menu();
        cout << "Enter Your Choice From above Menu: ";
        cin >> choice;

        Heap testHeap;
        PriorityQueue testPQ;
        HeapSort testHeapSort;
        vector<int>vec1;
        int size;


        switch (choice) {
            case 1:
                cout<<"Enter size of Inserting Numbers:  ";
                cin>>size;
                cout<<"Enter Values of Heap Elements (Insertion) ^_^\n";
                for (int i = 0; i < size; ++i) {
                    int num;
                    cin>>num;
                    testHeap.Inserting(num);
                }
                cout<<"Max Heap Elements: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";
                cout<<"Max Element in Heap: "<<testHeap.extracMax()<<"\n";
                cout<<"Heap Elements After Extracting Max Element: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";
                cout<<"Min Element in Heap: "<<testHeap.extracMin()<<"\n";
                cout<<"Heap Elements After Extracting Min Element: ";
                testHeap.PrintHeap();
                cout<<"-----------------------------------\n";
                break;

            case 2:
                cout<<"Enter size of Inserting Numbers:  ";
                cin>>size;
                cout<<"Enter Values of Priority Queue (Insertion) ^_^\n";
                for (int i = 0; i < size; ++i) {
                    int num;
                    cin>>num;
                    testPQ.push(num);
                }
                cout<<"Priority Queue Elements: ";
                testPQ.PrintPriorityQueue();
                cout<<"-----------------------------------\n";
                cout<<"Priority Element in Priority Queue: "<<testPQ.pop()<<"\n";
                cout<<"Priority Queue Elements After Extracting Priority Element: ";
                testPQ.PrintPriorityQueue();
                cout<<"-----------------------------------\n";
                break;

            case 3:
                cout<<"Enter size of Inserting Numbers:  ";
                cin>>size;
                cout<<"Enter Values of Heap Elements to Sort ^_^\n";
                for (int i = 0; i < size; ++i) {
                    int num;
                    cin>>num;
                    vec1.push_back(num);
                }
                cout<<"Heap Elements Before Sorting: ";
                for (int i = 0; i < size; ++i) {
                    cout<<vec1[i]<<" ,";
                }
                cout<<"\n-----------------------------------\n";
                cout<<"Heap Elements After Sorting : ";
                testHeapSort.HeapSortFun(vec1);
                for (int i = 0; i < size; ++i) {
                    cout<<vec1[i]<<" ,";
                }
                cout<<"\n-----------------------------------\n";
                break;

            case 4:
                cout << "Thank You, See You Later ^_^\n";
                status = false;
                return 0;

            default:
                cout << "Invalid Choice, Press Enter to choose Valid Choice again ^_^:" << endl;

        }
    }
}

int main(){


    TestFunction();


}

