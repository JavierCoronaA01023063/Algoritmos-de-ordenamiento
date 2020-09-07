#include <iostream>
#include <vector>



template <typename T>
class Sorter
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};

};


template <typename T>
class SelectionSort : public Sorter <T>
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
                Sorter<T>::swap(i, min, arr);
            }
            
        }
        
    };

};

template <typename T>
class Bubblesort : public Sorter<T>
{
    public:
    Bubblesort() {};
    ~Bubblesort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            bool no_swap = true;
            for (size_t j = 0; j < arr.size() - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
                
            }
            if (no_swap)
            {
                break;
            }
        }
    };
};

template <typename T>
class Insertionsort : public Sorter<T>
{
    public:
    Insertionsort() {};
    ~Insertionsort() {};

    void sort(std::vector<T> &arr)
    {
        T key;
        for (size_t i = 1; i < arr.size(); i++)
        {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 & arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    };
};

template <typename T>
class MergeSort : public Sorter<T>
{
    public:
    MergeSort() = default;

    void Sort(std::vector<T> &arr)
    {
        Sort_Merge(arr, 0, arr.size() - 1);
    }

    void Sort_Merge(std::vector<T> &arr, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r-l) / 2;

            Sort_Merge(arr, l, m);
            Sort_Merge(arr, m+1, r);

            Merge(arr, l, m, r);
        }
    }
    void Merge(std::vector<T> &arr, int l, int m, int r)
    {
        int arr1 = m - l + 1; 
        int arr2 = r - m;
        
        int O[arr1], S[arr2]; 

        for (size_t i = 0; i < arr1; i++)
        {
            O[i] = arr[l + i]; 
            for (size_t j = 0; j < arr2; j++)
            {
                S[j] = arr[m + 1 + j]; 
            }

        } 

        int a = 0; 
        int b = 0; 
        int c = l; 

        while (a < arr1 && b < arr2) 
        {  
            if (O[a] <= S[b]) 
            { 
                arr[c] = O[a]; 
                a++; 
            } 
            else 
            { 
                arr[c] = S[b]; 
                b++; 
            } 
            c++; 
        } 

        while (a < arr1) 
        { 
            arr[c] = O[a]; 
            a++; 
            c++; 
        } 


        while (b < arr2)
        { 
            arr[c] = S[b]; 
            b++; 
            c++;
        } 
    }
};
