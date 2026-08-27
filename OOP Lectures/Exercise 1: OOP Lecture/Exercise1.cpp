#include <iostream>
using namespace std;

bool AscendingCompare(int a, int b) { return a < b; }
bool DescendingCompare(int a, int b) { return a > b; }

int GetSize() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    return n;
}

void InputArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}

int GetElementAt(int arr[], int n, int idx) {
    if (idx < 0 || idx >= n) {
        cout << "Index out of bounds\n";
        return 0;
    }
    return arr[idx];
}

bool EqualByCompare(int a, int b, bool (*comp)(int,int)) {
    return !comp(a, b) && !comp(b, a);
}

void SelectionSort(int arr[], int n, bool (*comp)(int,int)) {
    for (int i = 0; i < n - 1; ++i) {
        int sel = i;
        for (int j = i + 1; j < n; ++j) {
            if (comp(arr[j], arr[sel])) sel = j;
        }
        if (sel != i) {
            int t = arr[i];
            arr[i] = arr[sel];
            arr[sel] = t;
        }
    }
}

void InsertionSort(int arr[], int n, bool (*comp)(int,int)) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && comp(key, arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort(int arr[], int n, bool (*comp)(int,int)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (comp(arr[j + 1], arr[j])) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void QuickSortHelper(int arr[], int l, int r, bool (*comp)(int,int)) {
    int i = l, j = r;
    int pivot = arr[l + (r - l) / 2];
    while (i <= j) {
        while (comp(arr[i], pivot)) ++i;
        while (comp(pivot, arr[j])) --j;
        if (i <= j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            ++i; --j;
        }
    }
    if (l < j) QuickSortHelper(arr, l, j, comp);
    if (i < r) QuickSortHelper(arr, i, r, comp);
}

void QuickSort(int arr[], int n, bool (*comp)(int,int)) {
    if (n > 0) QuickSortHelper(arr, 0, n - 1, comp);
}

void Heapify(int arr[], int start, int end, bool (*comp)(int,int)) {
    auto IsGreater = [comp](int a, int b) { return comp(b, a); };
    int root = start;
    while (true) {
        int child = 2 * root + 1;
        if (child > end) break;
        int swapIdx = root;
        if (IsGreater(arr[child], arr[swapIdx])) swapIdx = child;
        if (child + 1 <= end && IsGreater(arr[child + 1], arr[swapIdx])) swapIdx = child + 1;
        if (swapIdx == root) return;
        int t = arr[root];
        arr[root] = arr[swapIdx];
        arr[swapIdx] = t;
        root = swapIdx;
    }
}

void HeapSort(int arr[], int n, bool (*comp)(int,int)) {
    if (n <= 1) return;
    for (int start = (n - 2) / 2; start >= 0; --start) {
        Heapify(arr, start, n - 1, comp);
        if (start == 0) break;
    }
    for (int end = n - 1; end > 0; --end) {
        int t = arr[end];
        arr[end] = arr[0];
        arr[0] = t;
        Heapify(arr, 0, end - 1, comp);
    }
}

void ShellSort(int arr[], int n, bool (*comp)(int,int)) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && comp(temp, arr[j - gap])) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void CountingSortForRadix(int arr[], int n, int exp, int output[]) {
    int count[10];
    for (int i = 0; i < 10; ++i) count[i] = 0;
    for (int i = 0; i < n; ++i) {
        int digit = (arr[i] / exp) % 10;
        ++count[digit];
    }
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }
    for (int i = 0; i < n; ++i) arr[i] = output[i];
}

void RadixSort(int arr[], int n, bool (*comp)(int,int)) {
    if (n <= 1) return;
    bool ascending = comp(0, 1);
    int negCount = 0;
    for (int i = 0; i < n; ++i) if (arr[i] < 0) ++negCount;
    int posCount = n - negCount;
    int* positives = new int[posCount];
    int* negatives = new int[negCount];
    int pi = 0, ni = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) negatives[ni++] = -arr[i];
        else positives[pi++] = arr[i];
    }
    if (posCount > 0) {
        int maxVal = positives[0];
        for (int i = 1; i < posCount; ++i) if (positives[i] > maxVal) maxVal = positives[i];
        int* output = new int[posCount];
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            CountingSortForRadix(positives, posCount, exp, output);
        }
        delete[] output;
    }
    if (negCount > 0) {
        int maxVal = negatives[0];
        for (int i = 1; i < negCount; ++i) if (negatives[i] > maxVal) maxVal = negatives[i];
        int* output = new int[negCount];
        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            CountingSortForRadix(negatives, negCount, exp, output);
        }
        for (int i = 0; i < negCount; ++i) negatives[i] = -negatives[i];
        for (int i = 0; i < negCount / 2; ++i) {
            int t = negatives[i];
            negatives[i] = negatives[negCount - 1 - i];
            negatives[negCount - 1 - i] = t;
        }
        delete[] output;
    }
    int idx = 0;
    for (int i = 0; i < negCount; ++i) arr[idx++] = negatives[i];
    for (int i = 0; i < posCount; ++i) arr[idx++] = positives[i];
    delete[] positives;
    delete[] negatives;
    if (!ascending) {
        for (int i = 0; i < n / 2; ++i) {
            int t = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = t;
        }
    }
}

int SequentialSearch(int arr[], int n, int key, bool (*comp)(int,int)) {
    for (int i = 0; i < n; ++i) {
        if (EqualByCompare(arr[i], key, comp)) return i;
    }
    return -1;
}

int BinarySearch(int arr[], int n, int key, bool (*comp)(int,int)) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (EqualByCompare(arr[mid], key, comp)) return mid;
        if (comp(key, arr[mid])) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}

int InterpolationSearch(int arr[], int n, int key, bool (*comp)(int,int)) {
    if (n == 0) return -1;
    int lo = 0, hi = n - 1;
    bool ascending = comp(arr[lo], arr[hi]) || (!comp(arr[hi], arr[lo]) && !comp(arr[lo], arr[hi]) && arr[lo] <= arr[hi]);
    while (lo <= hi) {
        if (EqualByCompare(arr[lo], arr[hi], comp)) {
            if (EqualByCompare(arr[lo], key, comp)) return lo;
            else break;
        }
        if (ascending) {
            if (comp(key, arr[lo]) || comp(arr[hi], key)) break;
        } else {
            if (comp(arr[lo], key) || comp(key, arr[hi])) break;
        }
        long long num = (long long)(key - arr[lo]) * (hi - lo);
        long long den = (long long)(arr[hi] - arr[lo]);
        if (den == 0) break;
        int pos = lo + (int)(num / den);
        if (pos < lo || pos > hi) break;
        if (EqualByCompare(arr[pos], key, comp)) return pos;
        if (ascending) {
            if (comp(arr[pos], key)) lo = pos + 1;
            else hi = pos - 1;
        } else {
            if (comp(key, arr[pos])) lo = pos + 1;
            else hi = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n = GetSize();
    if (n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }
    int* arr = new int[n];
    InputArray(arr, n);
    cout << "Original array: ";
    PrintArray(arr, n);
    void (*sortFunc)(int[], int, bool (*)(int,int)) = nullptr;
    int sortChoice = 0;
    cout << "Choose sort: 1=Selection 2=Insertion 3=Bubble 4=Quick 5=Heap 6=Shell 7=Radix\n";
    cin >> sortChoice;
    switch (sortChoice) {
        case 1: sortFunc = SelectionSort; break;
        case 2: sortFunc = InsertionSort; break;
        case 3: sortFunc = BubbleSort; break;
        case 4: sortFunc = QuickSort; break;
        case 5: sortFunc = HeapSort; break;
        case 6: sortFunc = ShellSort; break;
        case 7: sortFunc = RadixSort; break;
        default: sortFunc = QuickSort; break;
    }
    bool (*comp)(int,int) = nullptr;
    int orderChoice = 0;
    cout << "Choose order: 1=Ascending 2=Descending\n";
    cin >> orderChoice;
    comp = (orderChoice == 2) ? DescendingCompare : AscendingCompare;
    int* arrCopy = new int[n];
    for (int i = 0; i < n; ++i) arrCopy[i] = arr[i];
    sortFunc(arrCopy, n, comp);
    cout << "Sorted array: ";
    PrintArray(arrCopy, n);
    int searchChoice = 0;
    cout << "Choose search: 1=Sequential 2=Binary 3=Interpolation\n";
    cin >> searchChoice;
    int (*searchFunc)(int[], int, int, bool (*)(int,int)) = nullptr;
    switch (searchChoice) {
        case 1: searchFunc = SequentialSearch; break;
        case 2: searchFunc = BinarySearch; break;
        case 3: searchFunc = InterpolationSearch; break;
        default: searchFunc = SequentialSearch; break;
    }
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int idx = searchFunc(arrCopy, n, key, comp);
    if (idx >= 0) cout << "Found at index: " << idx << "\n";
    else cout << "Not found\n";
    cout << "Element at index 0 (with boundary check): " << GetElementAt(arrCopy, n, 0) << "\n";
    delete[] arr;
    delete[] arrCopy;
    return 0;
}