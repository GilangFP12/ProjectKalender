#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int countworld = 50;

struct geser
{
    struct jadwal
    {
        int jam;
        int menit;
        int tanggalkegiatan;
        char namakegiatan[30];
        char lokasi[30];
        struct jadwal *next, *prev;
    } * head, *current, *tail;

} listgeser[MAX];

void pushHead(int tanggalkegiatan, char namakegiatan[], char lokasi[], int jam, int menit)
{
    listgeser[countworld].current = (struct jadwal *)malloc(sizeof(struct jadwal));
    listgeser[countworld].current->tanggalkegiatan = tanggalkegiatan;
    listgeser[countworld].current->jam = jam;
    listgeser[countworld].current->menit = menit;
    strcpy(listgeser[countworld].current->namakegiatan, namakegiatan);
    strcpy(listgeser[countworld].current->lokasi, lokasi);
    listgeser[countworld].current->next = listgeser[countworld].current->prev = NULL;
    if (listgeser[countworld].head == NULL)
    {
        listgeser[countworld].head = listgeser[countworld].tail = listgeser[countworld].current;
    }
    else
    {
        listgeser[countworld].head->prev = listgeser[countworld].current;
        listgeser[countworld].current->next = listgeser[countworld].head;
        listgeser[countworld].head = listgeser[countworld].current;
    }
}

void pushTail(int tanggalkegiatan, char namakegiatan[], char lokasi[], int jam, int menit)
{
    listgeser[countworld].current = (struct jadwal *)malloc(sizeof(struct jadwal));
    listgeser[countworld].current->tanggalkegiatan = tanggalkegiatan;
    listgeser[countworld].current->jam = jam;
    listgeser[countworld].current->menit = menit;
    strcpy(listgeser[countworld].current->namakegiatan, namakegiatan);
    strcpy(listgeser[countworld].current->lokasi, lokasi);
    listgeser[countworld].current->next = listgeser[countworld].current->prev = NULL;
    if (listgeser[countworld].head == NULL)
    {
        listgeser[countworld].head = listgeser[countworld].tail = listgeser[countworld].current;
    }
    else
    {
        listgeser[countworld].current->prev = listgeser[countworld].tail;
        listgeser[countworld].tail->next = listgeser[countworld].current;
        listgeser[countworld].tail = listgeser[countworld].current;
    }
}

void pushMiddle(int tanggalkegiatan, char namakegiatan[], char lokasi[], int jam, int menit)
{
    listgeser[countworld].current = (struct jadwal *)malloc(sizeof(struct jadwal));
    listgeser[countworld].current->tanggalkegiatan = tanggalkegiatan;
    listgeser[countworld].current->jam = jam;
    listgeser[countworld].current->menit = menit;
    strcpy(listgeser[countworld].current->namakegiatan, namakegiatan);
    strcpy(listgeser[countworld].current->lokasi, lokasi);

    if (listgeser[countworld].head == NULL)
    {
        pushHead(tanggalkegiatan, namakegiatan, lokasi, jam, menit);
    }
    else if (tanggalkegiatan < listgeser[countworld].head->tanggalkegiatan)
    {
        pushHead(tanggalkegiatan, namakegiatan, lokasi, jam, menit);
    }
    else if (tanggalkegiatan > listgeser[countworld].tail->tanggalkegiatan)
    {
        pushTail(tanggalkegiatan, namakegiatan, lokasi, jam, menit);
    }
    else if (tanggalkegiatan == listgeser[countworld].head->tanggalkegiatan)
    {
        pushHead(tanggalkegiatan, namakegiatan, lokasi, jam, menit);
    }
    else
    {
        listgeser[countworld].current->next = listgeser[countworld].current->prev = NULL;
        struct jadwal *temp = listgeser[countworld].head;
        while (temp != NULL && temp->tanggalkegiatan < listgeser[countworld].current->tanggalkegiatan)
        {
            temp = temp->next;
        }
        listgeser[countworld].current->prev = temp->prev;
        listgeser[countworld].current->next = temp;
        temp->prev->next = listgeser[countworld].current;
        temp->prev = listgeser[countworld].current;
    }
}

void delHead()
{
    listgeser[countworld].current = listgeser[countworld].head;
    if (listgeser[countworld].head == NULL)
    {
        printf("No Data");
    }
    else if (listgeser[countworld].head == listgeser[countworld].tail)
    {
        listgeser[countworld].head = listgeser[countworld].tail = NULL;
        free(listgeser[countworld].current);
    }
    else
    {
        listgeser[countworld].head = listgeser[countworld].head->next;
        listgeser[countworld].head->prev = NULL;
        free(listgeser[countworld].current);
    }
}

void delTail()
{
    listgeser[countworld].current = listgeser[countworld].tail;
    if (listgeser[countworld].head == NULL)
    {
        printf("No Data");
    }
    else if (listgeser[countworld].head == listgeser[countworld].tail)
    {
        listgeser[countworld].head = listgeser[countworld].tail = NULL;
        free(listgeser[countworld].current);
    }
    else
    {
        listgeser[countworld].tail = listgeser[countworld].tail->prev;
        listgeser[countworld].tail->next = NULL;
        free(listgeser[countworld].current);
    }
}

void delMiddle(int tanggaljadwal)
{
    if (listgeser[countworld].head == NULL)
    {
        printf("No Data");
    }
    else
    {
        listgeser[countworld].current = listgeser[countworld].head;
        while (listgeser[countworld].current != NULL)
        {
            if (listgeser[countworld].current->tanggalkegiatan == tanggaljadwal)
            {
                if (listgeser[countworld].current == listgeser[countworld].head)
                {
                    delHead();
                }
                else if (listgeser[countworld].current == listgeser[countworld].tail)
                {
                    delTail();
                }
                else
                {
                    listgeser[countworld].current->prev->next = listgeser[countworld].current->next;
                    listgeser[countworld].current->next->prev = listgeser[countworld].current->prev;
                }
                break;
            }
            listgeser[countworld].current = listgeser[countworld].current->next;
            if (listgeser[countworld].current->tanggalkegiatan != tanggaljadwal)
            {
                if (listgeser[countworld].current->next == NULL)
                {
                    printf("INVALID ID");
                }
            }
        }
    }
}

void cetak()
{
    int nomer = 1;
    listgeser[countworld].current = listgeser[countworld].head;
    if (listgeser[countworld].current != NULL)
    {
        printf("\n\n===========================================================================================================\n");
        printf("No\t\tTgl.\t\t\tNama Kegiatan\t\tLokasi\t\tJam\n");
        printf("===========================================================================================================\n");
        while (listgeser[countworld].current != NULL)
        {

            if (listgeser[countworld].current->menit == 0)
            {
                printf("%d\t\t%d\t\t\t%s\t\t\t%s\t\t%d.00\n", nomer, listgeser[countworld].current->tanggalkegiatan, listgeser[countworld].current->namakegiatan, listgeser[countworld].current->lokasi, listgeser[countworld].current->jam);
            }
            else
            {
                printf("%d\t\t%d\t\t\t%s\t\t\t%s\t\t%d.%d\n", nomer, listgeser[countworld].current->tanggalkegiatan, listgeser[countworld].current->namakegiatan, listgeser[countworld].current->lokasi, listgeser[countworld].current->jam, listgeser[countworld].current->menit);
            }
            listgeser[countworld].current = listgeser[countworld].current->next;
            nomer++;
        }
    }
    else
    {
        printf("\n\n===========================================================================================================\n");
        printf("No\t\tTgl.\t\t\tNama Kegiatan\t\tLokasi\t\tJam\n");
        printf("===========================================================================================================\n");
        printf("No Data\n");
    }
}

int hitung_Year(int thn)
{
    int jmlDay = 0, year;
    for (year = 1900; year < thn; year++)
    {
        if (year % 4 == 0)
        {
            jmlDay += 366;
        }
        else
        {
            jmlDay += 365;
        }
    }
    return (jmlDay);
}

int hitung_Month(int thn, int bln)
{
    int jmlDay = 0, Month;
    for (Month = 1; Month < bln; Month++)
    {
        if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
        {
            jmlDay += 31;
        }
        else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        {
            jmlDay += 30;
        }
        else
        {
            if (thn % 4 == 0)
            {
                jmlDay += 29;
            }
            else
                jmlDay += 28;
        }
    }
    return (jmlDay);
}

int cek_Day(int jmlDay)
{
    int Day = jmlDay % 7;
    return (Day);
}

int hitung_Day(int Month, int thn)
{
    int jmlDay = 0;
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        jmlDay += 31;
    }
    else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
    {
        jmlDay += 30;
    }
    else
    {
        if (thn % 4 == 0)
            jmlDay += 29;
        else
            jmlDay += 28;
    }
    return (jmlDay);
}

int main()
{
    int thn, bln, jmlDay, jumlah_Day, Day;
    int button;
    int no;
    char namajadual[30];
    char letak[30];
    int tanggaljadwal;
    int jam;
    int menit;

    printf("Tahun : ");
    scanf("%d", &thn);
    fflush(stdin);
    do
    {
        printf("Bulan : ");
        scanf("%d", &bln);
        fflush(stdin);
    } while (bln < 1 || bln > 12);

    system("cls");

    do
    {
        if (bln == 1)
        {
            printf("Kalender : Januari %d", thn);
        }
        else if (bln == 2)
        {
            printf("Kalender : Februari %d", thn);
        }
        else if (bln == 3)
        {
            printf("Kalender : Maret %d", thn);
        }
        else if (bln == 4)
        {
            printf("Kalender : April %d", thn);
        }
        else if (bln == 5)
        {
            printf("Kalender : Mei %d", thn);
        }
        else if (bln == 6)
        {
            printf("Kalender : Juni %d", thn);
        }
        else if (bln == 7)
        {
            printf("Kalender : Juli %d", thn);
        }
        else if (bln == 8)
        {
            printf("Kalender : Agustus %d", thn);
        }
        else if (bln == 9)
        {
            printf("Kalender : September %d", thn);
        }
        else if (bln == 10)
        {
            printf("Kalender : Oktober %d", thn);
        }
        else if (bln == 11)
        {
            printf("Kalender : November %d", thn);
        }
        else if (bln == 12)
        {
            printf("Kalender : Desember %d", thn);
        }

        jmlDay = hitung_Year(thn) + hitung_Month(thn, bln);
        Day = cek_Day(jmlDay);
        jumlah_Day = hitung_Day(bln, thn);

        printf("\n\n=====================================================\n");
        printf("Min\tSen\tSel\tRab\tKam\tJum\tSab\n");
        printf("=====================================================\n");

        for (int i = 0; i < Day; i++)
        {
            printf("\t");
        }
        for (int i = 1; i <= jumlah_Day; i++)
        {
            printf("%d\t", i);
            if (Day % 7 == 6)
                printf("\n");

            Day++;
        }

        cetak();
        printf("\nMenu Pilihan :\n1. Input Jadwal\n2. Hapus Jadwal\n3. Exit\n");
        button = getch();
        system("cls");
        if (button == 224)
        {
            button = getch();
            switch (button)
            {
            case 77:
                countworld = countworld + 1;
                if (countworld > 100)
                {
                    exit(0);
                }
                bln = bln + 1;
                if (bln > 12)
                {
                    bln = 1;
                    thn = thn + 1;
                }
                break;

            case 75:
                countworld = countworld - 1;
                if (countworld < 0)
                {
                    exit(0);
                }
                bln = bln - 1;
                if (bln < 1)
                {
                    bln = 12;
                    thn = thn - 1;
                }
                break;

            default:
                printf("Prosess selesai, terima kasih telah menggunakan app kami");
                exit(0);
                break;
            }
        }
        else if (button == 49)
        {
            fflush(stdin);
            printf("Masukkan nama kegiatan : ");
            gets(namajadual);
            fflush(stdin);
            printf("Masukkan tempat kegiatan : ");
            gets(letak);
            fflush(stdin);
            printf("Masukkan tanggal kegiatan : ");
            scanf("%d", &tanggaljadwal);
            fflush(stdin);
            printf("Masukkan jam kegiatan (hh.mm) : ");
            scanf("%d.%d", &jam, &menit);
            pushMiddle(tanggaljadwal, namajadual, letak, jam, menit);
            system("cls");
        }
        else if (button == 50)
        {
            fflush(stdin);
            printf("Masukkan tanggal kegiatan : ");
            scanf("%d", &tanggaljadwal);
            delMiddle(tanggaljadwal);
            system("cls");
        }
        else
        {
            printf("Prosess selesai, terima kasih telah menggunakan app kami");
            exit(0);
        }

    } while (1);
}