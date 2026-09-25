# C Waveform & Power Quality Analyser

A first-year Electrical and Electronic Engineering programming project developed in C at UWE Bristol.

## Project overview

This program analyses three-phase voltage waveform data stored in a CSV file. It loads up to 1,000 samples into a structured data type and calculates key power-quality measurements for each phase.

The project combines C programming with electrical engineering concepts and demonstrates working with real datasets, file I/O and automated engineering calculations.

## Features

- Loads three-phase waveform data from CSV
- Calculates RMS voltage for phases A, B and C
- Calculates DC offset
- Calculates peak-to-peak voltage
- Detects waveform clipping using a defined voltage threshold
- Checks RMS voltage against a 207–253 V compliance range
- Writes the calculated results to a text file

## Example results

Using the included 1,000-sample dataset:

| Measurement | Phase A | Phase B | Phase C |
| --- | ---: | ---: | ---: |
| RMS voltage | 229.81 V | 229.81 V | 229.81 V |
| DC offset | -0.00000 V | 0.00000 V | -0.00000 V |
| Peak-to-peak voltage | 650.00 V | 649.86 V | 649.86 V |
| Compliance | Compliant | Compliant | Compliant |
| Clipping events | 20 | 20 | 20 |

Total clipping events detected: **60**.

## Skills demonstrated

- C programming
- Structures and arrays
- Functions
- File I/O
- CSV data processing
- Mathematical calculations in C
- Three-phase waveform analysis
- Power-quality measurements

## Repository files

- `main.c` – waveform analysis program
- `power_quality_log.csv` – input waveform dataset
- `results.txt` – generated analysis results
- `CMakeLists.txt` – CMake project configuration

## Context

Created as part of my C Programming portfolio while studying Electrical and Electronic Engineering at UWE Bristol.
