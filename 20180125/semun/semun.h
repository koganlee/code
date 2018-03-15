static int sem_id;
union semun {
	int val;
	struct semid_ds * buf;
	unsigned short *array;
};
static int set_semvalue(void)
{
		union semun sem_union;

		sem_union.val = 1;
		if(semctl(sem_id, 0, SETVAL, sem_union) == -1) return 0;
		return 0;
}



static void del_semvalue(void)
 {
	 union semun sem_union;
   if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
   fprintf(stderr, "Failed to delete semaphore\n");
    }

 static int semaphore_p(void)
 {
    struct sembuf sem_b;
	 sem_b.sem_num = 0;
     sem_b.sem_op  = -1;
	 sem_b.sem_flg = SEM_UNDO;
     if(semop(sem_id, &sem_b, 1) == -1) {
		 fprintf(stderr, "semaphore_p failed\n");
		        return 0;
	  }
	         return 1;
   }

 static int semaphore_v(void)
 {
 struct sembuf sem_b;
	
  sem_b.sem_num = 0;
  sem_b.sem_op = 1;
  sem_b.sem_flg = SEM_UNDO;
   if(semop(sem_id, &sem_b, 1) == -1) {
         fprintf(stderr, "semaphore_v failed\n");
	   return 0;
	   }
		   return 1;
		 }
					
