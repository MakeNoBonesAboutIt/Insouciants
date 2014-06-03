#include "player.h"


int change_hp(struct player_t *player, int hp)
{
    if(MAX_HP <= player->player_hp + hp)
    {
        player->player_hp = MAX_HP;
    }
    else
    {
        if(MIN_HP >= player->player_hp + hp)
        {
            player->player_hp = MIN_HP;
            return 1;
        }
        else
        {
            player->player_hp = player->player_hp + hp;
        }
    }
    return 0;
}

struct card_t play_card_from_hand(struct player_t *player, int card)
{
    int n = player->player_hand.n;
    int i;
    struct card_t result;
    struct card_t *pcard;
    if(n <= card || card < 0)
    {
        result.attack = 0;
        result.life = 0;
        result.cost = 0;
        result.name[0] = '\0';
    }
    else
    {
        result = player->player_hand.cards[card];
        for(i = card + 1; i < n; i++)
        {
            player->player_hand.cards[i-1] = player->player_hand.cards[i];
        }
        player->player_hand.n = n - 1;
	pcard = &player->player_hand.cards[n-1];
        pcard->attack = 0;
        pcard->life = 0;
        pcard->cost = 0;
        pcard->name[0] = '\0';
    }
    return result;
}

void turn_begin(struct player_t *player)
{
    struct card_t card;
    player->player_mana.mana ++;
    if(draw_card(&player->player_deck, &card) == 0)
        push_card(card, &player->player_hand);
}
