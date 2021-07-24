namespace tst {

    static int partition(int* arr, int lo, int hi) {
        int pivot = arr[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (arr[j] < pivot) {
                int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
                i++;
            }
        }
        int t = arr[i]; arr[i] = arr[hi]; arr[hi] = t;
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
                    int t = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = t;
                }
            }
        }
    }

}
