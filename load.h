typedef void (*ArrayFunction)(int*, int);
typedef void (*MatrixFunction)(int**, int, int);

void *Load(const char * const s, void **l, const char * const name);
void closeLib(void *lib);