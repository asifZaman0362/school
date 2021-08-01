namespace tst {

#define ld const std::function<bool(T, T)>

    template<typename T>
    inline bool check_sorted(T* arr, const int n, ld cmp)
    {
        for (int i = 0; i < n - 1; i++) {
            if (!cmp(arr[i], arr[i+1]))
                return false;
        }
        return true;
    }

    inline int get_half(int a) {
        return (a + a % 2)/2;
    }

    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }

    inline int min(int a, int b)
    {
        return a < b ? a : b;
    }

    template<typename T>
    static inline void swap(T* a, T* b)
    {
        T c = *a;
        *a = *b;
        *b = c;
    }

    template<typename T>
    void merge(T* a, T* b, T* c, T *d, int n, int m, ld cmp)
    {   
        int q_len = 0, q_ptr = 0;
        int i = 0;
        int l = n + m;
        d[0] = a[0];
        for (int k = 0; k < l; k++) {
            if (k < n) d[k] = a[k];
            if ((i < m) && ((q_ptr >= n) || cmp(b[i], d[q_ptr]))) {
                c[k] = b[i++];
            } else {
                c[k] = d[q_ptr];
                q_ptr++;
            }
        }
    }

    template<typename T>
    T* split_merge(T* a, T* b, const int n, ld cmp)
    {
        if (n == 1) return a;
        int h1 = get_half(n);
        int h2 = n - h1;
        int* left = split_merge(a, b, h1, cmp);
        int* right = split_merge(a+h1, b, h2, cmp);
        merge(left, right, a, b, h1, h2, cmp);
        
        return a;
    }

    template<typename T>
    void msort(T* a, const int n, ld cmp)
    {
        int b[get_half(n)];
        split_merge(a, b, n, cmp);
    }

    template<typename T>
    static int partition(T* arr, int lo, int hi, ld cmp)
    {
        T pivot = arr[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (cmp(arr[j], pivot)) {
                swap(arr+i, arr+j);
                i++;
            }
        }
        swap(arr+i, arr+hi);
        return i;
    }

    template<typename T>
    void qsort(T* arr, int lo, int hi, ld cmp)
    {
        if (lo < hi) {
            int p = partition(arr, lo, hi, cmp);
            qsort(arr, lo, p - 1, cmp);
            qsort(arr, p + 1, hi, cmp);
        }
    }

    template<typename T>
    void bsort(T* arr, int n, ld cmp)
    {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (cmp(arr[j+1], arr[j])) {
                    swap(arr+j, arr+j+1);
                }
            }
        }
    }

    template<typename T>
    void ssort(T* arr, int n, ld cmp)
    {
        int i = 0;
        while (i < n-1) {
            int sel = i;
            for (int j = i+1; j < n; j++) {
                if (cmp(arr[j], arr[sel])) sel = j;
            }
            if (sel != i)
                swap(arr+sel, arr+i);
            i++;
        }
    }

    template<typename T>
    void isort(T* arr, int n, ld cmp)
    {
        int i = 1;
        while (i < n) {
            int sel = arr[i];
            int j = i - 1;
            while ((j >= 0) && cmp(sel, arr[j])) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = sel;
            i++;
        }
    }

}
