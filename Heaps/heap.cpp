#include<iostream>
using namespace std;
// member of the class are present
void upHeapify(vector<int>* &v)
{
	if(v->size==1) return;
	else{
		// creating a min heap
		int num=v[v->size-1];	
		ci=v->size-1;
		int pi=(ci-1)/2;
		while(pi>=0&&v[pi]>v[ci]){

			swap(v[pi],v[ci]);
			ci=pi;
			pi=(ci-1)/2;

		}
	}
	return;

}
int main()
{

	return 0;
}