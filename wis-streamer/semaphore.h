#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
//#define SEMV 1221
//#define SEMVE 1220
#define SEMA 1223  //semFull_audio
#define SEMAE 1222   //semEmpty_audio
/*�����������static �ؼ���,��ʾ����������ڲ�����,
 *ֻ���ڱ��ļ��ڵ���.
 */
int set_semvalue(int sem_id,int val);	//�����ź���
void del_semvalue(int sem_id);	//ɾ���ź���
int semaphore_p(int sem_id);	//-1
int semaphore_v(int sem_id);	// +1

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
    /* union semun is defined by including <sys/sem.h> */
#else
    /* according to X/OPEN we have to define it ourselves */
    union semun {
        int val;                    /* value for SETVAL */
        struct semid_ds *buf;       /* buffer for IPC_STAT, IPC_SET */
        unsigned short int *array;  /* array for GETALL, SETALL */
        struct seminfo *__buf;      /* buffer for IPC_INFO */
    };
#endif



