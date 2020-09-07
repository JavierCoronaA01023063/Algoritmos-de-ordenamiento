#include <iostream>
#include <vector>
#include <stdlib.h>
#include "ordenamiento.h"
using namespace std;
#include <ctime>
#include "mytimer.h"

#ifndef sorter_h 
#define sorter_h

#define DECLARE_TIMING(s)	    	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart_##s; std::chrono::duration<double> timeDiff_##s; double timeTally_##s = 0; long countTally_##s = 0
#define START_TIMING(s)		    	timeStart_##s = std::chrono::high_resolution_clock::now()
#define STOP_TIMING(s)		    	timeDiff_##s = (std::chrono::high_resolution_clock::now() - timeStart_##s); timeTally_##s += timeDiff_##s.count(); countTally_##s++
#define GET_TIMING(s)		    	(double)timeDiff_##s.count()
#define GET_AVERAGE_TIMING(s)		(double)(countTally_##s ? (double)timeTally_##s / ((double)countTally_##s)  : 0)
#define GET_TIMING_COUNT(s)  		(int)(countTally_##s)
#define SHOW_TIMING(s, msg)	    	std::cout << msg << " time: \t" <<  GET_TIMING(s) << " seconds (" << GET_TIMING(s) / 60 << "min)\t" << GET_AVERAGE_TIMING(s) << " sec average across " << GET_TIMING_COUNT(s) << " runs." << std::endl


template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

template <typename T>
void compare_vectors(vector<T> a, vector<T> b, string message = "")
{
    cout << message << " ";
    if (a == b)
    {
        cout << "correct implementation" << endl;
    }
    else
    {
        cout << "incorrect implementation" << endl;
    }
}


int main()
{
    vector <int> arr_tarea;
    int size = 100000; 
    for (size_t i = 0; i < size; i++)
    {
        arr_tarea.push_back((int)rand() / RAND_MAX);
    }
    
    
    vector <int> arr_1(arr_tarea);
    vector <int> arr_2(arr_tarea);
    vector <int> arr_3(arr_tarea);
    vector <int> arr_4(arr_tarea);

    DECLARE_TIMING(t);
    START_TIMING(t);
    std::sort(arr_tarea.begin(), arr_tarea.end());
    STOP_TIMING(t);
    SHOW_TIMING(t, "std::sort");

    //instancia Selection Sort
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort <int> selsort;
    selsort.sort(arr_1);
    STOP_TIMING(t1);
    compare_vectors(arr_tarea, arr_1, "Selection sort: ");
    SHOW_TIMING(t1, "SelectionSort");

    //instancia Bubble sort
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    Bubblesort <int> bubsort;
    bubsort.sort(arr_2);
    STOP_TIMING(t2);
    compare_vectors(arr_tarea, arr_2, "Bubble sort: ");
    SHOW_TIMING(t2, "BubbleSort");

    // instancia Insertion Sort
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    Insertionsort <int> inssort;
    inssort.sort(arr_3);
    STOP_TIMING(t3);
    compare_vectors(arr_tarea, arr_3, "Insertion sort: ");
    SHOW_TIMING(t3, "InsertionSort");

    // instancia Merge Sort
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort <int> mersort;
    mersort.sort(arr_4);
    STOP_TIMING(t4);
    compare_vectors(arr_tarea, arr_4, "Merge Sort: ");
    SHOW_TIMING(t4, "Merge Sort");  



    return 0;
};
#endif