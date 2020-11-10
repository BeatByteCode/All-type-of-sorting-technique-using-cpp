#include<iostream>

using namespace std;

class Sorting{
public:

    // Swaping method starts here
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // swaping method ends here


    //Bubble sort method starts here

    void bubbleSort(int a[], int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1-i; j++){
                if(a[j] > a[j+1]){
                    swap(&a[j],&a[j+1]);
                }
            }
        }
    }

    //Bubble sort method ends here


    //Selection sort methods starts here

    void selectionSort(int a[], int n){
        for(int i=0; i<n-1; i++){
            int min = i;
            for(int j=i+1; j<n; j++){
                if(a[min] > a[j]){
                    min = j;
                }
            }
            if(min != i){
                swap(&a[i],&a[min]);
            }
        }
    }

    //Selection sort methods end here


    //Insertion Sort method starts here
    void insertionSort(int a[], int n){
        for(int i=1; i<n; i++){
            int j=i-1;
            int key = a[i];

            while(j>=0 && a[j] > key){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = key;
        }
    }

    //Insertion sort method ends here

    //Quick Sort Methods starts here

        int partition(int a[], int l, int h){
            int pivot = a[h];
            int i = l-1;

            for(int j=l; j<h; j++){
                if(a[j] < pivot){
                    i++;
                    swap(&a[i],&a[j]);
                }
            }

            swap(&a[i+1],&a[h]);
            return i+1;

        }

        void quickSorting(int a[],int l, int h){
        if(l<h){
            int pivot = partition(a,l,h);
            quickSorting(a,l,pivot-1);
            quickSorting(a,pivot+1,h);
        }
        }
        void quickSort(int a[], int n){
            quickSorting(a,0,n-1);
        }
    //quick Sort Method Ends

    //Merge Sort methods Starts
        void mergeSortArray(int a[], int l, int mid, int h){
            int n= mid-l+1, m= h-mid;
            int left[n], right[m];
            int i,j,k;

            for(i=0;i<n;i++){
                left[i] = a[l+i];
            }
            for(j=0;j<m;j++){
                right[j] = a[mid+1+j];
            }

            i=0,j=0,k=1;

            while(i<n && j<m){
                if(left[i] <= right[j]){
                    a[k] = left[i];
                    i++;
                }else{
                    a[k] = right[j];
                    j++;
                }
                k++;
            }

            while(i<n){
                a[k] = left[i];
                k++;
                i++;
            }

            while(j<m){
                a[k] = right[j];
                k++;
                j++;
            }
        }

        void mergeSorting(int a[], int l, int h){
            if(l < h){
                int mid = l+(h-1)/2;
                mergeSorting(a,l,mid);
                mergeSorting(a,mid+1,h);
                mergeSortArray(a,l,mid,h);
            }
        }

        void mergeSort(int a[],int n){
            mergeSorting(a,0,n-1);
        }

    //Merge Sort Method ends

    //Heap sort methods starts here

    void heapify(int a[],int n,int i){

        int largest = i;
        int l = 2*i + 1;
        int r = 2*i +2;

        if(l<n && a[l]> a[largest]){
            largest = l;
        }

        if(r<n && a[r]> a[largest]){
            largest = r;
        }

        if(largest != i){
            swap(a[largest], a[i]);
            heapify(a,n,largest);
        }
    }

    void heapSort(int a[], int n){
        for(int i=n/2-1; i>=0; i--)
            heapify(a,n,i);

        for(int i=n-1; i>0; i--){
            swap(a[0],a[i]);
            heapify(a,i,0);
        }
    }
    //heap sort methods end here

    //Display method starts here

    void display(int a[], int n){
        cout<<"<< Sorted Array >>\n";
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
    }
    // Display method ends here

};

int main(){

    int choice,n;

    Sorting sort;
    cout<<"1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Quick Sort\n5. Merge Sort\n6. Heap Sort";
    cout<<"\nEnter Your Choice >> ";
    cin>>choice;
    cout<<"\nEnter number Of inputs >> ";
    cin>>n;
    cout<<"Enter numbers separated by space : ";

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    switch(choice){
    case 1:
        sort.bubbleSort(a,n);
        sort.display(a,n);
        break;
    case 2:
        sort.selectionSort(a,n);
        sort.display(a,n);
        break;
    case 3:
        sort.insertionSort(a,n);
        sort.display(a,n);
        break;
    case 4:
        sort.quickSort(a,n);
        sort.display(a,n);
        break;
    case 5:
        sort.mergeSort(a,n);
        sort.display(a,n);
        break;
    case 6:
        sort.heapSort(a,n);
        sort.display(a,n);
        break;

    default:
        cout<<"<<\n Wrong Choice >>";
    }
    return 0;
}
