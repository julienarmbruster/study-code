/*
 * File: main.c
 * Description: Program to demo usage of playlist
 */
#include "playlist.h"

/**
 * @brief exemplary usage of playlist
 *
 * @return int status code
 */
int main(void)
{
    printf("\nMaximum playlist size is set to %d songs.\n", MAX_SONGS);
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "Crawling", "Linkin Park");
    add_song(&myPlaylist, "Layla", "Eric Clapton");
    add_song(&myPlaylist, "Esperanto", "Max Herre");
    print_playlist(&myPlaylist);

    
    Song* foundSong = find_song_by_title(&myPlaylist, "Crawling");
    if (foundSong)
    {
        printf("Found song: Title: %s, Artist: %s\n", foundSong->title, foundSong->artist);
    }
    else
    {
        printf("Song 'Crawling' not found.\n");
    }

    printf("Laenge der Playlist ist %d\n", count_songs_recursive(myPlaylist.p_head));

    delete_firstSong(&myPlaylist);
    print_playlist(&myPlaylist);

    delete_playlist(&myPlaylist);

    return 0;
}
