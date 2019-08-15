#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<fstream>
#include<map>
#include<set>
using namespace std;
struct re {
	double v[5];
} px[33],py[33],tx[33],ty[33],w[33];
bool vis[10000];
int cnt;
struct ac{
	int x,y;
};
struct xr{
	double x,y;
	unsigned int vis;
	vector<ac> V;
} pack_v[100000];
int vv[100000][10];
const double num1 = 56 * 56;
const double num2 = 57 * 57;
int chosv[40];
ofstream os;
int scnt;
bool cmp(const xr &a,const xr &b) {
	return pow(a.x,2)+pow(a.y,2)<pow(b.x,2)+pow(b.y,2);
}
void get_out(int num) {
	cout<<"out\n"; 
	os<<++scnt<<endl;
	memset(chosv,0,sizeof(chosv)); 
	for(int i = 1;i<=num;i++) {
		if(vis[i]) {
			for(int j = 0; j < pack_v[i].V.size(); j++) {
				chosv[pack_v[i].V[j].x]=pack_v[i].V[j].y;
			}
		}
	}
	double ansx = 0, ansy = 0; 
	for(int i=1;i<=32;i++){
		os<<i<<","<<chosv[i]<<'\n';
//		ansx+=px[i].v[chosv[i]];
//		ansy+=py[i].v[chosv[i]];
	}
//	for(int i=1;i<=32;i++) {
//		os<<chosv[i]<<", ";
//	}
	os<<endl;
	//cout<<x<<" "<<y<<" "<<ansx<<" "<<ansy<<endl;
}
void dfs(int num,double a,double b,unsigned int visit,int sum,bool qvis) {
	//if(!qvis&&a*a+b*b>3000) cout<<sum<<" "<<a*a+b*b<<endl;
	if(pow((fabs(a)+(8-sum)*6),2)+pow(fabs(b)+(8-sum)*6,2)<num1) return;
	if(!qvis&&a*a+b*b>num1&&a*a+b*b<num2) {
//		cout<<"out\n";
		qvis=1;
		get_out(num); 
	}
	if(num>cnt) {
		//cout<<sum<<" "<<a*a+b*b<<" "<<c*c+d*d<<endl;
		return;
	}
	if(!(visit&pack_v[num].vis)) {
		vis[num] = 1;
		dfs(num+1, a+pack_v[num].x, b+pack_v[num].y, visit+pack_v[num].vis, sum+1,0);
		vis[num] = 0;
	}
	dfs(num+1,a,b,visit,sum,qvis);
}
int main() {
	os.open("outCK.txt");
	ifstream in; 
	in.open("Px.csv");
	char c;
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < 4 ; j++) {
			in>>px[i].v[j];
			in>>c;
		}
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
//	in.open("Txxiu.csv");
//	for(int i = 1; i <= 32; i++) {
//		for(int j = 0; j < 4 ; j++) {
//			in>>tx[i].v[j];
//			in>>c;
//		}
//		in>>tx[i].v[4];
//	}
//	in.close();
//	in.open("Tyxiu.csv");
//	for(int i = 1; i <= 32; i++) {
//		for(int j = 0; j < 4 ; j++) {
//			in>>ty[i].v[j];
//			in>>c;
//		}
//		in>>ty[i].v[4];
//	}
//	in.close();
	in.open("outBG.txt");
	int T;
	in>>T;
	while(T) {
		//cout<<T<<endl;
		++cnt;
		for(int i = 1; i <= T; i++) {
			ac a;
			double c,d;
			in>>a.x>>a.y>>c>>d;
			pack_v[cnt].V.push_back(a);
			pack_v[cnt].x+=px[a.x].v[a.y];
			pack_v[cnt].y+=py[a.x].v[a.y];
			pack_v[cnt].vis+=(unsigned int)1<<(a.x-1);
		}
		in>>T;
	}
	cnt--;
//	for(int i = 1; i<=cnt; i++) {
//		cout<<pack_v[i].vis<<" "<<pack_v[i].x<<" "<<pack_v[i].y<<endl;
//	}
	cout<<"A"<<" "<<cnt<<endl;
	//sort(pack_v+1,pack_v+1+cnt,cmp);
	dfs(0,0,0,0,0,0);
	cout<<"cnt: "<<cnt<<endl;
	os<<0<<endl;
}
