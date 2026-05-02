#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1000
#define CLIPPING_LIMIT 324.9

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;

int load_csv(const char *filename, WaveformSample samples[], int max_samples);
double calculate_rms(WaveformSample samples[], int count, int phase);
double calculate_dc_offset(WaveformSample samples[], int count, int phase);
int detect_clipping(WaveformSample samples[], int count);

int main(void) {
    WaveformSample samples[MAX_SAMPLES];

    int count = load_csv("power_quality_log.csv", samples, MAX_SAMPLES);

    printf("Loaded %d samples\n", count);

    double rms_A = calculate_rms(samples, count, 0);

    printf("Phase A RMS = %.2f V\n", rms_A);

    return 0;
}
int load_csv(const char *filename, WaveformSample samples[], int max_samples)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    char line[256];
    int count = 0;

    // Skip header line
    fgets(line, sizeof(line), fp);

    while (fgets(line, sizeof(line), fp) != NULL && count < max_samples)
    {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &samples[count].timestamp,
               &samples[count].phase_A_voltage,
               &samples[count].phase_B_voltage,
               &samples[count].phase_C_voltage,
               &samples[count].frequency,
               &samples[count].power_factor,
               &samples[count].thd_percent);

        count++;
    }

    fclose(fp);

    return count;
}
double calculate_rms(WaveformSample samples[], int count, int phase)
{
    double sum_sq = 0.0;

    for (int i = 0; i < count; i++)
    {
        double value;

        if (phase == 0)
            value = samples[i].phase_A_voltage;
        else if (phase == 1)
            value = samples[i].phase_B_voltage;
        else
            value = samples[i].phase_C_voltage;

        sum_sq += value * value;
    }

    return sqrt(sum_sq / count);
}