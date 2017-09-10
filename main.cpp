#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//declaration functions 
void * Thread_Main(void * context);

//
void * Thread_Main(void * context)
{
	for (int i = 0; i < 10; ++i)
	{
		printf("I am Thread, created by mario.\n");
		::sleep(1);
	}
	return NULL;
}

int main()
{
	//create thread handle
	pthread_t handle;
	//If create success, return zero. else return nonezero
	if (pthread_create(&handle, NULL, Thread_Main, NULL) != 0)
	{
		printf("Create Thread failed!\n");
		return -1;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("This is the main thread.\n");
		::sleep(1);
	}

	//wait Thread conclude
	pthread_join(handle, NULL);

	return 0;
}
