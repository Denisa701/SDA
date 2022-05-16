#include <stdio.h>

void Buble_sort1(int v[100], int n);
void Buble_sort2(int v[100], int n);
void Insertion_sort ( int v[100], int n);
void Selection_sort( int v[100], int n);
void Interclasare(int v[100] ,int left, int m, int right);
void Merge_sort(int v[100], int right, int left);
void swap(int x, int y);
int part(int v[100], int left, int right);
void Quick_sort( int v[100], int left, int right);


int main()
{
    int s[100]={25, 1, 44, 56, 100, 9, 2};
    int t[100]={6, 5, 3, 2, 8, 10, 9};
    int u[100]={100, 67, 34, 22, 15, 10, 2};
    int r[10000];
    for(int i =0; i<10000; i++){
        r[i] = rand();
    }

    
   // printf("BuBBle SoRt\n");
    Buble_sort1(s,6);
    //printf("\n\n");
    //Buble_sort2(s,6);
    // Buble_sort(t,6);
    // Buble_sort(u,6);

    // printf("\n\n Insertion sort\n");
    // Insertion_sort(s,6);
    // Insertion_sort(t,6);
    // Insertion_sort(u,6);

    // printf("\n\n Selection sort\n");

    // Selection_sort(s,6);
    // Selection_sort(t,6);
    // Selection_sort(u,6);

    // printf("\n\nMerge sort\n");

    // Merge_sort(s,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", s[i]);
    //     printf("\n");
    // Merge_sort(t,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", t[i]);
    //     printf("\n");
    // Merge_sort(u,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", u[i]);
    
    // printf("\n\n Quick sort\n");

    // Quick_sort(s,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", s[i]);
    //      printf("\n");
    // Quick_sort(t,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", t[i]);
    //      printf("\n");
    // Quick_sort(u,0,5);
    // for(int i =0; i<6; i++)
    //     printf("%d ", u[i]);
    //      printf("\n");

    //Buble_sort(r,10000);
    //Insertion_sort(r,10000);
     //Selection_sort(r,10000);
    // Merge_sort(r,0,10000-1);
    // for(int i =0; i<10000; i++)
    //     printf("%d ", r[i]);
    //      printf("\n");
    // Quick_sort(r,0,10000);
    // for(int i =0; i<10000; i++)
    //     printf("%d ", r[i]);
    //      printf("\n");

}


void Buble_sort1(int v[100], int n)
{
    for(int i = 0; i < n; i++){
        for (int j=0; j<(n-i-1); j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                printf("%d > %d\n", v[j], v[j+1]);
            }      
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");        
}

void Buble_sort2(int v[100], int n)
{
    int ok;
    do{
        ok = 0;
        for(int i=0; i<n-1; i++){
            if(v[i] > v[i+1]){
                swap(v[i],v[i+1]);
                ok = 1;
                printf("%d > %d\n", v[i], v[i+1]);
            }
        }
    }while(ok !=0);

    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");        
}

void Insertion_sort ( int v[100], int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int x = v[i];
        while(j >= 0 && x < v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");  
}

void Selection_sort( int v[100], int n)
{
    int x;
    for(int i = 0; i <= n-2; i++){
       int p = i;
       for(int j = i+1; j < n-1; j++)
           if(v[j] > v[p])
                p=j;
        if(p != i){
            swap(v[p],v[i]);
        }
       
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");  
}

void Merge_sort(int v[100], int right, int left){
    if(left < right){
        int m = (right + left)/2; 
        Merge_sort(v,left, m);
        Merge_sort(v,m+1, right);
        Interclasare(v,left, m, right);
    } 
}

void Interclasare(int v[100] ,int left, int m, int right){
    int z[100], i = left, j = m+1, k = 0;
    while(i <= m && j <= right){
        if(v[i] < v[j])
            z[k++] = v[i++];
        else
            z[k++] = v[j++];
    }
    for(int a = i; a <= m; a++)
        z[k++] = v[a];
    for(int a = j; a <= right; a++)
        z[k++] = v[a];
    for(int a = left; a <= right; a++)
        v[a] = z[a-left];
}

void Quick_sort( int v[100], int left, int right){
    if(left < right){
        int p = part(v,left,right);
        Quick_sort(v,left,p-1);
        Quick_sort(v,p+1,right);
    }
  
}
int part(int v[100], int left, int right){
    int i = 0;
    int j = -1;
    while (left < right)
    {
        if(v[left] > v[right]){
            swap(v[left], v[right]);
            if(i == 0 && j == -1){
                i = 1;
                j = 0;
            } else {
                j == -1;
                i == 0;
            }
            left = left + i;
            right = right + j;
        }
        return left;
    }
    
}

void swap(int x, int y)
{
    int t = x;
    x = y;
    y = t;
}