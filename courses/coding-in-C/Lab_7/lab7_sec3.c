#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char *title;
    char *artist;
    struct song *next;
}song;

typedef struct{
    song *head;
}playlist;



void add_song(playlist *playlist, song *newsong){
    song *temp;
    temp=playlist->head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newsong;
}
void delete_song(playlist *playlist, song *delsong){
    song *temp;
    song *del;
    temp=playlist->head;

    if(temp==delsong){
        playlist->head=temp->next;
        return;
    }
    while(temp!=0){
        if(temp->next == delsong){
            del=temp->next;
            temp->next=del->next;
            free(del);
        }
        temp=temp->next;
    }
}
void print_playlist(playlist*playlist){
    song* temp;
    temp = playlist->head;
    while(temp!=NULL){
        printf("%s, %s\n",temp->title, temp->artist);
        temp=temp->next;
    }
}

int main(){
    playlist p1;

    song *a;
    a = malloc(sizeof(song));
    a->title = malloc(strlen("TestTitle") + 1);
    strcpy(a->title, "TestTitle");
    a->artist = malloc(strlen("TestArtist") + 1);
    strcpy(a->artist, "TestArtist");
    a->next=NULL;
    p1.head=a;

    song *b;
    b = malloc(sizeof(song));
    b->title = malloc(strlen("TestTitle") + 1);
    strcpy(b->title, "TestTitle");
    b->artist = malloc(strlen("TestArtist") + 1);
    strcpy(b->artist, "TestArtist");
    b->next=NULL;
    print_playlist(&p1);

}

