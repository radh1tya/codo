#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lihat(void) {}
void tambah(void) {

    char *isi_data;
    char *kombinasi_isi_data;
    
    FILE *fptr;
    
    isi_data = malloc(256);
    kombinasi_isi_data = malloc(256);
    
    if (isi_data == NULL || kombinasi_isi_data == NULL ) {
	fprintf(stderr, "Gagal alokasiin memory isi_data :(\n");
	free(isi_data);
	free(kombinasi_isi_data);
	return;
    }

    kombinasi_isi_data[0] = '\0';

    size_t kombinasi_ukuran = 256;
    size_t kombinasi_panjang = 0;
    
    while(fgets(isi_data, 256, stdin) != NULL) {
	isi_data[strcspn(isi_data, "\n")] = 0;

	size_t isi_panjang = strlen(isi_data);
	if ( kombinasi_panjang + isi_panjang + 1 >= kombinasi_ukuran) {
	    kombinasi_ukuran *= 2;
	    char *temp = realloc(kombinasi_isi_data, kombinasi_ukuran);
	    if(temp == NULL) {
		fprintf(stderr, "Gagal realloc memory :(\n");
		free(isi_data);
		free(kombinasi_isi_data);
		return;
	    }
	    kombinasi_isi_data = temp;
	}
	strcat(kombinasi_isi_data, isi_data);
	kombinasi_panjang += isi_panjang;
    }

    fptr = fopen("./data.txt", "a");
    if (fptr == NULL) {
	fprintf(stderr, "Tidak bisa membuka data.txt :(\n");
	free(isi_data);
	return;
    }
   
    fprintf(fptr,"%s\n", kombinasi_isi_data);
    fprintf(fptr, "====\n");

    if (fclose(fptr) != 0) {
	fprintf(stderr, "Data.txt tidak ingin ditutup\n");
    }
    
    free(isi_data);
    free(kombinasi_isi_data);
  }

void hapus(void) {}
void create_file(void) {
    FILE *fptr;
    fptr = fopen("./data.txt", "a");
if (fptr != NULL) {
    printf("Berhasil membuat atau menimpa berkas data.txt\n");
    fclose(fptr);
} else {
    printf("Gagal membuat berkas data.txt\n");
}

}

int
main() {

    create_file();
    
    printf("todolist\n");
    printf("Silahkan pilih menu:\n1. Melihat\n2. Menambahkan\n3. Menghapus\n");

    int menu;
    scanf("%d", &menu);
    getchar();
    
    switch (menu) {
	case 1:
	    lihat();
	    break;
    case 2:
	tambah();
	break;
    case 3:
	hapus();
	break;
    }
    
    return 0;
}
