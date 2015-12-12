#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

#define N 1000000
#define EPS 1.0e-18

static int a[N];
static int b[N];

int myid, numprocs;

int sort(int size);

int main(int argc, char* argv[])
{
     double  t0, t1, t2, t_w;
     double  dc_inv, d_mflops;

     int     ierr;
     int     i, j;
     int     iflag, iflag_t;

     ierr = MPI_Init(&argc, &argv);
     ierr = MPI_Comm_rank(MPI_COMM_WORLD, &myid);
     ierr = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

        int size = 1;
        for (int j = 0; j < 18; j++) {
                size *= 2;
                srand(1);
                for (i = 0; i < size; i++) {
                        a[i] = rand() % 1000;
                }

                 ierr = MPI_Barrier(MPI_COMM_WORLD);
                 t1 = MPI_Wtime();

			 int get = 0;
                int t;
                if (myid == 0) {
                        while(get == 0) {
                                for (t = 1; t < 192; t++) {
                                        ierr = MPI_Recv(&get, 1, MPI_INT, t, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                                        if (get) break;
								}
                                for (t = 0; t < 192; t++) {
                                        ierr = MPI_Send(&get, 1, MPI_INT, t, 0, MPI_COMM_WORLD);
                                }
			}
                //      for (i = 0; i < size; i++) {                                                                                                    
                //              printf("%d ", a[i]);                                                                                                    
                //      }                                                                                                                               
                //      printf("\n");                                                                                                                   
                } else {
                        while(get == 0) {
                                get = sort(size);
				ierr = MPI_Send(&get, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
                                ierr = MPI_Recv(&get, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        }
		}

        //      for (i = 0; i < size; i++) {                                                                                                            
        //              printf("%d ", a[i]);                                                                                                            
        //      }                                                                                                                                       
        //      printf("\n");                                                                                                                           

                 ierr = MPI_Barrier(MPI_COMM_WORLD);
                 t2 = MPI_Wtime();
                 t0 =  t2 - t1;
                 ierr = MPI_Reduce(&t0, &t_w, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

                 if (myid == 0) {

                   printf("%d \n",size);
                   printf("%lf\n",t_w);

                   d_mflops = 2.0*(double)N*(double)N*(double)N/t_w;
                   d_mflops = d_mflops * 1.0e-6;
                   printf(" %lf [MFLOPS] \n", d_mflops);
                 }

                   MPI_Reduce(&iflag, &iflag_t, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        }

     ierr = MPI_Finalize();

     exit(0);
}

int sort(int size)
{
        int i;
        int k = 0;
	for(i = size; i >= 2; i--) {
		int get = rand() % i;
		b[k] = a[get];
                k++;
                a[get] = a[i - 1];
	}
        b[k] = a[0];
        for (i = 0; i < size; i++) {
                a[i] = b[i];
	}
        int ret = 1;
        for (i = 0; i < size - 1; i++) {
	        if (a[i] > a[i + 1]) {
			ret = 0;
                        break;
		}
        }
        return ret;
}







