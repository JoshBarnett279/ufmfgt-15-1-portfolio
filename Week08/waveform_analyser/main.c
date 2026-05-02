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

int main() {
    WaveformSample samples[MAX_SAMPLES];

    printf("Waveform analyser started\n");
    return 0;
}
