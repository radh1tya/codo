#include <stdio.h>
#include <stdlib.h>

void lihat(void) {}
void tambah(void) {

    char *isi_data;
    FILE *fptr;
    
    isi_data = malloc(256);

    while(scanf("%c", isi_data) != EOF);
    fprintf(fptr, isi_data);
    fprintf(fptr, "\n====\n");
    fclose(fptr);
}

void hapus(void) {}
void create_file(void) {
    FILE *fptr;

    fptr = fopen ("./data.txt", "a");
    
    if ( fptr == NULL ) {
	fptr = fopen ("./data.txt", "w");
	if (fptr != NULL) {
	    printf("Berhasil membuat berkas data.txt\n");
	} else {
	printf("Gagal membuat berkas data.txt\n");
	return;
	}
    }
    fclose(fptr);
}

int
main() {

    create_file();
    
    printf("todolist\n");
    printf("Silahkan pilih menu:\n1. Melihat\n2. Menambahkan\n3. Menghapus\n");

    int menu;
    scanf("%d", &menu);
    
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
