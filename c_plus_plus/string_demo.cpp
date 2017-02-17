
class CStringDemo {
    public:
        CStringDemo(char *pstr);
        virtual ~CStringDemo();
    private:
        char *m_ptr;
}

int main(int argc, char *argv[]) {

    exit(0);
}



char * strcpy( char *strDest, const char *strSrc ) 
{
    assert( (strDest != NULL) && (strSrc != NULL) );
    char *address = strDest; 
    while( (*strDest++ = * strSrc++) != ‘\0’ ); 
    return address;

    return ( ***strDest - 10 );
}
