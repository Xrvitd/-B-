#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<functional>
#define LL long long
#define PI acos(-1)
using namespace std;
struct xr {
	double LogMag[5][100][50];
	double Phase[5][100][50];
} tx[50];
struct P {
	double x,y;
} E[50][5][100][50];
struct ac {
	double x,y,ans;
} AnsM[100][100],AnsV[5000];
int Con[50];
bool vis[100][100];
double minAns=999;
double lenAns;
double Ans105,Ans1010;
double Ansv1,Ansmax;
int kAns;
ac acAns;
void get_in() {
	ifstream in;
	char c;
	in.open("cin2.csv");
	for(int i = 1; i <= 73 ; i++) {
		for(int l=1; l <= 4; l++) {
			for(int k=1; k <= 32; k ++) {
				for(int j = 1; j<= 37; j++) {
					in>>tx[k].Phase[l][i][j];
					if(l!=4||k!=32||j!=37)
						in>>c;
				}
			}
		}
	}
	in.close();
	in.open("cin1.csv");
	int az,el,num,config;
	for(int i=1; i<=37*73*4*32; i++) {
		//scanf("%d,%d,%d,%d",&az,&el,&num,&config);
		in>>az>>c>>el>>c>>num>>c>>config>>c;
		double xp;
		in>>tx[num].LogMag[config][az][el]>>c>>xp;
		//cout<< tx[num].LogMag[config][az][el]<<endl;
		E[num][config][az][el].x = pow(10,tx[num].LogMag[config][az][el]/20)*cos(tx[num].Phase[config][az][el]*PI/(double)180);
		E[num][config][az][el].y = pow(10,tx[num].LogMag[config][az][el]/20)*sin(tx[num].Phase[config][az][el]*PI/(double)180);
		//scanf(",%lf,%lf",&tx[num].LogMag[config][az][el],&tx[num].Phase[config][az][el]);
		//cout<<az<<" "<<el<<" "<<num<<" "<<config<<" "<<tx[num].LogMag[config][az][el]<<" "<<tx[num].Phase[config][az][el]<<endl;
		//tx[num].LogMag[config][az][el] = pow(10,tx[num].LogMag[config][az][el]/20)*cos(tx[num].Phase[config][az][el]/180*PI);

	}
	in.close();
}
inline int get_num() {
	char c;
	int f=1,num=0;
	while((c=getchar())==' '||c=='\n'||c=='\r');
	if(c=='-') f=-1;
	else num=c-'0';
	while(isdigit(c=getchar())) num=num*10+c-'0';
	return num*f;
}
bool cmp(const ac a,const ac b) {
	return a.ans>b.ans;
}
void dfs1(int x, int y) {
	if(vis[x][y]) return;
	if(x<1||y<1||x>73||y>37) return;
	if(AnsM[x][y].ans>lenAns) {
		vis[x][y] = 1;
		dfs1(x-1,y);
		dfs1(x+1,y);
		dfs1(x,y+1);
		dfs1(x,y-1);
	} else return;
}
void dfs2(double w, int x, int y) {
	if(vis[x][y]) return;
	if(x<1||y<1||x>73||y>37) return;
	if(AnsM[x][y].ans<w) {
		vis[x][y] = 1;
		dfs2(AnsM[x][y].ans,x-1,y);
		dfs2(AnsM[x][y].ans,x+1,y);
		dfs2(AnsM[x][y].ans,x,y+1);
		dfs2(AnsM[x][y].ans,x,y-1);
	} else return;
}
void solv(int num) {
	memset(AnsM,0,sizeof(AnsM));
	memset(AnsV,0,sizeof(AnsV));
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=32 ; i++) {
		for(int j=1; j<=73; j++) {
			for(int k=1; k<=37; k++) {
				AnsM[j][k].x+=E[i][Con[i]][j][k].x;
				AnsM[j][k].y+=E[i][Con[i]][j][k].y;
			}
		}
	}
	//cout<<"A";
	int cnt=0;
	double Maxs=0,Maxx=0,Maxy=0;
	for(int i=1; i<=73; i++) {
		for(int j=1; j<=37; j++) {
			//AnsM[i][j].ans=20*log10(sqrt(pow(AnsM[i][j].x,2)+pow(AnsM[i][j].y,2)));
			AnsM[i][j].ans=sqrt(pow(AnsM[i][j].x,2)+pow(AnsM[i][j].y,2));
			if(AnsM[i][j].ans>Maxs) {
				Maxs=AnsM[i][j].ans;
				Maxx=i;
				Maxy=j;
			}
		}
	}
	lenAns=Maxs/2;
	//cout<<"len: "<<lenAns<<" "<<Maxx<<" "<<Maxy<<endl;
	dfs1(Maxx,Maxy);
//	for(int i=1; i<=73; i++) {
//		for(int j=1; j<=37; j++) {
//			if(vis[i][j]) {
//				vis[i][j]=0;
//				dfs2(999,i,j);
//			}
//		}
//	} 
	/*for(int i=1; i<=73; i++) {
		for(int j=1; j<=37; j++) {
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=1; i<=73; i++) {
		for(int j=1; j<=37; j++) {
			if(!vis[i][j]) {
				AnsV[++cnt]=AnsM[i][j];
				/*if(AnsM[i][j].ans>Maxs) {
					Maxs=AnsM[i][j].ans;
					Maxx=i;
					Maxy=j;
				}*/
			}
		}
	}
	//cout<<"B";
	sort(AnsV+1,AnsV+1+cnt,cmp);
	if(minAns>sqrt(pow(AnsV[1].x,2)+pow(AnsV[1].y,2))/Maxs) {
		minAns=min(minAns,sqrt(pow(AnsV[1].x,2)+pow(AnsV[1].y,2))/Maxs);
		kAns=num;
		acAns=AnsV[1];
		Ansv1=sqrt(pow(AnsV[1].x,2)+pow(AnsV[1].y,2));
		Ansmax=Maxs;
		Ans105= 20*log10(AnsM[39][20].ans);
		Ans1010= 20*log10(AnsM[39][21].ans);

	}
	//cout<<num<<":   "<<AnsV[1].ans<<" "<<Maxs<<" "<<Maxx<<" "<<Maxy<<" "<<AnsM[39][20].ans<<'\n';

}
int main() {
	get_in();
	ofstream os;
//	os.open("out2.csv");
//	for(int i = 1; i <= 73 ; i++) {
//		for(int l=1; l <= 4; l++) {
//			for(int k=1; k <= 32; k ++) {
//				for(int j = 1; j<= 37; j++) {
//					os<<tx[k].Phase[l][i][j]<<",";
//				}
//			}
//		}
//		os<<endl;
//	}
//	os.close();
//	os.open("10 5 x.csv");
//	for(int i = 1; i <= 32 ; i++) {
//		for(int j = 1; j <= 4; j++) {
//			os<<E[i][j][39][20].x<<",";
//		}
//		os<<endl;
//	}
//	os.close();
//	for(int i=1; i<=1; i++) {
//		for(int j=1; j<=1; j++) {
//			for(int k=1; k<=73; k++) {
//				for(int l=1; l<=37; l++) {
//					cout<<E[i][j][k][l].x<<" "<<E[i][j][k][l].y<<" ";
//					cout<<endl;
//				}
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
	int T;
	ifstream in;
	in.open("outCK.txt");
	in>>T;
	while(T) {
		int a,b;
		char c;
		for(int i=1; i<=32; i++) {
			in>>a>>c>>b;
			Con[a]=b;
		}
		//if(T==58) {

		//for(int i=1; i<=32; i++) cout<<Con[i]<<" ";
		//cout<<endl;
		//cout<<T<<endl;
		solv(T);
		//}
		in>>T;
	}
	cout<<pow(minAns,2)<<endl;
	cout<<minAns<<endl;
	cout<<"Ans: "<<minAns<<" "<<kAns<<endl;
	cout<<"Ac: "<<acAns.ans<<" "<<acAns.x<<" "<<acAns.y<<endl;
	cout<<Ansv1<<" "<<Ansmax;
	os.open("outPBDP.txt"); 
	os<<"The num of CK: "<<kAns<<endl; 
	os<<pow(minAns,2)<<endl;
	return 0;
}

