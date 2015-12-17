#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

typedef enum {
  man,
  black,
  red
} tileKind;

typedef struct _tiles {
  struct _tiles* next;
  int width, height;
  tileKind tile[20][20];
  bool chk_tile[20][20];
  int man_x, man_y, count;
} tiles;

void move(tiles*, int, int, int);

int main() {
  tiles* head = (tiles*) malloc(sizeof(tiles));
  tiles* p = head;
  p->count = 1;
  p->next = NULL;
  string buf;
  bool chk_man;

  /* input */
  while(true) {
    chk_man = false;
    cin >> p->width >> p->height;
    /* exit input */
    if(p->width == 0 && p->height == 0) break;
    /* err: over 20 */
    if(p->width > 20 || p->height > 20) return -1;

    for(int i = 0; i < p->height; i++) {
      cin >> buf;
      if(buf.length() != p->width) break;
      for(int j = 0; j < p->width; j++) {
	switch(buf.at(j)) {
	case '.':
	  p->tile[i][j] = black;
	  break;
	case '#':
	  p->tile[i][j] = red;
	  break;
	case '@':
	  p->tile[i][j] = man;
	  /* err: plural man */
	  if(chk_man == true) return -1;
	  chk_man = true;
	  p->man_x = j;
	  p->man_y = i;
	  break;
	dafault:
	  /* err: undefined input */
	  return -1;
	}
	p->chk_tile[i][j] = false;
      }
    }

    /* err: no man */
    if(chk_man == false) return -1;
    /* create new node */
    p->next = (tiles*) malloc(sizeof(tiles));
    p = p->next;
    p->count = 1;
    p->next = NULL;
  }

  p = head;

  /* output */
  while(true) {
    /* call func */
    move(p, p->man_x, p->man_y, -1);
    /* output screen */
    cout << p->count << endl;
    p = p->next;
    free(head);
    if(p->next == NULL) {
      free(p);
      break;
    }
    head = p;
  }

  return 0;
}

void move(tiles* p, int x, int y, int prev) {
  /* move to right */
  if(prev != 1 && x + 1 < p->width) {
    if(p->tile[y][x + 1] == black && p->chk_tile[y][x + 1] == false) {
      p->chk_tile[y][x + 1] = true;
      (p->count)++;
      move(p, x + 1, y, 0);
    }
  }
  /* move to left */
  if(prev != 0 && x - 1 >= 0) {
    if(p->tile[y][x - 1] == black && p->chk_tile[y][x - 1] == false) {
      p->chk_tile[y][x - 1] = true;
      (p->count)++;
      move(p, x - 1, y, 1);
    }
  }
  /* move to bottom */
  if(prev != 3 && y + 1 < p->height) {
    if(p->tile[y + 1][x] == black && p->chk_tile[y + 1][x] == false) {
      p->chk_tile[y + 1][x] = true;
      (p->count)++;
      move(p, x, y + 1, 2);
    }
  }
  /* move to top */
  if(prev != 2 && y - 1 >= 0) {
    if(p->tile[y - 1][x] == black && p->chk_tile[y - 1][x] == false) {
      p->chk_tile[y - 1][x] = true;
      (p->count)++;
      move(p, x, y - 1, 3);
    }
  }
}
