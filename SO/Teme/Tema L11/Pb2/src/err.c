/* A se compila cu: gcc c err.o err.c */ 
#include <errno.h> 
#include <stdarg.h> 
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "../inc/hdr.h" 
/*
 * extern char *sys_siglist[];
*/
static void err_do( int, const char *, va_list); 

char *pname=NULL; 


/* Eroare fatala datorata unui apelsistem. 
 * Afiseaza mesaj si termina procesul. 
 * */
void err_sys(const char *frmt,...)
{
	va_list ap;
	va_start(ap, frmt);
	err_do(1,frmt,ap);
	va_end(ap);
	exit(1);
}

/* Eroare fatala independenta de apelul sistem. 
 * Afiseaza mesaj si termina procesul.
 * */ 
void err_quit(const char *frmt,...)
{
	va_list ap;
        va_start(ap, frmt);
	err_do(0,frmt,ap);
	va_end(ap);
	exit(1);
}


/* Eroare nefatala datorata unui apel sistem. 
 * Afiseaza mesaj si revine. 
 * */
void err_ret(const char *frmt,...)
{
	 va_list ap;
         va_start(ap, frmt);
	 err_do(1,frmt,ap);
	 va_end(ap);
	 return;				 
}

/* Eroare nefatala independenta de un apel sistem. 
 * Afiseaza mesaj si revine. 
 * */
void err_msg(const char *frmt,...)
{
	va_list ap;
        va_start(ap, frmt);
	err_do(0,frmt,ap);
	va_end(ap);
	return;	
}

/* Eroare fatala relativa la un apel sistem. 
 * Afiseaza mesaj, dump core si termina procesul. 
 * */ 
void  err_dump( const char *frmt, ...) 
{ 
	va_list ap;
	va_start( ap, frmt);
	err_do( 1, frmt, ap); 
	va_end(ap); 
	abort(); /* dump core */ 
	exit(1); 
} 

static void err_do( int errfan, const char *frmt, va_list ap) 
{ 
	int errno_save; 
	char buf[MAXLINE]; 
	errno_save=errno; 
	vsprintf( buf, frmt, ap); 
	if ( errfan) 
	   sprintf( buf+strlen( buf), ": %s", strerror( errno_save)); 
	strcat( buf, "\n"); 
	fflush( stdout); 
	fputs( buf, stderr); 
	fflush( NULL);/*goleste toate stdio si stdout*/ 
	return; 
} 
/* Functia print_exit permite afsarea unor informatii de stare
 * */
void print_exit(int status)
{
 if (WIFEXITED (status))
	 printf("Terminare normala, starea de \
		 exit = %d\n", WEXITSTATUS(status));
 else if ( WIFSIGNALED (status))
	 printf("Terminare Anormala, numar \
                 semnal = %d = %s%s\n", WTERMSIG(status),
		 sys_siglist[WTERMSIG(status)], 
#ifdef WCOREDUMP
	WCOREDUMP(status) ? "(generat fisierul core":" ");
#else
	" ");
#endif       	
 else if (WIFSTOPPED(status))
	 printf("Proces fiu oprit, numar semnal=%d%s\n",
		WSTOPSIG(status), sys_siglist[ WSTOPSIG(status)] );
}

void print_mask( const char *str)
{
	sigset_t sigset;
	int i, errno_save;
	
	errno_save=errno;
	if( sigprocmask (0,NULL, &sigset) < 0)
		err_sys("Eroare sigprocmask");
	printf("%s",str);
	for(i=1; i<NSIG;i++)
		if( sigismember(&sigset, i))
		   switch (i){
			   case SIGINT : printf("SIGINT "); break;
			   case SIGQUIT : printf("SIGQUIT "); break;
 			   case SIGALRM : printf("SIGALRM "); break;
			   case SIGUSR1 : printf("SIGUSR1 "); break;
			/*restul de semnale care intereseaza*/ 
		   }
	printf("\n");
	errno=errno_save;
}


/*
 * Sigfunc *signal_intr( int sig, Sigfunc *func)
 * */
