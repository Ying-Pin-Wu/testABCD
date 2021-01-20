#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

void test_vector(void)
{
	int array[] = {0,1,2,3,4,5};
	vector<int> v(10,0); // {0,0,0,0,0,0,0,0,0,0}
	vector<int> v1;
	//vector<int> v3(v.begin(), v.end());
//	v1.assign(10, 0); // v1 設 10 個 0
//	v1.assign(v.begin(), v.end()); // v1 複制 v
//	v1.assign(v.begin(), v.begin()+5); // 複製 v 前5個元素到 v1
	v1.assign(array, array+6); // 複製 array 前5個元素到 v1
	cout << "BBBBB" << endl;

    for(int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << endl;
		try {
			int iVal1 = v1.at(i+1);
		}catch(const exception& e) {
			cout << e.what();
		}



    }
	

	cout << "SSBBBB" << endl;

	vector<int>::iterator it ;
	for( it = v1.end()-1 ;it != v1.begin();it--) {
        auto n = *it;
        cout << n << endl;
    }




	cout << "ABBBB" << endl;
 	
	 while(!v1.empty()) {
        int n = v1.back();
        v1.pop_back();
        cout << n << endl;        
 	}


}

DWORD WINAPI myThread(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	
	test_vector();

	while(myCounter < 0x0FFFFFFF){
        myCounter++;
        if(myCounter == 0x0FFFFFFF){
            myCounter = 0;
        }
		Sleep(100);
    }
	return 0;
}


int main()
{
	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while(myChar != 'q') {
		// cout << myCounter << endl;
        // cout << myThreadID << endl;
		myChar = getchar();
	}
	CloseHandle(myHandle);
	system("pause");
	return 0;
}