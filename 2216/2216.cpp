#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct _account {
  struct _account *next;
  int price, payment;
} account;

int main() {
  int change, money[] = {1000, 500, 100}, num[3];
  account* head = (account*) malloc(sizeof(account));
  account* p = head;
  p->next = NULL;

  /* input */
  while(true) {
    cin >> p->price >> p->payment;
    /* input end */
    if(p->price == 0 && p->payment == 0) break;
    /* create new node */
    p->next = (account*) malloc(sizeof(account));
    p = p->next;
    p->next = NULL;
  }

  p = head;

  /* output */
  while(true) {
    /* output end */
    if(p->price == 0 && p->payment == 0) {
      free(p);
      break;
    }
    /* error */
    if(p->price % 100 != 0 || p->payment % 100 != 0) return 1;
    if(p->price > 100000000 || p->payment > 100000000) return 1;
    if((change = p->payment - p->price) < 0) return 1;
    /* calculate */
    for(int i = 0; i < 3; i++) {
      num[i] = change / money[i];
      change %= money[i];
    }
    cout << num[2] << " " << num[1] << " " <<  num[0] << endl;
    head = p;
    p = p->next;
    free(head);
  }

  return 0;
}
