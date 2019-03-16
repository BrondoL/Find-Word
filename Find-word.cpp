#include <iostream>
#include <cstring>

using namespace std;

char word[15][15]={ {'t','g','b','w','w','i','n','t','e','r','w','s','e','s','n'},
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
                    {'m','o','s','g','z','c','z','e','t','d','b','o','o','t','o'},
                    {'p','d','c','r','z','m','s','n','g','r','d','n','r','p','z'},
                    {'o','h','n','k','z','w','a','t','e','r','j','g','t','r','a'},
                };

void printword();

int main()
{
    printword();
    int jml;
    cout << endl;
    cout << "Jumlah kata yang ingin dicari ? ";
    cin >> jml;
    char kata[jml][15]; int pnjgkata[jml];
    cin.ignore();
    for(int i=0;i<jml;i++){
        cout << i+1 << ". ";
        cin.getline(kata[i], 15);
        pnjgkata[i]=strlen(kata[i]);    //Menghitung jumlah huruf pada kata
    }

	cin.get();
	return 0;
}

void printword(){
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++)
            cout << word[i][j] << "  ";
        cout << endl;
    }
}
