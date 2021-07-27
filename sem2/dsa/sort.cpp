namespace tst {

    template<typename T>
    static inline void swap(T* a, T* b) {
        T c = *a;
        *a = *b;
        *b = c;
    }
    
    template<typename T>
    static int partition(T* arr, int lo, int hi,
            const std::function<bool(T, T)> comp)
    {
        T pivot = arr[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (comp(arr[j], pivot)) {
                swap(arr+i, arr+j);
                i++;
            }
        }
        swap(arr+i, arr+hi);
        return i;
    }

    template<typename T>
    void qsort(T* arr, int lo, int hi,
            const std::function<bool(T, T)> comp)
    {
        if (lo < hi) {
            int p = partition(arr, lo, hi, comp);
            qsort(arr, lo, p - 1, comp);
            qsort(arr, p + 1, hi, comp);
        }
    }

    template<typename T>
    void bsort(T* arr, int n,
            const std::function<bool(T, T)> comp)
    {
        for (int i = 1; i < n-1; i++) {
            for (int j = 0; j < n - i; j++) {
                if (comp(arr[j+1], arr[j])) {
                    swap(arr+j, arr+j+1);
                }
            }
        }
    }

    template<typename T>
    void ssort(T* arr, int n,
            const std::function<bool(T, T)> comp)
    {
        int i = 0;
        while (i < n-1) {
            int sel = i;
            for (int j = i+1; j < n; j++) {
                if (comp(arr[j], arr[sel])) sel = j;
            }
            if (sel != i)
                swap(arr+sel, arr+i);
            i++;
        }
    }

    template<typename T>
        void isort(T* arr, int n,
                const std::function<bool(T, T)> comp) {
            int i = 1;
            while (i < n) {
                int sel = arr[i];
                int j = i - 1;
                while ((j >= 0) && comp(sel, arr[j])) {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = sel;
                i++;
            }
        }


}
