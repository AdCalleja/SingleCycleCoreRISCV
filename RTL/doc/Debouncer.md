# Entity: Debouncer

- **File**: Debouncer.v
## Diagram

![Diagram](Debouncer.svg "Diagram")
## Description

 Button Clock Debouncer

## Ports

| Port name | Direction | Type | Description |
| --------- | --------- | ---- | ----------- |
| clk       | input     |      |             |
| btn       | input     |      |             |
| btn_out   | output    |      |             |
## Signals

| Name        | Type | Description |
| ----------- | ---- | ----------- |
| slow_clk_en | wire |             |
| Q1          | wire |             |
| Q2          | wire |             |
| Q2_bar      | wire |             |
| Q0          | wire |             |
## Instantiations

- clock_enable1: clock_enable
- d0: my_dff_en
- d1: my_dff_en
- d2: my_dff_en
