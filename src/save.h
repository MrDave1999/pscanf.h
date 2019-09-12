#ifndef _SAVE_H
#define _SAVE_H

struct _node
{
	char a;
	struct _node* sig;
};

typedef struct _node node;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

uint8_t createNode(node** const, size_t* const);
void clearAll(node** const);
uint8_t saveStdin(node** const, size_t* const);
void CopyStdinToString(const node*, char* const, const size_t* const);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* _SAVE_H */