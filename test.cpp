#include <iostream> 
#include <vector>
using namespace std;

int findMin(vector<int> &v) {
	int min = 10000000, n = 0;
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        if (min > v[i]) {
            min = v[i],
            n = i;
        }
    }
    return n;
}

int main() {
	int n, r, avg;
	cin >> n >> r >> avg;
    vector<int> a, b, c;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        c.push_back(r - x);
        sum = sum + x;
   	}
    if(sum >= (avg * n))
		cout << 0;
    else {
	    int time = 0;
        sum = avg * n - sum;
        cout << sum << endl;
        for(int i = 0; i < a.size(); i++)
        	cout << c[i] << "   ";
        cout << endl;
        while(sum > 0) {
        	cout << "***" << sum << "  " << time << endl;
            int min = findMin(b);
            if (c[min] > sum) {
                time = time + sum * b[min];
                sum = 0;
            }
            else {
                time = time + c[min] * b[min];
                sum = sum - c[min]; 	           
           		a.erase(a.begin() + min);
            	b.erase(b.begin() + min);
            	c.erase(c.begin() + min);
  	      	}
  	    }
        cout << time;
    }
    return 0;
}
