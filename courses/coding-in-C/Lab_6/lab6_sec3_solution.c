#include <stdio.h>

struct sensordata{
    float time;
    double probability;
};
struct sensor{
    int id;
    double threshold;
    struct sensordata data[3000];
    int object_detection[3000];
};

int main(){
    struct sensor sensor1;
    struct sensor sensor2;
    int fused[3000];
    sensor1.threshold = 0.8;
    sensor2.threshold = 0.7;
    FILE *file1 = fopen("sensor1.txt", "r");
    FILE *file2 = fopen("sensor2.txt", "r");
   
    printf("Sensor 1:\n");
    for(int i=0;i<3000;i++){
        fscanf(file1, "%f %lf", &sensor1.data[i].time, &sensor1.data[i].probability);
        if(sensor1.data[i].probability>sensor1.threshold){
            sensor1.object_detection[i]=1;
        }
        else{
            sensor1.object_detection[i]=0;
        }
        if(sensor1.object_detection[i]!=sensor1.object_detection[i-1] && i){
            if(sensor1.object_detection[i]){
                printf("Start: %.2f ", sensor1.data[i].time);
            }
            if(sensor1.object_detection[i]==0){
                printf("Ende: %.2f \n", sensor1.data[i-1].time);
            }
        }
        if(i==2999&&sensor2.object_detection[i]) printf("Ende: %.2f \n", sensor1.data[i].time);
    }
    printf("\nSensor 2:\n");
    for(int i=0;i<3000;i++){
        fscanf(file2, "%f %lf", &sensor2.data[i].time, &sensor2.data[i].probability);

        if(sensor2.data[i].probability>sensor2.threshold){
            sensor2.object_detection[i]=1;
        }
        else{
            sensor2.object_detection[i]=0;
        }
        if(sensor2.object_detection[i]!=sensor2.object_detection[i-1] && i){
            if(sensor2.object_detection[i]){
                printf("Start: %.2f ", sensor2.data[i].time);
            }
            if(sensor2.object_detection[i]==0){
                printf("Ende: %.2f \n", sensor2.data[i-1].time);
            }
        }
        if(i==2999&&sensor2.object_detection[i]) printf("Ende: %.2f \n", sensor2.data[i].time);

    }
    printf("\nFused:\n");
    for(int i=0;i<3000;i++){
        fused[i]=sensor1.object_detection[i] & sensor2.object_detection[i];
        if(fused[i]!=fused[i-1] && i){
            if(fused[i]){
                printf("Start: %.2f ", sensor1.data[i].time);
            }
            if(fused[i]==0){
                printf("Ende: %.2f \n", sensor1.data[i-1].time);
            }
        }
        if(i==2999&&fused[1]) printf("Ende: %.2f \n", sensor1.data[i].time);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}