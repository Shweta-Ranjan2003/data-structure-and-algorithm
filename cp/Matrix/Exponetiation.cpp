#include<bits/stdc++.h>
//#define int long long int
 
using namespace std;
 
const int mod = 1e9 + 7;
 
struct Mat {
	// sz x sz
	int sz;
	vector<vector<int>> data;
 
	// constructor
	Mat(int _sz) {
		sz = _sz;
		data.resize(sz, vector<int>(sz, 0));
	}
 
	void identity() {
		data.resize(sz, vector<int>(sz, 0));
 
		for (int i = 0; i < sz; i++) {
			data[i][i] = 1;
		}
	}
 
	// O(sz^2)
	Mat operator+(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = (data[i][j] + b.data[i][j]) % mod;
			}
		}
		return res;
	}
 
	// O(sz^2)
	Mat operator-(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = (data[i][j] - b.data[i][j] + mod) % mod;
			}
		}
		return res;
	}
 
	// O(sz^2)
	Mat operator*(int b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = ((data[i][j] % mod) * (b % mod)) % mod;
			}
		}
		return res;
	}
 
	// O(sz^3)
	Mat operator*(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				// make res[i][j]
				for (int k = 0; k < sz; k++) {
					res.data[i][j] += (data[i][k] * b.data[k][j]) % mod;
					res.data[i][j] %= mod;
				}
			}
		}
		return res;
	}
 
	// O(log(b)*(sz^3))
	Mat operator^(int b) {
		Mat a = (*this);
 
		Mat res(sz);
		res.identity();
 
		while (b) {
			if (b & 1) {
				res = res * a;
			}
			a = a * a;
			b >>= 1;
		}
 
		return res;
	}
 
	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << data[i][j] << " ";
			} cout << '\n';
		}
		// cout << '\n';
	}
};
int main(){
    Mat a(2),b(2);
    a.identity();
    b.identity();
    Mat c=a+b;
    c.print();
    c=c^2;
    c.print();
    return 0;
}