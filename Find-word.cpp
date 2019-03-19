#include <iostream>
#include <cstring>

using namespace std;

char word[15][15]={ {'T','G','B','W','W','I','N','T','E','R','W','S','S','S','N'},
                    {'A','A','U','N','T','T','M','M','H','F','O','O','D','N','B'},
                    {'J','L','W','C','Q','L','D','Z','M','P','M','V','D','M','R'},
                    {'A','S','A','G','M','Q','U','W','V','V','B','S','O','H','I'},
                    {'B','W','P','L','O','T','A','N','A','D','T','P','G','N','C'},
                    {'R','E','W','N','G','O','D','J','C','P','N','A','T','N','K'},
                    {'E','E','O','T','W','O','S','B','Q','H','A','R','R','S','A'},
                    {'A','Z','C','G','E','S','W','E','W','N','A','K','N','P','B'},
                    {'D','I','N','N','E','R','Q','O','D','L','W','D','C','A','R'},
                    {'O','N','O','P','K','W','M','P','A','R','K','T','Z','C','C'},
                    {'Q','B','F','R','O','G','M','A','M','W','P','W','E','E','Y'},
                    {'L','Q','Z','Q','N','N','M','R','Z','J','J','S','C','L','G'},
                    {'M','O','S','G','Z','C','Z','E','T','D','B','O','O','T','O'},
                    {'P','D','C','R','Z','M','S','N','G','R','D','N','R','P','Z'},
                    {'O','H','N','K','Z','W','A','T','E','R','J','G','T','R','A'},
                };

void printword();
void dkb(int &, int &, int &, char (*wordval)[15]);

int main()
{
    printword();

    //  Jumlah kata yang dicari
    int jml;
    cout << endl << endl;
    cout << "\tJumlah kata yang ingin dicari ? ";
    cin >> jml;
    char kata[jml][15]; int pnjgkata[jml];
    cin.ignore();
    // Input kata
    for(int i=0;i<jml;i++){
        cout << i+1 << ". ";
        cin.getline(kata[i], 15);
        pnjgkata[i]=strlen(kata[i]);    //Menghitung jumlah huruf pada kata
    }

    // Mencari Kata
    int cek=0,cek2=0;
    for(int x=0;x<jml;x++){
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                if(kata[x][0]==word[i][j]){
                    // Diagonal bawah kanan
                    // ==================================
                    for(int k=0;k<pnjgkata[x];k++){
                        if(kata[x][k]==word[i+k][j+k]){
                            cek=k;
                        }else
                            break;
                    }
                    if(cek == (pnjgkata[x]-1)) {
                        cek2 +=1;
                    } else {
                        cek2 +=0;
                    }
                    cek=0;
                    // ==================================
                    // Diagonal Kiri Atas
                    for(int k=0;k<pnjgkata[x];k++){
                        if(kata[x][k]==word[i-k][j-k]){
                            cek=k;
                        }else
                            break;
                    }
                    if(cek == (pnjgkata[x]-1)) {
                        cek2 +=1;
                    } else {
                        cek2 +=0;
                    }
                    cek=0;
                    // ===================================
                    // Diagonal kanan atas
                    for(int k=0;k<pnjgkata[x];k++){
                        if(kata[x][k]==word[i-k][j+k]){
                            cek=k;
                        }else
                            break;
                    }
                    if(cek == (pnjgkata[x]-1)) {
                        cek2 +=1;
                    } else {
                        cek2 +=0;
                    }
                    cek=0;
                    // ===================================
                    // Diagonal kiri bawah
                    for(int k=0;k<pnjgkata[x];k++){
                        if(kata[x][k]==word[i+k][j-k]){
                            cek=k;
                        }else
                            break;
                    }
                    if(cek == (pnjgkata[x]-1)) {
                        cek2 +=1;
                    } else {
                        cek2 +=0;
                    }
                    cek=0;
                    // ===================================

                }
            }
        }
        if(cek2>0){
            cout << "Ada !";
            cek2 = 0;
        }else
            cout << "Tidak ada !";
    }

	cin.get();
	return 0;
}

void printword(){
    for(int i=0;i<15;i++){
        cout << "-----------------------------------------------------------"<<endl;
        for(int j=0;j<15;j++)
            cout << word[i][j] << " | ";
        cout << endl;
        if(i==14)
            cout << "-----------------------------------------------------------";
    }
}
