#ifndef head_h
#define head_h

typedef int (*fptrOperation)(int , int);

int add ( int , int );

int sub( int , int );

int mul( int , int );

int div( int , int );

int rem( int , int );

fptrOperation select( char );

int evaluate( char , int ,int );

#endif
