#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
using namespace std;

int r1,total_produced=0,total_consume=0;

sem_t notEmpty;

void* produce(void *arg){
	while(1){
	cout<<"Producer produces item."<<endl;
	cout<<"Total produced = "<<++total_produced<<
		" Total consume = "<<total_consume*-1<<endl;
	sem_post(¬Empty);	
	sleep(rand()%100*0.01);
	}
}

void* consume(void *arg){
	while(1){
	sem_wait(¬Empty);
	cout<<"Consumer consumes item."<<endl;	
	cout<<"Total produced = "<<total_produced<<
		" Total consume = "<<(--total_consume)*-1<<endl;
	sleep(rand()%100*0.01);
	}	
}

int main(int argv,char *argc[]){

	pthread_t producer,consumer;
	pthread_attr_t attr;

	sem_init(¬Empty,0,0);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	r1=pthread_create(&producer,&attr,produce,NULL);
	if(r1){
	cout<<"Error in creating thread"<<endl;
	exit(-1);
	}

	r1=pthread_create(&consumer,&attr,consume,NULL);
	if(r1){
	cout<<"Error in creating thread"<<endl;
	exit(-1);
	}

	pthread_attr_destroy(&attr);

	r1=pthread_join(producer,NULL);
	if(r1){
	cout<<"Error in joining thread"<<endl;
	exit(-1);
	}

	r1=pthread_join(consumer,NULL);
	if(r1){
	cout<<"Error in joining thread"<<endl;
	exit(-1);
	}
	pthread_exit(NULL);
    cout<<"\nCode by Chander Jindal\n";
	return 0;
}
