#include "standards.h"
#include "board.h"

#define _00_(_I_, _J_)  (_I_      ), (_J_      )
#define _09_(_I_, _J_)  (_J_      ), (7 - (_I_))
#define _18_(_I_, _J_)  (7 - (_I_)), (7 - (_J_))
#define _27_(_I_, _J_)  (7 - (_J_)), (_I_      )

#define _VV_(_I_, _J_)  (7 - (_I_)), (_J_      )
#define _HH_(_I_, _J_)  (_I_      ), (7 - (_J_))

void flip(struct board *b)
{
	uint8_t i, j, poo, pvv;
	uint8_t wsc, wbc, bsc, bbc;

	b->turn = (b->turn ? 0 : 1);

	wsc = b->bsc;
	wbc = b->bbc;
	bsc = b->wsc;
	bbc = b->wbc;

	b->wsc = bsc;
	b->wbc = bbc;
	b->bsc = wsc;
	b->bbc = wbc;

	if ((b->hx != 0) && (b->hy != 0))
		b->hx = 7 - b->hx;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			poo = get_piece(b, _00_(i, j));
			pvv = get_piece(b, _VV_(i, j));
			set_piece(b, _00_(i, j), OP_COL(pvv));
			set_piece(b, _VV_(i, j), OP_COL(poo));
		}
	}

}

bool mirror(struct board *b)
{
	uint8_t i, j, poo, phh;

	if ((b->wsc != 0) || (b->wbc != 0) || 
			(b->bsc != 0) || (b->bbc != 0))
		return false;

	if ((!on_bound(b->hx)) && (b->hy != 0))
		b->hy = 7 - b->hy;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 4; j++) {
			poo = get_piece(b, _00_(i, j));
			phh = get_piece(b, _HH_(i, j));
			set_piece(b, _00_(i, j), phh);
			set_piece(b, _HH_(i, j), poo);
		}
	}

	return true;
}

bool rotate(struct board *b, bool clock)
{
	uint8_t i, j, p00, p09, p18, p27;

	if ((b->wsc != 0) || (b->wbc != 0) || 
			(b->bsc != 0) || (b->bbc != 0))
		return false;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			if (BP_ == FIG(get_piece(b, i, j)))
				return false;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			p00 = get_piece(b, _00_(i, j));
			p09 = get_piece(b, _09_(i, j));
			p18 = get_piece(b, _18_(i, j));
			p27 = get_piece(b, _27_(i, j));

			if (clock) {
				set_piece(b, _00_(i, j), p09);
				set_piece(b, _09_(i, j), p18);
				set_piece(b, _18_(i, j), p27);
				set_piece(b, _27_(i, j), p00);
			} else {
				set_piece(b, _00_(i, j), p27);
				set_piece(b, _09_(i, j), p00);
				set_piece(b, _18_(i, j), p09);
				set_piece(b, _27_(i, j), p18);
			}
		}
	}

	return true;

}

uint32_t count_diff(struct board *b1, struct board *b2)
{
	uint64_t b[4];
	int8_t i, j;
	uint32_t sum = 0;

	for (i = 0; i < 4; i++)
		b[i] = *((uint64_t *)(b1->pos) + i) ^ (*(((uint64_t *)(b2->pos)) + i));


	for (i = 0; i < 4; i++) {
		for (j = 0; j < 64; j++) {
			sum += b[i] & 1;
			b[i] >>= 1;
		}
	}

	return sum;
}

uint32_t hash_pos(struct board *bo)
{
	uint8_t *data = (uint8_t *)bo;
	uint32_t res = 0;
	uint8_t i, j, hash[4];

	for (i = 0; i < 4; i++)
		hash[i] = 0;

	for (i = 0; i < 2 * sizeof(struct board); i++)
		hash[i % 4] ^= data[i % sizeof(struct board)];

	for (i = 0; i < 4; i++)
		res += hash[i] << (8 * i);

	return res;

}
