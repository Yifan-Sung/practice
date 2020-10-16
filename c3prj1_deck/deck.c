#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

/*
int com (card_t c1,card_t c2){
  if ((c1.value == c2.value) &&(c1.suit == c2.suit)) return 1;
  return 0;

}
*/

void print_hand(deck_t * hand){
  //card_t ** card =hand -> cards ;
  //card_t  card1;
  for (size_t i=0 ;i<(hand -> n_cards );i++){
    // card1=**(card +i);
    print_card(*(hand->cards[i]));
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (size_t i=0; i<(d->n_cards); i++) {
    if (((d->cards[i]->value) == c.value) && ((d->cards[i]->suit)==c.suit)) {
      //  printf("contained in deck");
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t max_rand=d->n_cards;
  card_t swap_card;
  size_t num;
  size_t num2;
  for (size_t i=0; i<max_rand; i++){
    num=rand()%max_rand;
    num2=rand()%max_rand;
    //   while (num>max_rand){
    //num/=2;
    //}
    // printf("num =%zu ", num);
    swap_card.value=d->cards[num]->value;
    swap_card.suit=d->cards[num]->suit;
    d->cards[num]->value=d->cards[num2]->value;
    d->cards[num]->suit=d->cards[num2]->suit;
    d->cards[num2]->value=swap_card.value;
    d->cards[num2]->suit=swap_card.suit;
  }
}

void assert_full_deck(deck_t * d) {
  // printf("running assert_full_deck");
  assert(d->n_cards == 52);
  for (size_t i=0; i < d->n_cards; i++){
    assert_card_valid(*(d->cards[i]));
    assert(deck_contains(d, card_from_num(i))==1);
  }

}


/*
void add_card_to(deck_t * deck,card_t c){
  card_t * c1=malloc(sizeof(*c1));
  c1->value = c.value;
  c1->suit = c.suit;
  deck ->cards= realloc(deck->cards,(deck ->n_cards+1)*sizeof(*deck ->cards));
  deck ->cards[deck ->n_cards]=c1;
  deck ->n_cards ++;
}

card_t * add_empty_card(deck_t * deck){
  card_t* c1=malloc(sizeof(*c1));
  c1->value = 0;
  c1->suit = 0;
  deck ->cards= realloc(deck->cards,(deck ->n_cards+1)*sizeof(*deck ->cards));
  deck ->cards[deck ->n_cards]=c1;
  deck ->n_cards ++;
  return c1;
}

deck_t * make_deck_exclude(deck_t * exclude_cards){
  deck_t* ans=malloc(sizeof(*ans));
  ans->cards=NULL;
  ans->n_cards=0;
  for(unsigned i=0;i<52;i++){
    card_t c= card_from_num(i);
    if(!deck_contains(exclude_cards,c)) add_card_to(ans,c);
  }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands,size_t n_hands){
  deck_t* deck=malloc(sizeof(*deck));
  deck->n_cards=0;
  deck->cards=NULL;
  for (size_t i=0; i<n_hands; i++){
    for (int x=0; x<hands[i]->n_cards; x++){
      deck->cards=realloc(deck->cards,(deck->n_cards+1)*sizeof(*deck->cards));
      deck->cards[deck->n_cards]=hands[i]->cards[x];
      deck->n_cards ++;
    }
  }
  deck_t* deck2=make_deck_exclude(deck);
  free(deck->cards);
  free(deck);
  return deck2;
}

void free_deck(deck_t * deck){
  for(int i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}

 */
