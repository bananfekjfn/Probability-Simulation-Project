#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double gen_exp_411186028(double lambda){

    double e =((double)rand()/((double)RAND_MAX+1.0));
    return -log(1- e) / lambda;
  }

int sim(double lambda) {
 int N = -1;
 double resttime = 0.0;
 double T = 0.0;
    double Ti[10000];
    int Ni[10000];
    double Ttotal = 0.0;
    double Ntotal = 0.0;
    double inter_arrival_time[10000];
    double service_time[10000];

    for (int i=0; i<10000; i++){
    inter_arrival_time [i] = gen_exp_411186028(lambda);
    service_time [i] = gen_exp_411186028(1);
    }
    Ti[0] = service_time [0];
    for (int i=1; i<10000; i++){
    if(service_time [i]>inter_arrival_time [i-1]){
    Ti[i] = service_time [i] - inter_arrival_time [i-1];
    Ttotal += Ti[i];
        }}
    for (int i=0; i<10000; i++){
     resttime += Ti[i];
    if (resttime >= inter_arrival_time[i] && i < 10000) {
    N += 1;
    resttime -= inter_arrival_time[i];}
            else{
         resttime += service_time[i+1];
   Ni[i] = N;
        }
        Ntotal += Ni[i];
    }
    N=Ntotal/10000;
    T=(Ttotal+service_time [0])/10000;

    printf("N= %d, T= %lf\n", N, T);
    return 0;
}

int main() {
    double lambda;

    srand(time(NULL));
    scanf("%lf\n",&lambda);
    printf("Input lambda: %lf\n ",lambda);

    sim(lambda);

    return 0;
}
