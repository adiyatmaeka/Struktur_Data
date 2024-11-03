/* Nama : Adiyatma Eka Saputra
Npm : 23081010134
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define maks 15

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

int jumlah = 0;

void push(node **head)
{
    if (jumlah >= maks)
    {
        printf("Stack penuh.\n");
        getch();
        return;
    }
    int angka;
    node *New;

    printf("Masukkan angka : ");
    scanf("%d", &angka);

    New = (node *)malloc(sizeof(node));

    if (New != NULL)
    {
        New->data = angka;
        New->next = *head;
        *head = New;
        jumlah++;
        printf("Angka %d berhasil ditambahkan.\n", angka);
        getch();
    }
    else
    {
        printf("Alokasi memori gagal.\n");
        getch();
    }
}

void pop(node **head)
{
    if (*head == NULL)
    {
        printf("Stack Kosong.\n");
        getch();
    }
    else
    {
        node *temp = *head;
        *head = (*head)->next;
        free(temp);
        jumlah--;
        printf("Node berhasil dihapus.\n");
        getch();
    }
}

void stacktop(node *head)
{
    if (head == NULL)
    {
        printf("Stack Kosong.\n");
        getch();
    }
    else
    {
        printf("Nilai teratas adalah : %d\n", head->data);
        getch();
    }
}
void emptystack(node *head)
{
    if (head == NULL)
    {
        printf("Stack Kosong.\n");
        getch();
    }
    else
    {
        printf("Stack tidak dalam keadaan kosong.");
        getch();
    }
}
void stackcount()
{
    printf("Jumlah data dalam stack sebanyak : %d\n", jumlah);
    getch();
}

void destroystack(node **head)
{
    while (*head != NULL)
    {
        pop(head);
    }
    printf("Stack berhasil dihapus.\n");
    getch();
}

int main()
{
    node *head = NULL;
    char pilihan;

    do
    {
        system("cls");
        printf("1. Tambahkan nilai pada stack.");
        printf("\n2. Hapus nilai pada stack.");
        printf("\n3. Tampilkan Stack top.");
        printf("\n4. Hitung jumlah stack.");
        printf("\n5. Hapus semua nilai pada stack.");
        printf("\n6. Cek apakah stack dalam keadaan kosong.");
        printf("\nMasukkan pilihan anda (Tekan 's' untuk keluar): ");
        scanf(" %c", &pilihan);

        system("cls");

        switch (pilihan)
        {
        case '1':
            push(&head);
            break;
        case '2':
            pop(&head);
            break;
        case '3':
            stacktop(head);
            break;
        case '4':
            stackcount();
            break;
        case '5':
            destroystack(&head);
            break;
        case '6':
            emptystack(head);
            break;
        }
    } while (pilihan != 's');

    return 0;
}
