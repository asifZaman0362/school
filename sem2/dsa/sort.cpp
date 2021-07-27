namespace tst {

    template<typename T>
    static inline void swap(T* a, T* b) {
        T c = *a;
        *a = *b;
        *b = c;
    }

    static int partition(int* arr, int lo, int hi) {
        int pivot = arr[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (arr[j] < pivot) {
                swap(arr+i, arr+j);
                i++;
            }
        }
        swap(arr+i, arr+hi);
        return i;
    }

    void qsort(int* arr, int lo, int hi) {
        if (lo < hi) {
            int p = partition(arr, lo, hi);
            qsort(arr, lo, p - 1);
            qsort(arr, p + 1, hi);
        }
    }

    void bsort(int* arr, int n) {
        for (int i = 1; i < n-1; i++) {
            for (int j = 0; j < n - i; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr+j, arr+j+1);
                }
            }
        }
    }

    void ssort(int* arr, int n) {
        int i = 0;
        while (i < n-1) {
            int sel = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[sel]) sel = j;
            }
            if (sel != i)
                swap(arr+sel, arr+i);
            i++;
        }
    }


}
