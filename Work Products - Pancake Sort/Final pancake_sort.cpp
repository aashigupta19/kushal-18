//Here, an analogy is created between a stack of pancakes of different sizes and an unsorted array. 
//The size of pancake at an index corresponds to the mangnitude of the array element at that index.


#include<iostream>   //iostream provides basic input and output services for C++ programs. iostream uses the objects cin , cout , cerr ,and clog for sending data to and from the standard streams input, output, error (unbuffered), and log (buffered) respectively.
#include<limits.h>     // To ensure that we don't exceed the data type limit. If the limit is exceeded,it displays an error message. 
#include<time.h>      //It contains definitions of functions to get and manipulate date and time information. 
#include<cstdlib.h>    //It is the header of the general purpose standard library of C++ programming language.
using namespace std;
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


// It contains all the methods for the functionality required by the methods of its subclass -Pancake
class Helper                                  
{
	public:

// The method returns the index of the maximum element from the elements of the array till index 'n'
		ll max(ll *a,ll n)             		 
		{
			ll m=INT_MIN;
			ll index=-1;
			for(ll k=0;k<=n;k++)
			{
				if(m<a[k])
				{
					m=a[k];
					index=k;
				}
			}
			return index;
		}	
	
	
// Function to swap two given function inputs 
		void swap(ll *a,ll *b)				
		{
			ll c=0;
			c=*a;
			*a=*b;
			*b=c;
		}
		

// Function to reverse the elements of an array 'a' within an index range (0 to i)
		void flip(ll *a,ll i)					
		{
			ll k,j;
			k=0;j=i;
			while(k<j)
			{
				swap(&a[k],&a[j]);
				k++;
				j--;
			}
		}
};


//This class implements the Pancake Sort algorithm recursively and iteratively.
class Pancake : protected Helper              					
{		
	
public:	
//Recursive function for pancake sort
		void pancakeRec(ll *a,ll n)							
		{

			if(n==0)                           				// No element in the array 
				return;
			ll i=max(a,n-1);
			if(i<n-1)        								// Maximum element's index is LESS THAN the last index of the input array 'a'
			{
				flip(a,i);      						    // To bring the maximum element to the top of the input array(index 0)
				flip(a,n-1);     							//To bring the maximum element to the bottom of the input array
			}
			pancakeRec(a,n-1);  							//Recursive call for array of size n-1
		}
			

// Iterative function for pancake sorting		
		void pancakeIter(ll *a,ll n)						
		{
			for(ll i=n-1;i>=0;i--)   
			{
																								                                                                                   
				ll j=max(a,i);       						 //function return the index of the maximum element in the array till index i
				if(j<i)      								 //If maximum elements's index is LESS THAN the last index(array_size-1) of the subarray from index 0 to i
				{
					flip(a,j); 							 	// To bring the maximum element to the top of the array(index 0)
					flip(a,i);  					  		//to bring the maximum element to the bottom of the subarray from index 0 to i
				}
			}
		}
		
};


// Function to print the output i.e., the sorted array
void sortedPrint(ll n,ll *a)
{
	for(int i=0;i<n;i++)                 
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


// Function that intakes array elements from the user
void driver()											
{
    
	ll n=0;
	cin>>n;   							 		//Number of pancakes in a stack(Number of elements in an array
	
	if(n<=0)
	{
		cout<<"Enter valid input(positive value)"<<endl;
		cin>>n;
	}
		   	
	ll a[n];
	for(ll i=0;i<n;i++)         				//Loop to intake array elements from the user/ customer
	{
		cin>>a[i];
	
	}
		
	Pancake p;           								
	p.pancakeIter(a,n);        							
	//p.pancakeRec(a,n);           				//pancakeRec: Method of pancake class. User is at the liberty to call either the pancakeIter or pancakeRec    	
	
	sortedPrint(n,a);
	
}



// Function to test the code against random values within the predefined limit
void test()
{
	 
	srand (time(NULL));        					  	//To make the seed correspond to the clock of the system, so it changes the sequence of random numbers generated for each run of the program.
	ll n=0;
	cin>>n;   							 		//Number of pancakes in a stack(Number of elements in an array
	
	if(n<=0)
	{
		cout<<"Enter valid input(positive value)"<<endl;
		cin>>n;
	}
	    
	ll a[n];
	    
	for (ll i=0; i<n; i++)    						//Loop to generate Array elements randomly
	{
	   	a[i]= rand()%(INT_MAX);
	    cout<<a[i]<<" ";     						 
	} 
	cout<<endl;    
			
	Pancake p;           					   
	//p.pancakeRec(a,n);        					 //pancakeRec: Method of pancake class. User is at the liberty to call either the pancakeIter or pancakeRec 

	sortedPrint(n,a);
}


int main()
{
    fastIO;
    ll t;
    cin>>t;        							 		 // t : denotes number of pancake stacks to sort according to their size
    while(t--)
    {
        driver(); 
        //test();                               	  // To test the code against random values within the predefined limit
    }
	return 0;
}

