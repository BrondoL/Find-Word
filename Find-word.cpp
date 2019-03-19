#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char kata2[15];
	int cari,panjang,flag,flag2;
	char kata[15][15] =			
{{'t','g','b','w','w','i','n','t','e','r','w','s','e','s','n'},
						
{'a','a','u','n','t','t','m','m','h','f','o','o','d','n','b'},
						
{'j','l','w','c','q','l','d','z','m','p','m','v','d','m','r'},
						
{'a','s','a','g','m','q','u','w','v','v','b','s','o','h','i'},
						
{'b','w','p','l','o','t','a','n','a','d','t','p','g','n','c'},
						
{'r','e','w','n','g','o','d','j','c','p','n','a','t','n','k'},
						
{'e','e','o','t','w','o','s','b','q','h','a','r','r','s','a'},
						
{'a','z','c','g','e','s','w','e','w','n','a','k','n','p','b'},
						
{'d','i','n','n','e','r','q','o','d','l','w','d','c','a','r'},
						
{'o','n','o','p','k','w','m','p','a','r','k','t','z','c','c'},
						
{'q','b','f','r','o','g','m','a','m','w','p','w','e','e','y'},
						
{'l','q','z','q','n','n','m','r','z','j','j','s','c','l','g'},
						
{'m','o','s','g','z','c','z','d','t','d','b','o','o','t','o'},
						
{'p','d','c','r','z','m','s','n','g','r','d','n','r','p','z'},
						
{'o','h','n','k','z','w','a','t','e','r','j','g','t','r','a'}};
	for(int i=0;i<15;i++) {
		for(int j=0;j<15;j++) {
			cout<<kata[i][j]<<"  ";
		} cout<<endl;
	} cout<<endl;
	
	cout<<"Cari berapa kali : "; cin>>cari;
	for(int i=0;i<cari;i++) {
		cout<<"Masukkan kata : "; cin>>kata2;
		panjang = strlen(kata2);
		
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				if (kata2[0] == kata[i][j]){
					//kekanan
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i][j+k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//dia bawah kanan
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i+k][j+k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//bawah
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i+k][j]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//dia kiri bawah
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i+k][j-k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//kekiri
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i][j-k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//dia kiri atas
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i-k][j-k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//atas
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i-k][j]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
					
					//dia kanan atas
					for(int k=0;k<panjang;k++) {
						if(kata2[k] == kata[i-k][j+k]) {
							flag=k;
						} else {
							break;
						}
					}
					if(flag == panjang-1) {
						flag2 +=1;
					} else {
						flag2 +=0;
					}
					flag=0;
				}
			}
		}
		if(flag2>0) {
			cout<<"ada\n\n";
		}else {
			cout<<"tidak ada\n\n";
		}
	}
	
}
