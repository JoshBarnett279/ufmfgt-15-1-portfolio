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
int detect_clipping_phase(WaveformSample samples[], int count, int phase);
double calculate_peak_to_peak(WaveformSample samples[], int count, int phase);

int main(void) {
    WaveformSample samples[MAX_SAMPLES];

    int count = load_csv("power_quality_log.csv", samples, MAX_SAMPLES);

    printf("Loaded %d samples\n\n", count);

    double rms_A = calculate_rms(samples, count, 0);

    printf("Phase A RMS = %.2f V\n\n", rms_A);

    double dc_A = calculate_dc_offset(samples, count, 0);

    printf("Phase A DC Offset = %.5f V\n\n", dc_A);

    int clips_A = detect_clipping_phase(samples, count, 0);
    int clips_B = detect_clipping_phase(samples, count, 1);
    int clips_C = detect_clipping_phase(samples, count, 2);

    printf("Phase A clipping events = %d\n", clips_A);
    printf("Phase B clipping events = %d\n", clips_B);
    printf("Phase C clipping events = %d\n", clips_C);
    printf("Total clipping readings = %d\n\n", clips_A + clips_B + clips_C);

    double p2p_A = calculate_peak_to_peak(samples, count, 0);
    printf("Phase A Peak-to-Peak = %.2f V\n", p2p_A);

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

// RMS calculation phase A

double calculate_rms(WaveformSample samples[], int count, int phase) {
    double sum_sq = 0.0;

    for (int i = 0; i < count; i++) {
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

//DC offset / average voltage
double calculate_dc_offset(WaveformSample samples[], int count, int phase)
{
    double sum = 0.0;

    for (int i = 0; i < count; i++)
    {
        double value;

        if (phase == 0)
            value = samples[i].phase_A_voltage;
        else if (phase == 1)
            value = samples[i].phase_B_voltage;
        else
            value = samples[i].phase_C_voltage;

        sum += value;
    }

    return sum / count;
}

// Clipping function

int detect_clipping_phase(WaveformSample samples[], int count, int phase)
{
    int clip_count = 0;

    for (int i = 0; i < count; i++)
    {
        double value;

        if (phase == 0)
            value = samples[i].phase_A_voltage;
        else if (phase == 1)
            value = samples[i].phase_B_voltage;
        else
            value = samples[i].phase_C_voltage;

        if (fabs(value) >= CLIPPING_LIMIT)
            clip_count++;
    }

    return clip_count;
}
// Peak to peak calculations
double calculate_peak_to_peak(WaveformSample samples[], int count, int phase)
{
    double max_val, min_val;

    for (int i = 0; i < count; i++)
    {
        double value;

        if (phase == 0)
            value = samples[i].phase_A_voltage;
        else if (phase == 1)
            value = samples[i].phase_B_voltage;
        else
            value = samples[i].phase_C_voltage;

        if (i == 0)
        {
            max_val = value;
            min_val = value;
        }
        else
        {
            if (value > max_val) max_val = value;
            if (value < min_val) min_val = value;
        }
    }

    return max_val - min_val;
}
