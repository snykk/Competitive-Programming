#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	int t; // t seleksi
	cin >> t;
	assert(1<=t<=8);
	while (t){
		int n,m; // n peserta, m lulus
		string id;
		cin >> n >> m >> id;
		assert(1<=n<=80);
		assert(0<=m<=n);
		int target_id;
		int cek = 0;
		string id_peserta[n];
		int sesi1[n],sesi2[n],sesi3[n];
		for (int i=0;i<n;i++){
			cin >> id_peserta[i] >> sesi1[i] >> sesi2[i] >> sesi3[i];
			if (id == id_peserta[i]){
				target_id = i;
			}
		}
		for (int i=0;i<n;i++){
			if (target_id!=i and sesi3[target_id] < sesi3[i]){
				cek += 1;				 
			} else if (target_id!=i and sesi3[target_id] == sesi3[i]){
				if (sesi2[target_id] < sesi2[i]){
					cek +=1;
				} else if (sesi2[target_id] == sesi2[i]){
					if (sesi1[target_id] < sesi1[i]){
						cek +=1;
					}
				}
			}
		}
		if (cek<m){
			cout << "YA" << endl;
		} else {
			cout << "TIDAK" << endl;
		}
		
		t--;
	}
	
	return 0;
}
