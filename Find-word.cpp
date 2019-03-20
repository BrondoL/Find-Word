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
int dkb(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Diagonal kanan bawah
int dKa(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Diagonal Kiri atas
int dka(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Diagonal kanan atas
int dKb(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Diagonal Kiri bawah
int va(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Vertikal Atas
int vb(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Vertikal Bawah
int hk(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Horizontal Kanan
int hK(int &, int &, int &, int cval, int c2val, int *, char (*kval)[15], char (*wval)[15]); // Horizontal Kiri

int main()
{
    char lagi = 'y';
    do{
            printword();

            // Jumlah kata yang dicari
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
            // ToUpper
            for(int i=0;i<jml;i++){
                for(int j=0;j<pnjgkata[i];j++){
                    if((int)kata[i][j] < 97 || (int)kata[i][j] > 122)
                        continue;
                    else
                        kata[i][j] = (char)((int)kata[i][j] - 32);
                }
            }
            // Mencari Kata
            int cek=0,cek2=0;
            for(int x=0;x<jml;x++){
                for(int i=0;i<15;i++){
                    for(int j=0;j<15;j++){
                        if(kata[x][0]==word[i][j]){
                            cek2 = dkb(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = dKa(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = dka(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = dKb(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = va(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = vb(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = hk(x, i, j, cek, cek2, pnjgkata, kata, word);
                            cek2 = hK(x, i, j, cek, cek2, pnjgkata, kata, word);
                        }
                    }
                }
            // OUTPUT
            if(x==0){
                cout << endl << "===================" << endl;
                cout << "||    RESULT :   ||" << endl;
                cout << "===================" << endl << endl;
            }
            cout << x+1 << ". ";
            if(cek2>0){
                cout << " Ada !";
                cek2 = 0;
            }else
                cout << " Tidak ada !";
                cout << endl;
            }
            cout << endl << "Ingin mencoba lagi ?(y/n) ";cin>>lagi;
    }while(lagi == 'y');
	cin.get();
	return 0;

}

void printword(){
	cout<<"\t\t      GAME FIND WORD"<<endl;
    for(int i=0;i<15;i++){
        cout << "-----------------------------------------------------------"<<endl;
        for(int j=0;j<15;j++)
            cout << word[i][j] << " | ";
        cout << endl;
        if(i==14)
            cout << "-----------------------------------------------------------";
    }
}
int dkb(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival+k][jval+k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int dKa(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival-k][jval-k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int dka(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival-k][jval+k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int dKb(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival-k][jval+k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int va(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival+k][jval]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int vb(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival-k][jval]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int hk(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival][jval+k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
int hK(int &xval, int &ival, int &jval, int cval, int c2val, int *valpnjg, char (*kval)[15], char (*wval)[15]){
    for(int k=0;k<*(valpnjg+xval);k++){
        if(kval[xval][k]==wval[ival][jval-k]){
            cval=k;
        }else
        break;
    }
    if(cval == (*(valpnjg+xval)-1)) {
        c2val +=1;
    } else {
        c2val +=0;
    }
    return c2val;
}
