#include <assert.h>
#include <stdio.h>
#include "mbt/torrent.h"
#include "mbt/be/bencode.h"

void test_mbt_torrent_init() {
    struct mbt_torrent *torrent = mbt_torrent_init();
    assert(torrent != NULL); // Ensure allocation succeeded
    assert(torrent->announce == NULL);
    assert(torrent->creation_date == 0);
    assert(torrent->created_by == NULL);
    assert(torrent->info.name == NULL);
    mbt_torrent_free(torrent);
    printf("test_mbt_torrent_init passed!\n");
}

void test_mbt_torrent_init() {
    struct mbt_torrent *torrent = mbt_torrent_init();
    assert(torrent != NULL); // Ensure allocation succeeded
    assert(torrent->announce == NULL);
    assert(torrent->creation_date == 0);
    assert(torrent->created_by == NULL);
    assert(torrent->info.name == NULL);
    mbt_torrent_free(torrent);
    printf("test_mbt_torrent_init passed!\n");
}


void test_mbt_torrent_free() {
    struct mbt_torrent *torrent = mbt_torrent_init();
    assert(torrent != NULL);
    mbt_torrent_free(torrent); // Ensure no crash during free
    printf("test_mbt_torrent_free passed!\n");
}

void test_mbt_be_parse_torrent_file() {
    struct mbt_torrent *torrent = mbt_torrent_init();
    assert(torrent != NULL);

    bool result = mbt_be_parse_torrent_file("tests/mock.torrent", torrent);
    assert(result == true); // Parsing should succeed
    assert(torrent->announce != NULL);
    assert(torrent->info.name != NULL);

    printf("Torrent announce: %s\n", torrent->announce);
    printf("Info name: %s\n", torrent->info.name);

    mbt_torrent_free(torrent);
    printf("test_mbt_be_parse_torrent_file passed!\n");
}

void test_mbt_be_make_torrent_file() {
    bool result = mbt_be_make_torrent_file("tests/mock_file.txt");
    assert(result == true);
    FILE *file = fopen("mock_file.txt.torrent", "r");
    assert(file != NULL); // Ensure file exists
    fclose(file);

    printf("test_mbt_be_make_torrent_file passed!\n");
}

