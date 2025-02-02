#include <iostream> 
using namespace std;

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int current = array[i];

        for (int j = i - 1; j >= 0; j--) {
            int previus = array[j];

            if (previus > current) {
                swap(array[j + 1], array[j]);
            }

            else break;
        }
    }
}

void showArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {
    int n = 10;
    int array[] = {4, 5, 6, 8, 2, 6, 3, 10, 9, 1};

    cout << "🔴: ";
    showArray(array, n);

    insertionSort(array, n);

    cout << "🟢: ";
    showArray(array, n);


    return 0;
}
