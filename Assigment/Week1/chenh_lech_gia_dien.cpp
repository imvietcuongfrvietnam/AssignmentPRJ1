#include<stdio.h>
#define VAT 10

double thang_cu[7] = {0, 1728, 1786, 2074, 2612, 2919, 3015};

double thang_moi[6] = {0, 1728, 2074, 2612, 3111, 3457};

double tien_dien_gia_cu(int kWh){
	if(kWh <= 50) return thang_cu[1] * kWh;
	else if(kWh<=100) return thang_cu[2] * (kWh-50) + tien_dien_gia_cu(50);
	else if(kWh<=200) return thang_cu[3] * (kWh-100) + tien_dien_gia_cu(100);
	else if(kWh<=300) return thang_cu[4] *(kWh-200) + tien_dien_gia_cu(200);
	else if(kWh<=400) return thang_cu[5] * (kWh-300) + tien_dien_gia_cu(300);
	else return thang_cu[6] * (kWh-400) + tien_dien_gia_cu(400);
	}

double tien_dien_gia_moi(int kWh){
	if(kWh <= 100) return thang_moi[1] * kWh;
	else if(kWh<=200) return thang_moi[2] * (kWh-100) + tien_dien_gia_moi(100);
	else if(kWh<=400) return thang_moi[3] * (kWh-200) + tien_dien_gia_moi(200);
	else if(kWh<=700) return thang_moi[4] * (kWh-400) + tien_dien_gia_moi(400);
	else  return thang_moi[5] * (kWh-700) + tien_dien_gia_moi(700);
}

double tien_tinh_ca_VAT(double tien_dien){
	return tien_dien* VAT / 100 + tien_dien;
}

int main(){
	int so_kWh;
	scanf("%d",&so_kWh);
	printf("%0.2lf", tien_tinh_ca_VAT(tien_dien_gia_moi(so_kWh) -tien_dien_gia_cu(so_kWh)));
	return 0;
	
}
