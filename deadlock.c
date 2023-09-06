//deadlock.c
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock_a;
pthread_mutex_t lock_b;

pid_t gettid()
{
    return syscall(SYS_gettid);
}

void* func1(void* arg)
{
	pthread_mutex_lock(&lock_a);
	sleep(1);
	pthread_mutex_lock(&lock_b);
	printf("current tid:%u\n", gettid());
	pthread_mutex_unlock(&lock_b);
	pthread_mutex_unlock(&lock_a);
}

// void* func2(void* arg)
// {
// 	pthread_mutex_lock(&lock_b);
// 	sleep(1);
// 	pthread_mutex_lock(&lock_a);
// 	printf("current tid:%u\n", gettid());
// 	pthread_mutex_unlock(&lock_a);
// 	pthread_mutex_unlock(&lock_b);
// }
void* func2(void* arg)
{
	pthread_mutex_lock(&lock_a);
	sleep(1);
	pthread_mutex_lock(&lock_b);
	printf("current tid:%u\n", gettid());
	pthread_mutex_unlock(&lock_b);
	pthread_mutex_unlock(&lock_a);
}
int main()
{
	pthread_mutex_init(&lock_a, NULL);
	pthread_mutex_init(&lock_b, NULL);

	pthread_t tid[2] = {0};

	pthread_create(&tid[0], NULL, &func1, NULL);
	pthread_create(&tid[1], NULL, &func2, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
