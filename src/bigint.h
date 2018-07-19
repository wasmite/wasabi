// this is the difference between the ASCII code for 0 and the integer 0
#define CHARZERO_ABOVEINTZERO 48

// This define defines a single byte unsigned integer
// if your system uses a different type for this kind of integer, substitute it
// here
typedef unsigned char digit;

// the type digit* represents an array of digit s

typedef struct {
  digit *number;  /// this is a pointer to an array of digit s
  int length;     // this is the length of the arrat referenced by number
} BigInt;

/*this function allocates & returns a bigint struct*/
// given a bigint that is _already_ allocated, initialize it with zero.
void newnum(BigInt *);

// given a bigint that is _already_ allocated,
// and given a number string, allocate the bigint
void newnumf(BigInt *, char *);

//
BigInt *newnumc(char *);

//
void numcpy(BigInt *, BigInt *);

//
void delnum(BigInt *);

//
void add(BigInt *, BigInt *, BigInt *);

//
void print(BigInt *);

//
void fprint(BigInt *, FILE *);
