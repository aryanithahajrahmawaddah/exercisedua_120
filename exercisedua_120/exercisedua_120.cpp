#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
	public:
		string nama;
		vector<pengarang*> daftar_pengarang;
		penerbit(string pNama) :nama(pNama) {
			cout << "penerbit \"" << nama << "\" ada\n";
		}
		~penerbit() {
			cout << "penerbit \"" << nama << "\" tidak ada \n";
		}
		void tambahpengarang(pengarang*); 
		void cetakpengarang();
};

class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" ada \n";
	}
	~pengarang() {
		cout << "pengarang \"" << nama << "\" tidak ada \n";
	}

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};
void pengarang::tambahpenerbit(penerbit* ppenerbit) {
	daftar_penerbit.push_back(ppenerbit);
	ppenerbit->tambahpengarang(this);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar penerbit dari pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

class buku {
public:
	string daftar;
	vector<buku*> daftar_buku;
};

int main() {
	penerbit* varpenerbit1 = new penerbit("Gama Press");
	penerbit* varpenerbit2 = new penerbit("Intan Pariwara");
	pengarang* varpengarang1 = new pengarang("Giga");
	pengarang* varpengarang2 = new pengarang("Joko");
	pengarang* varpengarang3 = new pengarang("Asroni");

	varpenerbit1->tambahpengarang(varpengarang1);
	varpenerbit1->tambahpengarang(varpengarang2);
	varpenerbit2->tambahpengarang(varpengarang1);
	varpenerbit2->tambahpengarang(varpengarang3);

	varpengarang1->cetakpenerbit();
	varpengarang2->cetakpenerbit();
	varpengarang3->cetakpenerbit();
	varpenerbit1->cetakpengarang();
	varpenerbit2->cetakpengarang();

	delete varpenerbit1;
	delete varpenerbit2;
	delete varpengarang1;
	delete varpengarang2;
	delete varpengarang3;

	return 0;
}