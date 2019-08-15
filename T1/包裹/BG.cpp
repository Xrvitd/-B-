#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const double esp = 0.01;
struct re {
	double v[5];
} p[40], t[40], px[40], py[40], tx[40], ty[40];
bool vis[40][5], visi[40];
int cnt;
ofstream os;
void get_out(int len) {
	++cnt; 
//	cout<<"out";
	//os<<" ---- " <<++cnt<<endl;
	os<<len<<'\n';
	for (int i = 1; i <= 32; i++) {
		for (int j = 1; j <= 4; j++) {
			if(vis[i][j]) {
					os<<i<<" "<<j<<" "<<px[i].v[j]<<" "<<py[i].v[j]<<"\n";
			}
		}
	}
}
void dfs(int len, double x, double y,int k) {
	if (len == 1) {
	
		if (x * x + y * y < esp) {//cout<<len<<" "<<x<<" "<<y<<endl;
			get_out(len);
		}
		//return;
	}
	if (len == 2) {
	
		if (x * x + y * y < esp) {//cout<<len<<" "<<x<<" "<<y<<endl;
			get_out(len);
		}
		//return;
	}
	
	if (len == 3) {
	
		if (x * x + y * y < esp) {//cout<<len<<" "<<x<<" "<<y<<endl;
			get_out(len);
		}
		//return;
	}
	if (len == 4) {
	
		if (x * x + y * y < esp) {//cout<<len<<" "<<x<<" "<<y<<endl;
			get_out(len);
		}
		return; 
	}
	for (int i = k; i <= 32; i++) {
		if (!visi[i]) {
			visi[i] = 1;
			for (int j = 1; j <= 4; j++) {
				vis[i][j] = 1;
				dfs(len + 1, x + tx[i].v[j], y + ty[i].v[j],i+1);
				vis[i][j] = 0;
			}
			visi[i] = 0;
		}
	}
}
int main() {
	os.open("outBG.txt");
	visi[4]=visi[20]=1;
	ifstream in;
	in.open("Px.csv");
	char c;
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < 4 ; j++) {
			in>>px[i].v[j];
			in>>c;
			//printf("%.10lf ",px[i].v[j]);
		}
		//cout<<endl;
		in>>px[i].v[4];
	}
	in.close();
	in.open("Py.csv");
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < 4 ; j++) {
			in>>py[i].v[j];
			in>>c;
		}
		in>>py[i].v[4];
	}
	in.close();
	in.open("Tx.csv");
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < 4 ; j++) {
			in>>tx[i].v[j];
			in>>c;
		}
		in>>tx[i].v[4];
	}
	in.close();
	in.open("Ty.csv");
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < 4 ; j++) {
			in>>ty[i].v[j];
			in>>c;
		}
		in>>ty[i].v[4];
	}
	in.close();
	dfs(0, 0, 0, 1);
	os<<0;
	cout<<cnt;
	return 0;
}
