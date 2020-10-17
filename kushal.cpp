#include <iostream>
#define ll long long int
using namespace std;

void Heap_sort(ll ar[],ll n)
{
    
}
void Bubble_sort(ll ar[],ll n)
{
    
}
void Quick_sort(ll ar[],ll n)
{
    
}
void Pancake_sort(ll ar[],ll n)
{
    
}
void Count_sort(ll ar[],ll n)
{
    
}
int main()
{
    cout<<"This is an sorting based code \n";
    cout<<"insert n elements to an array\n";
    ll n;
    cin>>n;
    ll ar[n];
    for(auto i:ar) cin>>ar[i];
    cout<<"choose any one by which you want to sort list upto k element \n";
    cout<<"1. Heap sort\n2. Bubble sort\n3. Quick sort\n4. Pancake sort\n5. Count sort\n";
    int x;
    cin>>x;
    switch(x)
    {
        case 1: Heap_sort(ar,n);
                break;
        case 2: Bubble_sort(ar,n);
                break;
        case 3: Quick_sort(ar,n);
                break;
        case 4: Pancake_sort(ar,n);
                break;
        case 5: Count_sort(ar,n);
                break;
        default: cout<<"look menu and then choose\n";
    }

    return 0;
}
