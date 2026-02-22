#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
	char *title;
	char *artist;
	struct Song *next;
} Song;

typedef struct {
	Song *head;
} Playlist;

static char *dup_string(const char *src) {
	size_t len = strlen(src) + 1;
	char *copy = (char *)malloc(len);
	if (copy == NULL) {
		return NULL;
	}
	memcpy(copy, src, len);
	return copy;
}

void init_playlist(Playlist *playlist) {
	if (playlist != NULL) {
		playlist->head = NULL;
	}
}

int add_song(Playlist *playlist, const char *title, const char *artist) {
	if (playlist == NULL || title == NULL || artist == NULL) {
		return 0;
	}

	Song *new_song = (Song *)malloc(sizeof(Song));
	if (new_song == NULL) {
		return 0;
	}

	new_song->title = dup_string(title);
	new_song->artist = dup_string(artist);
	if (new_song->title == NULL || new_song->artist == NULL) {
		free(new_song->title);
		free(new_song->artist);
		free(new_song);
		return 0;
	}
	new_song->next = NULL;

	if (playlist->head == NULL) {
		playlist->head = new_song;
		return 1;
	}

	Song *current = playlist->head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_song;
	return 1;
}

void print_playlist(const Playlist *playlist) {
	if (playlist == NULL) {
		return;
	}

	Song *current = playlist->head;
	while (current != NULL) {
		printf("Title: %s, Artist: %s\n", current->title, current->artist);
		current = current->next;
	}
}

void delete_firstSong(Playlist *playlist) {
	if (playlist == NULL || playlist->head == NULL) {
		return;
	}

	Song *first = playlist->head;
	playlist->head = first->next;
	free(first->title);
	free(first->artist);
	free(first);
}

void delete_playlist(Playlist *playlist) {
	if (playlist == NULL) {
		return;
	}

	Song *current = playlist->head;
	while (current != NULL) {
		Song *next = current->next;
		free(current->title);
		free(current->artist);
		free(current);
		current = next;
	}
	playlist->head = NULL;
}

int main(void) {
	Playlist playlist;
	init_playlist(&playlist);

	add_song(&playlist, "Crawling", "Linkin Park");
	add_song(&playlist, "Layla", "Eric Clapton");
	add_song(&playlist, "Esperanto", "Max Herre");

	print_playlist(&playlist);
	delete_firstSong(&playlist);
	print_playlist(&playlist);
	delete_playlist(&playlist);

	return 0;
}
