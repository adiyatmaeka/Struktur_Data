/* Nama = Adiyatma Eka Saputra
     Npm = 23081010134
  */
//======================================
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *selanjutnya;
};
typedef struct node node;

void Tambah_Awal(node **head);
void Tambah_Data(node **head);
void Tambah_Akhir(node **head);
void Hapus_Awal(node **head);
void Hapus_Tengah(node **head);
void Hapus_Akhir(node **head);
void TampilSemuaData(node *head);
int HitungJumlah(node *head);
int JumlahData(node *head);
node *Cari_Data(node *head, int angka);
//========================================
int main()
{
    node *head = NULL;
    char pilihan;
    int angka;

    do
    {
        system("cls");
        printf("Masukkan pilihan anda:\n");
        printf("1. Tambahkan data di awal\n");
        printf("2. Tambahkan data di tengah list\n");
        printf("3. Tambahkan data di akhir\n");
        printf("4. Hapus data awal \n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Tampilkan semua data\n");
        printf("9. Tampilkan jumlah data\n");
        printf("0. Tampilkan hasil penjumlahan semua data\n");
        printf("Masukkan pilihan anda (Tekan 's' untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilihan);

        switch (pilihan)
        {
        case '1':
            Tambah_Awal(&head);
            break;
        case '2':
            Tambah_Data(&head);
            break;
        case '3':
            Tambah_Akhir(&head);
            break;
        case '4':
            Hapus_Awal(&head);
            break;
        case '5':
            Hapus_Tengah(&head);
            break;
        case '6':
            Hapus_Akhir(&head);
            break;
        case '7':
            printf("\nMasukkan data yang ingin dicari: ");
            scanf("%d", &angka);
            node *hasil = Cari_Data(head, angka);
            if (hasil != NULL)
            {
                printf("Data %d ditemukan!\n", hasil->data);
            }
            else
            {
                printf("Data %d tidak ditemukan.\n", angka);
            }
            getch();
            break;
        case '8':
            TampilSemuaData(head);
            getch();
            break;
        case '9':
            printf("\nJumlah data dalam linked list: %d\n", HitungJumlah(head));
            getch();
            break;
        case '0':
            printf("\nHasil penjumlahan semua data: %d\n", JumlahData(head));
            getch();
            break;
        }

    } while (pilihan != 's');

    return 0;
}

//=================================================
void Tambah_Awal(node **head)
{
    int angka;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node)); // alokasi memori untuk node  baru

    if (pNew != NULL)
    {
        pNew->data = angka;
        if (*head == NULL)
        {
            pNew->selanjutnya = pNew; // jika list kosong node akan menunjuk dirinya sendiri
        }
        else
        {
            pCur = *head;
            while (pCur->selanjutnya != *head)
            {
                pCur = pCur->selanjutnya;
            }
            pNew->selanjutnya = *head;
            pCur->selanjutnya = pNew;
        }
        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }
}
//=====================================================
void Tambah_Data(node **head)
{
    int pos, angka;
    node *pNew, *pCur;

    system("cls");
    TampilSemuaData(*head);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    pCur = *head;
    while (pCur->data != pos && pCur->selanjutnya != *head)
    {
        pCur = pCur->selanjutnya;
    }

    pNew = (node *)malloc(sizeof(node));

    if (pCur->data != pos)
    {
        printf("\nNode tidak ditemukan\n");
        getch();
    }
    else if (pNew == NULL)
    {
        printf("\nAlokasi memori gagal\n");
        getch();
    }
    else
    {
        pNew->data = angka;
        pNew->selanjutnya = pCur->selanjutnya;
        pCur->selanjutnya = pNew;
    }
}
//================================================
void Tambah_Akhir(node **head)
{
    int angka;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL)
    {
        printf("Alokasi memori gagal");
        getch();
        return;
    }

    pNew->data = angka;

    if (*head == NULL)
    {
        *head = pNew;
        pNew->selanjutnya = pNew;
    }
    else
    {
        pCur = *head;
        while (pCur->selanjutnya != *head)
        {
            pCur = pCur->selanjutnya;
        }
        pCur->selanjutnya = pNew;
        pNew->selanjutnya = *head;
    }
}
//====================================================
void Hapus_Awal(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *temp = *head, *pCur = *head;

    if ((*head)->selanjutnya == *head)
    {
        *head = NULL;
    }
    else
    {
        while (pCur->selanjutnya != *head)
        {
            pCur = pCur->selanjutnya;
        }
        *head = (*head)->selanjutnya; // mengatur head ke node selanjutnya
        pCur->selanjutnya = *head;
    }

    free(temp); // menghapus node awal
    printf("Node di awal berhasil dihapus.\n");
}
//===================================================
void Hapus_Tengah(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    TampilSemuaData(*head);

    int data;
    printf("\nMasukkan nilai data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &data);

    node *pCur = *head, *pPrev = NULL;

    while (pCur->data != data && pCur->selanjutnya != *head)
    {
        pPrev = pCur;
        pCur = pCur->selanjutnya;
    }

    if (pCur->data != data)
    {
        printf("Data %d tidak ditemukan\n", data);
        return;
    }

    if (pCur == *head)
    {
        Hapus_Awal(head);
        return;
    }

    pPrev->selanjutnya = pCur->selanjutnya;
    free(pCur);
    printf("Node dengan data %d berhasil dihapus.\n", data);
}
//====================================================
void Hapus_Akhir(node **head)
{
    if (*head == NULL)
    {
        printf("List kosong\n");
        return;
    }

    node *pCur = *head, *pPrev = NULL;

    if ((*head)->selanjutnya == *head) // Jika hanya ada satu node
    {
        free(*head);
        *head = NULL;
        printf("Node di akhir berhasil dihapus.\n");
        return;
    }

    while (pCur->selanjutnya != *head)
    {
        pPrev = pCur;
        pCur = pCur->selanjutnya;
    }

    pPrev->selanjutnya = *head;
    free(pCur);
    printf("Node di akhir berhasil dihapus.\n");
}
//================================================
node *Cari_Data(node *head, int angka)
{
    if (head == NULL)
        return NULL;

    node *pCur = head;
    do
    {
        if (pCur->data == angka)
        {
            return pCur;
        }
        pCur = pCur->selanjutnya;
    } while (pCur != head);

    return NULL;
}
//==================================================
void TampilSemuaData(node *head)
{
    if (head == NULL)
    {
        printf("Linked list kosong\n");
        return;
    }

    node *pWalker = head;

    system("cls");
    printf("Data dalam linked list:\n");
    do
    {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->selanjutnya;
    } while (pWalker != head);

    printf("HEAD\n");
}
//==========================================================
int HitungJumlah(node *head)
{
    if (head == NULL)
        return 0;

    int jumlah = 0;
    node *pWalker = head;

    do
    {
        jumlah++;
        pWalker = pWalker->selanjutnya;
    } while (pWalker != head);

    return jumlah;
}

//================================================
int JumlahData(node *head)
{
    if (head == NULL)
        return 0;

    int total = 0;
    node *pWalker = head;

    do
    {
        total += pWalker->data;
        pWalker = pWalker->selanjutnya;
    } while (pWalker != head);

    return total;
}
