#include <iostream>
#include <vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int te=0;te<t;te++){
		int o;
		cin>>o;
		vector<int>vec;
		for(int op=0;op<o;op++){
			int ini;
			cin>>ini;
			if(ini==2) vec.push_back(-1);
			else{
				int next;
				cin>>next;
				vec.push_back(next);
			}
		}
		
		int i=0;
		int read=0;
		int count=0;
		for(int j=0;j<o;j++){
			if(vec[j]==-1){
				int k=j-1;
				int cnt=0;
				while(vec[k]==-1){
					cnt++;
					k--;
				}
				k=k-cnt;
				i=k-1;
				count=count-vec[k];
			}
			else{
				if(j>0 && vec[j-1]!=-1){
					i=j;
				}
				count+=vec[j];
				read=max(read,count);
			}
		}
		cout<<read<<endl;
	}
	return 0;
}