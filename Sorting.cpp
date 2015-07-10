#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iterator>

using namespace std;


void display_vector(vector<long> *vVec);
void quickSortInternal(vector<long> *vVec, long Start, long End);
void quickSort(vector<long> *vVec);
void selectionSort(vector<long> &vVec);
void MergeSort(vector<long> *mergeVec);
void internalMergeSort(vector<long> *mergeVec, long start, long end);
void merge(vector<long> *mergeVec, long lowStart,long lowEnd, long highStart, long highEnd);
void insertionSort(vector<long> *insertVec);


//All count functions are Static varibles held inside of functions so that they can be 
//accessed in multiple functions without being required to pass around a varible.

long InsertionCount(){
	static long InsertCount =0;
	InsertCount++;
	return InsertCount;
}
	
long MergeCount(){
	static long MergeCount =0;
	MergeCount++;
	return MergeCount;
}

long QuickCount(){
	static long QuickCount =0;
	QuickCount++;
	return QuickCount;
}

//Gets input from the user and based off of the responce creates 3 vectors of length n and 
//performs the Insertion Sort, QuickSort and Merge Sort on them and displays the number of actions taken by each to the user
int main(int argc, char * argv[])
{

	vector<long> *MergeVec = new vector<long>;
	vector<long> *InsertVec = new vector<long>;
	vector<long> *QuickVec = new vector<long>;
	vector<long> *MergeVecTwo = new vector<long>;
	vector<long> *InsertVecTwo = new vector<long>;
	vector<long> *QuickVecTwo = new vector<long>;
	cout<<"Enter [1] to test the sorting methods on a vector with elements in reverse order\nEnter [2] to test the sorting methods on a differently organized vector. ";
	int User;
	cin>>User;
	cout<< "How big of a vector do you want?";
	int VecSize;
	cin>>VecSize;
	for(int i =VecSize;i>0;i--){
		if(User==1){
			MergeVec->push_back(i);
			InsertVec->push_back(i);
			QuickVec->push_back(i);
		}
		else{
			if(i-VecSize/2 >=1){
				MergeVecTwo->push_back(long(i-VecSize/2));
				InsertVecTwo->push_back(long(i-VecSize/2));
				QuickVecTwo->push_back(long(i-VecSize/2));
			}
			else{
				MergeVecTwo->push_back(long(VecSize-i+1));
				InsertVecTwo->push_back(long(VecSize-i+1));
				QuickVecTwo->push_back(long(VecSize-i+1));
			}
		}
	}
	
	
	//cout<< "Vector before: "<<endl;
	//if(User==1)
	//	display_vector(MergeVec);
	//else
	//	display_vector(MergeVecTwo);
	

    // Now actually call the sort
	if(User==1){
		quickSort(QuickVec);
		insertionSort(InsertVec);
		MergeSort(MergeVec);
	}
	else{
		quickSort(QuickVecTwo);
		insertionSort(InsertVecTwo);
		MergeSort(MergeVecTwo);
	}

	/*
	cout << "Vector after Merge Sort: " << endl;
	display_vector(MergeVecTwo);
	cout << "Vector after Insertion Sort: " << endl;
	display_vector(InsertVecTwo);
	cout << "Vector after Quick Sort: " << endl;
	display_vector(QuickVecTwo);
	*/
	
	cout<< "Total number of Insertion Sort actions: " <<(InsertionCount())-1<<endl;
	cout<< "Total number of Merge Sort actions: " <<(MergeCount())-1<<endl;
	cout<< "Total number of Quick Sort actions: " << (QuickCount())-1<<endl;


	system("pause");
	return 0;
}
// a starter for MergeSort to make it cleaner
void MergeSort(vector<long> *mergeVec)
{
	MergeCount();
	internalMergeSort(mergeVec,0,(mergeVec->size()-1));
}
// the basic operation of merge sort, takes a vector, splits in half and calls recursivly until it is a single element. Once this happens it orders them correctly and merges the two together
void internalMergeSort(vector<long> *mergeVec, long start, long end)
{
	MergeCount();
	if((end-start)>0){
		MergeCount();
		long mid = start+(end-start)/2;
		MergeCount();
		internalMergeSort(mergeVec,start,mid);
		MergeCount();
		internalMergeSort(mergeVec,mid+1,end);
		MergeCount();
		merge(mergeVec,start,mid,mid+1,end );
	}
	//else do nothing
	
}
//Takes two sorted sections of a vector and merges them together
void merge(vector<long> * mergeVec, long lowStart,long lowEnd, long highStart, long highEnd)
{
	MergeCount();
	if((highEnd-highStart)<0||(lowEnd-lowStart)<0){
		MergeCount();
		return;
	}
	MergeCount();
	if((*mergeVec)[lowStart]<=(*mergeVec)[highStart])
	{
		MergeCount();
		merge(mergeVec, lowStart+1,lowEnd,highStart,highEnd);
	}
	else
	{
		MergeCount();
		mergeVec->insert(mergeVec->begin()+lowStart, (*mergeVec)[highStart]);
		MergeCount();
		mergeVec->erase(mergeVec->begin()+highStart+1);
		MergeCount();
		merge(mergeVec, lowStart+1,lowEnd+1,highStart+1,highEnd);
	}
}
//takes a random pivot point and puts all values smaller than the pivot in one vector, and larger in a second the continues recursivly until they are of size 1
void quickSortInternal(vector<long> * vVec, long Start, long End) 
{
	
	
	QuickCount();
    if(Start < End)
    {
		QuickCount();
		long randPivot = Start+rand()%(End-Start);
		QuickCount();
		swap((*vVec)[Start],(*vVec)[randPivot]);
		QuickCount();
		long iPivot = Start;
		QuickCount();
		long PivotValue = (*vVec)[iPivot];
		QuickCount();
		for( long i = Start + 1 ; i <= End; i++ )
		{
			QuickCount();
			if((*vVec)[i] < PivotValue) 
			{
				QuickCount();
				iPivot++;
				QuickCount();
				swap((*vVec)[i], (*vVec)[iPivot]);
			}  
			

		} 

		
		QuickCount();
		swap((*vVec)[iPivot], (*vVec)[Start]);
		QuickCount();
        quickSortInternal(vVec, Start, iPivot - 1);
		QuickCount();
        quickSortInternal(vVec, iPivot + 1, End);
    }
}
// makes the quick sort call cleaner
void quickSort(vector<long> * Vec)
{
	QuickCount();
	quickSortInternal(Vec, 0, Vec->size() - 1);
}
//takes the current position and finds, then swaps the value that should go into each position
void insertionSort(vector<long> *insertVec)
{
	InsertionCount();
	for(long i =1;i<insertVec->size();i++)
	{
		InsertionCount();
		int k = i-1;
		InsertionCount();
		int x = (*insertVec)[i];
		InsertionCount();
		while(x<(*insertVec)[k])
		{
			InsertionCount();
			(*insertVec)[k+1]=(*insertVec)[k];
			InsertionCount();
			k=k-1;
			InsertionCount();
			if(k<0){
				InsertionCount();
				break;
			}
		}
		InsertionCount();
		(*insertVec)[k+1] = x;
	}

}
//Just for fun
void selectionSort(vector<long> &vVec){ 
	long min;
	for(long i = 0; i<vVec.size();i++){
		min=i;
		for(long j = i+1;j<vVec.size();j++){
			if(vVec[min]>vVec[j]){
			min = j;
			}
		}
		swap(vVec[min],vVec[i]);
	}

}
//used to display contents of a vector, printed for the user
void display_vector(vector<long> * vVec){

	for(auto it = vVec->begin(); it!= vVec->end(); it++){
		cout <<" "<< *it <<endl;
	}
	cout<<endl;
}