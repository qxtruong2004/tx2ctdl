// nhung phan co ban cua danh sach moc noi don
#include <iostream>
#include <iomanip>
using namespace std;
struct sinhvien{
	string ten;
	int tuoi;
	string diachi;
	double diem;
};
//kieu du lieu cua node
struct Node{
	sinhvien infor;
	Node *next;
};
typedef Node *tro;
tro L;
// khoi tao danh sach rong
void create (tro &L){
	L = NULL;
}
//kiem tra danh sach rong
int ktra(tro L){
	return L == NULL;
}
void nhapsv(sinhvien &X){
	fflush(stdin); 
	cout << "Nhap ten: ";
	getline(cin, X.ten);
	cout <<"Nhap tuoi: ";
	cin >> X.tuoi;
	fflush(stdin);
	cout << "Nhap dia chi: ";
	getline(cin, X.diachi);
	cout << "Nhap diem: ";
	cin >> X.diem;
	cout << "*******\n";
}
void nhap(tro &L){
	tro Q, P;
	sinhvien X;
	int d = 0;
	L = NULL;
	do{
		nhapsv(X);
		P = new Node;
		P->infor = X;
		P->next = NULL;
		if(L == NULL){
			L = P;
		}
		else{
			Q->next = P;
		}
		Q = P;
		d++;
	}
	while (d < 3);
}
void hienthi(tro &L){
	tro Q = L;
	if ( L == NULL) cout << "Khong hop le";
	cout << setw(10) << "Ten SV";
	cout << setw(5) << "Tuoi";
	cout << setw(10) << "Dia chi";
	cout << setw(6) << "Diem";
	cout << endl;
	while( Q != NULL){
		sinhvien x = Q->infor;
		cout << setw(10) << x.ten;
		cout << setw(5) << x.tuoi;
		cout << setw(10) << x.diachi;
		cout << setw(6) << x.diem;
		cout << endl;
		Q = Q->next;
	}
}
//tim  kiem sinh vien theo tuoi 
void find(tro L){
	tro P = NULL, Q = L, previous = NULL;
	int age, d = 0;
	cout << "Nhap tuoi ban can tim: ";
	cin >> age;
	while (Q != NULL ){
		if(Q->infor.tuoi == age){
			tro temp = new Node;
			temp->infor = Q->infor;
			temp->next = NULL;
			if(P == NULL){
				P = temp;
			}
			else{
				previous->next = temp;
			}
			previous = temp;
			d++;
		}
		Q = Q->next;
	}
	if(d == 0) cout << "Khong co sinh vien nao co tuoi nhu vay";
	else {
		cout << "Da tim thay" << endl;
		hienthi(P);
	}
}
//chen vao vi tri bat ki( can tim vi tri de chen truoc)
void chen(tro &L){
	tro P = L;
	int n, i = 1;
	//xac dinh chieu dai cua danh sach
	int res = 0;
	while(P!= NULL){
		res++;
		P = P->next;
	} 
	cout << "Nhap vi tri can chen: "; cin >> n;
	if(n <= 0 || n > res + 1) cout << " Vi tri chen khong hop le";
	//nhap thong tin can chen
	sinhvien x;
	nhapsv(x);
	// tao 1 con tro chua thong tin vua nhap
	tro Q = new Node;
	Q->infor = x;
	//neu vi tri tren la dau tien
	if( n == 1){
		Q->next = L;
		L = Q;
	}
	// neu vi tri chen bat ki ta can tim vi tri truoc vi tri chen: vd chen truoc 3 thi tim vi tri 2
	else{
		while( P != NULL && i < n - 1){
			P = P->next;
			i++;
		}
	// tim duoc vi tri chen (P) => chen
	Q->next = P->next;
	P->next = Q;
	}
	
}
//xoa 1 node bat ki trong danh sach
void xoa(tro &L){
// xac dinh do dai cua danh sach
	int res = 0;
	int i = 1;
	tro P = L;
	while( P != NULL){
		res ++;
		P = P->next;
	}
	int n;
	cout << "Nhap vi tri muon xoa: "; cin >> n;
	if(n <= 0 || n > res) cout << "Vi tri xoa khong hop le";
// truong hop xoa node dau
	if(n == 1){
		tro Q;
		Q = L;
		L = L->next;
		delete Q;
	}
// truong hop xoa node bat ki va node cuoi
// tim vi tri can xoa(tim node dung truoc not can xoa
	else{
		
		while(P->next != NULL && i < n - 1 ){
		i++;
		P = P->next;
		}
	//chen tai vt 3 -> da tim thay vi tri 2
	tro Q;
	Q = P->next; // tro con xoa
	P->next = Q->next; // tro phia sau con tro can xoa
	delete Q;
	}
}
//hien thi danh sach sinh vien co diem tong ket >8.5
void chon(tro L) {
    tro P = L;
    int ret = 0;
    tro Q = NULL;
    tro danhSachDiemCao = NULL; // Danh sách m?i ch?a sinh viên có di?m > 8.5

    while (P != NULL) {
        sinhvien x = P->infor;
        if (x.diem >= 8.5) {
            ret++;
            if (Q == NULL) {
                Q = new Node; // T?o m?t nút m?i cho sinh viên có di?m > 8.5
               Q->infor = x;
               danhSachDiemCao = Q; // C?p nh?t danh sách m?i
         } else {
                Q->next = new Node; // T?o nút m?i cho sinh viên có di?m > 8.5
                Q = Q->next;
                Q->infor = x;
            }
        }
        P = P->next;
    }

   if (ret == 0)
       cout << "Không có sinh viên nào có di?m trên 8.5";
    else {
        cout << "Danh sách sinh viên có di?m > 8.5\n";
       hienthi(danhSachDiemCao); // Hi?n th? danh sách m?i
    }
}
//void chon(tro L){
//	tro P = L;
//	while (P!= NULL){
//		if(P->infor.diem > 6.5){
//			sinhvien x = P->infor;
//			cout << x.ten << " " << x.diachi << " " << x.tuoi << " " << x.diem << endl;
//		}
//		P = P->next;
//	}
//} 

//sap xep diem tang dan
//(chi thay doi infor chu khong thay doi cau truc)
void sapxep(tro &L){
	tro P = L;
	sinhvien x;
	while(P != NULL){
		tro Q = P->next;
		while(Q!= NULL){
			if(P->infor.diem > Q->infor.diem){
				x = P->infor;
				P->infor = Q->infor;
				Q->infor = x;
			}
			Q = Q->next;
		}
		P = P->next;
	}
}
//tim kiem diem max
double timdiemmax(tro &L){
	tro P = L;
	double diemmax = 0;
	while(P != NULL){
		if(P->infor.diem >= diemmax){
			diemmax = P->infor.diem;
		}
		P= P->next;
	}
	return diemmax;
}
// xoa con tro chua diem max
void dele(tro& L) {
    tro P = L;
    double x = timdiemmax(L);
    tro previous = NULL;

    while (P != NULL) {
        if (P->infor.diem == x) {
            if (previous == NULL) {
                L = P->next; // N?u dây là node d?u tiên, c?p nh?t con tr? d?u danh sách
            } else {
                previous->next = P->next;
            }

            tro Q = P;
            P = P->next;
            delete Q;
        } else {
            previous = P;
            P = P->next;
        }
    }
}
void tinhdiemtb(tro &L){
	tro P = L;
	int res = 0;
	double sum = 0;
	while(P!= NULL){
		sum += P->infor.diem;
		res ++;
		P = P->next;
	}
	cout << "Diem trung binh cua cac sinh vien la: " << (sum / res);
}
int main(){
	tro L;
	sinhvien X;
	nhap(L);
	hienthi(L);
	//chen(L);
	//xoa(L);
	//hienthi(L);
	//chon(L);
	//sapxep(L);
	//dele(L);
	//hienthi(L);
	tinhdiemtb(L);
	return 0;
}
