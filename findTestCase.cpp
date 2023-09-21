#include <bits/stdc++.h>
using namespace std;
void swapp (int a[100][100],int n,int x,int y){
	for (int i=0 ;i<n;i++){
		swap(a[i][x],a[i][y]);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("findTestCase.inp","r",stdin);
	freopen("findTestCase.out","w",stdout);
	
		int n,m;
		cin >> n>>m;
		int a[100][100];
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				cin >> a[i][j];
			}
		}
		int maxx=0;
		
		for (int i=0;i<n;i++){
			int tmp=0;
			//copy a sang b roi tinh toan tren hang b
			int b[100][100];
			for (int i=0;i<n;i++){
				for (int j=0;j<m;j++){
					b[i][j]=a[i][j];
				}
			}
			//end copy
			//dua cac cot co so 1 tai hang i lai gan nhau -> dem hcn -> lay max cac th
			//b1: dua cac cot co so 1 tai hang i gan nhau
			for (int j=0;j<m;j++){
				if(b[i][j]==0){
					
					for (int k=j+1;k<m;k++){
						if(b[i][k]){
							
							swapp (b,n,j,k);
							tmp +=1;
							break;
						}
					}
					
				}
				else tmp +=1;
			}
			
			// end b1

			//b2: dem hcn 
			int start=i;
			int end =i;
			//lap 1	
			while (start >0){
				int tam=start-1;			
				int c=1;
				for(int j=0;j<tmp;j++){
					if(b[tam][j]==0){
						c=0;
						break;
					}
				}
				if(c==0)break;
				start =tam;
			}
			//lap 2
			while (end <n-1){
				int tam=end+1;			
				int c=1;
				for(int j=0;j<tmp;j++){
					if(b[tam][j]==0){
						c=0;
						break;
					}
				}
				if(c==0)break;
				end =tam;
			}
			//lay max
			//test
			if(maxx<(tmp*(end-start+1)))maxx=tmp*(end-start+1);
			
		}
		cout << maxx <<endl;
	
}
