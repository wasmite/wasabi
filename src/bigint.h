//this is the difference between the ASCII code for 0 and the integer 0
#define CHARZERO_ABOVEINTZERO 48


//This define defines a single byte unsigned integer
//if your system uses a different type for this kind of integer, substitute it here
typedef unsigned char digit;

//the type digit* represents an array of digit s


typedef struct
{
   digit* number; ///this is a pointer to an array of digit s
   int length; // this is the length of the arrat referenced by number
} bigint;

void newnum(bigint*);
void newnumf(bigint*, char*);
bigint* newnumc(char*);
void numcpy(bigint*, bigint*);
void delnum(bigint*);

void add(bigint*, bigint*, bigint*);

void print(bigint*);
void fprint(bigint*, FILE*);
