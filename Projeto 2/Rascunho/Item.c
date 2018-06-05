#include "Item.h"





int freq(celula **raiz)
{
    int freq;

    freq = (*raiz)->item->freq;
    freq++;
    (*raiz)->item->freq = freq;

	return ((*raiz)->freq + 1);
}
