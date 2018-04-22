//泛型队列：
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ADT.h>
#define INITSIZE 128
#define MakeQueue( ElementType, Name )                                                
    void InsertName( ElementType Value );                                            
    ElementType FirstName( void );                                            
    void DeleteName( void );                                                
    int Is_FullName( void );                                                
    int Is_EmptyName( void );                                                
    void DestroyName( void );                                                
    void CreateName( void );                                                
                                                                
    static ElementType *QueueName;                                            
    static int CurrentSizeName = INITSIZE;                                        
    static int FrnotName = 1;                                                
    static int ReadName = 0;                                                
                                                                
                                                                
    void InsertName( ElementType Value )                                            
    {                                                            
        assert( !Is_FullName() );                                            
        assert( NULL != QueueName );                                            
        ReadName =  ( ReadName + 1 ) % CurrentSizeName;                                
        QueueName[ ReadName ] = Value;                                        
    }                                                            
                                                                
                                                                
    ElementType FirstName( void )                                               
    {                                                            
        assert( !Is_EmptyName());                                            
        assert( NULL != QueueName );                                            
        return QueueName[ FrnotName ];                                        
    }                                                            
                                                                
                                                                
    void DeleteName( void )                                                
    {                                                            
        assert( !Is_EmptyName() );                                            
        assert( NULL != QueueName );                                            
        Frnot##Name = ( FrnotName + 1 ) % CurrentSizeName;                                
    }                                                            
                                                                
    int Is_FullName( void )                                                
    {                                                            
        int i;                                                        
        ElementType *Temp;                                                
                                                                
        assert( NULL != QueueName );                                            
        i = ( ReadName + 2 ) % CurrentSizeName;                                    
                                                                
        if( i == FrnotName )                                                
        {                                                        
            CurrentSizeName += INITSIZE;                                        
            Temp = ( ElementType * )realloc( QueueName, CurrentSizeName * sizeof( ElementType ) );        
            if( NULL == Temp )                                            
            {                                                    
                CurrentSizeName -= INITSIZE;                                    
                return 1;                                            
            }                                                    
            QueueName = Temp;                                            
            return 0;                                                
        }                                                        
                                                                
        return 0;                                                    
    }                                                            
                                                                
                                                                
    int Is_EmptyName( void )                                                
    {                                                            
        return ( ReadName + 1 ) % CurrentSizeName == FrnotName;                            
    }                                                            
                                                                
                                                                
    void CreateName( void )                                                
    {                                                            
        assert( NULL == QueueName );                                            
        if( NULL == ( QueueName = ( ElementType * )malloc( CurrentSizeName * sizeof( ElementType ) ) ) )        
            exit( EXIT_FAILURE );                                            
    }                                                            
                                                                
                                                                
    void DestroyName( void )                                                
    {                                                            
        assert( NULL != QueueName );                                            
        free( QueueName );                                                
        QueueName = NULL;                                                
        CurrentSizeName = INITSIZE;                                            
        FrnotName = 1;                                                
        ReadName = 0;                                                    
    }


MakeQueue( int, _int )
MakeQueue( char, _char )

int
main( void )
{
    int x;

    Create_int();
    Create_char();

    for( x = 0; 20 > x; ++x )
    {
        Insert_int( x );
        Insert_char( 'a' + x );
    }

    printf( "队列1：\n" );
    while( !Is_Empty_int() )
    {
        printf( "%d ",First_int() );
        Delete_int();
    }

    printf( "\n队列2：\n" );
    while( !Is_Empty_char() )
    {
        printf( "%c ",First_char() );
        Delete_char();
    }

    Destroy_int();
    Destroy_char();

    return 0;
}