#include <stdlib.h>
#include <iostream>
using namespace std;
#define INF 99999999;
 
typedef struct _field {
  int towns[10][10];
  bool exist_town[10];
  struct _field* next;
} field;
 
typedef struct {
  int distance[10];
  bool dicision[10];
} town;
 
void commute(field*, town*, int);
 
int main(void) {
  field* head = (field*) malloc(sizeof(field));
  field* p = head;
  p->next = NULL;
  town t;
  int num_way, town1, town2, distance, min, min_num, tmp;
  /* input */
  while(true) {
    cin >> num_way;
    /* input exit */
    if(num_way == 0) break;
    /* err: over number of way */
    if(num_way < 0 || num_way > 45) return -1;
    /* initialization */
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) p->towns[i][j] = INF;
      p->exist_town[i] = false;
    }
    for(int i = 0; i < num_way; i++) {
      cin >> town1 >> town2 >> distance;
      /* err: over town number */
      if(town1 < 0 || town1 > 9 || town2 < 0 || town2 > 9) return -1;
      /* err: distance is negative */
      if(distance < 0) return -1;
      p->towns[town1][town2] = distance;
      p->towns[town2][town1] = distance;
      if(!p->exist_town[town1]) p->exist_town[town1] = true;
      if(!p->exist_town[town2]) p->exist_town[town2] = true;
    }
    p->next = (field*) malloc(sizeof(field));
    p = p->next;
    p->next = NULL;
  }
 
  p = head;
 
  /* operation */
  while(true) {
    if(p->next == NULL) {
      free(p);
      break;
    }
    min = -1;
    for(int my_town = 0; my_town < 10; my_town++) {
      if(p->exist_town[my_town]) {
        /* initialization */
        for(int i = 0; i < 10; i++) {
          if(i == my_town) {
            t.distance[i] = 0;
          } else {
            t.distance[i] = INF;
          }
          t.dicision[i] = false;
        }
        /* call function */
        commute(p, &t, my_town);
        tmp = 0;
        /* total time */
        for(int i = 0; i < 10; i++) {
          if(p->exist_town[i]) {
            tmp += t.distance[i];
          }
        }
        /* if shortest town */
        if(min > tmp || min == -1) {
          min = tmp;
          min_num = my_town;
        }
      }
    }
    /* output */
    cout << min_num << " " << min << endl;
 
    p = p->next;
    free(head);
    head = p;
  }
  return 0;
}
 
/* search route */
void commute(field* p, town* t, int town_num) {
  int min_num = -1, tmp;
  while(true) {
    min_num = -1;
    for(int i = 0; i < 10; i++) {
      if(p->exist_town[i] && !t->dicision[i]) {
        if(min_num == -1 || t->distance[min_num] > t->distance[i]) min_num = i;
      }
    }
    if(min_num == -1) break;
    t->dicision[min_num] = true;
    for(int i = 0; i < 10; i++) {
      if(p->exist_town[i] && t->distance[i] > (tmp = t->distance[min_num] + p->towns[min_num][i])) t->distance[i] = tmp;
    }
  }
}
