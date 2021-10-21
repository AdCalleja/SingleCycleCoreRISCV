# Entity: SlowClock

- **File**: SlowClock.v
## Diagram

![Diagram](SlowClock.svg "Diagram")
## Description

 Clock slower by counting pulses

## Ports

| Port name | Direction | Type | Description |
| --------- | --------- | ---- | ----------- |
| clk       | input     |      |             |
| slow_clk  | output    |      |             |
## Signals

| Name    | Type       | Description |
| ------- | ---------- | ----------- |
| counter | reg [23:0] |             |
## Processes
- unnamed: ( @(posedge clk) )
  - **Type:** always
