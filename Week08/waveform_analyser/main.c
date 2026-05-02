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
int check_compliance(double rms);
void write_results(const char *filename,
                   double rms_A, double rms_B, double rms_C,
                   double dc_A, double dc_B, double dc_C,
                   double p2p_A, double p2p_B, double p2p_C,
                   int comp_A, int comp_B, int comp_C,
                   int clips_A, int clips_B, int clips_C);


int main(void) {
    WaveformSample samples[MAX_SAMPLES];

    int count = load_csv("power_quality_log.csv", samples, MAX_SAMPLES);

    printf("Loaded %d samples\n\n", count);

    double rms_A = calculate_rms(samples, count, 0);
    double rms_B = calculate_rms(samples, count, 1);
    double rms_C = calculate_rms(samples, count, 2);

    double dc_A = calculate_dc_offset(samples, count, 0);
    double dc_B = calculate_dc_offset(samples, count, 1);
    double dc_C = calculate_dc_offset(samples, count, 2);

    double p2p_A = calculate_peak_to_peak(samples, count, 0);
    double p2p_B = calculate_peak_to_peak(samples, count, 1);
    double p2p_C = calculate_peak_to_peak(samples, count, 2);

    int compliant_A = check_compliance(rms_A);
    int compliant_B = check_compliance(rms_B);
    int compliant_C = check_compliance(rms_C);

    printf("Phase A RMS = %.2f V\n", rms_A);
    printf("Phase B RMS = %.2f V\n", rms_B);
    printf("Phase C RMS = %.2f V\n\n", rms_C);

    printf("Phase A DC Offset = %.5f V\n", dc_A);
    printf("Phase B DC Offset = %.5f V\n", dc_B);
    printf("Phase C DC Offset = %.5f V\n\n", dc_C);

    printf("Phase A Peak-to-Peak = %.2f V\n", p2p_A);
    printf("Phase B Peak-to-Peak = %.2f V\n", p2p_B);
    printf("Phase C Peak-to-Peak = %.2f V\n\n", p2p_C);

    printf("Phase A Compliance = %s\n", compliant_A ? "COMPLIANT" : "NOT COMPLIANT");
    printf("Phase B Compliance = %s\n", compliant_B ? "COMPLIANT" : "NOT COMPLIANT");
    printf("Phase C Compliance = %s\n", compliant_C ? "COMPLIANT" : "NOT COMPLIANT");

    int clips_A = detect_clipping_phase(samples, count, 0);
    int clips_B = detect_clipping_phase(samples, count, 1);
    int clips_C = detect_clipping_phase(samples, count, 2);

    write_results("results.txt",
                  rms_A, rms_B, rms_C,
                  dc_A, dc_B, dc_C,
                  p2p_A, p2p_B, p2p_C,
                  compliant_A, compliant_B, compliant_C,
                  clips_A, clips_B, clips_C);

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
// RMS compliance check

int check_compliance(double rms)
{
    if (rms >= 207.0 && rms <= 253.0)
        return 1;   // compliant
    else
        return 0;   // not compliant
}

// write to results.txt

void write_results(const char *filename,
                   double rms_A, double rms_B, double rms_C,
                   double dc_A, double dc_B, double dc_C,
                   double p2p_A, double p2p_B, double p2p_C,
                   int comp_A, int comp_B, int comp_C,
                   int clips_A, int clips_B, int clips_C)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error writing file.\n");
        return;
    }

    fprintf(fp, "Power Quality Analysis Results\n\n");

    fprintf(fp, "RMS Voltage:\n");
    fprintf(fp, "Phase A: %.2f V\n", rms_A);
    fprintf(fp, "Phase B: %.2f V\n", rms_B);
    fprintf(fp, "Phase C: %.2f V\n\n", rms_C);

    fprintf(fp, "DC Offset:\n");
    fprintf(fp, "Phase A: %.5f V\n", dc_A);
    fprintf(fp, "Phase B: %.5f V\n", dc_B);
    fprintf(fp, "Phase C: %.5f V\n\n", dc_C);

    fprintf(fp, "Peak-to-Peak Voltage:\n");
    fprintf(fp, "Phase A: %.2f V\n", p2p_A);
    fprintf(fp, "Phase B: %.2f V\n", p2p_B);
    fprintf(fp, "Phase C: %.2f V\n\n", p2p_C);

    fprintf(fp, "Compliance:\n");
    fprintf(fp, "Phase A: %s\n", comp_A ? "COMPLIANT" : "NOT COMPLIANT");
    fprintf(fp, "Phase B: %s\n", comp_B ? "COMPLIANT" : "NOT COMPLIANT");
    fprintf(fp, "Phase C: %s\n\n", comp_C ? "COMPLIANT" : "NOT COMPLIANT");

    fprintf(fp, "Clipping Events:\n");
    fprintf(fp, "Phase A: %d\n", clips_A);
    fprintf(fp, "Phase B: %d\n", clips_B);
    fprintf(fp, "Phase C: %d\n", clips_C);
    fprintf(fp, "Total: %d\n", clips_A + clips_B + clips_C);

    fclose(fp);
}